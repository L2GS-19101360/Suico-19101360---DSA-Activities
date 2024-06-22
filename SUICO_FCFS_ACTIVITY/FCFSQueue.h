#ifndef FCFS_QUEUE
#define FCFS_QUEUE
#include <stdbool.h>

typedef struct {
	char processId;
	int arrivalTime;
	int burstTime;
}ProcessData;

typedef struct node {
	ProcessData process;
	struct node *next;
}ProcessNode, *ProcessNodePtr;

typedef struct {
	ProcessNodePtr front;
	ProcessNodePtr rear;
}FCFSQueue;

FCFSQueue createFCFS();
void initFCFS(FCFSQueue *fq);
void populateFCFS(FCFSQueue *fq);

void fcfsScheduling(FCFSQueue *fq);

bool EnqueueProcess(FCFSQueue *fq, ProcessData p);
ProcessNodePtr Front(FCFSQueue fq);
bool DequeueProcess(FCFSQueue *fq);
ProcessNodePtr Rear(FCFSQueue fq);

bool isEmpty(FCFSQueue fq);

#endif
