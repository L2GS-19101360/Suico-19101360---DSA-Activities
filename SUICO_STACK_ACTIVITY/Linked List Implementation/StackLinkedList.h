#ifndef STACK_LINKED_LIST
#define STACK_LINKED_LIST

#include <stdbool.h>

typedef struct node {
	int data;
	struct node *next;
}Node, *NodePtr;

typedef struct stack {
    NodePtr top;
}Stack;

void initStack(Stack *s);
Stack createStack();

bool stack_push(int elem, Stack *s);
bool stack_pop(Stack *s);
int stack_peek(Stack s);
bool isFull(Stack s);
bool isEmpty(Stack s);

void stack_display(Stack s);
void stack_visualize(Stack s);

//create a function that would get all even numbers and return as new stack removing from the old stack
Stack stack_getAllEvenNumbers(Stack *s);

#endif
