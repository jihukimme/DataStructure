
/*

#include <stdio.h>
#include <stdlib.h>


void quiz(int a, int b, int*sum, int*diff);

int main(void) {

	int sum = 0;
	int diff = 0;

	quiz(10, 10, &sum, &diff);

	printf("sum = %d, diff = %d \n", sum, diff);



	return 0;
}



void quiz(int a, int b, int*sum, int*diff) {


	*sum = a + b;
	*diff = a - b;



}

*/



/*

#include<stdio.h>
#include<stdlib.h>



void hello(int n) {

	if (n == 0)
		return;

	printf("hello\n");

	hello(--n);

}



int main(void) {

	hello(5);


	return 0;
}


*/

/*

#include<stdio.h>
#include<stdlib.h>



void funcA(int n) {

	int a = 20;

	if (n == 0) {
		a = 30;
		return;
	}

	funcA(--n);


}

int main(void) {

	int m = 10;
	funcA(5);




	return 0;
}

*/

/*

#include <stdio.h>
#include <stdlib.h>


void print_hello(int n) {

	printf("hello\n");

	if (n == 1)
		return;
	else {
		print_hello(n-1);
	}



}

int main(void) {


	print_hello(5);



	return 0;
}

*/
/*

#include<stdio.h>
#include<stdlib.h>


void hello(int n) {

	if (n == 0)
		return;

	printf("hello\n");


	hello(--n);



}

int main(void) {


	hello(5);

	return 0;
}
*/


/*

#include <stdio.h>
#include <stdlib.h>

int sum(int a, int b) {



	if (a == b)
		return;
	else
		return(a + sum(a + 1, b));

}



int main(void) {
	printf("%d\n", sum(1, 1));
	printf("%d\n", sum(2, 2));
	printf("%d\n", sum(3, 3));


	printf("%d\n", sum(1, 2));
	printf("%d\n", sum(1, 3));

	printf("%d\n", sum(2, 5));
	printf("%d\n", sum(3, 5));

	return 0;
}

*/
/*
#include <stdio.h>
#include <stdlib.h>


void product(int table, int first, int last) {

	if (first > last)
		return;


	printf("%d X %d = %d\n", table, first, table * first);
	product(table, first + 1, last); //ó������ ���ϰ��� �ϴ� ���� 1�� �����ϵ��� ���� -> ���������� ���ϰ��� �ϴ� ������ Ŀ���� return��Ű���� ����
}


int main(void) {

	int table; //���ϰ��� �ϴ� ������
	int first_num; //���ϰ��� �ϴ� ���� ó�� ���� ��
	int last_num; //���ϰ��� �ϴ� ���� ������ ���� ��


	//����ڷκ��� �Է��� �޾� ��
	printf("���ϰ��� �ϴ� ���� �Է��ϼ���: ");
	scanf_s("%d", &table);
	printf("\n!!ó�� ���� ���� ������ ���� ������ Ŭ �� ����!!\n"); //ó�� ���� ���� ������ ���� ������ Ŭ �� ����

	printf("���ϰ��� �ϴ� ���� ó�� �������� �Է��ϼ���: ");
	scanf_s("%d", &first_num);
	printf("���ϰ��� �ϴ� ���� ������ �������� �Է��ϼ���: ");
	scanf_s("%d", &last_num);

	printf("\n\n\n======================%d���� %d���� %d������ ��� ��==========================\n", table, first_num, last_num);

	//������� ������������ product�Լ� ����
	product(table, first_num, last_num);

	return 0;
}
*/


/*

#include <stdio.h>
#include <stdlib.h>


int get_max(int* a, int value) {

	int largest = a[0];

	for (int i = 0; i < 10; i++){

		if (largest < a[i]) {
			largest = a[i];
		}
	}

	return largest;

}

int main(void) {

	int arr[10] = { 1,2,3,1,2,9,4,5,6};

	printf("%d", get_max(arr, 10));

	return 0;
}
*/

