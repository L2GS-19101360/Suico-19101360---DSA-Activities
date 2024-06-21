#ifndef FCFS_QUEUE
#define FCFS_QUEUE
#include <stdbool.h>

typedef struct {
	char processId;
	int arrivalTime;
	int burstTime;
	int executionTime;
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
ProcessData emptyProcess();

void populateFCFSQueue(FCFSQueue *fq);
void displayFCFSQueue(FCFSQueue fq);

bool EnqueueProcess(FCFSQueue *fq, ProcessData p);
ProcessData Front(FCFSQueue fq);
bool DequeueProcess(FCFSQueue *fq);
ProcessData Rear(FCFSQueue fq);

bool isEmpty(FCFSQueue fq);

#endif
