#include <stdio.h>
#include <stdlib.h>


typedef struct DlistNode {
    int data;
    struct DlistNode* llink;
    struct DlistNode* rlink;
} DlistNode;

void dinsert_first(DlistNode* head, int value) // 리스트의 가장 앞에 추가
{
    DlistNode* node = (DlistNode*)malloc(sizeof(DlistNode));

    node->rlink = head->rlink;
    node->llink = head;
    head->rlink->llink = node;
    head->rlink = node;
    node->data = value;
}

void dinsert_last(DlistNode* head, int value) // 리스트의 가장 뒤에 추가
{
    DlistNode* node = (DlistNode*)malloc(sizeof(DlistNode));

    node->llink = head->llink;
    node->rlink = head;
    head->llink->rlink = node;
    head->llink = node;
    node->data = value;

}

int get_circular_length(DlistNode* head) // 이중 연결 리스트의 길이를 계산
{
    DlistNode* node = head;
    int length = 0;

    for (head = head->rlink; node != head; head = head->rlink)
        length++;

    return length;
}

void print_list(DlistNode* head) {
    for (DlistNode* curr = head->rlink; curr != head; curr = curr->rlink) {
        printf("%d ", curr->data);
        if (curr->rlink != head)
            printf("-> ");
    }
    printf("\n");
}

int main(void)
{
    DlistNode* head = (DlistNode*)malloc(sizeof(DlistNode));
    head->rlink = head->llink = head;

    dinsert_last(head, 10);
    dinsert_last(head, 20);
    dinsert_last(head, 30);
    dinsert_first(head, 40);
    print_list(head);
    /*   40 -> 10  -> 20  ->30 */
    int length = get_circular_length(head); // 4를 반환
    printf("%d", length);
}