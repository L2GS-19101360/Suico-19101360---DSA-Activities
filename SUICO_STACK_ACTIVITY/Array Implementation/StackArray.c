#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"

void initStack(StackArrayList *s)
{
	s->top = -1;
}
StackArrayList createStack()
{
	StackArrayList stack;
	initStack(&stack);
	return stack;
}
bool isFull(StackArrayList s)
{
	return (s.top == MAX - 1) ? true : false;
}
bool isEmpty(StackArrayList s)
{
	return (s.top == 0) ? true : false;
}
bool stack_push(StackArrayList *s, int elem)
{
	bool returnBool = true;
	if (!isFull(*s)){
		s->top++;
		s->data[s->top] = elem;
	} else {
		returnBool = false;
	}
	return returnBool;
}
bool stack_pop(StackArrayList *s)
{
	bool returnBool = true;
	if (!isEmpty(*s)){
		s->top--;
	} else {
		returnBool = false;
	}
	return returnBool;
}
int stack_peek(StackArrayList s)
{
	return s.data[s.top];
}

StackArrayList stack_getAllEvenNumbers(StackArrayList *s)
{
	StackArrayList returnStack;
	returnStack = createStack();
	do {
    	if (stack_peek(*s)%2 == 0) {
    		stack_push(&returnStack, stack_peek(*s));
		} 
	} while (stack_pop(s));
	return returnStack;
}

void stack_display(StackArrayList s)
{
    StackArrayList temp = createStack();

    do {
    	stack_push(&temp, stack_peek(s));
	} while (stack_pop(&s));
	
	printf("\nDisplay Stack:\n");
	do {
		printf("%d ", stack_peek(temp));
    	stack_push(&s, stack_peek(temp));
	} while (stack_pop(&temp));
}
void stack_visualize(StackArrayList s)
{
	printf("Stack Visualization");
	printf("\n%-7s %-7s %-5s\n", "Index", "Data", "Status");
    printf("=======================\n");
    
    int x;
    for (x = 0; x <= s.top; x++) {
        printf("%-7d %-7d %-5s\n", x, s.data[x], x == s.top ? "Top" : "");
    }
}
