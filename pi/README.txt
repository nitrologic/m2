#Raspberry Pi Setup for Monkey2 Development


## Basic Checklist


* Expand Filesystem - yes
* Enable Camera - optional
* Advance Options - yes
 

## OpenCV Camera

To enable operation of the pi camera enable it with this command

    sudo raspi-config

Then after reboot check /dev/video0 is present, if no check the following

cat /etc/modules-load.d/modules.conf 

# /etc/modules: kernel modules to load at boot time.
#
# This file contains the names of kernel modules that should be loaded
# at boot time, one per line. Lines beginning with "#" are ignored.

bcm2835-v4l2
snd-bcm2835
i2c-dev
