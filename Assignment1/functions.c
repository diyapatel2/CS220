 /* 
 * Author: Diya Patel
 * Professor Prakash (CS220)
 * 09/10/2017
 */


#include "functions.h"
#include <stdio.h>
#include <math.h>
int isFib(unsigned long i) { 
unsigned long first, second, next; 
int var; 
var = 2; 
first = 1; 
second = 1; 
if(i ==0){
	return 1;
}
if(i == 1){
	return 2; 
}
while(second <= i){ 
	var++;
	if(second == i){
		return var; 
	}
	next = second;
        second = second + first;	
	first = next; 
}
 return -1; 
}

unsigned int count_vowels(unsigned long num) {
/* vowels == a, e, i, o, u, y */
int range;
int prevvalue; 
int count;
unsigned int vowels; 
int digits[sizeof(num)];
int i;
int digitcount;
range = 1000000000;

if(num < 0 || num > range){
return 0;
}

i = 0;
vowels = 0; 
digitcount = 1; 

while(num > 0){
digits[i]= num % 10;
if(digits[i] <= '9' && digitcount == 1){
	if((digits[i] == '2') || (digits[i] == '6')){
		vowels = vowels + 1;
	}
	if(digits[i] == '0'){
		vowels = vowels + 0; 
	}
	if((digits[i] == '1') || (digits[i] == '3') || (digits[i] == '4') || (digits[i] == '5') || (digits[i] == '7') || (digits[i] == '8') || (digits[i] == '9')		){
		vowels = vowels + 2; 
	}
}
if(digits[i] <= '9' && digitcount == 2){
	if((digits[i] == '2') || (digits[i] == '3') || (digits[i] == '4') || (digits[i] == '5') || (digits[i] == '6')){
		vowels = vowels + 1; 

	}
	if(digits[i] == '1'){
		vowels = 0;
		if(prevvalue == '0'){
			vowels = vowels + 1;
		}
		if(prevvalue == '2'){
			vowels = vowels + 2; 
		}
		if((prevvalue == '1') || (prevvalue == '3') || (prevvalue == '5') || (prevvalue == '6')){
			vowels = vowels + 3;
		}
		if((prevvalue == '4') || (prevvalue == '7') || (prevvalue == '8') || (prevvalue == '9')){
			vowels = vowels + 4; 
		}
	}
	if(digits[i] == '0'){
		vowels = vowels + 0; 
	}
	if((digits[i] == '7') || (digits[i] == '8') || (digits[i] == '9')){
		vowels = vowels + 2; 
	}
}	
if(digits[i] <= '9' && digitcount == 3){
	if((digits[i] == '2') || (digits[i] == '6')){
		vowels = vowels + 3;
	}
	if(digits[i] == '0'){
		vowels = vowels + 0;
	}
	if((digits[i] == '1') || (digits[i] == '3') || (digits[i] == '4') || (digits[i] == '5') || (digits[i] == '7') || (digits[i] == '8') || (digits[i] == '9')){
		vowels = vowels + 4; 
	}
}
if(digits[i] <= '9' && digitcount == 4){
	if((digits[i] == '2') || (digits[i] == '6')){
		vowels = vowels + 4;
	}
	if(digits[i] == '0'){
		vowels = vowels + 3; 
	}
	if((digits[i] = '1') || (digits[i] == '3') || (digits[i] == '4') || (digits[i] == '5') || (digits[i] == '7') || (digits[i] == '8') || (digits[i] == '9'))
	{
		vowels = vowels + 5; 
	
	}
}
if(digits[i] <= '9' && digitcount == 5){
	if((digits[i] == '2') || (digits[i] == '3') || (digits[i] == '4') || (digits[i] == '5') || (digits[i] == '6')){
		vowels = vowels + 4;
	}
	if(digits[i] == '1'){
		if((prevvalue == '0') || (prevvalue == '2') || (prevvalue == '1') || (prevvalue == '3') || (prevvalue == '5')) 
		{
			vowels = vowels + 1;
		}
		else{
			vowels = vowels + 2; 
		}
	}
	if(digits[i] == '0'){
		vowels = vowels + 0; 
	}
	else{
		vowels = vowels + 5; 
	}
}
if(digits[i] <= '9' && digitcount == 6){
	if((digits[i] == '2') || (digits[i] == '6')){
		vowels = vowels + 3; 		
	}
	if(digits[i] == '0'){
		vowels = vowels + 0; 
	}
	else{
		vowels + vowels + 4; 
	}
}
if(digits[i] <= '9' && digitcount == 7){
	if((digits[i] == '2') || (digits[i] == '6')){
		vowels = vowels + 4;
	}
	if(digits[i] == '0'){
		vowels = vowels + 3; 
	}
	else{
		vowels = vowels + 5;
	}
		
}
if(digits[i] >= '2' && digitcount == 8){
	if((digits[i] == '2') || (digits[i] == '3') || (digits[i] == '4') || (digits[i] == '5') || (digits[i] == '6')){
		vowels = vowels + 1;
	}
	else if(digits[i] == '1'){
		if((prevvalue == '0') || (prevvalue == '1') || (prevvalue == '2') || (prevvalue == '3') || (prevvalue == '5')){
			vowels = vowels + 1; 
		}
		else{
			vowels = vowels + 2; 
		}
	}
	else{
		vowels = vowels + 2; 
	}
}
if(digits[i] <= '9' && digitcount == 9){
	if((digits[i] == '2') || (digits[i] == '6')){
		vowels = vowels + 3; 
	}
	else{
		vowels = vowels + 4;
	}
		
} 
if(digits[i] == '1' && digitcount == 10){
	vowels = vowels + 5;
}
prevvalue = digits[i]; 
i++;
digitcount++;
num/=10;
}
return vowels; 
}

