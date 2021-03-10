
#TOOLS:=/media/cuongd/Data/PetaLinux/tools/linux-i386/gcc-arm-none-eabi/bin
#KERNEL_DIR:=/media/cuongd/Data/petalinux-ve/build/tmp/work-shared/plnx_arm/kernel-source
#PWD:=$(shell pwd)

#export ARCH:=arm
#export CROSS_COMPILE:=$(TOOLS)/arm-linux-gnueabihf-gcc



#CROSS:=/media/cuongd/Data/PetaLinux/tools/linux-i386/gcc-arm-none-eabi/bin/arm-linux-gnueabihf-gcc
#KERNEL_DIR:=/media/cuongd/Data/petalinux-ve/build/tmp/work-shared/plnx_arm/kernel-source
PWD:=$(shell pwd)
all:
    make ARCH=arm CROSS_COMPILE=${CROSS} -C ${KERNEL_DIR} SUBDIRS=${PWD} modules
clean:
    make -C ${KERNEL_DIR} SUBDIRS=${PWD} clean



#CC=$(CROSS_COMPILE)gcc     #append string in make