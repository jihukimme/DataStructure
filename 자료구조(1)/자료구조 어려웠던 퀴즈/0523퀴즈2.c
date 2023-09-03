#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List //����ü 
{
	struct List* next;
	char* data;
}ListNode;

void InsertLast(ListNode** head, char* Input)
{
	ListNode* addNode = (ListNode*)malloc(sizeof(ListNode)); //�߰��� ListNode ����  
	addNode->next = NULL; //������ ��尡 �� �����̱⿡ next �� NULL �� �ȴ�. 
	addNode->data = Input; //data�� �޾ƿ� Input�� �ִ´�. 

	if(*head == NULL) //*head�� NULL�� ��� �� List�̱� ������ addNode�� ù ���� �����. 
		*head = addNode;
	else
	{
		for(ListNode* curr = *head ; curr != NULL ; curr = curr->next) //�� List�� �ƴѰ�� ������ Node�� ã�� ������ ����� next�� addNode�� �ִ´�. 
		{
			if(curr->next == NULL)
			{
				curr->next = addNode;
				break; //list �� ��� Ȯ��Ǳ� ������ break�� �ɾ����� ������ for���� ������ �ʴ´�. 
			}
		}
	}
}

void InsertAfter(ListNode* head, char* Item, char* Input)
{
	int exist = 0; //Item ���ڿ��� ������ Node�� �����ϴ��� Ȯ���ϱ� ���� ���� exist. 

	for(ListNode* curr = head ; curr != NULL ; curr = curr->next) //����Ʈ ��ü�� �ȴ� for��. 
	{
		if(!strcmp(curr->data, Item)) //curr�� �ִ� data�� �޾ƿ� Item ���ڿ��� ���� �� ��� if���� �����Ѵ�. 
		{
			ListNode* addNode = (ListNode*)malloc(sizeof(ListNode));
			addNode->next = curr->next;
			addNode->data = Input;

			curr->next = addNode; //���� item�� ������ ���� ���� ����� next�� addNode�� �ִ´�. 

			exist = 1; //Item ���ڿ��� ������ Node�� �����ϱ⿡ 1�� exist�� �����Ѵ�. 

			break; // Node�� �߰��߱� ������ for���� �� ���� �ʿ䰡 ���� break�� �Ǵ�. 
		}
	}
	if(!exist)
		printf("Insert failed(%s dose not exist)\n", Item); //exist�� 0�ΰ�� Item�� ������ ���ڿ��� ���� node�� �����ٴ� ���̱� ������ �������� ����Ѵ�. 
}

void PrintList(ListNode* head)
{
	for(ListNode* curr = head ; curr != NULL ; curr = curr->next) //����Ʈ ��ü�� ���� for��. 
	{
		printf("%s", curr->data);

		if(curr->next != NULL) //�ڿ� ���� �ִ°�� -�� ���δ�. 
			printf("-");
	}
	printf("\n");
}

void FreeList(ListNode* head)
{
	printf("\n");

	while(head != NULL) //head�� NULL�� �� ������ �ݺ��Ѵ�. 
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
