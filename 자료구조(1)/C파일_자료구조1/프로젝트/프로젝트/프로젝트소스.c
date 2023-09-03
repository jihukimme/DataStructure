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
    if (p->data == val) {
        head->front = head->front->rlink;
        head->front->llink = NULL;
    }
    else {
        while (p->data != val)
            p = p->rlink;
        p->rlink->llink = p->llink;
        p->llink->rlink = p->rlink;

        free(p);
    }
}

//val 앞에 before 삽입
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

//val 뒤에 after 삽입
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

    while (choice != 8) {
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

/*
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
}node;

node* allocnewnode(int value) {
    node* nod = (node*)malloc(sizeof(node));

    nod->data = value;
    nod->next = NULL;
    nod->prev = NULL;

    return nod;
}

void insertlast(node* head, int value) {
    node* curr = head;
    for (curr = head; curr != NULL; curr = curr->next);
    
    curr->next = allocnewnode(value);
    curr->next->prev = curr;
}

void insertfirst(node* head, int value) {
    node* new_node = allocnewnode(value);

    new_node->next = head->next;
    head->prev = new_node;
}

void delete_node(node* head, int value) {
    if (head->data == value) {

        head->prev->next = head->next;
        head->next->prev = head->prev;

        free(head);
    }
    else
        return;
}

void printlist(node* head) {
    for (node* curr = head->next; curr != NULL; curr = curr->next) {
        printf("%d->", curr->data);
    }
}

int main(void) {


    node* list = allocnewnode(5);

    insertfirst(list, 3);
    insertfirst(list, 2);
    insertfirst(list, 1);
    insertlast(list, 4);
    insertlast(list, 5);
    insertlast(list, 6);

    delete_node(list, 5);

    printlist(list);

    return 0;
}
*/