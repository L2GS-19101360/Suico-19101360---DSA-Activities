#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "CloseDictionary.h"

void printHashTable(CLOSEDICT cd)
{
	int x;
	printf("Close Hashing Dictionary:\n");
    for (x = 0; x < cd.size; x++) {
    	printf("[%d]: %s\n", x, cd.hashTable[x].string);
	}
    printf("\n");
}
void insertHashValue(char string[], CLOSEDICT *cd)
{
	unsigned int hashIndex;
	int x;
	if (!isOverThreshold(*cd)) {
		hashIndex = hashValue(string, *cd);
		for (x = 0; strcmp(cd->hashTable[hashIndex].string, EMPTY) != 0 && strcmp(cd->hashTable[hashIndex].string, DELETED) != 0; x++, hashIndex = (hashValue(string, *cd) + (x*x))%cd->size) {}
		strcpy(cd->hashTable[hashIndex].string, string);
		cd->count++;
	}
}
unsigned int hashValue(char string[], CLOSEDICT cd)
{
	unsigned int hash = 0;
	int x;
	for (x = 0; x < strlen(string); x++) {
		hash = hash + 31 + string[x];
	}
	return hash%cd.size;
}
bool isOverThreshold(CLOSEDICT cd)
{
	return ((float)cd.count/cd.size > cd.threshold);
}
void INITIALIZE(CLOSEDICT *cd)
{
	cd->size = 10;
    cd->hashTable = (HASHTABLE *)malloc(cd->size * sizeof(HASHTABLE));
    int x;
	if (cd->hashTable != NULL) {
        for (x = 0; x < cd->size; x++) {
            strcpy(cd->hashTable[x].string, EMPTY);
        }
    }
    cd->threshold = 0.65;
    cd->count = 0;
}
