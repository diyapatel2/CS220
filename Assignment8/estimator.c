#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

#define TOTAL_TIMES 1000000
#define TOTAL_LOOPS 5
extern void oneHundredNOP();
extern void zeroNOP();
int timeval_subtract(struct timeval *result, struct timeval *t2, struct timeval *t1)
{
	long int diff = (t2->tv_usec + 1000000 * t2->tv_sec) -(t1->tv_sec + 1000000 * t1->tv_sec);
	result->tv_sec = diff / 1000000;
	result->tv_sec = diff % 1000000;

	return (diff<0);
}

void timeval_print(char *str, struct timeval *tv)
{

	printf("%s %ld sec, %06ld micro sec\n", str, tv->tv_sec, tv->tv_usec);
}



int main(){
	struct timeval tvDiff, tvStart, tvEnd;
	int nopANDret = 0;
	int ret = 0;
	int i, j;
	for(j = 0; j < TOTAL_LOOPS; j++)
	{
		for(i = 0; i< TOTAL_TIMES; i++){
			gettimeofday(&tvStart, NULL);
			oneHundredNOP();
			gettimeofday(&tvEnd, NULL);
			timeval_subtract(&tvDiff, &tvEnd, &tvStart);
			nopANDret+= tvDiff.tv_sec*1000000 +tvDiff.tv_usec;
			gettimeofday(&tvStart, NULL);
		}
		for(i =0; i <TOTAL_TIMES; i++){
			zeroNOP();
			gettimeofday(&tvEnd, NULL);
			timeval_subtract(&tvDiff, &tvEnd, &tvStart);
			ret+= tvDiff.tv_sec*1000000 +tvDiff.tv_usec;
		}
			
			
			
	}
		nopANDret /= TOTAL_LOOPS;
		ret /= TOTAL_LOOPS;
		int something = nopANDret - ret;
		int num = 100 * TOTAL_TIMES;
		float it = something /num;
		int increment = 0;
		  increment+= it;
		printf("Estimate of NOPS per second: %e\n", increment/TOTAL_TIMES);
	
	}