/*

#include <stdio.h>
#include <stdlib.h>


int sum(int num1, int num2) {

	int sum = num1 + num2;

	return sum;
}

int sum_total(int num1, int num2) {

	if (num1 == num2)
		return;

	return (num1 + sum_total(num1 + 1, num2));
}

int fac(int i) {

	if (i ==1)
		return 1;

	return i * fac(i-1);

}

int main(void) {

	printf("%d\n", sum(1, 8));
	printf("%d\n", sum_total(1, 10));
	printf("%d\n", fac(10));


	return 0;
}

*/

/*

#include <stdio.h>
#include <stdlib.h>


int power(int x, int n) {

	if (n == 0)
		return 1;

	else
		return x * power(x, n - 1);

}

int main(void) {

	printf("%d", power(2, 4));



	return 0;
}

*/

/*
#include <stdio.h>
#include <stdlib.h>


int get_max(int* list, int size) {

	if (size == 0)
		return list[size];
	

	int max = get_max(list, size - 1);

	if (list[size] > max)
		max = list[size];

	

	return max;

}
int main(void) {

	int arr[10] = { 13,14,2,4,21,32,42,5,2,9 };


	printf("%d", get_max(arr,10));


	return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

int power(int x, int n) {

	if (n == 0)
		return 1;

	else if (n % 2 == 0) {
		return power(x * x, n / 2);
	}
	else
		return x * power(x * x, (n - 1) / 2);

}

int main(void) {

	printf("%d\n", power(2, 4));
	printf("%d", power(3, 5));

	return 0;
}

*/

/*

#include <stdio.h>
#include <stdlib.h>

int fib(int n) {

	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	return(fib(n - 1) + fib(n - 2));
}

int main(void) {

	printf("%d", fib(6));

	return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

int fib(int n) {

	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	int p = 0;
	int pp = 1;
	int result = 0;

	for (int i = 2; i <= n; i++) {
		result = p + pp;
		p = pp;
		pp = result;
	}
	return result;
}

int main(void) {

	printf("%d", fib(7));

	return 0;
}
*/



/*
#include <stdio.h>
#include <stdlib.h>



void draw_star(int n) {
	
	
	if (n == 0) {
		printf("\n");
		return;	
	}

	else {
		printf("*");
		draw_star(n - 1);
	}
	
}


int get_sum(int num1, int num2) {
	
	if (num1 == num2) {
		return;
	}
	return (num1 + get_sum(num1 + 1, num2));
}



int main(void) {

	draw_star(3);
	draw_star(5);
	
	printf("1+2       =%d\n", get_sum(1, 2));
	printf("1+2+3     =%d\n", get_sum(1, 3));
	printf("1+2+3+4   =%d\n", get_sum(1, 4));

	return 0;
}

*/

/*

#include <stdio.h>
#include <stdlib.h>



int main(void) {

	int floor;

	scanf_s("%d", &floor);


	for (int i = 1; i <= floor; i++) {

		for (int j = floor; j > i; j--) {
			printf(" ");
		}

		for (int z = 1; z <= i; z++) {
			printf("*");
		}
		for (int c = 2; c <= i; c++) {
			printf("*");
		}

		printf("\n");
	}

	

	return 0;
}

*/

/*

#include <stdio.h>
#include <stdlib.h>


void print_p(int n) {

	if (n == 0) {
		printf("\n");
		return;
	}
	
	printf("*");
	print_p(n - 1);

}

void pira(int s, int  m) {

	if (s == m) {
		return;
	}
	
	print_p(s);
	pira(s + 1, m);




}
int main(void) {

	pira(1, 10);


	return 0;
}


*/


/*

#include <stdio.h>
#include <stdlib.h>

void star(int x, int y, int size)
{

	if ((x / size) % 3 == 1 && (y / size) % 3 == 1) {
		printf(" ");
	}
	else {
		if (size / 3 == 0) {
			printf("*");
		}
		else
			star(x, y, size / 3);
	}
}


int main(void) {

	int num = 0;
	scanf_s("%d", &num);

	for (int a = 0; a < num; a++) {

		for (int b = 0 ; b < num; b++) {
			star(a, b, num);
		}
		printf("\n");
	}


	return 0;
}


*/

