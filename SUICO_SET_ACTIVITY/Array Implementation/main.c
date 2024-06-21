#include <stdio.h>
#include <stdlib.h>
#include "SetArray.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char X = 'z';
	char Y = 109;
	
	SetArray setX = createSet();
	SetArray setY = createSet();
	
	populateSet(X, &setX);
	populateSet(Y, &setY);
	
	printf("Set X: "); visualizeSet(setX);
	printf("Set Y: "); visualizeSet(setY);
	
	SetArray uniSet = unionSet(setX, setY);
	SetArray intersectSet = intersectionSet(setX, setY);
	SetArray diffSetXY = differenceSet(setX, setY);
    SetArray diffSetYX = differenceSet(setY, setX);
	
	printf("Union Set: "); visualizeSet(uniSet);
	printf("Intersection Set: "); visualizeSet(intersectSet);
	printf("Difference Set (X-Y): "); visualizeSet(diffSetXY);
    printf("Difference Set (Y-X): "); visualizeSet(diffSetYX);   
    return 0;
}
