#include <stdio.h>
#include <stdlib.h>
#include "bits.h"
int main(){
	unsigned int address = 0xf712c0d0;
	unsigned int page_offset = 0x1a3;
	unsigned int tlb_id = 0;
	unsigned int tlb_tag = 0x8400;


	printf("get_page_offset %u\n", get_page_offset(address));
	print_in_binary(get_page_offset(address));

	printf("get_tlb_id %u\n", get_tlb_id(address));
	print_in_binary(get_tlb_id(address));
	
	printf("get_tlb_tag %u\n", get_tlb_tag(address));
	print_in_binary(get_tlb_tag(address));

	printf("set_page_offset %u\n", set_page_offset(address,page_offset));
	print_in_binary(set_page_offset(address, page_offset));

	printf("set_tlb_id %u\n", set_tlb_id(address, tlb_id));
	print_in_binary(set_tlb_id(address, tlb_id));

	printf("set_tlb_tag %u\n", set_tlb_tag(address, tlb_tag));
	print_in_binary(set_tlb_tag(address, tlb_tag));
}
