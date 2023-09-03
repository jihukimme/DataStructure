/*

//스택을 이용해서 순환 호출을 흉내내기.. 반복적 순회
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

#define SIZE 100
int top = -1;
TreeNode* stack[SIZE];

void push(TreeNode* p)
{
	if (top < SIZE - 1)
		stack[++top] = p;
}

TreeNode* pop()
{
	TreeNode* p = NULL;
	if (top >= 0)
		p = stack[top--];
	return p;
}

void inorder_iter(TreeNode* root)
{
	while (1) {
		for (; root; root = root->left)
			push(root);
		root = pop();

		if (!root) break;
		printf("[%d] ", root->data);
		root = root->right;
	}
}

//		  15
//	   4		 20
//    1	      16  25
TreeNode n1 = { 1,  NULL, NULL };
TreeNode n2 = { 4,  &n1,  NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3,  &n4 };
TreeNode n6 = { 15, &n2,  &n5 };
TreeNode* root = &n6;

int main(void)
{
	printf("중위 순회=");
	inorder_iter(root);
	printf("\n");
	

	return 0;
}
*/


/*

//큐를 활용한 레벨순회 프로그램
//큐 사용 -> 레벨순회
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

// ================ 원형큐 코드 시작 =================
#define MAX_QUEUE_SIZE 100
typedef TreeNode* element;
typedef struct { // 큐 타입
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

// 오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 공백 상태 검출 함수
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 삽입 함수
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 삭제 함수
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

void level_order(TreeNode* ptr)
{
	QueueType q;

	init_queue(&q);	 // 큐 초기화

	if (ptr == NULL) return;
	enqueue(&q, ptr);
	while (!is_empty(&q)) {
		ptr = dequeue(&q);
		printf(" [%d] ", ptr->data);
		if (ptr->left)
			enqueue(&q, ptr->left);
		if (ptr->right)
			enqueue(&q, ptr->right);
	}
}
//		  15
//	   4		 20
//    1	      16  25
TreeNode n1 = { 1,  NULL, NULL };
TreeNode n2 = { 4,  &n1,  NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3,  &n4 };
TreeNode n6 = { 15, &n2,  &n5 };
TreeNode* root = &n6;

int main(void)
{
	printf("레벨 순회=");
	level_order(root);
	printf("\n");
	return 0;
}
*/



/*


//수식 트리 계산 프로그램
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, *right;
}TreeNode;

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, NULL, NULL };
TreeNode n3 = { '*', &n1, &n2 };
TreeNode n4 = { 16, NULL, NULL };
TreeNode n5 = { 25, NULL, NULL };
TreeNode n6 = { '+', &n4, &n5 };
TreeNode n7 = { '+', &n3, &n6 };
TreeNode* root = &n7;


int evaluate(TreeNode* root) {
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return root->data;
	else {
		int op1 = evaluate(root->left);
		int op2 = evaluate(root->right);
		printf("%d %c %d = \n", op1, root->data, op2);

		switch (root->data) {
		case '+':
			return op1 + op2;
		case '*':
			return op1 * op2;
		case '-':
			return op1 - op2;
		case '/':
			return op1 / op2;
		}
	}

	return 0;
}

int main(void) {


	evaluate(root);


	return 0;
}
*/



/*

//트리를 선언할 때 main문 안에 메모리할당을 통해서 선언하면 노드의 순서를 신경쓰지 않아도 되지만.. 
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;


void inorder(TreeNode* root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void preorder(TreeNode* root) {
	if (root != NULL) {
		printf("%d ", root->data);	
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(TreeNode* root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}

int main(void) {
	TreeNode* n1, * n2, * n3, *root;
	n1 = (TreeNode*)malloc(sizeof(TreeNode));
	n2 = (TreeNode*)malloc(sizeof(TreeNode));
	n3 = (TreeNode*)malloc(sizeof(TreeNode));
	root = (TreeNode*)malloc(sizeof(TreeNode));
	
	n1->data = 1;
	n1->left = n2;
	n1->right = n3;

	n2->data = 2;
	n2->left = NULL;
	n2->right = NULL;

	n3->data = 3;
	n3->left = NULL;
	n3->right = NULL;

	root = n1;


	inorder(root);

	free(n1), free(n2), free(n3), free(root);

	return 0;
}
*/


/*


//main문 밖에 트리를 선언할 때에는 노드의 선언 순서를 고려해야한다. !!
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;


TreeNode n3 = { 3, NULL, NULL };
TreeNode n2 = { 2, NULL, NULL };
TreeNode n1 = { 1, &n2, &n3 };

TreeNode* root = &n1;

void inorder(TreeNode* root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void preorder(TreeNode* root) {
	if (root != NULL) {
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(TreeNode* root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}

int main(void) {


	inorder(root);

	return 0;
}
*/

