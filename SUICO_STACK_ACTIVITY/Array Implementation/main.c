#include <stdio.h>
#include <stdlib.h>
#include "StackArray.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	StackArrayList stack;
	stack = createStack();
	stack_push(&stack, 59);
	stack_push(&stack, 46);
	stack_push(&stack, 54);
	stack_push(&stack, 13);
	stack_push(&stack, 90);
	stack_visualize(stack);
	stack_display(stack);
	
	printf("\n\nGetting All Even Numbers:\n");
	StackArrayList getEvenStack;
	getEvenStack = stack_getAllEvenNumbers(&stack);
	stack_visualize(getEvenStack);
	stack_display(getEvenStack);
	return 0;
}
