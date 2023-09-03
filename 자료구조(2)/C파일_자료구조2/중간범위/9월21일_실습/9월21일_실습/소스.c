
/*
// 이진트리의 추가 연산(노드의 개수 구하기 - get_node_count, 단말노드 개수 구하기 - get_leaf_count, 높이 구하기 - get_height)
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

void inorder(TreeNode* root) {
	if (root != NULL) {
		inorder(root->left);
		printf("[%d] ", root->data);
		inorder(root->right);
	}
}

void preorder(TreeNode* root) {
	if (root != NULL) {
		printf("[%d] ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(TreeNode* root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("[%d] ", root->data);
	}
}

int get_height(TreeNode* node) {
	int height = 0;

	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));

	return height;
}

int get_node_count(TreeNode* node) {
	int count = 0;

	if (node != NULL)
		count = 1 + get_node_count(node->left) + get_node_count(node->right);

	return count;
}

int get_leaf_count(TreeNode* node) {
	int count = 0;

	if (node != NULL) {
		if (node->left == NULL && node->right == NULL)
			count++;
		else
			count = count + get_leaf_count(node->left) + get_leaf_count(node->right);
	}
	return count;
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

	int height = get_height(n1);
	printf("height= %d\n", height);

	int node_count = get_node_count(n1);
	printf("node_count= %d\n", node_count);

	int leaf_count = get_leaf_count(n1);
	printf("leaf_count= %d\n", leaf_count);

	free(n1); free(n2); free(n3);
	free(n4); free(n5); free(n6);


	return 0;
}

*/






//균형트리인지 확인하는 함수 - isBalanced, 노드가 가지고 있는 값의 함을 계산하는 함수 - get_sum_node, 자식이 하나만 있는 노드의 개수를 구하는 함수 - get_one_cild 함수 만들기
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

int get_sum_node(TreeNode* root) {
	int sum = 0;

	if (root != NULL) {
		sum = sum + root->data + get_sum_node(root->left) + get_sum_node(root->right);
	}

	return sum;
}

int get_one_child(TreeNode* root) {

	int count = 0;

	if (root != NULL) {
		if ((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL)) {
			count++;
		}
		count = count + get_one_child(root->left) + get_one_child(root->right);
	}
		
	return count;
}

int get_height(TreeNode* node) {
	int height = 0;

	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));

	return height;
}

int isBalanced(TreeNode* root) {
	if (-1 <= get_height(root->left) - get_height(root->right) <= 1) {
		printf("균형트리 입니다.\n");
		return 1;
	}
	else {
		printf("균형트리가 아닙니다.\n");
		return 0;
	}
}

int main(void)
{
	TreeNode* n1, * n2, * n3, * n4, * n5, * n6, *n7;

	n1 = (TreeNode*)malloc(sizeof(TreeNode));
	n2 = (TreeNode*)malloc(sizeof(TreeNode));
	n3 = (TreeNode*)malloc(sizeof(TreeNode));
	n4 = (TreeNode*)malloc(sizeof(TreeNode));
	n5 = (TreeNode*)malloc(sizeof(TreeNode));
	n6 = (TreeNode*)malloc(sizeof(TreeNode));
	n7 = (TreeNode*)malloc(sizeof(TreeNode));


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

	n5->data = 18;		// 다섯 번째 노드를 설정한다.
	n5->left = n7;
	n5->right = NULL;

	n6->data = 25;		// 여섯 번째 노드를 설정한다.
	n6->left = NULL;
	n6->right = NULL;

	n7->data = 16;
	n7->left = NULL;
	n7->right = NULL;


	int sum_node = get_sum_node(n1);
	printf("노드의 합은 %d입니다.\n", sum_node);

	int one_child = get_one_child(n1);
	printf("자식이 하나인 노드의 개수는 %d입니다.\n", one_child);

	isBalanced(n1);

	free(n1); free(n2); free(n3);
	free(n4); free(n5); free(n6);


	return 0;
}
