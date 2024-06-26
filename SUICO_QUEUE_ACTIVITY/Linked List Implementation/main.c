#include <stdio.h>
#include <stdlib.h>
#include "QueueLinkedList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Queue queueList;
	queueList = createQueue();
	
	printf("Creating Queue:\n");
	Enqueue(&queueList, 59);
	Enqueue(&queueList, 46);
	Enqueue(&queueList, 54);
	Enqueue(&queueList, 13);
	Enqueue(&queueList, 90);
	visualizeQueue(queueList);
	displayQueue(queueList);
	
	printf("\n\nGetting All Even Numbers:\n");
	Queue evenQueueList;
	evenQueueList = getAllEvenNumbers(&queueList);
	visualizeQueue(evenQueueList);
	displayQueue(evenQueueList);
	
	return 0;
}
