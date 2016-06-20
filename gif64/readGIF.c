/*
**  Copyright 1994, Home Pages, Inc.
**
**    Please read the file COPYRIGHT for specific information.
**
**    Home Pages, Inc.
**    257 Castro St. Suite 219
**    Mountain View, CA 94041
**
**    Phone: 1 415 903 5353
**      Fax: 1 415 903 5345
**
**    EMail: support@homepages.com
** 
*/
 
/* +-------------------------------------------------------------------+ */
/* | Copyright 1990 - 1994, David Koblas. (koblas@netcom.com)          | */
/* |   Permission to use, copy, modify, and distribute this software   | */
/* |   and its documentation for any purpose and without fee is hereby | */
/* |   granted, provided that the above copyright notice appear in all | */
/* |   copies and that both that copyright notice and this permission  | */
/* |   notice appear in supporting documentation.  This software is    | */
/* |   provided "as is" without express or implied warranty.           | */
/* +-------------------------------------------------------------------+ */

#include <stdio.h>
#include <setjmp.h>

#include "gif.h"

#define        TRUE    1
#define        FALSE   0

#define        MAX_LWZ_BITS            12

#define INTERLACE		0x40
#define LOCALCOLORMAP		0x80

#define BitSet(byte, bit)	(((byte) & (bit)) == (bit))
#define	ReadOK(file,buffer,len) (fread(buffer, len, 1, file) != 0)
#define MKINT(a,b)		(((b)<<8)|(a))
#define NEW(x)			((x *)malloc(sizeof(x)))

/***************************************************************************
*
*  ERROR()    --  should not return
*  INFO_MSG() --  info message, can be ignored
*
***************************************************************************/

#if 0
#define INFO_MSG(fmt)	pm_message fmt 
#define ERROR(str)	pm_error(str)
#else
#if 0 
#define INFO_MSG(fmt)	
#define ERROR(str) 	do { RWSetMsg(str); longjmp(setjmp_buffer, 1); } while(0)
#else
#define INFO_MSG(fmt)	
#define ERROR(str) 	longjmp(setjmp_buffer, 1)
#endif
#endif

/***************************************************************************/

static int readColorMap(FILE *, int, unsigned char [GIF_MAXCOLORS][3]);
static int GetDataBlock(FILE *, unsigned char *);
static void readImage(FILE *, int, int, int, unsigned char *);

static jmp_buf                  setjmp_buffer;

static int    verbose = FALSE;
static int    showComment = FALSE;

int     GIFTest(char *file)
{
        FILE    *fd = fopen(file, "rb");
        char    buf[10];
        int     ret = FALSE;

        if (fd != NULL && ReadOK(fd, buf, 6)) {
                if ((strncmp(buf, "GIF", 3) == 0) &&
                     ((strncmp(buf + 3, "87a", 3) != 0) ||
                      (strncmp(buf + 3, "89a", 3) != 0)))
                        ret = TRUE;
        }

        fclose(fd);

        return ret;
}