/*
#include<stdio.h>
#include<stdlib.h>

int main(void) {

	for (int i = 1; i <= 10; i++) {

		for (int j = 10; j > i; j--) {
			printf(" ");
		}
		
		for (int z = 1; z <= i; z++) {
			printf("*");
		}
		for (int k = 1; k <= i-1; k++) {
			printf("*");
		}

		printf("\n");
	}

	return 0;
}

*/


/*
#include <stdio.h>
#include <stdlib.h>


void get_num_seq(int num) {
	
	if (num < 10)
		printf("%d\n", num);

	else {
		get_num_seq(num / 10);
		printf("%d\n", num % 10);
	}

}

 int main(void) {
	
	 get_num_seq(2534);
		
	return 0;
	
}
*/

/*

#include <stdio.h>
#include <stdlib.h>



int main(void) {

	int n;
	scanf_s("%d", &n);

	int input[20];
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &input[i]);
	}

	int max = input[0];

	for (int j = 0; j < n; j++) {

		if (input[j] > max)
			max = input[j];

	}

	printf("%d\n", max);

	return 0;
}

*/

/*

#include <stdio.h>
#include <stdlib.h>


int get_max(int size, int* arr) {

	if (size == 0) {
		return arr[size];
	}

	int max = arr[size - 1];

	if (max < arr[size])
		max = arr[size];

	return max;
}

int main(void) {

	int n = 5;
	int arr[5] = { 14,24,23,25,32 };

	printf("%d\n", get_max(n, arr));


	return 0;
}


*/
/*

#include <stdio.h>
#include <stdlib.h>


int main(void) {

	int size;
	scanf_s("%d", &size);

	int arr1[1000] = { 0 };
	int arr2[1000] = { 0 };

	for (int i = 0; i < size; i++) {
		scanf_s("%d %d", &arr1[i], &arr2[i]);
	}

	int sum_arr[1000] = { 0 };

	for (int j = 0; j < size; j++) {
		sum_arr[j] = arr1[j] + arr2[j];
	}

	for (int z = 0; z < size; z++) {
		printf("Case #%d: %d\n", z + 1, sum_arr[z]);
	}
	


	return 0;
}
*/


/*
#include <stdio.h>
#include <stdlib.h>


int main(void) {

	int size;
	scanf_s("%d", &size);


	int arr1[100] = { 0 };
	int arr2[100] = { 0 };

	for (int i = 0; i < size; i++) {
		scanf_s("%d", &arr1[i]);
	}
	for (int i = 0; i < size; i++) {
		scanf_s("%d", &arr2[i]);
	}

	int tmp = 0;

	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size- 1 - i; j++)
		{
			if (arr1[j] > arr1[j + 1]) {
				tmp = arr1[j];
				arr1[j] = arr1[j + 1];
				arr1[j + 1] = tmp;
			}
				

			if (arr2[j] < arr2[j + 1]) {
				tmp = arr2[j];
				arr2[j] = arr2[j + 1];
				arr2[j + 1] = tmp;
			}
				
		}
	}

	
	int S = 0;

	for (int i = 0; i < size; i++)
		S = S + (arr1[i] * arr2[i]);

	printf("%d\n", S);


	return 0;
}
*/


/*
#include <Stdio.h>
#include <stdlib.h>

struct person {
	char name[100];
	int age;
	double height;
};


int main(void) {
	
	struct person p[5] = { { "������", 23, 3.7 }, {"������", 22, 3.5}, {"������", 22, 3}, {"������", 21, 2}, {"�ȶ���", 22, 4.2} };
	
	for (int i = 0; i < 5; i++) {
		printf("%s�� ������ %lf�Դϴ�.\n", p[i].name, p[i].height);
	}

	struct person* p1 = (struct person*)malloc(sizeof(struct person)*5);
	
	p1->age = 22;
	(p1 + 1)->age = 23;
	(p1 + 2)->age = 21;
	(p1 + 3)->age = 20;
	(p1 + 4)->age = 19;

	for (int i = 0; i < 5; i++) {
		printf("%d\n", (p1 + i)->age);
	}

	return 0;
}
*/


