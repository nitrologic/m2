# export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:/usr/local/lib"

#g++ -std=c++11 test1.cpp `pkg-config --libs opencv` -Wl,-rpath=/usr/local/lib

#g++ -Iinclude -std=c++11 test1.cpp `pkg-config --libs opencv` -Wl,-rpath=lib/pi

g++ -Iinclude -std=c++11 test1.cpp lib/mac/libopencv_core.dylib lib/mac/libopencv_imgcodecs.dylib lib/mac/libopencv_imgproc.dylib  lib/mac/libopencv_highgui.dylib
