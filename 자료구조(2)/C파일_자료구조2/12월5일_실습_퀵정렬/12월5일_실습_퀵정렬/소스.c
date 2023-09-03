#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 6
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int n;

typedef struct student {
	int grade;
	char name[10];
}student;

void swap(int a, int b, student list[]) {
	student tmp;
	tmp = list[a];
	list[a] = list[b];
	list[b] = tmp;
}

int partition(student list[], int left, int right)
{
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left].grade;
	do {
		do {
			low++;
		} while (list[low].grade < pivot);

		do {
			high--;
		} while (list[high].grade > pivot);

		if (low < high) {
			swap(low, high, list);
		}
	} while (low < high);

	swap(left, high, list);
	
	return high;
}

void quick_sort(int list[], int left, int right)
{
	if (left < right) {
		int q = partition(list, left, right);
		
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}

//
int main(void)
{
	int i;
	n = MAX_SIZE;
	//srand(time(NULL));
	//for (i = 0; i < n; i++)      	// 난수 생성 및 출력 
	//	list[i] = rand() % 100;

	//int list[MAX_SIZE] = { 5,7,4,9,8,5,6,3 };
	//int list[MAX_SIZE] = { 71,49,92,55,38,82,72,53 };
	//int list[MAX_SIZE] = { 2,3,3,1,2,1 };

	student list[6] = { {2, "Kim"}, {3, "Hong"}, {3, "John"},{1, "Lee"},{2, "Park"},{1, "Doug"} };
	quick_sort(list, 0, n - 1); // 퀵정렬 호출 
	/*for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");*/

	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d%s ", list[i].grade, list[i].name);
	}
	printf("\n");

	return 0;
}