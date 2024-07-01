#include <stdio.h>
#include <stdlib.h>
#include "OpenDictionary.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	OPENDICT od;
	INITIALIZE(&od);
	insertHashValue("Red", &od);
	insertHashValue("Blue", &od);
	insertHashValue("Yellow", &od);
	insertHashValue("Orange", &od);
	insertHashValue("Violet", &od);
	insertHashValue("Green", &od);
	printHashTable(od);
	return 0;
}
