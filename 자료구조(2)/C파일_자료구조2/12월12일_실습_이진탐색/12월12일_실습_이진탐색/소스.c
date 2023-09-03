#include <stdio.h>
#include <stdlib.h>

typedef struct student {
	int num;
	char name[10];
}student;

int compare(const void* arg1, const void* arg2)
{
	if (((student*)arg1)->num > ((student*)arg2)->num) return 1;
	else if (((student*)arg1)->num == ((student*)arg2)->num) return 0;
	else return -1;
}


int search_binary2(int key, int low, int high, student list[])
{
	int middle;

	while (low <= high) {       // ���� ���ڵ��� ���� ������
		middle = (low + high) / 2;
		if (key == list[middle].num)
			return middle;
		else if (key > list[middle].num)
			low = middle + 1;
		else
			high = middle - 1;
	}
	return -1;   // �߰ߵ��� ���� 
}

int seq_search(int key, int low, int high, student list[])
{
	int i;

	for (i = low; i <= high; i++)
		if (list[i].num == key)
			return i;  // Ž���� �����ϸ� Ű ���� �ε��� ��ȯ 
	return -1;    // Ž���� �����ϸ� -1 ��ȯ 
}

int main(void) {
	student list[10] = { { 1003, "Hong" }, {1004, "John"}, {1002, "Kim"}, {1134, "Park"},
{2341, "Doug"},{2004, "Lee"}, {2003, "Lee"}, {1111, "Son"},
{1314, "Do"}, {1531, "Joo"} };

	qsort((void*)list, 10, sizeof(student), compare);


	//�������� ���� �� �迭
	for (int i = 0; i < 10; i++) {
		printf("%d%s ", list[i].num, list[i].name);
	}
	printf("\n\n");


	int index = search_binary2(2004, 0, 9, list);
	printf("����Ž��: %d%s", list[index].num, list[index].name);
	printf("\n\n");

	int index2 = seq_search(2004, 0, 9, list);
	printf("����Ž��: %d%s", list[index].num, list[index].name);
	printf("\n\n");


	return 0;
}
