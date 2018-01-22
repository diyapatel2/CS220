#include "define.h"
#include <stdlib.h>
#include <math.h>

float distance(struct point p1, struct p2){
	float ret;
	float first;
	float second;
		first = (p1.x - p2.x) * (p1.x - p2.x);
		second = (p1.y - p2.y) * (p1.y - p2.y); 
		ret = sqrt(first + second); 
	return ret; 
}




int strrindex(char s[], char t[]){
	int i, d, a, ret; 
	/* set to -1 in case there is no match */ 
	ret = -1; 
	for(i = 0; s[i] != '\0'; i++){
		d = i;
		a = 0; 
 	/* The inner loop finds if there is the rightmost occurance of t[] in s[], it continues untill the end of s[], when it's the end, it records the index and breaks out of the loop */		
	while(t[a] != '\0' && s[d] == t[a]){
		d++;
		a++;							
 	}				
	if(t[a] == '\0'){
		ret = i;
													}
													}
	return ret; 
}

int is_int(char str[]){
	int ret; 
	int i ;
	for(i = 0; str[i] != '\0'; i++){
		if(str[i] != '.'){
			ret = 1; 
											        	}
		else{
			ret = 0; 
			break;
		}	
	}
	return ret; 
}