/*


//디렉토리 용량 계산하는 프로그램 -> 서브트리부터 계산을 해야하니깐 후위순회로 순환해야 함.
//실행이 안됨;;;
#include <stdio.h>
#include <stdlib.h>


typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode n3 = { 3, NULL, NULL };
TreeNode n2 = { 2, NULL, NULL };
TreeNode n1 = { 1, &n2, &n3 };

int calc_size(TreeNode* root) {
	int left_size, right_size;

	if (root == NULL)
		return 0;

	left_size = calc_size(root->left);
	right_size = calc_size(root->right);

	return(root->data + left_size + right_size);
}

int main(void) {


	printf("%d", clac_size(&n1));

	return 0;
}
*/




//이진 탐색 트리의 응용 : 영어 사전



/*


//이진탐색트리
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode* search(TreeNode* node, int key) {
	if (node == NULL) return NULL;
	if (key == node->key) return node;
	else if (key < node->key)
		return search(node->left, key);
	else
		return search(node->right, key);
}

TreeNode* new_node(int item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));

	temp->key = item;
	temp->left = NULL;
	temp->right = NULL;
	
	return temp;
}

TreeNode* insert_node(TreeNode* node, int key) {
	if (node == NULL) return new_node(key);

	if (node->key < key)
		return insert_node(node->right, key);
	else if (node->key > key)
		return insert_node(node->left, key);

	return node;
}

TreeNode* min_value_node(TreeNode* node) {
	TreeNode* curr = node;

	while (curr != NULL) {
		curr = curr->left;
	}

	return curr;
}

TreeNode* delete_node(TreeNode* root, int key) {
	if (root == NULL) return root;

	if (key < root->key)
		root->left = delete_node(root->left, key);
	else if (key > root->key)
		root->right = delete_node(root->right, key);
	else {
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}

		TreeNode* temp = min_value_node(root->right);

		root->key = temp->key;

		root->right = delete_node(root->right, temp->key);
	}
	return root;
}
*/






/*

//히프
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ELEMENT 200
typedef struct {
	int key;
}element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

HeapType* creat() {
	return (HeapType*)malloc(sizeof(HeapType));
}

HeapType* init(HeapType* h) {
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element data) {
	int i = ++(h->heap_size);

	while (i != 1 && (data.key > h->heap[i / 2].key)) {
		h->heap[i].key = h->heap[i / 2].key;
		i /= 2;
	}
	h->heap[i] = data;
}

element delete_max_heap(HeapType* h) {
	int parent, child;
	element item, temp;
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];

	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		if (child < h->heap_size && h->heap[child].key < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

void print_heap(HeapType* h) {
	h->heap[0].key = NULL;
	for (int i = 0; i <= h->heap_size; i++) {
		printf("%d |", h->heap[i].key);
	}
	printf("\n");
}

void print_heap_tree(HeapType* h) {

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


int main(void) {
	HeapType* heap;
	heap = creat();
	init(heap);

	element e1 = { 10 }, e2 = { 20 }, e3 = { 30 };
	insert_max_heap(heap, e1);
	insert_max_heap(heap, e2);
	insert_max_heap(heap, e3);
	print_heap(heap);
	print_heap_tree(heap);

	printf("\n\n====================\n");
	element d1 = delete_max_heap(heap);
	printf("%d 삭제\n", d1.key);
	
	printf("====================\n\n");
	print_heap(heap);
	print_heap_tree(heap);

	return 0;
}
*/


/*
//히프 정렬
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ELEMENT 200
typedef struct {
	int key;
}element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

HeapType* creat() {
	return (HeapType*)malloc(sizeof(HeapType));
}

HeapType* init(HeapType* h) {
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element data) {
	int i = ++(h->heap_size);

	while (i != 1 && (data.key > h->heap[i / 2].key)) {
		h->heap[i].key = h->heap[i / 2].key;
		i /= 2;
	}
	h->heap[i] = data;
}

element delete_max_heap(HeapType* h) {
	int parent, child;
	element item, temp;
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];

	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		if (child < h->heap_size && h->heap[child].key < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

void print_heap(HeapType* h) {
	h->heap[0].key = NULL;
	for (int i = 0; i <= h->heap_size; i++) {
		printf("%d |", h->heap[i].key);
	}
	printf("\n");
}

void print_heap_tree(HeapType* h) {

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

void heap_sort(element arr[], int n) {
	HeapType* h = creat();
	init(h);

	for (int i = 0; i < n; i++) {
		insert_max_heap(h, arr[i]);
	}
	
	for (int j = n - 1; j >= 0; j--) {
		arr[j] = delete_max_heap(h);
	}


	free(h);
}

#define SIZE 8
int main(void) {

	element list[SIZE] = { 23,56, 11,9,56,99,27,34 };

	HeapType* heap = creat();
	init(heap);

	for (int i = 0; i < SIZE; i++) {
		insert_max_heap(heap, list[i]);
	}

	print_heap(heap);
	printf("\n\n\n");
	print_heap_tree(heap);
	printf("\n\n\n");

	heap_sort(list, SIZE);
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", list[i]);
	}

	return 0;
}

*/




