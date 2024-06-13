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
		printf("\nStack is Full!\n");
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
		printf("\nStack is Empty!\n");
		returnBool = false;
	}
	return returnBool;
}
int stack_peek(StackArrayList s)
{
	return s.data[s.top];
}

void stack_display(StackArrayList s)
{
	do {
		printf("%d ", stack_peek(s));
	} while (stack_pop(&s));
}
void stack_visualize(StackArrayList s)
{
	printf("\n%-7s %-7s %-5s\n", "Index", "Data", "Status");
	printf("=======================\n");
	
	
}
