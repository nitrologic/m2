#pragma once

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#ifdef __LINUX__

#include <sys/ioctl.h>
#include <sys/mman.h>
#include <linux/fb.h>
#include <string.h>

class fb{

public:

static int queryFramebuffer(int fd,int *width,int *height,int *depth,int *bytesize){

	fb_fix_screeninfo fix={0};
	fb_var_screeninfo var={0};

	if (ioctl(fd,FBIOGET_FSCREENINFO,&fix)==-1){
		printf("Error reading fixed information\n");
		return -1;
	}

	if (ioctl(fd,FBIOGET_VSCREENINFO,&var)==-1){
		printf("Error reading fixed information\n");
		return -2;
	}

	*width=var.xres;
	*height=var.yres;
	*depth=var.bits_per_pixel;
	*bytesize=(*width)*(*height)*(*depth)/8;

	return 0;
}

static void *mapFramebuffer(int fd,int sizeBytes){
	void *memory=mmap(0,sizeBytes,PROT_WRITE,MAP_SHARED,fd,0);
	if ((int)memory==-1) {
		printf("Error: mmap failed on fd\n");
		return nullptr;
	}
	printf("Framebuffer mapped to %p\n",memory);
	return memory;
}

static void unmapFrameBuffer(void *memory,int sizeBytes){
	munmap(memory,sizeBytes);
}

};

#endif