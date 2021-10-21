SECTIONS
{
	. = 0x20008000;

	. = ALIGN(4);
	.text	:
	{
		start.o
		*(.text)
	}

	. = ALIGN(4);
	.rodata	:
	{
		*(.rodata)
	}

	. = ALIGN(4);
	.data	:
	{
		*(.data)
	}

	. = ALIGN(4);
	.bss	:
	{
		*(.bss)
	}
}
