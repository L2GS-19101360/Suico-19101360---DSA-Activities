#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char fName[20];
	char lName[20];
}studName;

typedef struct {
	int month;
	int year;
}bday;

typedef struct {
	studName name;
	bday birthdate; 
	int age;
	int idNum;
}studentInfo;

typedef struct {
	studentInfo studArray[20];
	int studCount;
}classRecord;

int insertMenu()
{
	int option;
	printf("\n[1] Insert At Front\n");
	printf("[2] Insert At Rear\n");
	printf("[3] Insert At Specific Location\n");
	printf("[4] Insert At Sorted by Age\n");
	printf("Enter Option: "); scanf("%d", &option);
	return option;
}

studentInfo createStudent()
{
	studentInfo newStudent;
	printf("\nEnter ID Number: "); scanf("%d", &newStudent.idNum);
	printf("Enter First Name: "); scanf("%s", &newStudent.name.fName); fflush(stdin);
	printf("Enter Last Name: "); scanf("%s", &newStudent.name.lName); fflush(stdin);
	printf("Enter Age: "); scanf("%d", &newStudent.age);
	printf("Enter Birth Month: "); scanf("%d", &newStudent.birthdate.month);
	printf("Enter Birth Year: "); scanf("%d", &newStudent.birthdate.year);
	return newStudent;
}

void deleteAtFront(classRecord *record)
{
	int x;
	if (record->studCount > 0) {
		for (x = 0; x < record->studCount - 1; x++) {
			record->studArray[x] = record->studArray[x + 1];
		}
		record->studCount--;
	} else {
		printf("Class Record is Empty!");
	}
}

void deleteAtEnd(classRecord *record)
{
	if (record->studCount > 0) {
		record->studCount--;
	} else {
		printf("Class Record is Empty!");
	}
}

void deleteAtLocation(classRecord *record)
{
	int x, position;
	if (record->studCount > 0) {
		printf("Enter Location: "); scanf("%d", &position);
		for (x = position; x < record->studCount - 1; x++) {
			record->studArray[x] = record->studArray[x + 1];
		}
		record->studCount--;
	} else {
		printf("Class Record is Empty!");
	}
}

int deleteMenu()
{
	int option;
	printf("\n[1] Delete At Front\n");
	printf("[2] Delete At Rear\n");
	printf("[3] Delete At Specific Location\n");
	printf("Enter Option: "); scanf("%d", &option);
	return option;
}
void deleteOption(classRecord *record)
{
	int loop = 1;
	while (loop) {
		switch(deleteMenu()) {
			case 1:
				deleteAtFront(record);
				break;
			case 2:
				deleteAtEnd(record);
				break;
			case 3:
				deleteAtLocation(record);
				break;
		}
		loop = 0;
	}
}

void insertAtFront(classRecord *record)
{
	int x;
	if (record->studCount < 20) {
		for (x = record->studCount; x >= 0; x--) {
			record->studArray[x] = record->studArray[x - 1];
		}
		record->studArray[0] = createStudent();
		record->studCount++;
	} else {
		printf("Class Record is Full!");
	}
}

void insertAtEnd(classRecord *record)
{
	if (record->studCount < 20) {
		record->studArray[record->studCount++] = createStudent();
	} else {
		printf("Class Record is Full!");
	}
}

void insertAtLocation(classRecord *record)
{
	int x, position;
	if (record->studCount < 20) {
		printf("Enter Location: "); scanf("%d", &position);
		for (x = record->studCount; x >= position; x--) {
			record->studArray[x] = record->studArray[x - 1];
		}
		record->studArray[position] = createStudent();
		record->studCount++;
	} else {
		printf("Class Record is Full!");
	}
}

void sortByAge(classRecord *record)
{
	int x, y;
	studentInfo temp;
	for (x = 0; x < record->studCount; x++) {
		for (y = 0; y < record->studCount; y++) {
			if (record->studArray[y].age > record->studArray[y + 1].age) {
				temp = record->studArray[y];
				record->studArray[y] = record->studArray[y + 1];
				record->studArray[y + 1] = temp;
			}
		}
	}
}

void insertAtSortedAge(classRecord *record)
{
	if (record->studCount < 20) {
		record->studArray[record->studCount++] = createStudent();
		sortByAge(record);
	} else {
		printf("Class Record is Full!");
	}
}

void insertOption(classRecord *record)
{
	int loop = 1;
	while (loop) {
		switch(insertMenu()) {
			case 1:
				insertAtFront(record);
				break;
			case 2:
				insertAtEnd(record);
				break;
			case 3:
				insertAtLocation(record);
				break;
			case 4:
				insertAtSortedAge(record);
				break;
		}
		loop = 0;
	}
}

int mainMenu()
{
	int option;
	printf("\n[1] Insert New Student\n");
	printf("[2] Delete Student\n");
	printf("[3] Exit\n");
	printf("Enter Option: "); scanf("%d", &option);
	return option;
}

void displayRecord(classRecord record)
{
	int x;
	
	printf("%-3s %-10s %-10s %-10s %-5s %-10s %-10s\n", " ", "ID Number", "First Name", "Last Name", "Age", "Month", "Year");
    printf("-----------------------------------------------------------\n");
    
    for(x = 0; x < record.studCount; x++) {
        printf("[%d] %-10d %-10s %-10s %-5d %-10d %-10d\n", x,
											                record.studArray[x].idNum,
											                record.studArray[x].name.fName,
											                record.studArray[x].name.lName,
											                record.studArray[x].age,
											                record.studArray[x].birthdate.month,
											                record.studArray[x].birthdate.year);
    }
}

void initArray(classRecord *record)
{
	record->studCount = 0;
	studentInfo students[] = {
		{{"Tom", "Cat"}, {1, 1998}, 21, 12345,},
		{{"Jerry", "Mouse"}, {2, 1999}, 22, 23456,},
		{{"Lorenz", "Suico"}, {3, 2000}, 23, 34567,}
	};
	int size = sizeof(students)/sizeof(students[0]), x;
	
	for (x = 0; x < size; x++) {
		record->studArray[record->studCount++] = students[x];
	}
}
