
TOOLS := /media/cuongd/Data/PetaLinux/tools/linux-i386/gcc-arm-linux-gnueabi/bin
#KERNEL_DIR:=/media/cuongd/Data/petalinux-ve/build/tmp/work/plnx_arm-xilinx-linux-gnueabi/linux-xlnx/4.9-xilinx-v2017.2+gitAUTOINC+5d029fdc25-r0/linux-plnx_arm-standard-build
#KERNEL_DIR := /lib/modules/$(shell uname -r)/build
#KERNEL_DIR := "/media/cuongd/Data/petalinux-ve/build/tmp/work-shared/plnx_arm/kernel-source"
KERNEL_DIR := "/lib/modules/$(shell uname -r)/build"
#export ARCH:=arm
#export CROSS_COMPILE:=${TOOLS}/arm-linux-gnueabihf-

EXTRA_CFLAGS := -I

INCLUDE_FILE := 					\
		uart_isp.h 					\
		uart_register.h


OBJECT_FILE := 						\
		uart_isp.o					\
		uart_register.o				\

obj-m += uart_isp.o

uart_isp-obj:= ${INCLUDE_FILE} ${OBJECT_FILE}

all:
	make -C ${KERNEL_DIR} M=${PWD} modules
clean:
	make -C ${KERNEL_DIR} M=${PWD} clean
