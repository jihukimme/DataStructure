

//기본적인 히프트리.. 추가적으로 히프트리를 완전이진트리형으로 출력하는 함수 만들기
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

	heap = create(); 	// 히프 생성
	init(heap);	// 초기화

				// 삽입
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

