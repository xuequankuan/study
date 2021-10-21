#define GPNCON	*((volatile unsigned long *)0x7F008830)	
#define GPNDAT	*((volatile unsigned long *)0x7F008834)

#define GPFCON	*((volatile unsigned long *)0x7F0080A0)	
#define GPFDAT	*((volatile unsigned long *)0x7F0080A4)

void buzzer_on()
{
	GPFCON = 0x40000000;
	GPFDAT |= (1 << 15);

	return ;
}

void buzzer_off()
{
	GPFCON = 0x40000000;
	GPFDAT &= ~(1 << 15);

	return ;
}

void delay(int count)
{
	while(count--);
}

int main()
{
	GPNCON = 0x00000000;

	while(1)
	{
#if 0
		buzzer_on();
		delay(5000000);
		buzzer_off();
		delay(5000000);
#endif
		if(GPNDAT & 0x1)
		{
			buzzer_off();
		}
		else
		{
			buzzer_on();
		}
	}

	return 0;
}






