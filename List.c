#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node* next;
};

struct node* ListInit(void)
{
    struct node* node = (struct node*) malloc(sizeof(struct node));
    if (node == NULL) exit(1);

    node->next = NULL;
    node->value = 0;

    return node;
}

void ListFree(struct node* a)
{
    free(a);
}

void ListFreeAll(struct node* a)
{
    struct node* temp;
    while (a != NULL)
    {
        temp = a->next;
        free(a);
        a = temp;
    }
}

void ListPrint(struct node* a)
{
    while (a != NULL)
    {
        printf("%d,", a->value);
        a = a->next;
    }
}

void ListInsert(struct node* list, int val, int i)
{
    struct node* newNode;
    if (list == NULL) return;
    int j=0;

    for(; j<i; j++)
    {
        if(list->next == NULL) return;
        list = list->next;
    }

    newNode = ListInit();
    newNode->value = val;

    int* temp = list->next;//i+1

    list->next = newNode;
    newNode->next = temp;
}

void ListDelete(struct node* list, int i)
{
    if (list == NULL) return;
    int j=0;

    for(; j<i-1; j++)
    {
        if(list->next == NULL) return;
        list = list->next;
    }
    list->next=list->next->next;
}

void ListAppendInt(struct node* list, int val)
{
    struct node* newNode;

    if (list == NULL) return;
    while (list->next != NULL) list = list->next;

    newNode = ListInit();
    newNode->value = val;

    list->next = newNode;
}

int main(void)
{
    struct node* n;
    int i, val=5, j=2;

    n = ListInit();

    for (i=1; i <= 4; i++) ListAppendInt(n, i);

    ListInsert(n, val, j);
    ListPrint(n);
    ListDelete(n, j+1);
    ListPrint(n);
    ListFreeAll(n);

    while (1);

    return 0;
}
