#include "LinkedList-Functions.h"

int main(void)
{
	NodePtr head = NULL;
	studentInfo studentInfo[] = {
		{"Homer Simpson", 93017, 19},
		{"Peter Griffin", 84307, 20},
		{"Bob Jones", 29623, 22},
	};
	
	initLinkedList(&head);
	displayStudent(head);
	
	printf("\nInsert at End:\n");
	insertAtEnd(studentInfo[0], &head);
	displayStudent(head);

	printf("\nInsert at Front:\n");
	insertAtFront(studentInfo[1], &head);	
	displayStudent(head);
	
	printf("\nInsert at Specific Location at 2:\n");
	insertAtLocation(2, studentInfo[2], &head);	
	displayStudent(head);
	
	printf("\nDelete at End:\n");
	deleteAtEnd(&head);
	displayStudent(head);

	printf("\nDelete at Front:\n");
	deleteAtFront(&head);	
	displayStudent(head);
	
	printf("\nDelete at Specific Location at 1:\n");
	deleteAtLocation(1, &head);
	displayStudent(head);
	return 0;
}
