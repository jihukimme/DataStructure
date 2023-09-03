/*

//������� �׷���
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct GraphType {
	int n;	// ������ ����
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

// �׷��� �ʱ�ȭ
void init(GraphType* g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}
// ���� ���� ����
void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "�׷���: ������ ���� �ʰ�");
		return;
	}
	g->n++;
}
// ���� ���� ����
void insert_edge(GraphType* g, int start, int end)
{
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "�׷���: ���� ��ȣ ����");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}
// ���� ��� ��� �Լ�
void print_adj_mat(GraphType* g)
{
	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			printf("%2d ", g->adj_mat[i][j]);
		}
		printf("\n");
	}
}

void main()
{
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	for (int i = 0; i < 4; i++)
		insert_vertex(g, i);

	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	print_adj_mat(g);

	free(g);
}
*/




//������� �׷����� �߰����� �Լ�
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct GraphType {
	int n;	// ������ ����
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

// �׷��� �ʱ�ȭ 
void init(GraphType* g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}
// ���� ���� ����
void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "�׷���: ������ ���� �ʰ�");
		return;
	}
	g->n++;
}
// ���� ���� ����
void insert_edge(GraphType* g, int start, int end)
{
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "�׷���: ���� ��ȣ ����");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}
// ���� ��� ��� �Լ�
void print_adj_mat(GraphType* g)
{
	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			printf("%2d ", g->adj_mat[i][j]);
		}
		printf("\n");
	}
}

//2) count_edges(g) // ������ ���� ��ȯ
int count_edges(GraphType* g) {
	int count = 0;

	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			if (g->adj_mat[i][j] == 1)
				count++;
		}
	}

	return (count / 2);
}

//3) find_degree(g, n) // n�� ������ ���� ��ȯ
int find_degree(GraphType* g, int n) {
	int count = 0;
	for (int i = 0; i < g->n; i++) {
		if (g->adj_mat[n][i] == 1)
			count++;
	}

	return count;
}

//4) edge_exist(g, m, n) // m, n  ���̿� ������ �ִ°�(��,����)
void edge_exist(GraphType* g, int m, int n) {
	if (g->adj_mat[m][n] == 1 || g->adj_mat[n][m] == 1)
		printf("��\n");
	else
		printf("����\n");
}

//5) list_conn_vertex(g, n) // n�� �������� ����� ��� ���� ���
void list_conn_vertex(GraphType* g, int n) {
	printf("%d�� �������� ����� ��� ����: ", n + 1);
	for (int i = 0; i < g->n; i++) {
		if (g->adj_mat[n][i] == 1 || g->adj_mat[i][n] == 1)
			printf("%d ", i + 1);
	}
	printf("\n");
}

void main()
{
	GraphType* g = (GraphType*)malloc(sizeof(GraphType));
	init(g);

	for (int i = 0; i < 5; i++)
		insert_vertex(g, i); //���� 5�� ����.

	//���� ����
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 0, 4);
	insert_edge(g, 1, 2);
	insert_edge(g, 1, 4);
	insert_edge(g, 2, 3);
	insert_edge(g, 3, 4);

	//���� ��� ���
	print_adj_mat(g);


	//2) count_edges(g) // ������ ���� ��ȯ
	printf("������ ����: %d\n", count_edges(g));

	//3) find_degree(g, n) // n�� ������ ���� ��ȯ
	for (int i = 0; i < 5; i++) {
		printf("%d�� ������ ����: %d\n", i + 1, find_degree(g, i));
	}

	//4) edge_exist(g, m, n) // m, n  ���̿� ������ �ִ°�(��,����)
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d�� %d ���̿� ������ �ִ°�(��, ����): ", i + 1, j + 1);
			edge_exist(g, i, j);
			printf("\n");
		}
	}

	//5) list_conn_vertex(g, n) // n�� �������� ����� ��� ���� ���
	for (int i = 0; i < 5; i++) {
		list_conn_vertex(g, i);
	}


	free(g);
}
