#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

typedef struct LIST{
	int weight;
	int height;
}LIST;


void swap(LIST* x, LIST* y) {
	LIST temp = *x;
	*x = *y;
	*y = temp;
}


/*
void swap(int x, int y, LIST list[]) {
	LIST temp;
	temp = list[x];
	list[x] = list[y];
	list[y] = temp;
}



void selection_sort(LIST *list, int n){
	int i, j;

	int least;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) {	
			//올림차순으로 설정
			if (list[j].height < list[least].height)
				least = j;
			
		}
		swap(i , least, list);
	}
}
*/

void selection_sort(LIST* list, int n) {
	int i, j;

	int least;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) {
			//올림차순으로 설정
			if (list[j].height < list[least].height)
				least = j;

		}
		swap(&list[i],list+least);
	}
}

int main(void){
	int i;
	int n = MAX_SIZE;
	
	LIST list[MAX_SIZE] = { {3, 120}, {5, 130}, {19, 150}, {4, 120}, {20, 180}, {11, 120}, {7, 120}, {35, 300}, {1, 111}, {6, 165} };
	
	selection_sort(list, n); // 선택정렬 호출 
	for (i = 0; i < n; i++) {
		printf("%d ", list[i].weight);
	}
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("%d ", list[i].height);
	}
	printf("\n");


	return 0;
}