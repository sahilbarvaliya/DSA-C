#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void Display(struct Node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    };
}

void DisplayRec(struct Node *p)
{
    static int flag = 0;

    if ((p != head) || (flag == 0))
    {
        flag = 1;
        printf("%d ", p->data);
        DisplayRec(p->next);
    }
    flag = 0;
}

struct Node *create(struct Node *node, int A[], int n)
{
    int i;
    struct Node *t, *last;
    node = (struct Node *)malloc(sizeof(struct Node));

    node->data = A[0];
    node->next = node->prev = NULL;

    last = node;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }

    return node;
}

int main()
{

    int A[] = {10, 20, 30, 40, 50};
    head = create(head, A, 5);

    Display(head);
    // DisplayRec(head);
    return 0;
}
