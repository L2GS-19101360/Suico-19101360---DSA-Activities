#ifndef SET_ARRAY
#define SET_ARRAY
#include <stdbool.h>

#define MAX 8

typedef struct {
	int binary[MAX];
	int data[MAX];
	int dataCount;
	int binaryCount;
}SetArray;

SetArray createSet();
void initSet(SetArray *set);
void populateSet(int value, SetArray *set);

SetArray unionSet(SetArray a, SetArray b);
SetArray intersectionSet(SetArray a, SetArray b);
SetArray differenceSet(SetArray a, SetArray b);

void addSetValue(SetArray *set, int value);
void deleteSetValue(SetArray *set);

void visualizeSet(SetArray set);

#endif
