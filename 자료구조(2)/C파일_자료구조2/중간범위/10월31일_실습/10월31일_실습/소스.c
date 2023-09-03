//인접리스트 원형리스트버전
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10
typedef struct GraphNode
{
	int vertex;
	struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
	int n;	// 정점의 개수
	GraphNode* adj_list[MAX_VERTICES];
} GraphType;

// 그래프 초기화 
void init(GraphType* g)
{
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
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

// 간선 삽입 연산, u에서 v, v에서 u의 간선을 입력
void insert_edge_last(GraphType* g, int u, int v)
{
	GraphNode* node, * node2;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
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
		printf("정점 %d의 인접 리스트 ", i);

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
	visited[v] = 1; //정점 v에 방문 
	printf("정점 %d -> ", v); //방문한 정점 출력
	for (w = g->adj_list[v]->link; w != g->adj_list[v]; w = w->link) //인접 정점 탐색
		if (visited[w->vertex] != 1) //만약 해당 정점에 방문하지 않았다면
			dfs_list(g, w->vertex);	 //정점 w에서 다시 깊이우선탐색
}

int main()
{
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	for (int i = 0; i < 6; i++)
		insert_vertex(g, i);

	//간선 삽입
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
	
	

	//인접리스트 출력
	printf("인접리스트 \n");
	print_adj_list(g);
	printf("\n=====================\n");

	//깊이탐색 과정 출력
	printf("정점 0을 기준으로 깊이탐색 \n");
	dfs_list(g, 0);
	free(g);

	return 0;
}
