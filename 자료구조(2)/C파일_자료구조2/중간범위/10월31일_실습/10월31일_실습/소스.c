//��������Ʈ ��������Ʈ����
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10
typedef struct GraphNode
{
	int vertex;
	struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
	int n;	// ������ ����
	GraphNode* adj_list[MAX_VERTICES];
} GraphType;

// �׷��� �ʱ�ȭ 
void init(GraphType* g)
{
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
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

// ���� ���� ����, u���� v, v���� u�� ������ �Է�
void insert_edge_last(GraphType* g, int u, int v)
{
	GraphNode* node, * node2;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "�׷���: ���� ��ȣ ����");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node2 = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node2->vertex = u;

	if (g->adj_list[u] == NULL) {
		g->adj_list[u] = node;
		node->link = g->adj_list[u];
	}
	else {
		node->link = g->adj_list[u]->link;
		g->adj_list[u]->link = node;
		g->adj_list[u] = node;
	}
	if (g->adj_list[v] == NULL) {
		g->adj_list[v] = node2;
		node2->link = g->adj_list[v];
	}
	else {
		node2->link = g->adj_list[v]->link;
		g->adj_list[v]->link = node2;
		g->adj_list[v] = node2;
	}
}


void print_adj_list(GraphType* g)
{
	for (int i = 0; i < g->n; i++) {
		GraphNode* p = g->adj_list[i]->link;
		printf("���� %d�� ���� ����Ʈ ", i);

		do {
			printf("-> %d ", p->vertex);
			p = p->link;
		}while (p != g->adj_list[i]->link);
		
		printf("\n");
	}
}

int visited[MAX_VERTICES];
void dfs_list(GraphType* g, int v)
{
	GraphNode* w;
	visited[v] = 1; //���� v�� �湮 
	printf("���� %d -> ", v); //�湮�� ���� ���
	for (w = g->adj_list[v]->link; w != g->adj_list[v]; w = w->link) //���� ���� Ž��
		if (visited[w->vertex] != 1) //���� �ش� ������ �湮���� �ʾҴٸ�
			dfs_list(g, w->vertex);	 //���� w���� �ٽ� ���̿켱Ž��
}

int main()
{
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	for (int i = 0; i < 6; i++)
		insert_vertex(g, i);

	//���� ����
	insert_edge_last(g, 0, 1);
	insert_edge_last(g, 0, 2);
	insert_edge_last(g, 0, 3);
	insert_edge_last(g, 1, 0);
	insert_edge_last(g, 1, 4);
	insert_edge_last(g, 2, 0);
	insert_edge_last(g, 2, 3);
	insert_edge_last(g, 2, 4);
	insert_edge_last(g, 2, 5);
	insert_edge_last(g, 3, 0);
	insert_edge_last(g, 3, 2);
	insert_edge_last(g, 3, 5);
	insert_edge_last(g, 4, 1);
	insert_edge_last(g, 4, 2);
	insert_edge_last(g, 4, 5);
	insert_edge_last(g, 5, 2);
	insert_edge_last(g, 5, 3);
	insert_edge_last(g, 5, 4);
	
	

	//��������Ʈ ���
	printf("��������Ʈ \n");
	print_adj_list(g);
	printf("\n=====================\n");

	//����Ž�� ���� ���
	printf("���� 0�� �������� ����Ž�� \n");
	dfs_list(g, 0);
	free(g);

	return 0;
}
