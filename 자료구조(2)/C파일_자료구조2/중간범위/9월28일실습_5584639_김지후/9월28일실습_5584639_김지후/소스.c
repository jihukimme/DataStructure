
//히프트리의 기본적인 코드(최대 히프트리, 최소 히프트리)
//히프트리가 만들어지는 과정을 나타내봐라
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


// 생성 함수
HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}

// 초기화 함수
void init(HeapType* h)
{
	h->heap_size = 0;
}

// 현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
// 삽입 함수
void insert_max_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);

	//  트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;     // 새로운 노드를 삽입
}

// 삭제 함수
element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// 현재 노드의 자식노드 중 더 작은 자식노드를 찾는다.
		if ((child < h->heap_size) &&
			(h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break;
		// 한 단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

//구성된 최대 히프트리가 저장된 배열의 내용을 표시
void print_heap(HeapType* h) {
	printf("구성된 최대 히프트리가 저장된 배열의 내용을 표시\n");
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

	heap = create(); 	// 히프 생성
	init(heap);	// 초기화

				// 삽입
	printf("순차적으로 읽어서 최대히프트리가 만들어지는 과정\n");
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