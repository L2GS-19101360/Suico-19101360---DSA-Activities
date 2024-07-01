#ifndef OPEN_HASHING_DICTIONARY
#define OPEN_HASHING_DICTIONARY
#include <stdbool.h>

typedef struct node {
	char string[10];
	struct node *next;
}NODE, *NODEPTR;

typedef struct {
	NODEPTR *hashTable;
	int count;
	int size;
	float threshold;
}OPENDICT;

void INITIALIZE(OPENDICT *od);
bool isOverThreshold(OPENDICT od);
void insertHashValue(char string[], OPENDICT *od);
unsigned int hashValue(char string[], OPENDICT od);
void displayOpenDictionary(OPENDICT od);

#endif
