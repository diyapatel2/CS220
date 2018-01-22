//malloc_limits.c
<stdlib.h>

long long i = 0;

while(malloc(4096) != NULL){
	i++;

}
printf("%lld/n",i);
return 0; 
