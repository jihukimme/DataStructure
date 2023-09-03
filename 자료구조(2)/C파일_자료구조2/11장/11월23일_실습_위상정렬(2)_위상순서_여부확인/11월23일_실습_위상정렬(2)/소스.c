#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100

typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
}GraphNode;

typedef struct GraphType {
	int n;
	GraphNode* adj_list[MAX_VERTICES];
}GraphType;

void graph_init(GraphType* g) {
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}

void insert_vertex(GraphType* g, int v) {
	if ((g->n) + 1 > MAX_VERTICES) {
		fprintf(stderr, "�׷��� ���� ���� �ʰ�");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int u, int v) {
	GraphNode* node;
	if (u >= g->n || v >= g->n)
	{
		fprintf(stderr, "�׷��� ���� ��ȣ ����");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}

int in_degree[MAX_VERTICES];
int removed[MAX_VERTICES];

int remove_zero_vertex(GraphType* g) {
	GraphNode* node;

	printf("in_degree[]: ");
	for (int i = 0; i < g->n; i++) {
		printf("%d ", in_degree[i]);
	}
	printf("\n");

	printf("removed[]: ");
	for (int i = 0; i < g->n; i++) {
		printf("%d ", removed[i]);
	}
	printf("\n\n");

	for (int i = 0; i < g->n; i++) {
		//�������� ���� �����̸鼭 �������� 0�� ��������
		if (removed[i] == 0 && in_degree[i] == 0) {
			removed[i] = 1;
			node = g->adj_list[i];
			while (node != NULL) {
				int w = node->vertex;
				//���õ� ������ ����� ������ �������� ���ҽ�Ŵ
				in_degree[w]--;
				node = node->link;
			}
			return i;
		}
	}
	return -1;
}

int topo_sort(GraphType* g) {
	int i;
	GraphNode* node;
	int index;

	// �迭 �ʱ�ȭ
	for (i = 0; i < g->n; i++) {
		in_degree[i] = 0;
		removed[i] = 0;
	}
	// in_degree �� ����
	for (i = 0; i < g->n; i++) {
		GraphNode* node = g->adj_list[i];
		while (node != NULL){
			in_degree[node->vertex]++;
			node = node->link;
		}
	}

	while ((index = remove_zero_vertex(g)) != -1) {
		printf("���� %d����\n", index);
	}
	printf("\n");
	
	int sum_indegree = 0;
	int sum_removed = 0;
	for (i = 0; i < g->n; i++) {
		sum_indegree += in_degree[i];
		sum_removed += removed[i];
	}

	if (sum_indegree != 0 && sum_removed != g->n)
		return(FALSE);
	else
		return(TRUE);
}


int main() {
	GraphType g;

	graph_init(&g);
	insert_vertex(&g, 0);
	insert_vertex(&g, 1);
	insert_vertex(&g, 2);
	insert_vertex(&g, 3);
	insert_vertex(&g, 4);
	insert_vertex(&g, 5);

	insert_edge(&g, 0, 2);
	insert_edge(&g, 0, 3);
	insert_edge(&g, 1, 3);
	insert_edge(&g, 1, 4);
	insert_edge(&g, 2, 0);
	insert_edge(&g, 2, 3);
	insert_edge(&g, 2, 5);
	insert_edge(&g, 3, 5);
	insert_edge(&g, 4, 5);

	

	//in_degree[] ���� ���� 0�� �ƴϰ�, removed[] ���� ���� 1�� �ƴ� ��� = ���� ������ �������� �ʽ��ϴ�..
	if (topo_sort(&g))
		printf("���� ������ �����մϴ�.\n");
	else
		printf("���� ������ �������� �ʽ��ϴ�.\n");

	return 0;
}
