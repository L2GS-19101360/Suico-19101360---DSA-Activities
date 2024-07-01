#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "OpenDictionary.h"

void displayOpenDictionary(OPENDICT od)
{
    printf("Open Hashing Dictionary:\n");
    int x;
    NODEPTR current;
    for (x = 0; x < od.size; x++) {
        printf("[%d]: ", x);
        current = od.hashTable[x];
        for (current = od.hashTable[x]; current != NULL; current = current->next) {
        	printf("%s -> ", current->string);	
		}
        printf("\n");
    }
}
void insertHashValue(char string[], OPENDICT *od)
{
	unsigned int hashIndex;
	if (!isOverThreshold(*od)) {
		hashIndex = hashValue(string, *od);
		NODEPTR *trav = &(od->hashTable[hashIndex]), temp = (NODEPTR)malloc(sizeof(NODE));
		if (temp != NULL) {
			strcpy(temp->string, string);
			temp->next = NULL;
			for (trav = &(od->hashTable[hashIndex]); *trav != NULL && (strcmp(temp->string, (*trav)->string) > 0); trav = &(*trav)->next) {}
			temp->next = *trav;
			*trav = temp;	
			od->count++;
		}
	}
}
unsigned int hashValue(char string[], OPENDICT od)
{
	unsigned int hash = 0;
	int x;
	for (x = 0; x < strlen(string); x++) {
		hash = 31 + hash + string[x];
	}
	return hash%od.size;
}
bool isOverThreshold(OPENDICT od)
{
	return ((float)od.count/od.size > od.threshold);
}
void INITIALIZE(OPENDICT *od)
{
	od->size = 10;
	od->hashTable = malloc(sizeof(NODEPTR) * od->size);
	int x;
	if (od->hashTable != NULL) {
		for (x = 0; x < od->size; x++) {
			od->hashTable[x] = NULL;
		}
		od->threshold = 0.65;
		od->count = 0;
	}
}