/*
#include <Stdio.h>
#include <stdlib.h>

struct person {
	char name[10];
	int age;
	float height;

	struct person* p;

};

int main(void) {
	struct person* p1 = (struct person*)malloc(sizeof(struct person));
	p1->p = (struct person*)malloc(sizeof(struct person));
	p1->p->p = (struct person*)malloc(sizeof(struct person));

	
	return 0;
}
*/

/*
#include <Stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
	char name[10];
	int age;
	float height;

	struct person* next;

};


int main(void) {

	struct person* p1 = (struct person*)malloc(sizeof(struct person));
	struct person* p2 = (struct person*)malloc(sizeof(struct person));
	

	
	strcpy((*p1).name, "kim");
	p1->age = 21;
	p1->next = p2;

	strcpy((*p2).name, "park");
	p2->age = 23;

	

	struct person* p = 0;
	for (p = p1; p!= 0; p = p->next) {
		printf("%s�� ���̴� %d�Դϴ�.\n", p->name, p->age);
	}


	return 0;
}

*/

/*
#include <stdio.h>
#include <stdlib.h>
#define MAX 7	 	//ũ�� ����

typedef struct {
	int degree[MAX];		//����� �޴� �迭
	int coef[MAX];		//������ �޴� �迭
}Poly;

Poly add_poly(Poly f, Poly g) {
	Poly c = { {0}, {0} };
	int count = 0;	//Poly c�� f�� g�� ���� �����ϱ� ���ؼ� ���
	int tmp = 0;	//f�� g�� ������ Poly c�� ������������ �迭�ϱ� ���ؼ� ���

	//Poly c�� f�� �����ϴ� for��
	for (int i = 0; i < MAX; i++) {
		c.coef[i] = f.coef[i];
		c.degree[i] = f.degree[i];
		if (c.coef[i] == 0 && c.degree[i] == 0) {
			break;
		}
		else
			count++;
		//f�� ������ �� �޺κп� g�� �����ϱ� ���ؼ� count�� ������Ŵ
	}
	for (int i = 0; i < MAX; i++) {
		c.coef[i + count] = g.coef[i];
		//g�� c��, f�� ������ �� �� �޺κп� ����
		c.degree[i + count] = g.degree[i];

		if (c.coef[i + count] == 0 && c.degree[i + count] == 0)
			//c�� �����Ұ� ���� �� ����
			break;
	}


	//c�� ���� �� coef, degree�迭�� ������������ ����
	for (int i = 0; i < MAX - 1; i++) {
		for (int j = 0; j < MAX - 1 - i; j++) {
			if (c.coef[j] < c.coef[j + 1]) {
				tmp = c.coef[j];
				c.coef[j] = c.coef[j + 1];
				c.coef[j + 1] = tmp;

				tmp = c.degree[j];
				c.degree[j] = c.degree[j + 1];
				c.degree[j + 1] = tmp;
			}
		}
	}

	//������������ ���� �� coef�� ���� ���� ��� coef�� �ϳ����ϰ� �׿� �´� degree�� ���ϵ��� ����
	for (int i = 0; i < MAX; i++) {

		if (c.coef[i] == c.coef[i + 1]) {
			tmp = c.degree[i + 1];
			c.degree[i + 1] = 0;
			c.degree[i] = tmp + c.degree[i];

			c.coef[i + 1] = 0;
		}
	}



	return c;

}

void print_poly(Poly result) {
	//����ü Poly result�� ����ϴ� �Լ� print_poly
	for (int i = 0; i < MAX; i++) {
		//����� 0�� ��� 0������ ������� �ʵ��� ����
		if (result.degree[i] == 0) {
			continue;
		}
		//������ 0�� ��� ����� ����ϵ��� ����
		else if (result.coef[i] == 0) {
			printf("%d", result.degree[i]);
		}

		else {
			printf("%dx^%d + ", result.degree[i], result.coef[i]);
		}
	}
	printf("\n");
}

int main(void) {
	// f, g, �� ���� �ڵ�...
	Poly f = { {1,1,1}, {100,2,0} };
	//f(x) = x ^ 100 + x ^ 2 + 1�� ����� �����ϴ� �迭��, ������ �����ϴ� �迭�� ������ �����ϴ� ����ü Poly f����
	Poly g = { {1,2}, {1000, 0} };
	//g(x) = x ^ 1000 + 2       �� ����� �����ϴ� �迭��, ������ �����ϴ� �迭�� ������ �����ϴ� ����ü Poly g����
	Poly result;
	result = add_poly(f, g);	//result�� add_poly�� ���ؼ� f(x) + g(x)�� ���� ����
	print_poly(result);	//print_poly�� ���ؼ� result�� ���

	return 0;
}

���׽� ���� ���α׷�
*/