GIFStream *GIFReadFP(FILE *fd)
{
	unsigned char   buf[256];
	unsigned char   c;
	GIFStream	*stream;
	GIFData		*cur, **end;
	GIF89info	info;
	int		resetInfo = TRUE;
	int		n;

	if (fd == NULL)
		return NULL;

	if (setjmp(setjmp_buffer))
		goto out;

	if (! ReadOK(fd,buf,6)) 
	       ERROR("error reading magic number" );

	if (strncmp((char*)buf,"GIF",3) != 0) 
	       ERROR("not a GIF file" );

	if ((strncmp(buf + 3, "87a", 3) != 0) && 
	    (strncmp(buf + 3, "89a", 3) != 0)) 
		ERROR("bad version number, not '87a' or '89a'" );

	if (! ReadOK(fd,buf,7))
		ERROR("failed to read screen descriptor");

	stream = NEW(GIFStream);

	stream->width           = MKINT(buf[0], buf[1]);
	stream->height          = MKINT(buf[2], buf[3]);

	stream->cmapSize        = 2 << (buf[4] & 0x07);
	stream->colorMapSize    = stream->cmapSize;
	stream->colorResolution = ((int)(buf[4] & 0x70) >> 3) + 1;
	stream->background      = buf[5];
	stream->aspectRatio     = buf[6];

	stream->data            = NULL;

	end = &stream->data;

	/*
	**  Global colormap is present.
	*/
	if (BitSet(buf[4], LOCALCOLORMAP)) {
		if (readColorMap(fd, stream->cmapSize, stream->cmapData))
			ERROR("unable to get global colormap");
	} else {
		stream->cmapSize   = 0;
		stream->background = -1;
	}

	if (stream->aspectRatio != 0 && stream->aspectRatio != 49) {
	       float   r;

	       r = ((float) stream->aspectRatio + 15.0) / 64.0;
	       INFO_MSG(("warning - non-square pixels; to fix do a 'pnmscale -%cscale %g'",
		   r < 1.0 ? 'x' : 'y',
		   r < 1.0 ? 1.0 / r : r ));
	}

	while (ReadOK(fd, &c, 1) && c != ';') {
		if (resetInfo) {
			info.disposal    = 0;
			info.inputFlag   = 0;
			info.delayTime   = 0;
			info.transparent = -1;
			resetInfo = FALSE;
		}
		cur = NULL;

		if (c == '!') {		/* Extension */
			if (! ReadOK(fd,&c,1))
				ERROR("EOF / read error on extention function code");
			if (c == 0xf9) {	/* graphic control */
				(void) GetDataBlock(fd, buf);
				info.disposal    = (buf[0] >> 2) & 0x7;
				info.inputFlag   = (buf[0] >> 1) & 0x1;
				info.delayTime   = MKINT(buf[1],buf[2]);
				if (BitSet(buf[0], 0x1))
					info.transparent = buf[3];

				while (GetDataBlock(fd,  buf) != 0)
					;
			} else if (c == 0xfe || c == 0x01) {
				int		len = 0;
				int		size = 256;
				char		*text = NULL;

				/* 
				**  Comment or Plain Text
				*/

				cur = NEW(GIFData);

				if (c == 0x01) {
					(void)GetDataBlock(fd, buf);
						
					cur->type   = gif_text;
					cur->info   = info;
					cur->x      = MKINT(buf[0],buf[1]);
					cur->y      = MKINT(buf[2],buf[3]);
					cur->width  = MKINT(buf[4],buf[5]);
					cur->height = MKINT(buf[6],buf[7]);

					cur->data.text.cellWidth  = buf[8];
					cur->data.text.cellHeight = buf[9];
					cur->data.text.fg         = buf[10];
					cur->data.text.bg         = buf[11];

					resetInfo = TRUE;
				} else {
					cur->type    = gif_comment;
				}

				text = (char*)malloc(size);

				while ((n = GetDataBlock(fd, buf)) != 0) {
					if (n + len >= size) 
						text = (char*)realloc(text, size += 256);
					memcpy(text + len, buf, n);
					len += n;
				}

				if (c == 0x01) {
					cur->data.text.len  = len;
					cur->data.text.text = text;
				} else {
					cur->data.comment.len  = len;
					cur->data.comment.text = text;
				}
			} else {
				/*
				**  Unrecogonized extension, consume it.
				*/
				while (GetDataBlock(fd, buf) > 0)
					;
			}
		} else if (c == ',') {
			if (! ReadOK(fd,buf,9))
			       ERROR("couldn't read left/top/width/height");

			cur = NEW(GIFData);

			cur->type   = gif_image;
			cur->info   = info;
			cur->x      = MKINT(buf[0], buf[1]);
			cur->y      = MKINT(buf[2], buf[3]);
			cur->width  = MKINT(buf[4], buf[5]);
			cur->height = MKINT(buf[6], buf[7]);
			cur->data.image.cmapSize = 1 << ((buf[8] & 0x07) + 1);
			if (BitSet(buf[8], LOCALCOLORMAP)) {
				if (readColorMap(fd, cur->data.image.cmapSize, 
					             cur->data.image.cmapData))
					ERROR("unable to get local colormap");
			} else {
				cur->data.image.cmapSize = 0;

			}
			cur->data.image.data = (unsigned char *)malloc(cur->width * cur->height);
			cur->data.image.interlaced = BitSet(buf[8], INTERLACE);
			readImage(fd, BitSet(buf[8], INTERLACE), 
				cur->width, cur->height, cur->data.image.data);

			resetInfo = TRUE;
		} else {
			INFO_MSG(("bogus character 0x%02x, ignoring", (int)c));
		}

		if (cur != NULL) {
			*end = cur;
			end = &cur->next;
			cur->next = NULL;
		}
	}

	if (c != ';')
		ERROR("EOF / data stream" );

out:

	return stream;
}

