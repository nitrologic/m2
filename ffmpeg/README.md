# ffmpeg module research

## Background

Continued research into most suitable SDK for a kickass monkey2 video IO module.



## video for linux 2 VFL2

> v4l2-ctl -L

User Controls

                     brightness (int)    : min=0 max=100 step=1 default=50 value=50 flags=slider
                       contrast (int)    : min=-100 max=100 step=1 default=0 value=0 flags=slider
                     saturation (int)    : min=-100 max=100 step=1 default=0 value=0 flags=slider
                    red_balance (int)    : min=1 max=7999 step=1 default=1000 value=1000 flags=slider
                   blue_balance (int)    : min=1 max=7999 step=1 default=1000 value=1000 flags=slider
                horizontal_flip (bool)   : default=0 value=0
                  vertical_flip (bool)   : default=0 value=0

           power_line_frequency (menu)   : min=0 max=3 default=1 value=1
				0: Disabled
				1: 50 Hz
				2: 60 Hz
				3: Auto
                      sharpness (int)    : min=-100 max=100 step=1 default=0 value=0 flags=slider
                  color_effects (menu)   : min=0 max=15 default=0 value=0
				0: None
				1: Black & White
				2: Sepia
				3: Negative
				4: Emboss
				5: Sketch
				6: Sky Blue
				7: Grass Green
				8: Skin Whiten
				9: Vivid
				10: Aqua
				11: Art Freeze
				12: Silhouette
				13: Solarization
				14: Antique
				15: Set Cb/Cr
                         rotate (int)    : min=0 max=360 step=90 default=0 value=0
             color_effects_cbcr (int)    : min=0 max=65535 step=1 default=32896 value=32896

Codec Controls

             video_bitrate_mode (menu)   : min=0 max=1 default=0 value=0 flags=update
				0: Variable Bitrate
				1: Constant Bitrate
                  video_bitrate (int)    : min=25000 max=25000000 step=25000 default=10000000 value=10000000
         repeat_sequence_header (bool)   : default=0 value=0
            h264_i_frame_period (int)    : min=0 max=2147483647 step=1 default=60 value=60
                     h264_level (menu)   : min=0 max=11 default=11 value=11
				0: 1
				1: 1b
				2: 1.1
				3: 1.2
				4: 1.3
				5: 2
				6: 2.1
				7: 2.2
				8: 3
				9: 3.1
				10: 3.2
				11: 4
                   h264_profile (menu)   : min=0 max=4 default=4 value=4
				0: Baseline
				1: Constrained Baseline
				2: Main
				4: High

Camera Controls

                  auto_exposure (menu)   : min=0 max=3 default=0 value=0
				0: Auto Mode
				1: Manual Mode
         exposure_time_absolute (int)    : min=1 max=10000 step=1 default=1000 value=1000
     exposure_dynamic_framerate (bool)   : default=0 value=0
             auto_exposure_bias (intmenu): min=0 max=24 default=12 value=12
				0: -4000 (0xfffffffffffff060)
				1: -3667 (0xfffffffffffff1ad)
				2: -3333 (0xfffffffffffff2fb)
				3: -3000 (0xfffffffffffff448)
				4: -2667 (0xfffffffffffff595)
				5: -2333 (0xfffffffffffff6e3)
				6: -2000 (0xfffffffffffff830)
				7: -1667 (0xfffffffffffff97d)
				8: -1333 (0xfffffffffffffacb)
				9: -1000 (0xfffffffffffffc18)
				10: -667 (0xfffffffffffffd65)
				11: -333 (0xfffffffffffffeb3)
				12: 0 (0x0)
				13: 333 (0x14d)
				14: 667 (0x29b)
				15: 1000 (0x3e8)
				16: 1333 (0x535)
				17: 1667 (0x683)
				18: 2000 (0x7d0)
				19: 2333 (0x91d)
				20: 2667 (0xa6b)
				21: 3000 (0xbb8)
				22: 3333 (0xd05)
				23: 3667 (0xe53)
				24: 4000 (0xfa0)
      white_balance_auto_preset (menu)   : min=0 max=9 default=1 value=1
				0: Manual
				1: Auto
				2: Incandescent
				3: Fluorescent
				4: Fluorescent H
				5: Horizon
				6: Daylight
				7: Flash
				8: Cloudy
				9: Shade
            image_stabilization (bool)   : default=0 value=0
                iso_sensitivity (intmenu): min=0 max=4 default=0 value=0
				0: 0 (0x0)
				1: 100 (0x64)
				2: 200 (0xc8)
				3: 400 (0x190)
				4: 800 (0x320)
         exposure_metering_mode (menu)   : min=0 max=2 default=0 value=0
				0: Average
				1: Center Weighted
				2: Spot
                     scene_mode (menu)   : min=0 max=13 default=0 value=0
				0: None
				8: Night
				11: Sports

