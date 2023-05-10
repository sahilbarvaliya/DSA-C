#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *create(struct Node *node, int A[], int n)
{
    int i;
    struct Node *t, *last;
    node = (struct Node *)malloc(sizeof(struct Node));

    node->data = A[0];
    node->next = NULL;

    last = node;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }

    return node;
}

void MidNode(struct Node *p)
{
    struct Node *q = p;

    while (q)
    {
        q = q->next;
        if (q)
        {
            q = q->next;
        }
        if (q)
        {
            p = p->next;
        }
    }

    printf("%d", p->data);
}

int main()
{

    int A[] = {10, 20, 30, 40, 50, 60, 70, 80};
    head = create(head, A, 8);
    MidNode(head);
    return 0;
}