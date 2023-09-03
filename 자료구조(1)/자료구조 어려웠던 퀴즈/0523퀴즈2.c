#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List //구조체 
{
	struct List* next;
	char* data;
}ListNode;

void InsertLast(ListNode** head, char* Input)
{
	ListNode* addNode = (ListNode*)malloc(sizeof(ListNode)); //추가용 ListNode 생성  
	addNode->next = NULL; //마지막 노드가 될 예정이기에 next 는 NULL 이 된다. 
	addNode->data = Input; //data는 받아온 Input을 넣는다. 

	if(*head == NULL) //*head가 NULL인 경우 빈 List이기 때문에 addNode를 첫 노드로 만든다. 
		*head = addNode;
	else
	{
		for(ListNode* curr = *head ; curr != NULL ; curr = curr->next) //빈 List가 아닌경우 마지막 Node를 찾아 마지막 노드의 next에 addNode를 넣는다. 
		{
			if(curr->next == NULL)
			{
				curr->next = addNode;
				break; //list 가 계속 확장되기 때문에 break를 걸어주지 않으면 for문이 끝나지 않는다. 
			}
		}
	}
}

void InsertAfter(ListNode* head, char* Item, char* Input)
{
	int exist = 0; //Item 문자열과 동일한 Node가 존재하는지 확인하기 위한 변수 exist. 

	for(ListNode* curr = head ; curr != NULL ; curr = curr->next) //리스트 전체를 훑는 for문. 
	{
		if(!strcmp(curr->data, Item)) //curr에 있는 data와 받아온 Item 문자열이 동일 한 경우 if문을 실행한다. 
		{
			ListNode* addNode = (ListNode*)malloc(sizeof(ListNode));
			addNode->next = curr->next;
			addNode->data = Input;

			curr->next = addNode; //현재 item과 동일한 값을 가진 노드의 next에 addNode를 넣는다. 

			exist = 1; //Item 문자열과 동일한 Node가 존재하기에 1로 exist를 변경한다. 

			break; // Node를 추가했기 때문에 for문을 더 돌릴 필요가 없어 break를 건다. 
		}
	}
	if(!exist)
		printf("Insert failed(%s dose not exist)\n", Item); //exist가 0인경우 Item과 동일한 문자열을 가진 node가 없었다는 것이기 때문에 오류문을 출력한다. 
}

void PrintList(ListNode* head)
{
	for(ListNode* curr = head ; curr != NULL ; curr = curr->next) //리스트 전체를 도는 for문. 
	{
		printf("%s", curr->data);

		if(curr->next != NULL) //뒤에 값이 있는경우 -를 붙인다. 
			printf("-");
	}
	printf("\n");
}

void FreeList(ListNode* head)
{
	printf("\n");

	while(head != NULL) //head가 NULL이 될 때까지 반복한다. 
	{
		printf("%s freed \n", head->data);

		ListNode* Temp = head;
		head = head->next;
		free(Temp);
	}
	printf("\n");
}

int main()
{
	ListNode* head = NULL;

	InsertLast(&head, "Apple");
	PrintList(head);
	InsertLast(&head, "Durian");
	PrintList(head);

	InsertAfter(head, "Apple", "Banana");
	PrintList(head);
	InsertAfter(head, "Tomato", "Grape");
	PrintList(head);
	InsertAfter(head, "Banana", "Carrot");
	PrintList(head);
	
	FreeList(head);
	
	return 0;
}
