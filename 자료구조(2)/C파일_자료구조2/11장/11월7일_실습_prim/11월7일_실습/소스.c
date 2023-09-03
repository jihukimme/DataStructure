//Ư�� �������� �����ϴ� �ּҺ�� ����Ʈ�� 
//prim�˰���
//���õ� �������� Ȯ���ϴ� �˰���


#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000

typedef struct GraphType {
	int n;	// ������ ����
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];

// �ּ� dist[v] ���� ���� ������ ��ȯ
int get_min_vertex(int n){ //n�� ��������
	int v, i; 
	for (i = 0; i < n; i++)
		if (!selected[i]) { //i�� ���õȰ� �ƴϸ�
			v = i;
			break;
		}
	for (i = 0; i < n; i++) {
		if (!selected[i] && (distance[i] < distance[v])) //i�� ���õȰ� �ƴϰ� v�� �Ÿ����� �۴ٸ�
			v = i; 
	}
	return (v);
}


void prim(GraphType* g, int s){
	int i, u, v;

	for (u = 0; u < g->n; u++)
		distance[u] = INF; //�Ÿ� �ʱ�ȭ
	distance[s] = 0; //�������� �Ÿ��� 0����

	for (i = 0; i < g->n; i++) {
		u = get_min_vertex(g->n); //u�� �ּҰŸ� ������ ����
		selected[u] = TRUE; //u�� ����

		if (distance[u] == INF) 
			return;
		
		printf("���� %d �߰�\n", u);
		for (v = 0; v < g->n; v++) {
			if (g->weight[u][v] != INF) {
				if (!selected[v] && g->weight[u][v] < distance[v]) {
					distance[v] = g->weight[u][v];
				}
			}
		}

		//select���
		printf("selected[%d]: ", u);
		for (int j = 0; j < g->n; j++) {
			printf("%d ", selected[j]);
		}

		//distance���
		printf("\ndistance[%d]: ", u);
		for (int j = 0; j < g->n; j++) {
			if (distance[j] == INF)
				printf("INF ");
			else
				printf("%d ", distance[j]);
		}
		printf("\n");
		printf("\n");
	}
}

int main(void){
	GraphType g = { 7,
	{{ 0, 29, INF, INF, INF, 10, INF },
	{ 29,  0, 16, INF, INF, INF, 15 },
	{ INF, 16, 0, 12, INF, INF, INF },
	{ INF, INF, 12, 0, 22, INF, 18 },
	{ INF, INF, INF, 22, 0, 27, 25 },
	{ 10, INF, INF, INF, 27, 0, INF },
	{ INF, 15, INF, 18, 25, INF, 0 } }
	};

	GraphType g2 = { 7,
	{{ 0,  7,  INF, INF,   3,  10, INF },
	{ 7,  0,    4,  10,   2,   6, INF },
	{ INF,  4,    0,   2, INF, INF, INF },
	{ INF, 10,    2,   0,  11,   9,   4 },
	{ 3,  2,  INF,  11,   0, INF,   5 },
	{ 10,  6,  INF,   9, INF,   0, INF },
	{ INF, INF, INF,   4,   5, INF,   0 } }
	};


	prim(&g2, 1);

	return 0;
}