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
	printHashTable(cd);
	insertHashValue("Black", &cd);
	printHashTable(cd);
//	insertHashValue("White", &cd);
//	printHashTable(cd);
//	insertHashValue("Brown", &cd);
//	printHashTable(cd);
	return 0;
}