JPEG Compression Controls

            compression_quality (int)    : min=1 max=100 step=1 default=30 value=30
                     brightness (int)    : min=0 max=100 step=1 default=50 value=50 flags=slider
                       contrast (int)    : min=-100 max=100 step=1 default=0 value=0 flags=slider
                     saturation (int)    : min=-100 max=100 step=1 default=0 value=0 flags=slider
                    red_balance (int)    : min=1 max=7999 step=1 default=1000 value=1000 flags=slider
                   blue_balance (int)    : min=1 max=7999 step=1 default=1000 value=1000 flags=slider
                horizontal_flip (bool)   : default=0 value=0
                  vertical_flip (bool)   : default=0 value=0



## ffmpeg configuration for pi build

Followed from here https://www.assetbank.co.uk/support/documentation/install/ffmpeg-debian-squeeze/ffmpeg-debian-jessie/

oops, wrong version, this one is todays second pick:

http://ffmpeg.org/releases/ffmpeg-3.1.1.tar.bz2


pi@raspberrypi ~/ffmpeg-2.7.2 $ ./configure --enable-gpl --enable-postproc --enable-swscale --enable-avfilter --enable-libmp3lame --enable-libvorbis --enable-libtheora --enable-libx264 --enable-libspeex --enable-shared --enable-pthreads --enable-libopenjpeg --enable-nonfree
install prefix            /usr/local
source path               .
C compiler                gcc
C library                 glibc
ARCH                      arm (armv6)
big-endian                no
runtime cpu detection     yes
ARMv5TE enabled           yes
ARMv6 enabled             yes
ARMv6T2 enabled           yes
VFP enabled               yes
NEON enabled              yes
THUMB enabled             no
debug symbols             yes
strip symbols             yes
optimize for size         no
optimizations             yes
static                    yes
shared                    yes
postprocessing support    yes
new filter support        yes
network support           yes
threading support         pthreads
safe bitstream reader     yes
SDL support               yes
opencl enabled            no
texi2html enabled         no
perl enabled              yes
pod2man enabled           yes
makeinfo enabled          no
makeinfo supports HTML    no

External libraries:
iconv			libvorbis		libxcb_xfixes
libmp3lame		libx264			lzma
libopenjpeg		libxcb			sdl
libspeex		libxcb_shape		xlib
libtheora		libxcb_shm		zlib

