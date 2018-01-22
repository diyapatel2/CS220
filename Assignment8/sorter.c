#include <stdio.h>
#include <stdlib.h>
#include "node.h"

/* modeled after https://ptspts.blogspot.com/2010/01/how-to-swap-two-nodes-in-doubly-linked.html*/
void swap(Node *n1, Node *n2){
	Node *t;
	t = n1->next;
	n1->next = n2->next;
	n2->next= t;

	if(n1->next != NULL){
		n1->next->prev = n1;
	}
	if(n2->next != NULL){
		n2->next->prev = n2;
	}

	t = n1->prev;
	n1->prev = n2->prev;
	n2->prev = t;

	if(n1->prev != NULL){
		n1->prev->next = n1;
	}
	if(n2->prev != NULL){
		n2->prev->next = n2;
	}
}

Node *sort_nodes(Node *head){
	Node *init = head; 
	Node *big, *follow, *hhead, *temp_head;
if((head != NULL) && (init != NULL)){
        follow = init->next; 
	big = init;	
	while(init->next)
	{
		if(big > follow){
		
		}
		if(big < follow){
			big = follow; 
		}
		big = follow->next; 
	}
	hhead = big; 
}
swap(init, big); 
int a; 
int iter = 1;
while(1)
{
	temp_head = hhead; 
	for(a = 0; a <iter; a++){
		temp_head = temp_head->next; 
	}
	iter++;
	if(temp_head != NULL){
		big = temp_head; 
		follow = temp_head->next; 
		while(follow != NULL)
		{
			if(big > follow){
			
			}
			if(big < follow){
				big = follow;
			}
			follow = follow->next; 
	
		}
	}
	else{
		break;
	
	}
	swap(temp_head, big);
}
	return hhead; 
}








