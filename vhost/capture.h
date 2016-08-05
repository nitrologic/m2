#pragma once

static int open_device(void);
static void init_device(void);
static void uninit_device(void);
static int close_device(void);
static void stop_capturing(void);
static void start_capturing(void);
static int readFrame(void);

extern int frame_number=0;
extern void *frame_data;
extern int frame_size=0;
extern int frame_type=0;
