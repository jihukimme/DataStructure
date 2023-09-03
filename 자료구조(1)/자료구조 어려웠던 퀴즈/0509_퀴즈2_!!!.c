#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


//stack 구조체 생성.
typedef struct stack 
{
	void* array; //스택 데이터 저장용 배열
	int max; //스택 저장 최대 개수 저장용 변수
	int top; //스택 top 위치 저장용 변수
	char type;  //스택 자료형 저장용 변수 i == int ; c == char

}stack;

//stack 구조체 초기화 함수.
void init(stack* stc, int max, char type)
{
	//받은 자료형따라 배열 동적 할당.
	if(type == 'c')
		stc->array = (char*)malloc(sizeof(char)*max);
	else if(type == 'i')
		stc->array = (int*)malloc(sizeof(int)*max);

	stc->max = max-1;
	stc->top = -1;
	stc->type = type;
}

//스택이 비어있는지 확인하는 함수.
bool isEmpty(stack* stc)
{
	return (stc->top == -1); //top의 위치가 -1이면 빈 스택(true) 아니면 비지 않은 스택(false) 반환.
}

//스택이 가득 차 있는지 확인하는 함수.
bool isFull(stack* stc)
{
	return (stc->top == stc->max); //top의 위치가 max(최대)인 경우 가득 찬 스택(true) 아니면 가득 차지 않은 스택(false) 반환.
}

//스택에 값을 넣어주는 함수.
void push(stack* stc, void* input)
{
	if(isFull(stc)) //스택이 가득 찬 경우 스택이 가득 찼다고 표시.
		printf("STACK IS FULL!\n");
	else
	{
		stc->top++;

		//배열이 void*형이기 때문에 사용하기 편하도록 각 자료형*를 임시로 생성해서 값을 넣는다. (void*형은 자료형이 정해져 있지 않아 [] 의 사용이 불가능하다)
		if(stc->type == 'c')
		{
			char* temp = stc->array;
			temp[stc->top] = (char)input;
		}
		else if(stc->type == 'i')
		{
			int* temp = stc->array;
			temp[stc->top] = (int)input;
		}	
	}
}

//스택에서 값을 빼 오는 함수.
void* pop(stack* stc)
{
	if(isEmpty(stc)) //빈 스택인 경우 함수 종료.
		return;
	else
	{
		//배열이 void*형이기 때문에 사용하기 편하도록 각 자료형*를 임시로 생성해서 값을 뺀다. (void*형은 자료형이 정해져 있지 않아 [] 의 사용이 불가능하다)
		if(stc->type == 'c')
		{		
			char* temp = stc->array;
			stc->top--;
			return temp[stc->top+1];	
		}	
		else if(stc->type == 'i')
		{
			int* temp = stc->array;
			stc->top--;
			return temp[stc->top+1];
		}	
	}
}

//스택에 마지막으로 넣은 값을 확인하는 함수.
void* peek(stack* stc)
{
	if(isEmpty(stc)) //빈 스택인 경우 함수 종료.
		return;	
	else
	{
		//배열이 void*형이기 때문에 사용하기 편하도록 각 자료형*를 임시로 생성해서 값을 확인한다. (void*형은 자료형이 정해져 있지 않아 [] 의 사용이 불가능하다)
		if(stc->type == 'c')
		{
			char* temp = stc->array;
			return temp[stc->top];	
		}
		else if(stc->type == 'i')
		{
			int* temp = stc->array;
			return temp[stc->top];
		}	
	}
}

