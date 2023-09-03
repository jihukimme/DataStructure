#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES  20	
#define INF 1000 // 무한대 (연결이 없는 경우)

typedef struct GraphType {
	int n;	// 정점의 개수
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int prev_node[MAX_VERTICES]; // 마지막 경유 노드
int distance[MAX_VERTICES]; // 시작정점으로부터의 최단경로 거리 
int found[MAX_VERTICES]; // 방문한 정점 표시 

int choose(int distance[], int n, int found[]) {
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++)
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	return minpos;
}

void print_status(GraphType* g) {
	static int step = 1;
	printf("STEP %d: ", step++);
	printf("distance: ");
	for (int i = 0; i < g->n; i++) {
		if (distance[i] == INF)
			printf(" * ");
		else
			printf("%2d ", distance[i]);
	}
	printf("\n");
	printf("        found:    ");
	for (int i = 0; i < g->n; i++)
		printf("%2d ", found[i]);
	printf("\n");
	printf("    prev_node:    ");
	for (int i = 0; i < g->n; i++)
		printf("%2d ", prev_node[i]);
	printf("\n\n");
}


void shortest_path(GraphType* g, int start, int dest) // 목적지
{
	int i, u, w;
	for (i = 0; i < g->n; i++) // 초기화 
	{
		distance[i] = g->weight[start][i];
		found[i] = FALSE;
		prev_node[i] = start;
	}
	found[start] = TRUE; // 시작 정점 방문 표시
	distance[start] = 0;
	for (i = 0; i < g->n; i++) {
		print_status(g);// distance, found, prev_node

		u = choose(distance, g->n, found);
		found[u] = TRUE;
		if (u == dest) break;

		for (w = 0; w < g->n; w++)
			if (!found[w])
				if (distance[u] + g->weight[u][w] < distance[w])
				{
					distance[w] = distance[u] + g->weight[u][w];
					prev_node[w] = u; // 직전 경유 노드 저장
				}
	}
}

void print_shortes_path(GraphType* g, int start, int dest) {
	printf("%d부터 %d까지의 최단경로 경유노드: ", start, dest);
	printf("%d->", start);
	//prev_node[dest]-> prev_node[prev_node[dest]]-> prev_node[prev_node[prev_node[dest]]] ...의 역순
	int arr[MAX_VERTICES] = { NULL };//역순으로 출력하기 위해 배열선언
	int count = 0;
	int j = prev_node[dest];
	for (int i = 0; i < g->n; i++) {
		if (start == j)
			break;
		arr[count] = j;
		count++;
		j = prev_node[j];
	}
	//출력
	for (int i = count-1; i >= 0; i--) {
		printf("%d->", arr[i]);
	}
	printf("%d\n", dest);
	
	printf("%d부터 %d까지의 최단경로: ", start, dest);
	printf("%d\n", distance[dest]);
}

int main(void) {
	GraphType g = { 7,
	{{ 0,  7,  INF, INF,   3,  10, INF },
	{ 7,  0,    4,  10,   2,   6, INF },
	{ INF,  4,    0,   2, INF, INF, INF },
	{ INF, 10,    2,   0,  11,   9,   4 },
	{ 3,  2,  INF,  11,   0, INF,   5 },
	{ 10,  6,  INF,   9, INF,   0, INF },
	{ INF, INF, INF,   4,   5, INF,   0 } }
	};

	int start = 0, dest = 3;
	shortest_path(&g, start, dest);
	// start에서 dest까지 최단경로의 길이, 경로
	print_shortes_path(&g, start, dest);

	return 0;
}