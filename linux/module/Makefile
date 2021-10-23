obj-m := hello.o

KERNELDIR = /usr/src/linux-headers-2.6.32-45-generic
default:
	$(MAKE) -C $(KERNELDIR) M=`pwd` modules 
