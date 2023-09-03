#include<stdio.h>
#include<stdlib.h>
#define TURE 1
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
		fprintf(stderr, "그래프 정점 개수 초과");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int u, int v) {
	GraphNode* node;
	if (u >= g->n || v >= g->n)
	{
		fprintf(stderr, "그래프 정점 번호 오류");
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
	for (int i = 0; i < g->n; i++) {
		if (removed[i] == 0 && in_degree[i] == 0) {
			removed[i] = 1;
			node = g->adj_list[i];
			while (node != NULL) {
				int w = node->vertex;
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

	// 배열 초기화
	for (i = 0; i < g->n; i++) {
		in_degree[i] = 0;
		removed[i] = 0;
	}
	// in_degree 값 설정
	for (i = 0; i < g->n; i++) {
		GraphNode* node = g->adj_list[i];
		while (node != NULL){
			in_degree[node->vertex]++;
			node = node->link;
		}
	}
	printf("in_degree[]: ");
	for (i = 0; i < g->n; i++) {
		printf("%d ", in_degree[i]);
	}
	printf("\n");

	while ((index = remove_zero_vertex(g)) != -1) {
		printf("정점 %d -> ", index);
	}
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
	/*
	insert_edge(&g, 0, 2);
	insert_edge(&g, 0, 3);
	insert_edge(&g, 1, 3);
	insert_edge(&g, 1, 4);
	insert_edge(&g, 2, 3);
	insert_edge(&g, 2, 5);
	insert_edge(&g, 3, 5);
	insert_edge(&g, 4, 5);
	*/

	insert_edge(&g, 0, 1);
	insert_edge(&g, 0, 2);
	insert_edge(&g, 0, 3);
	insert_edge(&g, 1, 4);
	insert_edge(&g, 2, 4);
	insert_edge(&g, 2, 5);
	insert_edge(&g, 3, 5);

	topo_sort(&g);

	return 0;
}
