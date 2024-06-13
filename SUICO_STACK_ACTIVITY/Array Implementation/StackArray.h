#ifndef STACK_ARRAY
#define STACK_ARRAY

#include <stdbool.h>

#define MAX 10

typedef struct {
	int data[MAX];
	int top;
}StackArrayList;

void initStack(StackArrayList *s);
StackArrayList createStack();

bool stack_push(StackArrayList *s, int elem);
bool stack_pop(StackArrayList *s);
int stack_peek(StackArrayList s);
bool isFull(StackArrayList s);
bool isEmpty(StackArrayList s);

void stack_display(StackArrayList s);
void stack_visualize(StackArrayList s);

//create a function that would get all even numbers and return as new stack removing from the old stack
StackArrayList stack_getAllEvenNumbers(StackArrayList *s);

#endif