GIFStream *GIFRead(char *file)
{
	FILE		*fp = fopen(file, "rb");
	GIFStream	*stream = NULL;

	if (fp != NULL) {
		stream = GIFReadFP(fp);
		fclose(fp);
	}
	return stream;
}

static int readColorMap(FILE *fd, int size, 
			unsigned char data[GIF_MAXCOLORS][3])
{
	int             i;
	unsigned char   rgb[3 * GIF_MAXCOLORS];
	unsigned char	*cp = rgb;

	if (! ReadOK(fd, rgb, size * 3))
		return TRUE;

	for (i = 0; i < size; i++) {
		data[i][0] = *cp++;
		data[i][1] = *cp++;
		data[i][2] = *cp++;
	}

	return FALSE;
}

/*
**
*/

static int    ZeroDataBlock = FALSE;

static int GetDataBlock(FILE *fd, unsigned char *buf)
{
       unsigned char   count;

       if (! ReadOK(fd,&count,1)) {
               INFO_MSG(("error in getting DataBlock size"));
               return -1;
       }

       ZeroDataBlock = count == 0;

       if ((count != 0) && (! ReadOK(fd, buf, count))) {
               INFO_MSG(("error in reading DataBlock"));
               return -1;
       }

       return count;
}

/*
**
**
*/

/*
**  Pulled out of nextCode
*/
static	int		curbit, lastbit, get_done, last_byte;
static	int		return_clear;
/*
**  Out of nextLWZ
*/
static int      stack[(1<<(MAX_LWZ_BITS))*2], *sp;
static int      code_size, set_code_size;
static int      max_code, max_code_size;
static int      clear_code, end_code;

static void initLWZ(int input_code_size)
{
	static int	inited = FALSE;

	set_code_size = input_code_size;
	code_size     = set_code_size + 1;
	clear_code    = 1 << set_code_size ;
	end_code      = clear_code + 1;
	max_code_size = 2 * clear_code;
	max_code      = clear_code + 2;

	curbit = lastbit = 0;
	last_byte = 2;
	get_done = FALSE;

	return_clear = TRUE;

	sp = stack;
}

static int nextCode(FILE *fd, int code_size)
{
	static unsigned char    buf[280];
	static int maskTbl[16] = {
		0x0000, 0x0001, 0x0003, 0x0007, 
		0x000f, 0x001f, 0x003f, 0x007f,
		0x00ff, 0x01ff, 0x03ff, 0x07ff,
		0x0fff, 0x1fff, 0x3fff, 0x7fff,
	};
	int                     i, j, ret, end;

	if (return_clear) {
		return_clear = FALSE;
		return clear_code;
	}

	end = curbit + code_size;

	if (end >= lastbit) {
		int	count;

		if (get_done) {
			if (curbit >= lastbit)
				ERROR("ran off the end of my bits" );
			return -1;
		}
		buf[0] = buf[last_byte-2];
		buf[1] = buf[last_byte-1];

		if ((count = GetDataBlock(fd, &buf[2])) == 0)
			get_done = TRUE;

		last_byte = 2 + count;
		curbit = (curbit - lastbit) + 16;
		lastbit = (2+count)*8 ;

		end = curbit + code_size;
	}

	j = end / 8;
	i = curbit / 8;

        if (i == j) 
                ret = buf[i];
        else if (i + 1 == j) 
                ret = buf[i] | (buf[i+1] << 8);
        else 
                ret = buf[i] | (buf[i+1] << 8) | (buf[i+2] << 16);

        ret = (ret >> (curbit % 8)) & maskTbl[code_size];

	curbit += code_size;
	
	return ret;
}

