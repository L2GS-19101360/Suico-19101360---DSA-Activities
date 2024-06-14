#ifndef STACK_LINKED_LIST
#define STACK_LINKED_LIST

#include <stdbool.h>

typedef struct node {
	int data;
	struct node *next;
}StackNode;

typedef struct stack {
    StackNode *top;
} *StackLinkedList;

void initStack(StackLinkedList *s);
StackLinkedList createStack();

bool stack_push(int elem, StackLinkedList *s);
bool stack_pop(StackLinkedList *s);
int stack_peek(StackLinkedList s);
bool isFull(StackLinkedList s);
bool isEmpty(StackLinkedList s);

void stack_display(StackLinkedList s);
void stack_visualize(StackLinkedList s);

//create a function that would get all even numbers and return as new stack removing from the old stack
StackLinkedList stack_getAllEvenNumbers(StackLinkedList *s);

#endif
