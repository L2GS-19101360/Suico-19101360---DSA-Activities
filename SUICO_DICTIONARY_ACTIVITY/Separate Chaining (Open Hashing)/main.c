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
	insertHashValue("Black", &od);
	displayOpenDictionary(od);
	printf("After Resizing Hash Table:\n");
	resizeOpenDictionary(&od);
	insertHashValue("White", &od);
	insertHashValue("Brown", &od);
	insertHashValue("Pink", &od);
	insertHashValue("Gray", &od);
	displayOpenDictionary(od);
	deleteHashValue("Green", &od);
	deleteHashValue("Blue", &od);
	displayOpenDictionary(od);
	printf("Member Red? %s\n", memberHashValue("Red", od) ? "True" : "False");
	printf("Member Blue? %s\n", memberHashValue("Blue", od) ? "True" : "False");
	printf("Member Cyan? %s\n", memberHashValue("Cyan", od) ? "True" : "False");
	return 0;
}
