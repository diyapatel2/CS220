#include <stdio.h>
#include <stdlib.h>
#include "bits.h"
void print_in_binary(unsigned int x){
	int i; 
	for (i = 31; i >= 0; i--){
		if(IS_SET_ANY(x, BIT(i)))
		{
			printf("1");
		
		}else{
			printf("0");
		}
	
	}
	printf("\n");

}
unsigned int get_page_offset(unsigned int address){
	/*BITS 0 THROUGH 11*/
	return BF_GET(address, 11, 12);


}
unsigned int get_tlb_id(unsigned int address){
	/*BITS 12, 13, 14 */
	return BF_GET(address, 14, 3); /*???*/

}
unsigned int get_tlb_tag(unsigned int address){
	/*BITS 24 THROUGH 31*/
	return BF_GET(address, 31, 8);
}
unsigned int set_page_offset(unsigned int address, unsigned int new_offset){
	return (address, new_offset, 11, 12);

}
unsigned int set_tlb_id(unsigned int address, unsigned int new_tlb_id){
	return (address, new_tlb_id, 14, 3);
}
unsigned int set_tlb_tag(unsigned int address, unsigned int new_tag){
	return (address, new_tag,  31, 8);
}