#define readLWZ(fd) ((sp > stack) ? *--sp : nextLWZ(fd))

static int nextLWZ(FILE *fd)
{
       static int	table[2][(1<< MAX_LWZ_BITS)];
       static int	firstcode, oldcode;
       int		code, incode;
       register int	i;

       while ((code = nextCode(fd, code_size)) >= 0) {
               if (code == clear_code) {
                       for (i = 0; i < clear_code; ++i) {
                               table[0][i] = 0;
                               table[1][i] = i;
                       }
                       for (; i < (1<<MAX_LWZ_BITS); ++i)
                               table[0][i] = table[1][i] = 0;
                       code_size = set_code_size+1;
                       max_code_size = 2*clear_code;
                       max_code = clear_code+2;
                       sp = stack;
			do {
			       firstcode = oldcode = nextCode(fd, code_size);
			} while (firstcode == clear_code);

			return firstcode;
               }
	       if (code == end_code) {
                       int             count;
                       unsigned char   buf[260];

                       if (ZeroDataBlock)
                               return -2;

                       while ((count = GetDataBlock(fd, buf)) > 0)
                               ;

                       if (count != 0)
                               INFO_MSG(("missing EOD in data stream"));
                       return -2;
               }

               incode = code;

               if (code >= max_code) {
                       *sp++ = firstcode;
                       code = oldcode;
               }

               while (code >= clear_code) {
                       *sp++ = table[1][code];
                       if (code == table[0][code])
                               ERROR("circular table entry BIG ERROR");
                       code = table[0][code];
               }

               *sp++ = firstcode = table[1][code];

               if ((code = max_code) <(1<<MAX_LWZ_BITS)) {
                       table[0][code] = oldcode;
                       table[1][code] = firstcode;
                       ++max_code;
                       if ((max_code >= max_code_size) &&
                               (max_code_size < (1<<MAX_LWZ_BITS))) {
                               max_code_size *= 2;
                               ++code_size;
                       }
               }

               oldcode = incode;

               if (sp > stack)
                       return *--sp;
       }
       return code;
}

static void readImage(FILE *fd, int interlace, int width, int height, 
			unsigned char *data)
{
       unsigned char	*dp, c;      
       int		v, xpos = 0, ypos = 0, pass = 0;

	/*
	**  Initialize the Compression routines
	*/
	if (! ReadOK(fd,&c,1))
		ERROR("EOF / read error on image data" );

	initLWZ(c);

	if (verbose)
		INFO_MSG(("reading %d by %d%s GIF image",
			width, height, interlace ? " interlaced" : ""));

	if (interlace) {
		int	i;
		int	pass = 0, step = 8;

		for (i = 0; i < height; i++) {
			dp = &data[width * ypos];
			for (xpos = 0; xpos < width; xpos++) {
				if ((v = readLWZ(fd)) < 0)
					goto fini;

				*dp++ = v;
			}
			if ((ypos += step) >= height) {
				do {
					if (pass++ > 0)
						step /= 2;
					ypos = step / 2;
				} while (ypos > height);
			}
		}
	} else {
		dp = data;
		for (ypos = 0; ypos < height; ypos++) {
			for (xpos = 0; xpos < width; xpos++) {
				if ((v = readLWZ(fd)) < 0)
					goto fini;

				*dp++ = v;
			}
		}
	}

fini:
       if (readLWZ(fd) >= 0)
               INFO_MSG(("too much input data, ignoring extra..."));

       return;
}
