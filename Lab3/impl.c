#include <stdio.h>
#include <stdlib.h>
struct bad_struct{
	short s1;
	long l1;
	short s2; 
};
struct good_struct{
	short s1;
	short s2;
	long l1;
};
union unit{
	char c;
	int i;
	long l;
};

unsigned int foo(int x[]){
	return sizeof(x);


}
int main(){
	int x[10];
	int ret; 
	struct bad_struct bs;
	struct good_struct gs;
	union unit u;

	printf("size of u %d\n", sizeof(u));
	printf("address of u %p\n", &u);
	scanf("%lu", &u.l);

	printf("%d\n", (int) sizeof(u));
	printf("%c, %lu, %d, %s\n", u.c, u.l, u.i, &u.l);
	
	printf("size of array %d\n", sizeof(x));
	ret = foo(x);
	printf("printing foo size of array %d\n", ret);
}