Enabled decoders:
aac			bfi			g729
aac_latm		bink			gif
aasc			binkaudio_dct		gsm
ac3			binkaudio_rdft		gsm_ms
ac3_fixed		bintext			h261
adpcm_4xm		bmp			h263
adpcm_adx		bmv_audio		h263i
adpcm_afc		bmv_video		h263p
adpcm_ct		brender_pix		h264
adpcm_dtk		c93			hevc
adpcm_ea		cavs			hnm4_video
adpcm_ea_maxis_xa	ccaption		hq_hqa
adpcm_ea_r1		cdgraphics		hqx
adpcm_ea_r2		cdxl			huffyuv
adpcm_ea_r3		cinepak			iac
adpcm_ea_xas		cljr			idcin
adpcm_g722		cllc			idf
adpcm_g726		comfortnoise		iff_byterun1
adpcm_g726le		cook			iff_ilbm
adpcm_ima_amv		cpia			imc
adpcm_ima_apc		cscd			indeo2
adpcm_ima_dk3		cyuv			indeo3
adpcm_ima_dk4		dca			indeo4
adpcm_ima_ea_eacs	dfa			indeo5
adpcm_ima_ea_sead	dirac			interplay_dpcm
adpcm_ima_iss		dnxhd			interplay_video
adpcm_ima_oki		dpx			jacosub
adpcm_ima_qt		dsd_lsbf		jpeg2000
adpcm_ima_rad		dsd_lsbf_planar		jpegls
adpcm_ima_smjpeg	dsd_msbf		jv
adpcm_ima_wav		dsd_msbf_planar		kgv1
adpcm_ima_ws		dsicinaudio		kmvc
adpcm_ms		dsicinvideo		lagarith
adpcm_sbpro_2		dss_sp			libopenjpeg
adpcm_sbpro_3		dvbsub			libspeex
adpcm_sbpro_4		dvdsub			libvorbis
adpcm_swf		dvvideo			loco
adpcm_thp		dxa			mace3
adpcm_vima		dxtory			mace6
adpcm_xa		eac3			mdec
adpcm_yamaha		eacmv			metasound
aic			eamad			microdvd
alac			eatgq			mimic
alias_pix		eatgv			mjpeg
als			eatqi			mjpegb
amrnb			eightbps		mlp
amrwb			eightsvx_exp		mmvideo
amv			eightsvx_fib		motionpixels
anm			escape124		movtext
ansi			escape130		mp1
ape			evrc			mp1float
apng			exr			mp2
ass			ffv1			mp2float
asv1			ffvhuff			mp3
asv2			ffwavesynth		mp3adu
atrac1			fic			mp3adufloat
atrac3			flac			mp3float
atrac3p			flashsv			mp3on4
aura			flashsv2		mp3on4float
aura2			flic			mpc7
avrn			flv			mpc8
avrp			fourxm			mpeg1video
avs			fraps			mpeg2video
avui			frwu			mpeg4
ayuv			g2m			mpegvideo
bethsoftvid		g723_1			mpl2
msa1			ptx			tta
msmpeg4v1		qcelp			twinvq
msmpeg4v2		qdm2			txd
msmpeg4v3		qdraw			ulti
msrle			qpeg			utvideo
mss1			qtrle			v210
mss2			r10k			v210x
msvideo1		r210			v308
mszh			ra_144			v408
mts2			ra_288			v410
mvc1			ralf			vb
mvc2			rawvideo		vble
mxpeg			realtext		vc1
nellymoser		rl2			vc1image
nuv			roq			vcr1
on2avc			roq_dpcm		vima
opus			rpza			vmdaudio
paf_audio		rv10			vmdvideo
paf_video		rv20			vmnc
pam			rv30			vorbis
pbm			rv40			vp3
pcm_alaw		s302m			vp5
pcm_bluray		sami			vp6
pcm_dvd			sanm			vp6a
pcm_f32be		sgi			vp6f
pcm_f32le		sgirle			vp7
pcm_f64be		shorten			vp8
pcm_f64le		sipr			vp9
pcm_lxf			smackaud		vplayer
pcm_mulaw		smacker			vqa
pcm_s16be		smc			wavpack
pcm_s16be_planar	smvjpeg			webp
pcm_s16le		snow			webvtt
pcm_s16le_planar	sol_dpcm		wmalossless
pcm_s24be		sonic			wmapro
pcm_s24daud		sp5x			wmav1
pcm_s24le		srt			wmav2
pcm_s24le_planar	ssa			wmavoice
pcm_s32be		stl			wmv1
pcm_s32le		subrip			wmv2
pcm_s32le_planar	subviewer		wmv3
pcm_s8			subviewer1		wmv3image
pcm_s8_planar		sunrast			wnv1
pcm_u16be		svq1			ws_snd1
pcm_u16le		svq3			xan_dpcm
pcm_u24be		tak			xan_wc3
pcm_u24le		targa			xan_wc4
pcm_u32be		targa_y216		xbin
pcm_u32le		tdsc			xbm
pcm_u8			text			xface
pcm_zork		theora			xl
pcx			thp			xsub
pgm			tiertexseqvideo		xwd
pgmyuv			tiff			y41p
pgssub			tmv			yop
pictor			truehd			yuv4
pjs			truemotion1		zero12v
png			truemotion2		zerocodec
ppm			truespeech		zlib
prores			tscc			zmbv
prores_lgpl		tscc2

Enabled encoders:
a64multi		libopenjpeg		pgmyuv
a64multi5		libspeex		png
aac			libtheora		ppm
ac3			libvorbis		prores
ac3_fixed		libx264			prores_aw
adpcm_adx		libx264rgb		prores_ks
adpcm_g722		ljpeg			qtrle
adpcm_g726		mjpeg			r10k
adpcm_ima_qt		movtext			r210
adpcm_ima_wav		mp2			ra_144
adpcm_ms		mp2fixed		rawvideo
adpcm_swf		mpeg1video		roq
adpcm_yamaha		mpeg2video		roq_dpcm
alac			mpeg4			rv10
alias_pix		msmpeg4v2		rv20
amv			msmpeg4v3		s302m
apng			msvideo1		sgi
ass			nellymoser		snow
asv1			pam			sonic
asv2			pbm			sonic_ls
avrp			pcm_alaw		srt
avui			pcm_f32be		ssa
ayuv			pcm_f32le		subrip
bmp			pcm_f64be		sunrast
cinepak			pcm_f64le		svq1
cljr			pcm_mulaw		targa
comfortnoise		pcm_s16be		tiff
dca			pcm_s16be_planar	tta
dnxhd			pcm_s16le		utvideo
dpx			pcm_s16le_planar	v210
dvbsub			pcm_s24be		v308
dvdsub			pcm_s24daud		v408
dvvideo			pcm_s24le		v410
eac3			pcm_s24le_planar	vorbis
ffv1			pcm_s32be		wavpack
ffvhuff			pcm_s32le		webvtt
flac			pcm_s32le_planar	wmav1
flashsv			pcm_s8			wmav2
flashsv2		pcm_s8_planar		wmv1
flv			pcm_u16be		wmv2
g723_1			pcm_u16le		xbm
gif			pcm_u24be		xface
h261			pcm_u24le		xsub
h263			pcm_u32be		xwd
h263p			pcm_u32le		y41p
huffyuv			pcm_u8			yuv4
jpeg2000		pcx			zlib
jpegls			pgm			zmbv
libmp3lame

