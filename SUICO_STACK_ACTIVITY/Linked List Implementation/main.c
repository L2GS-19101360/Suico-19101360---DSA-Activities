#include <stdio.h>
#include <stdlib.h>
#include "StackLinkedList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Stack stackList;
	stackList = createStack();
	
	stack_push(59, &stackList);
	stack_push(46, &stackList);
	stack_push(54, &stackList);
	stack_push(13, &stackList);
	stack_push(90, &stackList);
	
	stack_visualize(stackList);
	stack_display(stackList);
	
	printf("\n\nGetting All Even Numbers:\n");
	Stack evenStackList;
	evenStackList = stack_getAllEvenNumbers(&stackList);
	stack_visualize(evenStackList);
	stack_display(evenStackList);
	return 0;
}
