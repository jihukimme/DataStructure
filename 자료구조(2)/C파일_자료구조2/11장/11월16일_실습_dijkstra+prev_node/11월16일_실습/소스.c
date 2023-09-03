#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES  20	
#define INF 1000 // ���Ѵ� (������ ���� ���)

typedef struct GraphType {
	int n;	// ������ ����
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int prev_node[MAX_VERTICES]; // ������ ���� ���
int distance[MAX_VERTICES]; // �����������κ����� �ִܰ�� �Ÿ� 
int found[MAX_VERTICES]; // �湮�� ���� ǥ�� 

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


void shortest_path(GraphType* g, int start, int dest) // ������
{
	int i, u, w;
	for (i = 0; i < g->n; i++) // �ʱ�ȭ 
	{
		distance[i] = g->weight[start][i];
		found[i] = FALSE;
		prev_node[i] = start;
	}
	found[start] = TRUE; // ���� ���� �湮 ǥ��
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
					prev_node[w] = u; // ���� ���� ��� ����
				}
	}
}

void print_shortes_path(GraphType* g, int start, int dest) {
	printf("%d���� %d������ �ִܰ�� �������: ", start, dest);
	printf("%d->", start);
	//prev_node[dest]-> prev_node[prev_node[dest]]-> prev_node[prev_node[prev_node[dest]]] ...�� ����
	int arr[MAX_VERTICES] = { NULL };//�������� ����ϱ� ���� �迭����
	int count = 0;
	int j = prev_node[dest];
	for (int i = 0; i < g->n; i++) {
		if (start == j)
			break;
		arr[count] = j;
		count++;
		j = prev_node[j];
	}
	//���
	for (int i = count-1; i >= 0; i--) {
		printf("%d->", arr[i]);
	}
	printf("%d\n", dest);
	
	printf("%d���� %d������ �ִܰ��: ", start, dest);
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
	// start���� dest���� �ִܰ���� ����, ���
	print_shortes_path(&g, start, dest);

	return 0;
}