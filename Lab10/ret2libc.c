#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
extern uint32_t* get_ebp(void);

void ret2libc(int dummy)
{
	char *str = "/bin/bash";
	long *curr_ebp = get_ebp();
	curr_ebp[2] = curr_ebp[1];
	curr_ebp[1] = &system;
	curr_ebp[3] = str; 
	
}

void ret2libc_generic(char *cmd)
{
	long *curr_ebp = get_ebp();
	curr_ebp[3] = curr_ebp[2];
	curr_ebp[2] = curr_ebp[1];
	curr_ebp[1] = &system;

}

int main(){
/*	ret2libc(0);*/
	ret2libc_generic("ls");
	printf("Done!\n");
	return 0;

}
