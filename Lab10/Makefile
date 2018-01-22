all: prelim ret2libc

prelim: prelim.c 
	gcc prelim.c -std=c89 -m32 -g -o prelim
.PHONY: clean
	
ret2libc:
	gcc -std=c89 -m32 ret2libc.c get_ebp.S -g -o ret2libc


clean:
	rm prelim ret2libc

