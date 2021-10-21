CROSS_COMPILE 	:= 	/opt/arm/4.3.2/bin/arm-linux-
CC 	     	:= 	$(CROSS_COMPILE)gcc
LD 		:= 	$(CROSS_COMPILE)ld
OBJCOPY 	:= 	$(CROSS_COMPILE)objcopy

CFLAGS		+=	-Wall 
LDFLAGS		+=	-Tmaps.lds

ENV		?= 	RAM

ifeq ($(ENV), RAM)
LDFLAGS		+=	-Ttext=0x20000000
else
#LDFLAGS		+=	-Ttext=0x0
endif


TARGET		:=	led.bin
BUILD		:=	led

COBJS		+=	main.o	
COBJS		+= 	start.o

#SD_TOOLS	:= 	mk210

all:$(TARGET)
$(TARGET):$(BUILD)
ifeq ($(ENV), RAM)
	$(OBJCOPY) -O binary $^ $@
else
	$(OBJCOPY) -O binary $^ $@
	#$(SD_TOOLS) $@.tmp $@
endif

$(BUILD):$(COBJS)
	$(LD) $(LDFLAGS) -o $@  $^

%.o:%.c
	$(CC) $(CFLAGS)	-c -o $@ $^
%.o:%.S
	$(CC) $(CFLAGS)	-c -o $@ $^
	

clean:
	rm -f *.o *.tmp $(TARGET) $(BUILD)
