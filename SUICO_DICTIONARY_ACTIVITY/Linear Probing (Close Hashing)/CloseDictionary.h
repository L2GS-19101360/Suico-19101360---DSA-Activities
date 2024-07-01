#ifndef CLOSE_HASHING_DICTIONARY
#define CLOSE_HASHING_DICTIONARY
#include <stdbool.h>

#define EMPTY ""
#define DELETED "DELETED"

typedef struct {
	char string[10];
}HASHTABLE;

typedef struct {
	HASHTABLE *hashTable;
	int size;
	int count;
	float threshold;
}CLOSEDICT;

void INITIALIZE(CLOSEDICT *cd);
bool isOverThreshold(CLOSEDICT cd);
void insertHashValue(char string[], CLOSEDICT *cd);
unsigned int hashValue(char string[], CLOSEDICT cd);
void printHashTable(CLOSEDICT cd);

#endif
