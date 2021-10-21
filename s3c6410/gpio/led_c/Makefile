led_on.bin:led_on.o
	#arm-linux-gcc -c -o led_on.o led_on.S
	arm-linux-gcc -c -o led_on_c.o led_on_c.c
	arm-linux-ld -Ttext 0x40000000 $^ led_on_c.o -o led_on.elf	#$^不repeat的
	arm-linux-objcopy -O binary -S led_on.elf led_on.bin
%.o:%.S
	arm-linux-gcc -c -o $@ $< 
clean:
	rm -f *.o *.elf *.bin
