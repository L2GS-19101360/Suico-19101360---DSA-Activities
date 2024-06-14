#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackLinkedList.h"

void initStack(StackLinkedList *s)
{
	(*s)->top = NULL;
}
StackLinkedList createStack()
{
	StackLinkedList stack = (StackLinkedList)malloc(sizeof(StackLinkedList));
	if (stack != NULL) {
		initStack(&stack);
	}
	return stack;
}

bool stack_push(int elem, StackLinkedList *s)
{
	StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
	bool retBool = false;
	if (temp != NULL) {
		temp->data = elem;
		temp->next = NULL;
		
		if ((*s)->top == NULL) {
			(*s)->top = temp;
		} else {
			temp->next = (*s)->top;
			(*s)->top = temp;
		}
		retBool = true;
	}
	return retBool;
}
bool isEmpty(StackLinkedList s)
{
	return ((*s).top == NULL) ? true : false;
}
bool stack_pop(StackLinkedList *s)
{
	StackLinkedList temp;
	bool retBool = true;
	if (!isEmpty(*s)) {
		temp = *s;
		(*s)->top = temp->top->next;
	} else {
		retBool = false;
	}
	return retBool;
}
int stack_peek(StackLinkedList s)
{
	return s->top->data;
}

void stack_display(StackLinkedList s)
{
	StackLinkedList tempStack = createStack();
	while (!isEmpty(s)){
        stack_push(stack_peek(s), &tempStack);
        stack_pop(&s);
	}
	
	printf("\nDisplay Stack:\n");
	while (!isEmpty(tempStack)){
		printf("%d ", stack_peek(tempStack));
        stack_push(stack_peek(tempStack), &s);
        stack_pop(&tempStack);
	}
}
void stack_visualize(StackLinkedList s)
{
	printf("Stack Visualization");
	printf("\n%-7s %-7s %-5s\n", "Index", "Data", "Status");
    printf("=======================\n");
    
    int x;
    StackNode *trav;
	for (x = 0, trav = s->top; trav != NULL; x++, trav = trav->next) {
    	printf("%-7d %-7d %-5s\n", x, trav->data, trav->next == NULL ? "Top" : "");
	}
}

//create a function that would get all even numbers and return as new stack removing from the old stack
StackLinkedList stack_getAllEvenNumbers(StackLinkedList *s)
{
	StackLinkedList returnStack = createStack();
	while (!isEmpty(*s)){
        if (stack_peek(*s)%2 == 0) {
        	stack_push(stack_peek(*s), &returnStack);
		}
        stack_pop(s);
	}
	return returnStack;
}