unsigned int count_ones(long n) {
  // TODO: Add your function declaration here
  unsigned int count;
  unsigned int remain; 
  int i;
  int flag = 0; 
  int neg;
  remain = count = neg = 0;
  i = 63;
  long binary[64] = {0};

 if(n == 0){
 	return 0;
 }
 if(n < 0){
	 /* if its negative it will be 1 */
	 neg = 1; 
	 n = n * -1; 
 }
 
 /* Converts into binary and puts it into an array */
while(n != 0){
	 remain = n%2;
	 n = n/2;
	 binary[i] = remain;
	 i--;
	
}
 /* Add one and Flip the bits if the number is negative */
if(neg == 1){
	for(i = 63; i >= 0; i--){
		if((binary[i] == 1) && (flag == 0)){
			flag = 1; 
			binary[i] == 1; 
		}
		else if((binary[i] == 1) && (flag == 1)){
			binary[i] = 0;
		
		}
		else if((binary[i] == 0) && (flag == 0)){
			binary[i] = 0; 
		
		}
		else if(binary[i] == 0 && (flag == 1)){
			binary[i] = 1; 

		}
	}	
}
/* Finally, count the number of ones */ 
for(i = 0; i < 64; i++){
	if(binary[i] == 1){
		count++;
	}
}
return count; 
}

unsigned long swap_bytes(unsigned long n) {
  // TODO: Add your function declaration here
  //
  //
 
n =  ((n & 0xff00ff00ff00ff00ull)>>8ull)
	    | ((n & 0x00ff00ff00ff00ffull)<<8ull);
	    return n;
}

long a4_minus_b4(int a, int b) {
  // TODO: Add your function declaration here
   int i;
   long temp_a, temp_b; 
   temp_a = 1;
   temp_b = 1; 
   if(a < 0){
   	a = a * -1;
   }
   if(b < 0){
   	b = b * -1;
   }
   for(i = 1; i <= 4; i++){
   	temp_a = a*temp_a;
	temp_b = b*temp_b; 
   }
	return temp_a - temp_b; 

}