//중위식을 후위식으로 바꿔서 반환하는 함수.
char* getPostfix(char* infix)
{
	//후위식으로 바꾸는 과정에서 나오는 연산자를 저장할 스택 생성 및 초기화.
	stack* opers = (stack*)malloc(sizeof(stack));
	init(opers, 10, 'c');

	//반환할 결과인 후위식을 저장할 스택 생성 및 초기화.
	stack* postfix = (stack*)malloc(sizeof(stack));
	init(postfix, 10, 'c');

	//받아온 중위식을 처음부터 끝까지 한자리씩 확인한다.
	for(int T = 0 ; T < strlen(infix) ; T ++)
	{
		char temp = infix[T]; //매번 infix[T] 적기에는 불편하니 temp변수를 생성해서 넣어서 사용한다.

		if(isdigit(temp)) //숫자인지 확인해주는 isdigit 함수를 이용해서 숫자인 경우 후위식 스택에 넣는다.
			push(postfix, temp);
		else if(temp == '*' || temp == '/') //연산자 중 * 혹은 / 인 경우 연산자 스택에 넣는다.
			push(opers, temp);
		else if(temp == '+' || temp == '-') //연산자 중 + 혹은 - 인 경우 연산자 스택에 * 혹은 / 가 먼저 들어가 있는경우 연산 순서에 문제가 생기기에 peek의 결과가 * 혹은 / 가 아닐때까지 연산자 스택에서 연산자를 빼서 후위식에 넣는다.
		{
			while(peek(opers) == '*' || peek(opers) == '/')
				push(postfix, pop(opers));
	
			push(opers, temp);	
		}	
		else if(temp == '(') // 여는 소괄호인 경우 연산자 스택에 넣는다.
			push(opers, temp);
		else if(temp == ')') // 닫는 소괄호인 경우 여는 소괄호가 나올 때 까지 연산자 스택에서 연산자를 빼서 후위식에 넣는다.
		{
			char oper = pop(opers);

			while(oper != '(')
			{
				push(postfix, oper);
				oper = pop(opers);
			}
		}	
	
		if(T == strlen(infix)-1) // 중위식이 끝난 경우 연산자 스택이 빌 때 까지 연산자스택에서 연산자를 빼서 후위식에 넣는다.
			while(!isEmpty(opers))
				push(postfix, pop(opers));	
	}
	
	char* result = postfix->array; //후위식 스택속 배열을 반환하기 위해 *변수를 만들어 주소값을 저장한다.

	// 쓸모가 다한 동적할당을 할당 해제한다.
	free(postfix);
	free(opers->array);
	free(opers);

	return result;
}

//후위식을 받아 계산 결과를 출력하는 함수.
void calc(char* postfix)
{
	
	//계산 중 숫자를 저장할 스택 생성 및 초기화.
	stack* numbers = (stack*)malloc(sizeof(stack));
	init(numbers, 10, 'i');

	bool problem = false; //계산중 문제(/0)이 있는지 확인하는 함수.

	//받아온 후위식을 처음부터 끝까지 한자리씩 확인한다.
	for(int T = 0 ; T < strlen(postfix) ; T ++)
	{
		char temp = postfix[T]; //매번 postfix[T] 적기에는 불편하니 temp변수를 생성해서 넣어서 사용한다.

		//해당 T번쨰의 후위식이 숫자인 경우
		if(isdigit(temp)) 
		{
			char tmp[1];
			tmp[0] = temp;
			push(numbers, atoi(tmp)); //atoi함수(char*를 받아 int를 반환)를 이용해 받아온 숫자를  숫자 스택에 넣는다.
		}
		else //숫자가 아닌경우는 연산자인 경우.
		{
			//계산 순서를 맞추기 위해 숫자 스택에서 b부터 뺀 후 a를 뺸다.
			int b = pop(numbers); 
			int a = pop(numbers);

			//각 연산자 별 연산을 수행해서 숫자 스택에 넣는다.
			if(temp == '*')
				push(numbers, a*b);
			else if(temp == '/')
			{	
				if(b == 0) // / 연산자에서 b가 0인 경우는 /0이기에 오류가 발생한다.
				{
					problem = true; //오류 발생 여부 확인용 변수의 값을 true로 바꾸고 연산 for문을 종료한다.
					break;
				}	
				else
				{	
					push(numbers, a/b);
				}	
			}	
			else if(temp == '+')
				push(numbers, a+b);
			else if(temp == '-')
				push(numbers, a-b);
		}	
	}
	
	
	if(problem) //오류 발생 여부 확인용 변수의 값이 참인경우 /0이 있었던 것이기에 0으로 나눌 수 없다는 결과를 출력한다.
		printf("계산결과 : 오류: 0으로 나눌 수 없습니다.\n");
	else //오류 발생 여부 확인용 변수의 값이 거짓인경우 계산에 문제가 없었던 것이기에 숫자 스택에 남은 숫자(결과)를 출력한다.
		printf("계산결과: %d\n", pop(numbers));

	//계산에 사용했던 스택과 스택 속 배열의 동적 할당을 해제한다.
	free(numbers->array);
	free(numbers);
}



int main()
{
	printf("수식을 입력 하세요: ");
	
	char infix[20] = {'\0'}; // 중위식 저장용 배열 생성.

	scanf("%s", infix); //중위식 입력.

	printf("\n");


	char* postfix = getPostfix(infix); //후위식 저장용 *변수를 생성 한 후 후위식 변환 함수를 호출해서 후위식을 받아온다.

	printf("후위식: %s\n", postfix); // 받아온 후위식을 출력.

	calc(postfix); //계산 함수 호출.

	free(postfix); //후위식 저장용 *변수의 할당을 해제한다.

	return 0;

}
