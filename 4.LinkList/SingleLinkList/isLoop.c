#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *first = NULL;

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

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

int isLoop(struct Node *f)
{
    struct Node *p = NULL;
    struct Node *q = NULL;

    p = q = f;

    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    } while ((p && q) && (p != q));

    if (p == q)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    struct Node *t1 = NULL;
    struct Node *t2 = NULL;

    int A[] = {10, 20, 30, 40, 50};
    first = create(first, A, 5);

    t1 = first->next->next;             // 30
    t2 = first->next->next->next->next; // 50
    t2->next = t1;                      // 30

    printf("%d", isLoop(first));
    // Display(first);
    return 0;
}
