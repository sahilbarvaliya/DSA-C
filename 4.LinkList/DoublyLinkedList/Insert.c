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

int Length(struct Node *p)
{
    int count = 0;

    while (p)
    {
        count++;
        p = p->next;
    }

    return count;
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;

    if (index < 0 || index > Length(p))
    {
        printf("Invalid Position");
        return;
    }
    if (index == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));

        t->data = x;
        t->next = head;
        t->prev = NULL;
        head = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = p;
        t->next = p->next;
        if (p->next)
        {
            p->next->prev = t;
        }
        p->next = t;
    }
}

int main()
{

    int A[] = {10, 20, 30, 40, 50};
    head = create(head, A, 5);

    Insert(head, 5, 15);
    Display(head);
    return 0;
}
