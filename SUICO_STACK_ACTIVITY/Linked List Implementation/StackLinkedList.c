#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackLinkedList.h"

void initStack(Stack *s)
{
	s->top = NULL;
}
Stack createStack()
{
	Stack createStack;
	initStack(&createStack);
	return createStack;
}

bool isEmpty(Stack s)
{
	return (s.top == NULL);
}

bool stack_push(int elem, Stack *s)
{
	bool retBool = false;
	Node *temp = (Node *)malloc(sizeof(Node));
	if (temp != NULL) {
		temp->data = elem;
		temp->next = NULL;
		
		if (s->top == NULL) {
			s->top = temp;
		} else {
			temp->next = s->top;
			s->top = temp;
		}
		retBool = true;
	}
	return retBool;
}
bool stack_pop(Stack *s)
{
	bool retBool = false;
	NodePtr temp;
	if (!isEmpty(*s)) {
		temp = s->top;
		s->top = temp->next;
		free(temp);
		retBool = true;
	}
	return retBool;
}
int stack_peek(Stack s)
{
	return s.top->data;
}

void stack_display(Stack s)
{
	Stack tempStack = createStack();
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
void stack_visualize(Stack s)
{
	printf("Stack Visualization");
	printf("\n%-7s %-7s %-5s\n", "Index", "Data", "Status");
    printf("=======================\n");
    
    int x;
    NodePtr trav;
	for (x = 0, trav = s.top; trav != NULL; x++, trav = trav->next) {
    	printf("%-7d %-7d %-5s\n", x, trav->data, trav->next == NULL ? "Top" : "");
	}
}

//create a function that would get all even numbers and return as new stack removing from the old stack
Stack stack_getAllEvenNumbers(Stack *s)
{
	Stack returnStack = createStack();
	while (!isEmpty(*s)){
        if (stack_peek(*s)%2 == 0) {
        	stack_push(stack_peek(*s), &returnStack);
		}
        stack_pop(s);
	}
	return returnStack;
}
