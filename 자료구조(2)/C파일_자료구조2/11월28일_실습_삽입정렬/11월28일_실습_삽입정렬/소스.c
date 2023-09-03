#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

typedef struct LIST {
	int weight;
	int height;
}LIST;

/*
void swap(int x, int y, LIST list[]) {
	LIST temp;

	temp = list[x];
	list[x] = list[y];
	list[y] = temp;
}
*/

void swap(LIST* x, LIST* y) {
	LIST temp;
	temp = *x;
	*x = *y;
	*y = temp;
}



// 삽입정렬
void insertion_sort_weight(LIST list[], int n){
	int i, j;
	
	LIST key;
	for (i = 1; i < n; i++) {
		key = list[i];
		//올림차순 설정
		for (j = i - 1; j >= 0 && list[j].weight > key.weight; j--) {
			//list[j + 1] = list[j]; /* 레코드의 오른쪽 이동 */
			//temp = list[j+1]; list[j+1] = list[j]; list[j] = temp;
			list[j + 1] = list[j];
		}
		list[j + 1] = key;
	}
}

// 삽입정렬
void insertion_sort_height(LIST list[], int n) {
	int i, j;

	LIST key;
	for (i = 1; i < n; i++) {
		key = list[i];
		//올림차순 설정
		for (j = i - 1; j >= 0 && list[j].height > key.height; j--) {
			//list[j + 1] = list[j]; /* 레코드의 오른쪽 이동 */
			//temp = list[j+1]; list[j+1] = list[j]; list[j] = temp;
			list[j + 1] = list[j];
		}
		list[j + 1] = key;
	}
}


int main(void) {
	int i;
	int n = MAX_SIZE;

	LIST list[MAX_SIZE] = { {3, 120}, {5, 130}, {19, 150}, {4, 120}, {20, 180}, {11, 120}, {7, 120}, {35, 300}, {1, 111}, {6, 165} };

	insertion_sort_height(list, n); // 삽입정렬 호출 

	for (i = 0; i < n; i++) {
		printf("%d ", list[i].weight);
	}
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("%d ", list[i].height);
	}

	return 0;
}