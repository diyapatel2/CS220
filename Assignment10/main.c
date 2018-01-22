#include <stdio.h>
#include <stdlib.h>
#include "macros.h"
#include "bt.h"

extern unsigned long rotate(unsigned long val, unsigned long num, unsigned long direction);
extern void print_backtrace(int count);


	void baz(){
		print_backtrace(4);
	}
	void bar(){
	baz();
	}
	void foo(){
	bar();
	}

int main(int argc, char* argv[]){
	printf("main address: 0x%016x\n", "main address", &main);
	printf("foo address: 0x%016x\n", "foo address", &foo);
	printf("bar address: 0x%016x\n", "bar address", &bar);
	printf("baz address: 0x%016x\n", "baz address", &baz);
	foo();  
	
 	unsigned long val = 0xDEADBEEFDEADBEEF;
	unsigned long num = 2; 
	unsigned long ret; 

	
	printf("\nTesting assembly function\n");
	val = 0xDEADBEEFDEADBEEF;
	num = 2; 
	ret = rotate(val, num, 1);
	printf("%lx\n", ret);

	val = 0xDEADBEEFDEADBEEF;
	num = 2; 
	ret = rotate(val, num, 0);
	printf("%lx\n", ret);

	val = 0xDEADBEEFDEADBEEF;
	num = 66; 
	ret = rotate(val, num, 1);
	printf("%lx\n", ret);


	val = 0X1;
	num = 1; 
	ret = rotate(val, num, 0);
	printf("%lx\n", ret);

	printf("\n");

	if(TEST_IF_ANY_SET(0XDEADBEEFDEADBEEF, 63, 0)){
		printf("%d\n", 1);	
	}
	else{
		printf("%d\n", 0);
	}

	if(TEST_IF_ALL_SET(0XDEADBEEFDEADBEEF, 63, 0)){
		printf("%d\n", 1);	
	}
	else{
		printf("%d\n", 0);
	}
	if(TEST_IF_ANY_SET(0XDEADBEEFDEADBEEF, 35, 32)){
		printf("%d\n", 1);		
	}
	else{
		printf("%d\n", 0);
	}

	if(TEST_IF_ALL_SET(0xDEADBEEFDEADBEEF, 35, 32)){
		printf("%d\n", 1);
	}
	else{
		printf("%d\n", 0);
	}

	
	if(TEST_IF_ANY_SET(0xDEADBEEFDEADBEEF, 7, 4)){
		printf("%d\n", 1);
	}
	else{
		printf("%d\n", 0);
	}

	if(TEST_IF_ALL_SET(0xDEADBEEFDEADBEEF, 7, 4)){
		printf("%d\n", 1);
	}
	else{
		printf("%d\n", 0);
	}
	
	
	return 0;


}

