#include <stdio.h>
#include <stdlib.h>
#include "bt.h"
#include <stdint.h>

extern unsigned int *getrbp();
extern int main(int, char*[]);
/*
	void baz(){
	print_backtrace(1);
	}
	void bar(){
	baz();
	}
	void foo(){
	bar();
	}

int main(int argc, char* argv[]){
	printf("%x\n", "main address", &main);
	printf("%x\n", "foo address", &foo);
	printf("%x\n", "bar address", &bar);
	printf("%x\n", "baz address", &baz);
	foo(); 
	return 0;
	}
*/
void print_backtrace(int count){

	uint64_t *curr_rbp;
	uint64_t *ret_address; 
	void *main_start = &main;


	/*printf("The address of main is: %p\n", main_start);*/


	uint64_t *main_end = (uint64_t *)main_start;
	
	while((*(unsigned char*)main_end) != 0xC3){
		main_end = (void*) ((char*)main_end+1); 
	}
	curr_rbp = (uint64_t *)getrbp();
	
int level = 1;
while(count > 0)
{
	
	ret_address = (uint64_t *) *(curr_rbp + 0x1);
	printf("#%d\t0x%016x\n", level, ret_address);
	
	
	if(ret_address > (uint64_t *) &main_start && ret_address <(uint64_t *) &main_end){
		return;
	}
	
	else{
	level++;
	curr_rbp = (uint64_t*) *curr_rbp;
	count--;
	}
}
}
