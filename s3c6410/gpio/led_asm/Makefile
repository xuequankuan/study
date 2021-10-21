led_on.bin:led_on.s
	arm-linux-gcc -c -o led_on.o led_on.s
	arm-linux-ld -Ttext 0x0C000000 led_on.o -o led_on.elf
	#arm-linux-ld -Ttext 0x50000000 led_on.o -o led_on.elf
	arm-linux-objcopy -O binary -S led_on.elf led_on.bin
clean:
	rm *.o *.elf *.bin
