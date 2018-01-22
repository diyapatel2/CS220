// main.c

#include "functions.h"
#include <stdio.h> 
#include "functions.c"
int main(int argc, char **argv) {

  // TODO: Add your tests here
 
/*Testing first function*/
int ret;
unsigned long i = 2; 
unsigned long d = 8;
printf("Value of i is 2:  %lu, expected return in 4: ", i);
ret = isFib(i);
printf("Actual return is %d.\n ", ret);
printf("Value of i is 8:  %lu, expected return is 7: ", d);
ret = isFib(d); 
printf("Actual return value is %d.\n ", ret); 

/* Testing second function*/
unsigned int num = 5768209;
unsigned int out; 
printf("The value of num is %d : ", num);
out = count_vowels(num);
printf("The expected return is 15, the actual output is %d : \n", out);

/* Testing third function */
printf("\n\n Now testing count_ones function...." ); 
unsigned int y; 
unsigned long a = 25; 
unsigned long b = -20; 

printf("Value of n1(25) in decimal is %lu : ", a);
y = count_ones(a);
printf("Expected return of n1 is 3. Actual return is %lu.\n", y);
printf("Value of n2(-20) in decimal is %lu : ", b);
y = count_ones(b); 
printf("Expected return of n1 is 61. Actual return is %lu.\n", y);

/*Now testing Fourth Function*/
unsigned long n = *(unsigned long*) "12345678deadbeef"; 
unsigned long ans;
printf("The value of n is %I64x", n);
ans = swap_bytes(n);
printf("The ans is : %I64x", ans);

/*Now testing Fifth function*/
printf("\n\n Now testing a4_minus_b4 function...." );
int c = 8; 
int e = 5;
long r; 
printf("Value of a is %d and value of b is %d ", c, e);
r = a4_minus_b4(c,e);
printf("Expected return is 3471; Actual return is %li:\n ", r);
  return 0;

 
}
