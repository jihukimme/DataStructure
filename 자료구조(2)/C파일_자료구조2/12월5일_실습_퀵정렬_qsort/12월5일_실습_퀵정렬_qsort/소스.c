#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct student {
	int grade;
	char name[5];
}student;
//
int compare(const void* arg1, const void* arg2)
{
	/*if (*(double*)arg1 > *(double*)arg2) return 1;
	else if (*(double*)arg1 == *(double*)arg2) return 0;
	else return -1;*/

	/*if (((student*)arg1)->grade > ((student*)arg2)->grade) return 1;
	else if (((student*)arg1)->grade == ((student*)arg2)->grade) return 0;
	else return -1;*/

	if (*((student*)arg1)->name > *((student*)arg2)->name) return 1;
	else if (*((student*)arg1)->name == *((student*)arg2)->name) return 0;
	else return -1;
	
}
//
int main(void)
{
	int i;
	//double list[5] = { 2.1, 0.9, 1.6, 3.8, 1.2 };

	student list[10] = { {3, "Hong"}, {3, "John"}, {2, "Kim"}, {2, "Park"}, {1, "Doug"},
	{4, "Lee"}, {3, "Lee"}, {1, "Son"}, {4, "Do"}, {1, "Joo"} };

	qsort((void*)list, (size_t)10, sizeof(student), compare);
	
	for (i = 0; i < 10; i++) {
		printf("%d %s\n", list[i].grade, list[i].name);
	}

	return 0;
}