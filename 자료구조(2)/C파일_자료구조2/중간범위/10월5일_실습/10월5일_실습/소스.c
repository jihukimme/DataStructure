

//�⺻���� ����Ʈ��.. �߰������� ����Ʈ���� ��������Ʈ�������� ����ϴ� �Լ� �����
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void Print_Heap(HeapType* h) {
	
	int i = 1;
	int k = 1;

	while (i <= h->heap_size) {
		for (int j = 1; j <= pow(2, k - 1); j++) {
			if (i > h->heap_size)
				break;
			printf("%2d ", h->heap[i].key);
			i++;
		}
		printf("\n");
		k++;
	}

}

int main(void)
{
	element e1 = { 10 }, e2 = { 40 }, e3 = { 30 }, e4 = { 5 }, e5 = { 12 }, e6 = { 6 }, e7 = { 15 }, e8 = { 9 }, e9 = { 60 };
	HeapType* heap;

	heap = create(); 	// ���� ����
	init(heap);	// �ʱ�ȭ

				// ����
	insert_max_heap(heap, e1);
	insert_max_heap(heap, e2);
	insert_max_heap(heap, e3);
	insert_max_heap(heap, e4);
	insert_max_heap(heap, e5);
	insert_max_heap(heap, e6);
	insert_max_heap(heap, e7);
	insert_max_heap(heap, e8);
	insert_max_heap(heap, e9);


	Print_Heap(heap);


	free(heap);
	return 0;
}

