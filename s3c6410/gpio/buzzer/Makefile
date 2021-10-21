buzzer.bin:start.o buzzer.o
	#arm-linux-gcc -c -o led_on.o led_on.S
	#arm-linux-gcc -c -o led_on_c.o led_on_c.c
	arm-linux-ld -Ttext 0x40000000 $^ -o buzzer.elf	
	arm-linux-objcopy -O binary -S buzzer.elf $@
%.o:%.s
	arm-linux-gcc -c -o $@ $< 
%.o:%.c
	arm-linux-gcc -c -o $@ $< 
clean:
	rm -f *.o *.elf *.bin
