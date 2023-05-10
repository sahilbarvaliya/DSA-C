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

void Reverse(struct Node *p)
{
    int i;
    struct Node *temp;

    while (p != NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p != NULL && p->next == NULL)
        {
            head = p;
        }
    }
}

int main()
{

    int A[] = {10, 20, 30, 40, 50};
    head = create(head, A, 5);

    Reverse(head);
    Display(head);
    return 0;
}
