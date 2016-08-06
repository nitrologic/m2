# VHost a monkey2 Device Abstraction Model

Currently vhost provides monkey2 support for implementation of linux framebuffers, video inputs and i2c bus peripherals and sockets.

A virtual model is also supplied to emulate the Pi SenseHat 8x8 LED array and allow testing and devlopment on non linux platforms.

![pihat](pihat.jpg?raw=true "PiSenseHat")

## V4L2

[Video for Linux Reference](https://linuxtv.org/downloads/v4l-dvb-apis/index.html)

Formats for Pi Camera Rev 1.3  as listed by capture.cpp:

format[0] 4:2:0, planar, YUV YU12  [0]16x16..2592x1944 1-90
format[1] 4:2:2, packed, YUYV YUYV  [0]16x16..2592x1944 1-90
format[2] RGB24 (LE) RGB3  [0]16x16..2592x1944 1-90
format[3] JPEG JPEG  [0]16x16..2592x1944 1-90
format[4] H264 H264  [0]16x16..2592x1944 1-90
format[5] MJPEG MJPG  [0]16x16..2592x1944 1-90
format[6] 4:2:2, packed, YVYU YVYU  [0]16x16..2592x1944 1-90
format[7] 4:2:2, packed, VYUY VYUY  [0]16x16..2592x1944 1-90
format[8] 4:2:2, packed, UYVY UYVY  [0]16x16..2592x1944 1-90
format[9] 4:2:0, planar, NV12 NV12  [0]16x16..2592x1944 1-90
format[10] RGB24 (BE) BGR3  [0]16x16..2592x1944 1-90
format[11] 4:2:0, planar, YVU YV12  [0]16x16..2592x1944 1-90
format[12] 4:2:0, planar, NV21 NV21  [0]16x16..2592x1944 1-90
format[13] RGB32 (BE) BGR4  [0]16x16..2592x1944 1-90
