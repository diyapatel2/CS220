#include <stdio.h>
#include <pthread.h>


/*Each thread could get a different worker function or the same worker function could be used to multiple functions*/
void *global_var = NULL;
void *worker_function(void *payload){
	/*Thread's code goes here*/
	printf("In thread %d\n", (int) payload);
}
#define NUM_THREADS 3

int main(){
	pthread_t threads [NUM_THREADS];
	/*threads = malloc(NUM_THREADS *sizeof(pthread_t));*/
	int i; 

	/*Declare payload here*/
	void *payload;
for(i = 0; i <NUM_THREADS; i++){
	pthread_create(&threads[i], NULL, worker_function, (void *) payload);

}
printf("In main thread\n");

for(i = 0; i < NUM_THREADS; i++){
	pthread_join(threads[i], NULL);
}

printf("Exiting main thread\n");
pthread_exit(NULL);
return(0);
}
