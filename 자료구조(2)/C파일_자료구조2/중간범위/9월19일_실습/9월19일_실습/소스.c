

//����Ʈ�� ������ -> ������ȸ�� ����غ��� �ǽ�


#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

void preorder(TreeNode* root) {
	if (root != NULL) {
		printf("[%d] ", root->data);  // ��� �湮
		preorder(root->left);// ���ʼ���Ʈ�� ��ȸ
		preorder(root->right);// �����ʼ���Ʈ�� ��ȸ
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


	n1->data = 15;		// ù ��° ��带 �����Ѵ�.
	n1->left = n2;
	n1->right = n3;

	n2->data = 4;		// �� ��° ��带 �����Ѵ�.
	n2->left = n4;
	n2->right = NULL;

	n3->data = 20;		// �� ��° ��带 �����Ѵ�.
	n3->left = n5;
	n3->right = n6;

	n4->data = 1;		// �� ��° ��带 �����Ѵ�.
	n4->left = NULL;
	n4->right = NULL;

	n5->data = 16;		// �ټ� ��° ��带 �����Ѵ�.
	n5->left = NULL;
	n5->right = NULL;

	n6->data = 25;		// ���� ��° ��带 �����Ѵ�.
	n6->left = NULL;
	n6->right = NULL;

	printf("������ȸ= ");
	preorder(n1);

	printf("\n������ȸ= ");
	inorder(n1);

	free(n1); free(n2); free(n3);
	free(n4); free(n5); free(n6);


	return 0;
}



/*
//������ȸ�� ť�� ����ϴ� ��ȸ���̴�.
//ť�� ����Ѵ�!!! -> ������ȸ!!

#include <stdio.h>
#include <stdlib.h>


typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

// ================ ����ť �ڵ� ���� =================
#define MAX_QUEUE_SIZE 100
typedef TreeNode* element;
typedef struct { // ť Ÿ��
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

// ���� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// ���� ���� ���� �Լ�
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// ���� �Լ�
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// ���� �Լ�
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

void level_order(TreeNode* ptr)
{
	QueueType q;

	init_queue(&q);	 // ť �ʱ�ȭ

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
	printf("���� ��ȸ=");
	level_order(root);
	printf("\n");

	

	return 0;
}

*/