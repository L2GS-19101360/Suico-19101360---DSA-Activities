#include <stdio.h>
#include <stdlib.h>
#include "FCFSQueue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	FCFSQueue FQHead = createFCFS();
    populateFCFSQueue(&FQHead);
    displayFCFSQueue(FQHead);
	return 0;
}
