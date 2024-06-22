#include <stdio.h>
#include <stdlib.h>
#include "FCFSQueue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
    FCFSQueue FQHead = createFCFS();
    populateFCFS(&FQHead);
    fcfsScheduling(&FQHead);
	return 0;
}
