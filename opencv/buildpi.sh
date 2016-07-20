# export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:/usr/local/lib"

#g++ -std=c++11 test1.cpp `pkg-config --libs opencv` -Wl,-rpath=/usr/local/lib

g++ -Iinclude -std=c++11 test1.cpp `pkg-config --libs opencv` -Wl,-rpath=lib/pi
