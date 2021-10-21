.text
.global _start

_start:
	bl init_led

loop:
	B loop


