#include <stdio.h>
#include <unistd.h>

int main(){
	int x = 1;
	pid_t pid;
	pid = fork();
	if(pid == 0){
	x++;
	printf("In child\n");
	printf("child pid: %d\n", getpid());
	printf("parent pid: %d\n", getppid());
	printf("x = %x\n", x);
	}else{
	sleep(1);
	x--;
	printf("In parent\n");
	printf("Child pid: %d\n", getpid());
	printf("Parent pid: %d\n", getppid());
	printf("x = %x\n", x);
	}
	return(0);
}
