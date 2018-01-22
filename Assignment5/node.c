#include "node.h"
#include <stdio.h>

void printNode(Node *n){
	if(n != NULL){

		printf("Address of node n : %p\n", &n->ptr);
		printf("Value of n: %d\n", n->val);
		printf("Value of var: %p\n", &n->var);
		printf("Value of ptr: %p\n", &n->ptr);
	
	}
	else{
		printf("Null");
	}

} 


/*
Node *insert_into_list(Node *head, int n){
	Node *current; 
	current = (Node *) malloc(sizeof(current);
	current->n.val.c = n; 
	current->ptr = head;
	return current; 
}
*/

/*
Node *find_head(void *p){
	Node *temp; 
	int offset = (unsigned char *) &(temp.p) - (unsigned char *)&temp;
	if(ptr == NULL){
		return NULL;
	}
	return(Node *)((unsigned char *)ptr - offset);//contains head of node
}
*/

Node *my_reverse(Node *head){
	//reversing node	
//	Node* curr = (Node *) &(head->ptr);
	Node *curr = head->ptr;
	Node* prev = NULL;
	Node* next  = NULL;
	while(curr != NULL){
		next = curr->ptr;
		curr->ptr = prev;
		prev = curr;
		curr = next;
	}
//printNode(find_head(prev));
//return find_head(prev);
//printNode(find_head(prev));
printNode(prev);
return prev;
}
