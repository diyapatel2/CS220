/* hellosh.c */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
int main(){
	char line[1024];
	int pid, i, total_lines, d; 
	total_lines = d = 0; 
	char *tmp; 
	while(1){
		printf("Hello!!>");
		if(!fgets(line, 1023, stdin)){
			break;
		}
		if(strcmp(line, "exit\n") == 0) break;
		for(i = 0; i < strlen(line); i++){
			if(line[i] == '\n'){
				line[i] = '\0';
				total_lines++;
				break;
			
			}
			if(line[i] == ' '){
				total_lines++;
			}
			
		}
		int fill = total_lines + 1; 
		char *args[fill]; 
		tmp = strtok(line, " \t"); 
		for(d = 0; tmp != NULL; d++){
			args[d] = malloc(100); 
			strcpy(args[d], tmp); 
			tmp = strtok(NULL, " ");
		}
		
		args[d] = '\0';
		pid = fork(); 
		char input[100], output[100];
		int in, out; 
		in = out = 0;


		if(pid == 0){

			for(i = 0; args[i] != '\0'; i++){
				if(strcmp(args[i], "<") == 0){
					strcpy(input, args[i+1]);
					args[i] = '\0';
					in = 2; 
				}
				if(strcmp(args[i], ">") == 0){
					strcpy(output, args[i+1]);
					args[i] = '\0';
					out = 2; 
				
				}

			}
			int fd0, fd1; 
			if(in){
				fd0 = open(input, O_RDONLY, 0);
				dup2(fd0, STDIN_FILENO);
				close(fd0);
			}
			if(out){
				fd1 = creat(output, 0644);
				dup2(fd1, STDOUT_FILENO);
				close(fd1);
			
			}
			/*This is the child*/
			execvp(line, args); 
			fprintf(stderr, "Hello!!: %s\n", strerror(errno)); 
			exit(errno); 
		}else{
			/*This is the parent*/
			wait(NULL); 
			
		}
		for(i = 0; i < total_lines; i++){
			free(args[i]); 
		}

	
	}
	return 0; 
}
