#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SetArray.h"

SetArray createSet() {
    SetArray set;
    initSet(&set);
    return set;
}

void initSet(SetArray *set) {
    set->dataCount = 0;
    set->binaryCount = MAX;
    int x;
    for (x = 0; x < MAX; x++) {
        set->binary[x] = 0;
    }
}

void populateSet(int value, SetArray *set) {
    int maskValue, x;
    for (maskValue = 7; maskValue >= 0; maskValue--) {
        if ((value >> maskValue) & 1) {
            set->binary[7 - maskValue] = 1;
        } else {
            set->binary[7 - maskValue] = 0;
        }
    }
    for (x = 0; x < MAX; x++) {
        if (set->binary[x] == 1) {
            addSetValue(set, x);
        }
    }
}

void addSetValue(SetArray *set, int value) {
    set->data[set->dataCount++] = value;
}

void deleteSetValue(SetArray *set) {
    if (set->dataCount > 0) {
        set->dataCount--;
    }
}

void visualizeSet(SetArray set) {
	int x;
    for (x = 0; x < set.dataCount; x++) {
        printf("%d ", set.data[x]);
    }
    printf("\n");
}

SetArray unionSet(SetArray a, SetArray b) {
    SetArray set = createSet();
    int x;
    for (x = 0; x < MAX; x++) {
        set.binary[x] = a.binary[x] | b.binary[x];
    }
    for (x = 0; x < MAX; x++) {
        if (set.binary[x] == 1) {
            addSetValue(&set, x);
        }
    }
    return set;
}

SetArray intersectionSet(SetArray a, SetArray b) {
    SetArray set = createSet();
    int x;
	for (x = 0; x < MAX; x++) {
        set.binary[x] = a.binary[x] & b.binary[x];
    }
    for (x = 0; x < MAX; x++) {
        if (set.binary[x] == 1) {
            addSetValue(&set, x);
        }
    }
    return set;
}

SetArray differenceSet(SetArray a, SetArray b) {
    SetArray set = createSet();
    int x;
	for (x = 0; x < MAX; x++) {
        set.binary[x] = a.binary[x] & ~b.binary[x];
    }
    for (x = 0; x < MAX; x++) {
        if (set.binary[x] == 1) {
            addSetValue(&set, x);
        }
    }
    return set;
}
