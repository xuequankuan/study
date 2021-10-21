.text
.code 32
.global _start

_start:
	ldr r0, =0x7F008820
	ldr r1, =0x1111
	str r1, [r0]

	ldr r0, =0x7F008824
	ldr r1, =0x0
	str r1, [r0]

loop:
	B loop


