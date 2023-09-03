
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
	product(table, first + 1, last); //처음으로 곱하고자 하는 값이 1씩 증가하도록 설정 -> 마지막으로 곱하고자 하는 값보다 커지면 return시키도록 설정
}


int main(void) {

	int table; //구하고자 하는 구구단
	int first_num; //구하고자 하는 단의 처음 곱셈 값
	int last_num; //구하고자 하는 단의 마지막 곱셈 값


	//사용자로부터 입력을 받아 옴
	printf("구하고자 하는 단을 입력하세요: ");
	scanf_s("%d", &table);
	printf("\n!!처음 곱셈 값은 마지막 곱셈 값보다 클 수 없음!!\n"); //처음 곱셈 값은 마지막 곱셈 값보다 클 수 없다

	printf("구하고자 하는 단의 처음 곱셈값을 입력하세요: ");
	scanf_s("%d", &first_num);
	printf("구하고자 하는 단의 마지막 곱셈값을 입력하세요: ");
	scanf_s("%d", &last_num);

	printf("\n\n\n======================%d단의 %d부터 %d까지의 결과 값==========================\n", table, first_num, last_num);

	//결과값을 가져오기위한 product함수 실행
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
	
	struct person p[5] = { { "김지후", 23, 3.7 }, {"김재훈", 22, 3.5}, {"김지훈", 22, 3}, {"모지리", 21, 2}, {"똑똑이", 22, 4.2} };
	
	for (int i = 0; i < 5; i++) {
		printf("%s의 학점은 %lf입니다.\n", p[i].name, p[i].height);
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
		printf("%s의 나이는 %d입니다.\n", p->name, p->age);
	}


	return 0;
}

*/

/*
#include <stdio.h>
#include <stdlib.h>
#define MAX 7	 	//크기 지정

typedef struct {
	int degree[MAX];		//계수를 받는 배열
	int coef[MAX];		//차수를 받는 배열
}Poly;

Poly add_poly(Poly f, Poly g) {
	Poly c = { {0}, {0} };
	int count = 0;	//Poly c에 f와 g를 같이 저장하기 위해서 사용
	int tmp = 0;	//f와 g를 저장한 Poly c를 내림차순으로 배열하기 위해서 사용

	//Poly c에 f를 저장하는 for문
	for (int i = 0; i < MAX; i++) {
		c.coef[i] = f.coef[i];
		c.degree[i] = f.degree[i];
		if (c.coef[i] == 0 && c.degree[i] == 0) {
			break;
		}
		else
			count++;
		//f를 저장한 후 뒷부분에 g를 저장하기 위해서 count를 증가시킴
	}
	for (int i = 0; i < MAX; i++) {
		c.coef[i + count] = g.coef[i];
		//g를 c에, f를 저장한 후 그 뒷부분에 저장
		c.degree[i + count] = g.degree[i];

		if (c.coef[i + count] == 0 && c.degree[i + count] == 0)
			//c에 저장할게 없을 때 종료
			break;
	}


	//c에 저장 된 coef, degree배열을 내림차순으로 정리
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

	//내림차순으로 정리 후 coef가 같은 수일 경우 coef를 하나로하고 그에 맞는 degree를 더하도록 설정
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
	//구조체 Poly result를 출력하는 함수 print_poly
	for (int i = 0; i < MAX; i++) {
		//계수가 0인 경우 0임으로 출력하지 않도록 설정
		if (result.degree[i] == 0) {
			continue;
		}
		//차수가 0일 경우 계수만 출력하도록 설정
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
	// f, g, 값 설정 코드...
	Poly f = { {1,1,1}, {100,2,0} };
	//f(x) = x ^ 100 + x ^ 2 + 1를 계수를 저장하는 배열과, 차수를 저장하는 배열에 나누어 저장하는 구조체 Poly f선언
	Poly g = { {1,2}, {1000, 0} };
	//g(x) = x ^ 1000 + 2       를 계수를 저장하는 배열과, 차수를 저장하는 배열에 나누어 저장하는 구조체 Poly g선언
	Poly result;
	result = add_poly(f, g);	//result에 add_poly를 통해서 f(x) + g(x)의 값을 저장
	print_poly(result);	//print_poly를 통해서 result를 출력

	return 0;
}

다항식 덧셈 프로그램
*/


