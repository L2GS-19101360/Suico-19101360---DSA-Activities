#include <stdio.h>
#include <stdlib.h>
#include "CloseDictionary.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	CLOSEDICT cd;
	INITIALIZE(&cd);
	insertHashValue("Red", &cd);
	insertHashValue("Blue", &cd);
	insertHashValue("Yellow", &cd);
	insertHashValue("Orange", &cd);
	insertHashValue("Violet", &cd);
	insertHashValue("Green", &cd);
	insertHashValue("Black", &cd);
	printHashTable(cd);
	printf("After Resizing Hash Table:\n");
	resizeCloseDictionary(&cd);
	insertHashValue("White", &cd);
	insertHashValue("Brown", &cd);
	insertHashValue("Pink", &cd);
	insertHashValue("Gray", &cd);
	printHashTable(cd);
	deleteHashValue("Red", &cd);
	deleteHashValue("Blue", &cd);
	printHashTable(cd);
	printf("Member Yellow? %s\n", memberHashValue("Yellow", cd) ? "True" : "False");
	printf("Member Pink? %s\n", memberHashValue("Pink", cd) ? "True" : "False");
	printf("Member Cyan? %s\n", memberHashValue("Cyan", cd) ? "True" : "False");
	return 0;
}