Enabled hwaccels:

Enabled parsers:
aac			dvd_nav			mpegvideo
aac_latm		dvdsub			opus
ac3			flac			png
adx			gsm			pnm
bmp			h261			rv30
cavsvideo		h263			rv40
cook			h264			tak
dca			hevc			vc1
dirac			mjpeg			vorbis
dnxhd			mlp			vp3
dpx			mpeg4video		vp8
dvbsub			mpegaudio		vp9

Enabled demuxers:
aac			gsm			mtv
ac3			gxf			mv
act			h261			mvi
adf			h263			mxf
adp			h264			mxg
adx			hevc			nc
aea			hls			nistsphere
afc			hnm			nsv
aiff			ico			nut
amr			idcin			nuv
anm			idf			ogg
apc			iff			oma
ape			ilbc			paf
apng			image2			pcm_alaw
aqtitle			image2_alias_pix	pcm_f32be
asf			image2_brender_pix	pcm_f32le
ass			image2pipe		pcm_f64be
ast			image_bmp_pipe		pcm_f64le
au			image_dpx_pipe		pcm_mulaw
avi			image_exr_pipe		pcm_s16be
avr			image_j2k_pipe		pcm_s16le
avs			image_jpeg_pipe		pcm_s24be
bethsoftvid		image_jpegls_pipe	pcm_s24le
bfi			image_pictor_pipe	pcm_s32be
bink			image_png_pipe		pcm_s32le
bintext			image_qdraw_pipe	pcm_s8
bit			image_sgi_pipe		pcm_u16be
bmv			image_sunrast_pipe	pcm_u16le
boa			image_tiff_pipe		pcm_u24be
brstm			image_webp_pipe		pcm_u24le
c93			ingenient		pcm_u32be
caf			ipmovie			pcm_u32le
cavsvideo		ircam			pcm_u8
cdg			iss			pjs
cdxl			iv8			pmp
cine			ivf			pva
concat			jacosub			pvf
data			jv			qcp
daud			latm			r3d
dfa			live_flv		rawvideo
dirac			lmlm4			realtext
dnxhd			loas			redspark
dsf			lrc			rl2
dsicin			lvf			rm
dss			lxf			roq
dts			m4v			rpl
dtshd			matroska		rsd
dv			mgsts			rso
dvbsub			microdvd		rtp
dxa			mjpeg			rtsp
ea			mlp			sami
ea_cdata		mlv			sap
eac3			mm			sbg
epaf			mmf			sdp
ffm			mov			sdr2
ffmetadata		mp3			segafilm
filmstrip		mpc			shorten
flac			mpc8			siff
flic			mpegps			sln
flv			mpegts			smacker
fourxm			mpegtsraw		smjpeg
frm			mpegvideo		smush
g722			mpjpeg			sol
g723_1			mpl2			sox
g729			mpsub			spdif
gif			msnwc_tcp		srt
stl			tty			webm_dash_manifest
str			txd			webvtt
subviewer		vc1			wsaud
subviewer1		vc1t			wsvqa
sup			vivo			wtv
swf			vmd			wv
tak			vobsub			xa
tedcaptions		voc			xbin
thp			vplayer			xmv
tiertexseq		vqf			xwma
tmv			w64			yop
truehd			wav			yuv4mpegpipe
tta			wc3

