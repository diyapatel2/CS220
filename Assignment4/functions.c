#include "functions.h"
int cryptic_calculator(void *payload){
/*creating struct with variables of type short in */
typedef struct{
	short int Byte1;
	short int Byte3;
	short int Byte5;
	short int Byte7;
}foo;
/*casting payload to struct*/
foo f[4];
f[0].Byte1 = (*(short int*)&payload);
f[1].Byte3 = (*(short int*)&payload+2);
f[2].Byte5 = (*(short int*)&payload +4);
f[3].Byte7 = (*(short int*)&payload+6);
/*going through the bytes: if first char is * then multiplication of byte1, byte5 and byte7 is return. If first char is / and byte3 is not 0, then the quotient of byte3 divided by byte5 is returned, else 0xBAD is returned. */
if(f[0].Byte1 == '*'){
	return f[1].Byte3 *f[2].Byte5 *f[3].Byte7;

}
else if(f[0].Byte1 == '/'){
	if(f[1].Byte3 == 0){
		return 0xBAD;
	}
	else{
		return f[2].Byte5/f[1].Byte3;
	}

}
return 0xBAD;
}
void my_memcpy(void *dst, void *src, unsigned int num_bytes){
/*Casting the addresses of dst/src to char*  */
  char *s = (char *) src;
  char *d = (char *) dst;

  /*loop to copy over from src to dst, one int at a time */
  int i;
  for(i = 0; i <num_bytes; i++){
  	d[i] = s[i];
  }
}

void swap_strs(char *s1, char *s2){
 /*defining variables */
  int length_of_str;
  length_of_str = 0;
  int i,j;
  char *temp;
  /*if char *s1, is not empty then save its value in corresponding temp index and end temp with end of characters */
  i = 0;
  while(s1[i] != '\0'){
  	temp[i] = s1[i];
	i++;
  }
  temp[i] = '\0';
/*if char *s2 is not empty then save it in the corresponding s1 index, and end s1 with end of characters */
  i =0; 
  while(s2[i] != '\0'){
  	s1[i] = s2[i];
	i++;
  }
  s1[i] = '\0';
  /*if temp is not empty then store its value into the corresponding index in s2 and end s2 with end of characters */
  i = 0;
  while(temp[i] != '\0'){
  	s2[i] = temp[i];
  	i++;
  }
  s2[i] = '\0';
}
