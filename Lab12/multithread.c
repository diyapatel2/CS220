#include <stdio.h>
#include <pthread.h>



char my_arr[1024];
#define NUM_THREADS 1
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER; 

void *parent_thread(void *args){

	int max_args;
	int i; 
	pthread_mutex_lock(&m);
	printf("Enter your inputs: \n");
	scanf("%s", &my_arr);
	pthread_mutex_unlock(&m);
	pthread_exit(NULL);
}

void *child_thread(void *args){
	pthread_mutex_lock(&m);
	printf("In child_thread %s", my_arr);
	pthread_mutex_unlock(&m);
	pthread_exit(NULL);
}

int main(){
	int i;
	pthread_t tid1, tid2; 

	pthread_create(&tid1, NULL, parent_thread, NULL);
	pthread_create(&tid2, NULL, child_thread, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_exit(NULL);
	return 0; 
}
