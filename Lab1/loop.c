#include <stdio.h>
#include <time.h>

void forLoop(unsigned int n) {
	unsigned int i;
	for(i = 0; i < n; i++)
		;
}

void whileLoop(unsigned int n) {
	while(n > 0)
		n--;
}

void doWhileLoop(unsigned int n) {
	do { n--; } while (n > 0);
}

int main()
{
	int i;

	/* the loop */
    	clock_t tic = clock();
	for(i = 0; i < 3; i++){
    	forLoop(1000000000);
	}

	clock_t toc = clock();	
    double total = (toc - tic);
    double Foriter = ((3000000000/total) *CLOCKS_PER_SEC);
   
    printf("Elapsed: %f\n Average Iterations %f seconds\n",Foriter, (double)((total/3)/CLOCKS_PER_SEC));



    tic = clock();
    for(i = 0;i < 3;i++){
    whileLoop(1000000000);
    }
    toc = clock();
    double total2 = (toc - tic);
    double whileiter = ((300000000/total2) * CLOCKS_PER_SEC);
    printf("Elapsed: %f\n Average Iterations %f seconds\n",whileiter, (double)((total2/3)/ CLOCKS_PER_SEC));

tic = clock();
for(i = 0; i < 3; i++){
doWhileLoop(1000000000);
}
toc = clock();
double total3 = (toc - tic);
double dowhileiter = ((3000000000/total3)* CLOCKS_PER_SEC);
printf("Elapsed: %f\n Average Iterations %f seconds\n",dowhileiter, (double)((total/3)/CLOCKS_PER_SEC));

    return 0;
}
