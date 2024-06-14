#include "Array-Functions.h"

int main(void)
{
	classRecord Record;
	initArray(&Record);
	int loop = 1;
	while (loop) {
		displayRecord(Record);
		switch(mainMenu()) {
			case 1:
				insertOption(&Record);
				break;
			case 2:
				deleteOption(&Record);
				break;
			case 3:
				loop = 0;
				break;
		}
	}
	return 0;
}