/*
#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int size;
	int top;
	int* data;
	int pop_num; //pop�� ���� ����
}stack;

void create(stack* s, int size) {
	//size��ŭ data�� int�� �޸��Ҵ�
	s->data = (int*)malloc(size * sizeof(int));
	s->top = -1;
	s->size = size;
}

//s->top = -1�϶� ������ ����ִ� ����
int is_empty(stack* s) {
	return(s->top = -1);
}
//������ ���� ���
int is_full(stack* s) {
	return ((s->top) == (s->size - 1));
}


void push(stack* s, int item) {
	//������ ���� ũ�⸸ŭ push
	if (s->top < s->size - 1) {
		s->top++;
		s->data[s->top] = item;
		printf("push�߽��ϴ�: %d\n", item);
	}
	//������ ũ�⸦ �ʰ��� �� ������ ũ�⸦ Ű����
	else{
		s->size = s->size * 2;
		s->data = (int*)realloc(s->data, s->size * sizeof(int));
		push(s, item);
	}
}

int pop(stack* s) {
	printf("\npop: ");
	//pop��Ŵ
	if (s->top >= 0) {
		int value;
		value = s->data[s->top];
		s->top--;

		s->pop_num = value;

		return s->pop_num;
	}
	//������ ������� ��Ÿ��
	if (is_empty(s)) {
		printf("������ ������ϴ�.\n");

		return 0;
	}
}


int main(void) {
	stack s;


	create(&s, 3); //stack�� 3�� ����

	push(&s, 10);
	push(&s, 20);
	push(&s, 30);
	push(&s, 40); //push �Լ����� ������ stack ������ �ʰ��Ͽ��� �� �޸𸮸� �߰��� �Ҵ��ϵ��� ����
	push(&s, 50);
	push(&s, 60);
	push(&s, 70);

	for (int i = 0; i < 7; i++) {
		printf("%d\n", pop(&s));
	}

	pop(&s);//stack�� �����ִ°� ���� �� pop�ϸ� �� �̻� pop ��������


	return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct QuizInt {

	int oddNum;//Ȧ��

	int evenNum;//¦��

};

void DoMallocQuiz(char* c, int n) {

	//1. DoMallocQuiz �Լ��� ù��° ���ڷ� ���� ���ڿ� ���
	printf("\n%s\n", c);

	//2. Heap ������ struct QuizInt ���� �迭�� �Ҵ� (ũ��: n)
	struct QuizInt* a = (struct QuizInt*)malloc(sizeof(struct QuizInt) * n);

	//3. oddNum �� ������ Ȧ���� �ְ�, evenNum �� ������ ¦���� �ִ´�.
	srand(time(NULL));

	int num = 0;
	//evenNum
	for (int i = 0; i < n; i++) {
		num = rand() % 20;
		if (num % 2 == 0)
			a[i].evenNum = num;
		else
			i--;
	}
	//�ߺ��Ǵ� ���ڰ� ������� �ٽ� �������� ���� �޾ƿ´�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				continue;
			}
			else
			{
				num = rand() % 20;

				if (num % 2 == 0)
					a[j].evenNum = num;
				else
					j--;
			}
		}
	}

	//oddNum
	for (int i = 0; i < n; i++) {
		num = rand() % 20;
		if (num % 2 == 1)
			a[i].oddNum = num;
		else
			i--;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (a[i].oddNum == a[j].oddNum) {
				do {
					num = rand() % 20;

					if (num % 2 == 1)
						a[j].oddNum = num;
					else
						j--;
				} while (a[i].oddNum != a[j].oddNum);

			}
		}
	}





	//(���� ���� : 0 - 19, ��, �� �� ����� ���ڴ� �ٽ� ���� �� ����)

	//4. �Ʒ� ������� ���.
	printf("ODD: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i].oddNum); //oddNum�� main�Լ����� �Է��� ũ�⸸ŭ ���
	}
	printf("\nEVEN: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i].evenNum);//evenNum�� main�Լ����� �Է��� ũ�⸸ŭ ���
	}
	printf("\n");
}

int main(int argc, char* argv[]) {

	DoMallocQuiz("5 random numbers", 5);

	DoMallocQuiz("4 random numbers", 4);

	return 0;

}
*/