/*

//최소히프 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ELEMENT 200
typedef struct {
	int key;
}element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

HeapType* creat() {
	return (HeapType*)malloc(sizeof(HeapType));
}

HeapType* init(HeapType* h) {
	h->heap_size = 0;
}

void insert_min_heap(HeapType* h, element data) {
	int i = ++(h->heap_size);

	while (i != 1 && (data.key < h->heap[i / 2].key)) {
		h->heap[i].key = h->heap[i / 2].key;
		i /= 2;
	}
	h->heap[i] = data;
}

element delete_min_heap(HeapType* h) {
	int parent, child;
	element item, temp;
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];

	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		if (child < h->heap_size && h->heap[child].key > h->heap[child + 1].key)
			child++;
		if (temp.key <= h->heap[child].key) break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

void print_heap(HeapType* h) {
	h->heap[0].key = NULL;
	for (int i = 0; i <= h->heap_size; i++) {
		printf("%d |", h->heap[i].key);
	}
	printf("\n");
}

void print_heap_tree(HeapType* h) {

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

void heap_sort(element arr[], int n) {
	HeapType* h = creat();
	init(h);

	for (int i = 0; i < n; i++) {
		insert_min_heap(h, arr[i]);
	}

	for (int j = n - 1; j >= 0; j--) {
		arr[j] = delete_min_heap(h);
	}


	free(h);
}

#define SIZE 8
int main(void) {

	element list[SIZE] = { 23,56, 11,9,56,99,27,34 };

	HeapType* heap = creat();
	init(heap);

	for (int i = 0; i < SIZE; i++) {
		insert_min_heap(heap, list[i]);
	}

	print_heap(heap);
	printf("\n\n\n");
	print_heap_tree(heap);
	printf("\n\n\n");

	heap_sort(list, SIZE);
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", list[i]);
	}

	return 0;
}

*/






/*
//인접행렬 그래프 
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct GraphType {
	int n;	// 정점의 개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

// 그래프 초기화 
void init(GraphType* g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}
// 정점 삽입 연산
void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}
// 간선 삽입 연산
void insert_edge(GraphType* g, int start, int end)
{
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}
// 인접 행렬 출력 함수
void print_adj_mat(GraphType* g)
{
	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			printf("%2d ", g->adj_mat[i][j]);
		}
		printf("\n");
	}
}

//2) count_edges(g) // 간선의 개수 반환
int count_edges(GraphType* g) {
	int count = 0;

	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			if (g->adj_mat[i][j] == 1)
				count++;
		}
	}

	return count;
}

//3) find_degree(g, n) // n번 정점의 차수 반환
int find_degree(GraphType* g, int n) {
	int count = 0;
	for (int i = 0; i < g->n; i++) {
		if (g->adj_mat[n][i] == 1)
			count++;
	}
	return (count / 2);
}

//4) edge_exist(g, m, n) // m, n  사이에 간선이 있는가(참,거짓)
void edge_exist(GraphType* g, int m, int n) {
	if (g->adj_mat[m][n] == 1 || g->adj_mat[n][m] == 1)
		printf("참\n");
	else
		printf("거짓\n");
}

//5) list_conn_vertex(g, n) // n과 간선으로 연결된 모든 정점 출력
void list_conn_vertex(GraphType* g, int n) {
	printf("%d과 간선으로 연결된 모든 정점: ", n);
	for (int i = 0; i < g->n; i++) {
		if (g->adj_mat[n][i] == 1)
			printf("%d ", i);
	}
	printf("\n");
}

void main()
{
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	for (int i = 0; i < 4; i++)
		insert_vertex(g, i); //정점 0, 1, 2, 3 삽입.

	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);

	print_adj_mat(g);


	//2) count_edges(g) // 간선의 개수 반환
	printf("간선의 개수: %d\n", count_edges(g));

	//3) find_degree(g, n) // n번 정점의 차수 반환
	for (int i = 0; i < 4; i++) {
		printf("%d번 정점의 차수: %d\n", i, find_degree(g, i));
	}

	//4) edge_exist(g, m, n) // m, n  사이에 간선이 있는가(참,거짓)
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d와 %d 사이에 간선이 있는가(참, 거짓): ", i, j);
			edge_exist(g, i, j);
			printf("\n");
		}
	}

	//5) list_conn_vertex(g, n) // n과 간선으로 연결된 모든 정점 출력
	for (int i = 0; i < 4; i++) {
		list_conn_vertex(g, i);
	}





	free(g);
}
*/


