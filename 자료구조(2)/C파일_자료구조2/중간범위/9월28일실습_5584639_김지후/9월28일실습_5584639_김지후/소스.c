
//����Ʈ���� �⺻���� �ڵ�(�ִ� ����Ʈ��, �ּ� ����Ʈ��)
//����Ʈ���� ��������� ������ ��Ÿ������
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 200

typedef struct {
	int key;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;


// ���� �Լ�
HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}

// �ʱ�ȭ �Լ�
void init(HeapType* h)
{
	h->heap_size = 0;
}

// ���� ����� ������ heap_size�� ���� h�� item�� �����Ѵ�.
// ���� �Լ�
void insert_max_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);

	//  Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;     // ���ο� ��带 ����
}

// ���� �Լ�
element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// ���� ����� �ڽĳ�� �� �� ���� �ڽĳ�带 ã�´�.
		if ((child < h->heap_size) &&
			(h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break;
		// �� �ܰ� �Ʒ��� �̵�
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

//������ �ִ� ����Ʈ���� ����� �迭�� ������ ǥ��
void print_heap(HeapType* h) {
	printf("������ �ִ� ����Ʈ���� ����� �迭�� ������ ǥ��\n");
	for (int i = 0; i <= h->heap_size; i++) {
		h->heap[0].key = 0;
		printf("%d | ", h->heap[i].key);
	}
	printf("\n\n");
}


int main(void)
{
	element e1 = { 10 }, e2 = { 40 }, e3 = { 30 }, e4 = { 5 }, e5 = { 12 }, e6 = { 6 }, e7 = { 15 }, e8 = { 9 }, e9 = { 60 };
	element a1, a2, a3, a4, a5, a6, a7, a8, a9;
	HeapType* heap;

	heap = create(); 	// ���� ����
	init(heap);	// �ʱ�ȭ

				// ����
	printf("���������� �о �ִ�����Ʈ���� ��������� ����\n");
	insert_max_heap(heap, e1);
	for (int i = 1; i <= 1; i++) {
		printf("%d->", heap->heap[i].key);
	}
	printf("\n");
	insert_max_heap(heap, e2);
	for (int i = 1; i <= 2; i++) {
		printf("%d->", heap->heap[i].key);
	}
	printf("\n");
	insert_max_heap(heap, e3);
	for (int i = 1; i <= 3; i++) {
		printf("%d->", heap->heap[i].key);
	}
	printf("\n");
	insert_max_heap(heap, e4);
	for (int i = 1; i <= 4; i++) {
		printf("%d->", heap->heap[i].key);
	}
	printf("\n");
	insert_max_heap(heap, e5);
	for (int i = 1; i <= 5; i++) {
		printf("%d->", heap->heap[i].key);
	}
	printf("\n");
	insert_max_heap(heap, e6);
	for (int i = 1; i <= 6; i++) {
		printf("%d->", heap->heap[i].key);
	}
	printf("\n");
	insert_max_heap(heap, e7);
	for (int i = 1; i <= 7; i++) {
		printf("%d->", heap->heap[i].key);
	}
	printf("\n");
	insert_max_heap(heap, e8);
	for (int i = 1; i <= 8; i++) {
		printf("%d->", heap->heap[i].key);
	}
	printf("\n");
	insert_max_heap(heap, e9);
	for (int i = 1; i <= 9; i++) {
		printf("%d->", heap->heap[i].key);
	}
	printf("\n\n\n");
	


	print_heap(heap);



	
	free(heap);
	return 0;
}