/*            ��������
#include <stdio.h>
#include <stdlib.h>

int main() {

	char* str = malloc(sizeof(char)*101);

	scanf("%s", str);

	int count = 0;

	for (int i = 0; i < 101; i++) {
		if (str[i] == 'a' || str[i] == 'i' || str[i] == 'e'|| str[i] == 'o' || str[i] == 'u')
			count++;
	}

	printf("%d", count);

	return 0;
}
*/

/*         �����б�
#include <stdio.h>
#include <stdlib.h>

int main() {

	char* arr[5] = { 0 };

	for (int i = 0; i < 5; i++) {
		arr[i] = (char*)malloc(sizeof(char) * 15);

		scanf("%s", arr[i]);
	}

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[j][i] != 0)
				printf("%c", arr[j][i]);
		}
	}


	return 0;
}
*/


/* ÿ��
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int n, p;

	scanf("%d", &n);

	char*** name;
	name = (char***)malloc(sizeof(char***) * 100);
	double** price;
	price = (double**)malloc(sizeof(double**) * 100);
	double** max;
	max = (double**)malloc(sizeof(double**) * 100);

	int index[100];

	int i, j;

	for (i = 0; i < n; i++) {
		max[i] = (double*)malloc(sizeof(double) * 100);
		price[i] = (double*)malloc(sizeof(double) * 100);
		name[i] = (char**)malloc(sizeof(char*) * 100);
	}

	for (i = 0; i < n; i++) {

		scanf("%d", &p);
		for (j = 0; j < p; j++) {
			max[i][j] = 0;
			name[i][j] = (char*)malloc(sizeof(char) * 21);
			scanf("%lf %s", &price[i][j], &name[i][j][0]);

			if (max[i][0] < price[i][j]) {
				max[i][0] = price[i][j];

				index[i] = j;
			}
		}

	}



	for (i = 0; i < n; i++) {
		printf("%s\n", name[i][index[i]]);
	}




	return 0;

}
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
	int top;
	char* arr[5];
	int size;
}stack;

void init(stack* s, int size) {
	s->top = -1;
	s->size = size;
	s->arr[++(s->top)] = (char*)malloc(sizeof(char) * size);
}

int full(stack* s) {
	if (s->top == s->size)
		return 0;
	else
		return 1;
}

int empty(stack* s) {
	if (s->top == -1)
		return 1;
	else
		return 0;
}

void push(stack* s, char* c) {
	if (full(s) == 0)
		printf("push �����߻�\n");
	else {
		strcpy_s((s->arr[s->top]), c);
		s->top++;
	}
}

void pop(stack* s) {
	if (empty(s) == 1)
		printf("pop �����߻�\n");
	s->top--;
	printf("%s\n", s->arr[s->top]);
}

int main(void) {

	stack* s = (stack*)malloc(sizeof(stack));
	init(s, 3);

	push(s, "good");
	push(s, "world");
	push(s, "hello");
	push(s, "hi");

	while (!empty(s)) {
		pop(s);
	}
	pop(s);
	free(s);

	return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	   int top;
	   int size;
	   char* str[3];
	
}stack;
void init(stack * s, int num) {
	   s->top = 0;
	   s->size = num;
	   for (int i = 0; i < s->size; i++)
		   s->str[i] = (char*)malloc(sizeof(char) * 5);
	
}
int full(stack * s) {
	   if (s->top == s->size)
		     return 0;
	   else
		     return 1;
	
}
int empty(stack * s) {
	   if (s->top == 0)
		     return 1;
	   else
		     return 0;
	
}
int push(stack * s, char* a) {
	   if (full(s) == 0)
		     return printf("PUSH �����߻�\n");
	     strcpy(s->str[s->top], a);
	     s->top++;
	
}
char* pop(stack * s) {
	   if (empty(s) == 1) {
		     printf("POP �����߻�\n");
		     return 0;
		
	}
	 s->top--;
	   return s->str[s->top];
	
}
int main() {
	   stack * s = (stack*)malloc(sizeof(stack));
	   init(s, 3);
	   push(s, "Good");
	   push(s, "World");
	   push(s, "Hello");
	   push(s, "Hi");
	   while (!empty(s)) {
		     printf("%s\n", pop(s));
		
	}
	 pop(s);
	   free(s);
	   return 0;
	
}
*/



