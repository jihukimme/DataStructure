

//이진트리 만들어보고 -> 전위순회로 출력해보기 실습


#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

void preorder(TreeNode* root) {
	if (root != NULL) {
		printf("[%d] ", root->data);  // 노드 방문
		preorder(root->left);// 왼쪽서브트리 순회
		preorder(root->right);// 오른쪽서브트리 순회
	}
}

void inorder(TreeNode* root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}


int main(void)
{
	TreeNode* n1, * n2, * n3, * n4, * n5, * n6;

	n1 = (TreeNode*)malloc(sizeof(TreeNode));
	n2 = (TreeNode*)malloc(sizeof(TreeNode));
	n3 = (TreeNode*)malloc(sizeof(TreeNode));
	n4 = (TreeNode*)malloc(sizeof(TreeNode));
	n5 = (TreeNode*)malloc(sizeof(TreeNode));
	n6 = (TreeNode*)malloc(sizeof(TreeNode));


	n1->data = 15;		// 첫 번째 노드를 설정한다.
	n1->left = n2;
	n1->right = n3;

	n2->data = 4;		// 두 번째 노드를 설정한다.
	n2->left = n4;
	n2->right = NULL;

	n3->data = 20;		// 세 번째 노드를 설정한다.
	n3->left = n5;
	n3->right = n6;

	n4->data = 1;		// 네 번째 노드를 설정한다.
	n4->left = NULL;
	n4->right = NULL;

	n5->data = 16;		// 다섯 번째 노드를 설정한다.
	n5->left = NULL;
	n5->right = NULL;

	n6->data = 25;		// 여섯 번째 노드를 설정한다.
	n6->left = NULL;
	n6->right = NULL;

	printf("전위순회= ");
	preorder(n1);

	printf("\n중위순회= ");
	inorder(n1);

	free(n1); free(n2); free(n3);
	free(n4); free(n5); free(n6);


	return 0;
}



/*
//레벨순회는 큐를 사용하는 순회법이다.
//큐를 사용한다!!! -> 레벨순회!!

#include <stdio.h>
#include <stdlib.h>


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