#define GPMCON	*((volatile unsigned long *)0x7F008820)	
#define GPMDAT	*((volatile unsigned long *)0x7F008824)

int init_led()
{
	GPMCON = 0x1111;
	GPMDAT = 0x0c;

	return 0;
}
