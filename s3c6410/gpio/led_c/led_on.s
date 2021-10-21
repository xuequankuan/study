# 1 "led_on.S"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "led_on.S"
.text
.global _start

_start:
 bl init_led

loop:
 B loop
