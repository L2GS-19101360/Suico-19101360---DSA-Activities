#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "CloseDictionary.h"

bool memberHashValue(char string[], CLOSEDICT cd)
{
    unsigned int hashIndex = hashValue(string, cd);
    int x;
    for (x = 0; strcmp(cd.hashTable[hashIndex].string, EMPTY) != 0; hashIndex = (hashIndex + (x * x)) % cd.size, x++) {
        if (strcmp(cd.hashTable[hashIndex].string, string) == 0) {
            return true;
        }
        if (strcmp(cd.hashTable[hashIndex].string, EMPTY) == 0) {
            break;
        }
    }
    return false;
}
void deleteHashValue(char string[], CLOSEDICT *cd)
{
	unsigned int hashIndex = hashValue(string, *cd);
	int x;
	for (x = 0; strcmp(string, cd->hashTable[hashIndex].string) != 0; hashIndex = (hashIndex + (x*x))%cd->size, x++){}
	strcpy(cd->hashTable[hashIndex].string, DELETED);
	cd->count--;
}
void resizeCloseDictionary(CLOSEDICT *cd)
{
	int newSize = cd->size * 2, x;
	HASHTABLE *newHashTable = (HASHTABLE *)malloc(newSize * sizeof(HASHTABLE));
	if (newHashTable != NULL) {
		for (x = 0; x < newSize; x++) {
            strcpy(newHashTable[x].string, EMPTY);
        }

		for (x = 0; x < cd->size; x++) {
	        if (strcmp(cd->hashTable[x].string, EMPTY) != 0 && strcmp(cd->hashTable[x].string, DELETED) != 0) {
	            unsigned int hashIndex = hashValue(cd->hashTable[x].string, *cd);
	            int i;
	            for (i = 0; strcmp(newHashTable[hashIndex].string, EMPTY) != 0 && strcmp(newHashTable[hashIndex].string, DELETED) != 0; i++, hashIndex = (hashIndex + i * i) % newSize) {}
	            strcpy(newHashTable[hashIndex].string, cd->hashTable[x].string);
	        }
	    }
	
	    free(cd->hashTable);
	    cd->hashTable = newHashTable;
	    cd->size = newSize;
	}
}
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
    if (isOverThreshold(*cd)) {
        resizeCloseDictionary(cd);
    }
    unsigned int hashIndex = hashValue(string, *cd);
    int x;
    for (x = 0; strcmp(cd->hashTable[hashIndex].string, EMPTY) != 0 && strcmp(cd->hashTable[hashIndex].string, DELETED) != 0; x++, hashIndex = (hashIndex + x * x) % cd->size) {}
    strcpy(cd->hashTable[hashIndex].string, string);
    cd->count++;
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
