#include <stdio.h>
#include <stdlib.h>
#include "toggle.h"

void print_in_binary(unsigned int x){
	int i;
	for(i = 31; i >= 0; i--){
		if(IS_SET_ANY(x, BIT(i)))
		{
			printf("1");
		
		}else{
			printf("0");
		}
	}
	printf("\n");
	}
int toggle(int x, int b){
	return (x ^ (1 << b));
}

int main(){
	unsigned long x = toggle_bit(5,0);
	print_in_binary(x);
	printf("using the toggle check function\n");
	int a = toggle(5,0);
	print_in_binary(a);
	x = toggle_bit(5, 2);
	print_in_binary(x);
	printf("using the toggle check function\n");
	a = toggle(5,2);
	print_in_binary(a);
	x = toggle_bit(24, 3);
	print_in_binary(x);
	printf("using the toggle check function\n");
	a = toggle(24,3);
	print_in_binary(a);
	x = toggle_bit(64, 5);
	print_in_binary(x);
	printf("using the toggle check function\n");
	a = toggle(64,5);
	print_in_binary(a);
	x = toggle_bit(30, 4);
	print_in_binary(x);
	printf("using the toggle check function\n");
	a = toggle(30,4);
	print_in_binary(a);


}
