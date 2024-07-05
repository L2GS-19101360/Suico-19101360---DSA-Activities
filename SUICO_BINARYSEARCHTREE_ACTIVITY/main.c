#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void)
{
	NodePtr BTS;
	INITIALIZEBST(&BTS);
	POPULATEBST(&BTS);
	
	printf("Preorder traversal:\n");
    DFSPREORDER(BTS);
    printf("\n\nInorder traversal:\n");
    DFSINORDER(BTS);
    printf("\n\nPostorder traversal:\n");
    DFSPOSTORDER(BTS);
	return 0;
}
