#include "define.h"
#include <stdio.h>
int main(int argc, char const *argv[]) {

struct point a, b; 
scanf("%d %d", &a.x, &a.y);
scanf("%d %d", &b.x, &b.y);
printf("Distance between a and b %lf\n", distance(a,b));


 /* Testing second function */ 
 char test[] = "abcdedfabcde";
 char find[] = "abc";
 printf("Found the right index: %d\n", strrindex(test, find));
 
 int ret; 
 char ex[] = {"-2334"};
 ret = is_int(ex);
 printf("%d", ret); 


}
