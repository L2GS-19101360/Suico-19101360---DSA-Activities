#include <stdio.h>
#include <stdlib.h>
#include "QueueArray.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	CircularArray queue = createQueue();
	Enqueue(&queue, 72);
	Enqueue(&queue, 14);
	Enqueue(&queue, 51);
	Enqueue(&queue, 89);
	Enqueue(&queue, 33);
	visualizeQueue(queue);
	displayQueue(queue);
	return 0;
}
