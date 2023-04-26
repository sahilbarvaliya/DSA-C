#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *first = NULL;
struct Node *secound = NULL;
struct Node *third = NULL;
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

void mearge(struct Node *f, struct Node *s)
{
    struct Node *third = NULL;
    struct Node *last = NULL;

    if (f->data < s->data)
    {
        third = last = f;
        f = f->next;
        last->next = NULL;
    }
    else
    {
        third = last = s;
        s = s->next;
        last->next = NULL;
    }

    while (f && s)
    {
        if (f->data < s->data)
        {
            last->next = f;
            last = f;
            f = f->next;
            last->next = NULL;
        }
        else
        {
            last->next = s;
            last = s;
            s = s->next;
            last->next = NULL;
        }
    }
    if (f)
    {
        last->next = f;
    }
    else
    {
        last->next = f;
    }
}

int main()
{

    int A[] = {3, 5, 7, 12, 15};
    int B[] = {2, 4, 6, 11, 16};
    first = create(first, A, 5);
    secound = create(secound, B, 5);
    mearge(first, secound);
    Display(secound);
    return 0;
}
