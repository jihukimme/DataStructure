#include <stdio.h>
#include <stdlib.h>

#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

void bubble_sort(int list[], int n){
	int i, j, temp;
	int count = 1;

	//방법 1
	//for (i = n - 1; i > 0; i--) {
	//	for (j = 0; j < i; j++) {
	//		/* 앞뒤의 레코드를 비교한 후 교체 */
	//		if (list[j] > list[j + 1]) {
	//			SWAP(list[j], list[j + 1], temp);
	//		}
	//	}
	//	printf("%d단계: ", count++);
	//	for (int k = 0; k < n; k++) {
	//		printf("%d ", list[k]);
	//	}
	//	printf("\n");
	//}

	//방법 2
	//for (i = 0; i < n-1; i++) {
	//	for (j = 0; j < n-1 - i; j++) {
	//		/* 앞뒤의 레코드를 비교한 후 교체 */
	//		if (list[j] > list[j + 1]) {
	//			SWAP(list[j], list[j + 1], temp);
	//		}
	//	}
	//	printf("%d단계: ", count++);
	//	for (int k = 0; k < n; k++) {
	//		printf("%d ", list[k]);
	//	}
	//	printf("\n");
	//}

	//방법 3 (맨 앞에서부터 정렬)
	for (i = 0; i < n-1; i++) {
		for (j = n-1; j > i; j--) {
			/* 앞뒤의 레코드를 비교한 후 교체 */
			if (list[j] > list[j - 1]) {
				SWAP(list[j], list[j - 1], temp);
			}
		}
		printf("%d단계: ", count++);
		for (int k = 0; k < n; k++) {
			printf("%d ", list[k]);
		}
		printf("\n");
	}

	printf("정렬완료: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");
}


int main(void) {
	int list[6] = { 3, 7, 9, 4, 1, 6 };
	printf("정렬전: ");
	for (int i = 0; i < 6; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");


	bubble_sort(list, 6);

	return 0;
}


