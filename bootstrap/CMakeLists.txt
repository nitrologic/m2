cmake_minimum_required(VERSION 2.8.9)
 
project(monkey2)
 
IF(PI)
   add_definitions( -D__PI__)
   SET(CMAKE_SYSTEM_NAME Linux)
   SET(CMAKE_SYSTEM_VERSION 1)
   SET(CMAKE_C_COMPILER gcc-4.9)
   SET(CMAKE_CXX_COMPILER g++-4.9)
   SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w -std=c++11")   
ENDIF(PI)
 
include_directories( 
  /home/pi/monkey2/modules/monkey/native
)
 
file(GLOB mx2cc_src 
  /home/pi/monkey2/modules/std/std.buildv1.0.0/build_cache/desktop_release_linux/*.cpp
  /home/pi/monkey2/modules/libc/libc.buildv1.0.0/build_cache/desktop_release_linux/*.cpp
  /home/pi/monkey2/modules/stb-image/stb-image.buildv1.0.0/build_cache/desktop_release_linux/*.cpp
  /home/pi/monkey2/modules/stb-image-write/stb-image-write.buildv1.0.0/build_cache/desktop_release_linux/*.cpp
  /home/pi/monkey2/modules/miniz/miniz.buildv1.0.0/build_cache/desktop_release_linux/*.cpp
  /home/pi/monkey2/modules/hoedown/hoedown.buildv1.0.0/build_cache/desktop_release_linux/*.cpp
  *.cpp
  /home/pi/monkey2/modules/monkey/native/*.cpp
  /home/pi/monkey2/modules/stb-image/native/*.c
  /home/pi/monkey2/modules/stb-image-write/native/*.c
  /home/pi/monkey2/modules/std/misc/native/*.cpp
  /home/pi/monkey2/modules/std/fiber/native/*.cpp
  /home/pi/monkey2/modules/std/libc/native/*.cpp
  /home/pi/monkey2/modules/miniz/native/*.c
  /home/pi/monkey2/modules/hoedown/hoedown/src/*.c
 
)
 
file(GLOB mx2cc_h 
  *.h
)
 
IF(PI)
 
include_directories( 
  /opt/vc/include
  /opt/vc/include/interface/vmcs_host/linux
  /opt/vc/include/interface/vcos/pthreads
)
 
ADD_EXECUTABLE( mx2cc_pi
  ${mx2cc_src}
  ${mx2cc_h}
)
target_link_libraries(mx2cc_pi rt pthread)
 
# find_library(EGL_LIB EGL /opt/vc/lib)
# find_library(GLES_LIB GLESv2 /opt/vc/lib)
# find_library(BCM_LIB bcm_host /opt/vc/lib)
# target_link_libraries(mx2cc_pi pthread asound ${EGL_LIB} ${GLES_LIB} ${BCM_LIB})
 
ENDIF(PI)
