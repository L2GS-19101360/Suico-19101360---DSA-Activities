#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[20];
	int idNum;
	int age;
}studentInfo;

typedef struct node {
	studentInfo studentData;
	struct node *next;
}Node, *NodePtr;

void displayStudent(NodePtr headPtr)
{
	int x;
	printf("%-3s %-10s %-20s %-5s\n", " ", "ID Number", "Name", "Age");
    printf("---------------------------------------------------\n");
    for (x = 0; headPtr != NULL; headPtr = headPtr->next, x++) {
    	printf("[%d] %-10d %-20s %-5d\n", x, headPtr->studentData.idNum, headPtr->studentData.name, headPtr->studentData.age);
	}
}

void deleteAtFront(NodePtr *headPtr)
{
	NodePtr temp;
	if (headPtr != NULL) {
		temp = *headPtr;
		*headPtr = temp->next;
		free(temp);		
	} else {
		printf("Student List is Empty!");
	}
}

void deleteAtEnd(NodePtr *headPtr)
{
	NodePtr temp;
	if (headPtr != NULL) {
		for ( ; (*headPtr)->next != NULL; headPtr = &(*headPtr)->next) {}
		temp = *headPtr;
		*headPtr = NULL;
		free(temp);
	} else {
		printf("Student List is Empty!");
	}	
}

void deleteAtLocation(int position, NodePtr *headPtr)
{
	int x;
	NodePtr temp;
	if (headPtr != NULL) {
		for (x = 0; (*headPtr)->next != NULL && x != position; headPtr = &(*headPtr)->next, x++) {}
		temp = *headPtr;
		*headPtr = temp->next;
		free(temp);
	} else {
		printf("Student List is Empty!");
	}
}

void insertAtLocation(int position, studentInfo student, NodePtr *headPtr)
{
	int x;
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->studentData = student;
	temp->next = NULL;
	if (temp != NULL) {
		for (x = 0; *headPtr != NULL && x != position; headPtr = &(*headPtr)->next, x++) {}
		temp->next = *headPtr;
		*headPtr = temp;
	}
}

void insertAtFront(studentInfo student, NodePtr *headPtr)
{
	if (*headPtr != NULL) {
		Node *temp = (Node *)malloc(sizeof(Node));
		temp->studentData = student;
		temp->next = NULL;
		if (temp != NULL) {
			temp->next = *headPtr;
			*headPtr = temp;
		}
	}
}

void insertAtEnd(studentInfo student, NodePtr *headPtr)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->studentData = student;
	temp->next = NULL;
	if (temp != NULL) {
		for ( ; *headPtr != NULL; headPtr = &(*headPtr)->next) {}
		*headPtr = temp;
	}
}

void initLinkedList(NodePtr *headList)
{
	studentInfo students[] = {
		{"Tom Cat", 99312, 21},
		{"Jerry Mouse", 70859, 22},
		{"Lorenz Suico", 22022, 23},
	};
	int x, size = sizeof(students)/sizeof(students[0]);
	
	for (x = 0; x < size; x++) {
		insertAtEnd(students[x], headList);
	}
}