/*
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//���� ���� ����Ʈ ���� ��� ������ ����ü�� ����
typedef struct Node {
	int data;
	struct Node* llink;
	struct Node* rlink;
}Node;

//������ ����ϴ� ������ front�� rear�� ����ü�� ����
typedef struct DQue {
	Node* front;
	Node* rear;
}DQue;

//���� ���� �����ϴ� ����
DQue* createDQue()
{
	DQue* DQ;
	DQ = (DQue*)malloc(sizeof(DQue));
	DQ->front = NULL;
	DQ->rear = NULL;

	return DQ;
}

//���� �������� Ȯ���ϴ� ����
int isEmpty(DQue* DQ)
{
	if (DQ->front == NULL) {
		return 1;
	}
	else
		return 0;
}

//���� front ������ �����ϴ� ����
void add_front(DQue* DQ, int item) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = item;
	//���� ������ ���
	if (DQ->front == NULL) {
		DQ->front = newNode;
		DQ->rear = newNode;
		newNode->rlink = NULL;
		newNode->llink = NULL;
	}
	else {
		DQ->front->llink = newNode;
		newNode->rlink = DQ->front;
		newNode->llink = NULL;
		DQ->front = newNode;
	}
}

//���� rear �ڷ� �����ϴ� ����
void add_rear(DQue* DQ, int item) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = item;
	//���� ������ ���
	if (DQ->rear == NULL) {
		DQ->front = newNode;
		DQ->rear = newNode;
		newNode->rlink = NULL;
		newNode->llink = NULL;
	}
	else {
		DQ->rear->rlink = newNode;
		newNode->rlink = NULL;
		newNode->llink = DQ->rear;
		DQ->rear = newNode;
	}
}

//���� front ��带 �����ϰ� ��ȯ�ϴ� ����
int delete_front(DQue* DQ) {
	Node* old = DQ->front;
	int item;
	if (isEmpty(DQ)) return 0;
	else {
		item = old->data;
		if (DQ->front->rlink == NULL) {
			DQ->front = NULL;
			DQ->rear = NULL;
		}
		else {
			DQ->front = DQ->front->rlink;
			DQ->front->llink = NULL;
		}
		free(old);
		return item;
	}
}

//���� rear ��带 �����ϰ� ��ȯ�ϴ� ����
int delete_rear(DQue* DQ) {
	Node* old = DQ->rear;
	int item;
	if (isEmpty(DQ)) {
		return 0;
	}
	else {
		item = old->data;
		if (DQ->rear->llink == NULL) {
			DQ->front = NULL;
			DQ->rear = NULL;
		}
		else {
			DQ->rear = DQ->rear->llink;

			DQ->rear->rlink = NULL;
		}
		free(old);
		return item;
	}
}

//Ư�� item�� �����ϴ� ����
void delete_item(DQue* head, int val)
{
	Node* p = head->front;
	Node* new = (Node*)malloc(sizeof(Node));

	if (head->front->data == val) {
		new = head->front->rlink;
		head->front = new;
	}
	else if (head->rear->data == val) {
		new = head->rear->llink;
		head->rear = new;
	}

	for (Node* p = head->rear; p != head->front; p = p->llink) {
		if (p->data == val) {

			p->rlink->llink = p->llink;
			p->llink->rlink = p->rlink;

			free(p);
			break;
		}
	}


}

void insert_before(DQue* DQ, int val, int before) {


	Node* temp = DQ->front;

	Node* new = (Node*)malloc(sizeof(Node));

	DQ->front->llink = new;
	new->rlink = DQ->front;
	new->llink = NULL;
	DQ->front = new;

	for (temp = DQ->front; temp->rlink != NULL; temp = temp->rlink) {
		if (temp->data == val) {

			for (temp = new; temp->data != val; temp = temp->rlink) {
				temp->data = temp->rlink->data;

			}
			temp->llink->data = before;

		}
	}
}

void insert_after(DQue* DQ, int val, int after) {

	Node* temp = DQ->front;

	Node* new = (Node*)malloc(sizeof(Node));

	DQ->front->llink = new;
	new->rlink = DQ->front;
	new->llink = NULL;
	DQ->front = new;

	for (temp = DQ->front; temp->rlink != NULL; temp = temp->rlink) {
		if (temp->data == val) {

			for (temp = new; temp->data != val; temp = temp->rlink) {
				temp->data = temp->rlink->data;

			}
			temp->data = after;

		}
	}

}


//���� front ������ rear ������ ����ϴ� ����
void printDQ(DQue* DQ) {
	Node* temp = DQ->front;

	if (isEmpty(DQ)) {
		printf("EMPTY\n");
	}

	printf("ť: ");

	if (temp == NULL)
		printf("NULL");

	while (temp) {
		printf("%d ", temp->data);

		temp = temp->rlink;

		if (temp != NULL)
			printf("- ");
		else
			continue;

	}
	printf("\n\n");

}

int main(void) {
	DQue* DQ = createDQue();

	int choice = 0;
	int value = 0;
	int before = 0;
	int after = 0;

	while (choice != 5) {
		printf("1. Add_Front\n2. Add_Rear\n3. Delete_Front\n4. Delete_Rear\n5. delete_item\n6. insert_before\n7. insert_after\n8. ����\n");
		printf("�Է�: ");

		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			scanf("%d", &value);
			add_front(DQ, value);
			printDQ(DQ);
			break;
		case 2:
			scanf("%d", &value);
			add_rear(DQ, value);
			printDQ(DQ);
			break;
		case 3:
			delete_front(DQ);
			printDQ(DQ);
			break;
		case 4:
			delete_rear(DQ);
			printDQ(DQ);
			break;
		case 5:
			scanf("%d", &value);
			delete_item(DQ, value);
			printDQ(DQ);
			break;
		case 6:
			printf("���� �ΰ� �Է��Ͻÿ�(ex: insert_before(20,1) = 20 �տ� 1����) : ");
			scanf("%d %d", &after, &before);
			insert_before(DQ, after, before);
			printDQ(DQ);
			break;
		case 7:
			printf("���� �ΰ� �Է��Ͻÿ�(ex: insert_after(40,45) = 40 �ڿ� 45 ����) : ");
			scanf("%d %d", &before, &after);
			insert_after(DQ, before, after);
			printDQ(DQ);
			break;

		case 8:
			printf("BYE\n");
			exit(0);
			break;

		}


	}


	return 0;
}
*/