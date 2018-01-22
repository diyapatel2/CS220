#include "node.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
 struct _Node head, n2, n3, n4;
 
 head.val.n = 1; 
 head.ptr = &(head.ptr);
 printf("head.ptr: %p\n", head.ptr);
 n2.val.n =2;
 n2.ptr = &(n2.ptr);
 printf("n2.ptr: %p\n", n2.ptr);
 n3.val.n = 3;
 n3.ptr = &(n3.ptr);
 printf("n3.ptr: %p\n", n3.ptr);
 n4.val.n = 4;
 n4.ptr = NULL;
 printf("n4.ptr: %p\n", n4.ptr);
 printf("\n Now printing new addresses \n");
 

 //printNode(&head);
 my_reverse(&head);
 /*
 head.val.n = 1;
 n2.val.n = 2; 
 n3.val.n = 3;
 n4.val.n = NULL;
 insert_into_list(head,0);
 insert_into_list(n2,1);
 insert_into_list(n3,3);
 insert_into_list(n4,4);
 my_reverse(&head);
*/
  return 0;
}