Enabled muxers:
a64			ipod			pcm_s32be
ac3			ircam			pcm_s32le
adts			ismv			pcm_s8
adx			ivf			pcm_u16be
aiff			jacosub			pcm_u16le
amr			latm			pcm_u24be
apng			lrc			pcm_u24le
asf			m4v			pcm_u32be
asf_stream		matroska		pcm_u32le
ass			matroska_audio		pcm_u8
ast			md5			psp
au			microdvd		rawvideo
avi			mjpeg			rm
avm2			mkvtimestamp_v2		roq
bit			mlp			rso
caf			mmf			rtp
cavsvideo		mov			rtp_mpegts
crc			mp2			rtsp
dash			mp3			sap
data			mp4			segment
daud			mpeg1system		singlejpeg
dirac			mpeg1vcd		smjpeg
dnxhd			mpeg1video		smoothstreaming
dts			mpeg2dvd		sox
dv			mpeg2svcd		spdif
eac3			mpeg2video		spx
f4v			mpeg2vob		srt
ffm			mpegts			stream_segment
ffmetadata		mpjpeg			swf
filmstrip		mxf			tee
flac			mxf_d10			tg2
flv			mxf_opatom		tgp
framecrc		null			truehd
framemd5		nut			uncodedframecrc
g722			oga			vc1
g723_1			ogg			vc1t
gif			oma			voc
gxf			opus			w64
h261			pcm_alaw		wav
h263			pcm_f32be		webm
h264			pcm_f32le		webm_chunk
hds			pcm_f64be		webm_dash_manifest
hevc			pcm_f64le		webp
hls			pcm_mulaw		webvtt
ico			pcm_s16be		wtv
ilbc			pcm_s16le		wv
image2			pcm_s24be		yuv4mpegpipe
image2pipe		pcm_s24le

Enabled protocols:
cache			http			rtmpt
concat			httpproxy		rtp
crypto			icecast			srtp
data			md5			subfile
ffrtmphttp		mmsh			tcp
file			mmst			udp
ftp			pipe			udplite
gopher			rtmp			unix
hls

Enabled filters:
adelay			deshake			pan
aecho			detelecine		perms
aeval			drawbox			perspective
aevalsrc		drawgrid		phase
afade			earwax			pixdesctest
aformat			ebur128			pp
ainterleave		edgedetect		pp7
allpass			elbg			psnr
alphaextract		eq			pullup
alphamerge		equalizer		qp
amerge			extractplanes		removelogo
amix			fade			repeatfields
amovie			fftfilt			replaygain
anull			field			rgbtestsrc
anullsink		fieldmatch		rotate
anullsrc		fieldorder		sab
apad			find_rect		scale
aperms			flanger			select
aphaser			format			sendcmd
aresample		fps			separatefields
aselect			framepack		setdar
asendcmd		framestep		setfield
asetnsamples		fspp			setpts
asetpts			geq			setsar
asetrate		gradfun			settb
asettb			haldclut		showcqt
ashowinfo		haldclutsrc		showinfo
asplit			hflip			showpalette
astats			highpass		showspectrum
astreamsync		histeq			showwaves
atempo			histogram		showwavespic
atrim			hqdn3d			shuffleplanes
avectorscope		hqx			signalstats
bandpass		hue			silencedetect
bandreject		idet			silenceremove
bass			il			sine
bbox			interlace		smartblur
biquad			interleave		smptebars
blackdetect		join			smptehdbars
blackframe		kerndeint		split
blend			lenscorrection		spp
boxblur			life			stereo3d
cellauto		lowpass			super2xsai
channelmap		lut			swapuv
channelsplit		lut3d			tblend
chorus			lutrgb			telecine
codecview		lutyuv			testsrc
color			mandelbrot		thumbnail
colorbalance		mcdeint			tile
colorchannelmixer	mergeplanes		tinterlace
colorlevels		movie			transpose
colormatrix		mpdecimate		treble
compand			mptestsrc		trim
concat			negate			unsharp
copy			noformat		uspp
cover_rect		noise			vflip
crop			null			vignette
cropdetect		nullsink		volume
curves			nullsrc			volumedetect
dcshift			overlay			w3fdif
dctdnoiz		owdenoise		xbr
decimate		pad			yadif
dejudder		palettegen		zoompan
delogo			paletteuse

Enabled bsfs:
aac_adtstoasc		mjpeg2jpeg		mpeg4_unpack_bframes
chomp			mjpega_dump_header	noise
dump_extradata		mov2textsub		remove_extradata
h264_mp4toannexb	mp3_header_decompress	text2movsub
imx_dump_header

Enabled indevs:
alsa			lavfi			v4l2
dv1394			oss			x11grab_xcb
fbdev

Enabled outdevs:
alsa			oss			v4l2
fbdev			sdl

License: nonfree and unredistributable
Creating config.mak, config.h, and doc/config.texi...