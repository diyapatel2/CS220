#include <stdio.h>
#include "functions.h"
#include <assert.h>
int main(int argc, char const *argv[]) {
  void *payload = "/0000";
  int ret; 
  ret = cryptic_calculator(payload);
  printf("%d\n", ret);


  char x[10]= "Hello";
  char y[10]= "World";

   swap_strs(x, y);
   printf("str1 is %s, str2 is %s", x, y);

   return 0;
}
