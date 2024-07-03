#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "OpenDictionary.h"

bool memberHashValue(char string[], OPENDICT od)
{
	bool retBool = false;
	unsigned int hashIndex = hashValue(string, od);
	NODEPTR trav = od.hashTable[hashIndex];
	for (; trav != NULL && (strcmp(string, trav->string) != 0); trav = trav->next){}
	if (trav != NULL) {
		retBool = true;
	}
	return retBool;
}
void deleteHashValue(char string[], OPENDICT *od)
{
	unsigned int hashIndex = hashValue(string, *od);
	NODEPTR *trav = &(od->hashTable[hashIndex]), temp;
	for (; *trav != NULL && (strcmp(string, (*trav)->string) != 0); trav = &(*trav)->next) {}
	temp = *trav;
	*trav = temp->next;
	free(temp);
	od->count--;
}
void resizeOpenDictionary(OPENDICT *od)
{
	int newSize = od->size * 2, x;
	NODEPTR *newHashTable = malloc(sizeof(NODEPTR) * newSize), *trav, nextNode;
	unsigned int newHashIndex;
	if (newHashTable != NULL) {
		for (x = 0; x < newSize; x++) {
	        newHashTable[x] = NULL;
	    }
	    
	    NODEPTR *oldHashTable = od->hashTable;
	    int oldSize = od->size;

	    od->hashTable = newHashTable;
	    od->size = newSize;
	
	    for (x = 0; x < oldSize; x++) {
	        NODEPTR current = oldHashTable[x];
	        while (current != NULL) {
	            NODEPTR nextNode = current->next;
	            unsigned int newHashIndex = hashValue(current->string, *od);
	
	            NODEPTR *trav = &(newHashTable[newHashIndex]);
	            for (; *trav != NULL && strcmp(current->string, (*trav)->string) > 0; trav = &(*trav)->next){}
	            
	            current->next = *trav;
	            *trav = current;
	
	            current = nextNode;
	        }
	    }
	
	    free(oldHashTable);
	}
}
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
    printf("\n");
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
			for (; *trav != NULL && (strcmp(temp->string, (*trav)->string) > 0); trav = &(*trav)->next) {}
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
