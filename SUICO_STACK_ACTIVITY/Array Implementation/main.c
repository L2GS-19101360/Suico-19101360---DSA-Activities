#include <stdio.h>
#include <stdlib.h>
#include "StackArray.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	StackArrayList stack;
	stack = createStack();
	stack_push(&stack, 1);
	stack_push(&stack, 2);
	stack_push(&stack, 3);
	stack_display(stack);
	stack_visualize(stack);
	return 0;
}
