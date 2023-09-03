#include <stdio.h>
#include <stdlib.h>

#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

void bubble_sort(int list[], int n){
	int i, j, temp;
	int count = 1;

	//��� 1
	//for (i = n - 1; i > 0; i--) {
	//	for (j = 0; j < i; j++) {
	//		/* �յ��� ���ڵ带 ���� �� ��ü */
	//		if (list[j] > list[j + 1]) {
	//			SWAP(list[j], list[j + 1], temp);
	//		}
	//	}
	//	printf("%d�ܰ�: ", count++);
	//	for (int k = 0; k < n; k++) {
	//		printf("%d ", list[k]);
	//	}
	//	printf("\n");
	//}

	//��� 2
	//for (i = 0; i < n-1; i++) {
	//	for (j = 0; j < n-1 - i; j++) {
	//		/* �յ��� ���ڵ带 ���� �� ��ü */
	//		if (list[j] > list[j + 1]) {
	//			SWAP(list[j], list[j + 1], temp);
	//		}
	//	}
	//	printf("%d�ܰ�: ", count++);
	//	for (int k = 0; k < n; k++) {
	//		printf("%d ", list[k]);
	//	}
	//	printf("\n");
	//}

	//��� 3 (�� �տ������� ����)
	for (i = 0; i < n-1; i++) {
		for (j = n-1; j > i; j--) {
			/* �յ��� ���ڵ带 ���� �� ��ü */
			if (list[j] > list[j - 1]) {
				SWAP(list[j], list[j - 1], temp);
			}
		}
		printf("%d�ܰ�: ", count++);
		for (int k = 0; k < n; k++) {
			printf("%d ", list[k]);
		}
		printf("\n");
	}

	printf("���ĿϷ�: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");
}


int main(void) {
	int list[6] = { 3, 7, 9, 4, 1, 6 };
	printf("������: ");
	for (int i = 0; i < 6; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");


	bubble_sort(list, 6);

	return 0;
}


