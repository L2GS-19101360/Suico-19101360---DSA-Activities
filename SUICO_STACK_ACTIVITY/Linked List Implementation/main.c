#include <stdio.h>
#include <stdlib.h>
#include "StackLinkedList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	StackLinkedList headPtr = NULL;
	headPtr = createStack();
	
	stack_push(59, &headPtr);
	stack_push(46, &headPtr);
	stack_push(54, &headPtr);
	stack_push(13, &headPtr);
	stack_push(90, &headPtr);
	
	stack_visualize(headPtr);
	stack_display(headPtr);
	
	printf("\n\nGetting All Even Numbers:\n");
	StackLinkedList evenStackList;
	evenStackList = stack_getAllEvenNumbers(&headPtr);
	stack_visualize(evenStackList);
	stack_display(evenStackList);
	return 0;
}