/*
#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int size;
	int top;
	int* data;
	int pop_num; //pop한 수를 저장
}stack;

void create(stack* s, int size) {
	//size만큼 data에 int형 메모리할당
	s->data = (int*)malloc(size * sizeof(int));
	s->top = -1;
	s->size = size;
}

//s->top = -1일때 스택이 비어있는 상태
int is_empty(stack* s) {
	return(s->top = -1);
}
//스택이 꽉찬 경우
int is_full(stack* s) {
	return ((s->top) == (s->size - 1));
}


void push(stack* s, int item) {
	//생성한 스택 크기만큼 push
	if (s->top < s->size - 1) {
		s->top++;
		s->data[s->top] = item;
		printf("push했습니다: %d\n", item);
	}
	//스택의 크기를 초과할 때 스택의 크기를 키워줌
	else{
		s->size = s->size * 2;
		s->data = (int*)realloc(s->data, s->size * sizeof(int));
		push(s, item);
	}
}

int pop(stack* s) {
	printf("\npop: ");
	//pop시킴
	if (s->top >= 0) {
		int value;
		value = s->data[s->top];
		s->top--;

		s->pop_num = value;

		return s->pop_num;
	}
	//스택이 비었음을 나타냄
	if (is_empty(s)) {
		printf("스택이 비었습니다.\n");

		return 0;
	}
}


int main(void) {
	stack s;


	create(&s, 3); //stack을 3개 생성

	push(&s, 10);
	push(&s, 20);
	push(&s, 30);
	push(&s, 40); //push 함수에서 생성한 stack 범위를 초과하였을 때 메모리를 추가로 할당하도록 설정
	push(&s, 50);
	push(&s, 60);
	push(&s, 70);

	for (int i = 0; i < 7; i++) {
		printf("%d\n", pop(&s));
	}

	pop(&s);//stack에 남아있는게 없을 때 pop하면 더 이상 pop 되지않음


	return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct QuizInt {

	int oddNum;//홀수

	int evenNum;//짝수

};

void DoMallocQuiz(char* c, int n) {

	//1. DoMallocQuiz 함수의 첫번째 인자로 들어온 문자열 출력
	printf("\n%s\n", c);

	//2. Heap 영역에 struct QuizInt 형의 배열을 할당 (크기: n)
	struct QuizInt* a = (struct QuizInt*)malloc(sizeof(struct QuizInt) * n);

	//3. oddNum 에 임의의 홀수를 넣고, evenNum 에 임의의 짝수를 넣는다.
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
	//중복되는 숫자가 있을경우 다시 무작위의 수를 받아온다
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





	//(숫자 범위 : 0 - 19, 단, 한 번 사용한 숫자는 다시 나올 수 없음)

	//4. 아래 양식으로 출력.
	printf("ODD: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i].oddNum); //oddNum을 main함수에서 입력한 크기만큼 출력
	}
	printf("\nEVEN: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i].evenNum);//evenNum을 main함수에서 입력한 크기만큼 출력
	}
	printf("\n");
}

int main(int argc, char* argv[]) {

	DoMallocQuiz("5 random numbers", 5);

	DoMallocQuiz("4 random numbers", 4);

	return 0;

}
*/

/*            모음개수
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

/*         세로읽기
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


/* 첼시
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
		printf("push 에러발생\n");
	else {
		strcpy_s((s->arr[s->top]), c);
		s->top++;
	}
}

void pop(stack* s) {
	if (empty(s) == 1)
		printf("pop 에러발생\n");
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
		     return printf("PUSH 에러발생\n");
	     strcpy(s->str[s->top], a);
	     s->top++;
	
}
char* pop(stack * s) {
	   if (empty(s) == 1) {
		     printf("POP 에러발생\n");
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

//이중 연결 리스트 덱의 노드 구조를 구조체로 정의
typedef struct Node {
	int data;
	struct Node* llink;
	struct Node* rlink;
}Node;

//덱에서 사용하는 포인터 front와 rear를 구조체로 정의
typedef struct DQue {
	Node* front;
	Node* rear;
}DQue;

//공백 덱을 생성하는 연산
DQue* createDQue()
{
	DQue* DQ;
	DQ = (DQue*)malloc(sizeof(DQue));
	DQ->front = NULL;
	DQ->rear = NULL;

	return DQ;
}

//덱이 공백인지 확인하는 연산
int isEmpty(DQue* DQ)
{
	if (DQ->front == NULL) {
		return 1;
	}
	else
		return 0;
}

//덱의 front 앞으로 삽입하는 연산
void add_front(DQue* DQ, int item) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = item;
	//덱이 공백인 경우
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

//덱의 rear 뒤로 삽입하는 연산
void add_rear(DQue* DQ, int item) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = item;
	//덱이 공백인 경우
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

//덱의 front 노드를 삭제하고 반환하는 연산
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

//덱의 rear 노드를 삭제하고 반환하는 연산
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

//특정 item을 삭제하는 연산
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


//덱의 front 노드부터 rear 노드까지 출력하는 연산
void printDQ(DQue* DQ) {
	Node* temp = DQ->front;

	if (isEmpty(DQ)) {
		printf("EMPTY\n");
	}

	printf("큐: ");

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
		printf("1. Add_Front\n2. Add_Rear\n3. Delete_Front\n4. Delete_Rear\n5. delete_item\n6. insert_before\n7. insert_after\n8. 종료\n");
		printf("입력: ");

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
			printf("값을 두개 입력하시오(ex: insert_before(20,1) = 20 앞에 1삽입) : ");
			scanf("%d %d", &after, &before);
			insert_before(DQ, after, before);
			printDQ(DQ);
			break;
		case 7:
			printf("값을 두개 입력하시오(ex: insert_after(40,45) = 40 뒤에 45 삽입) : ");
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