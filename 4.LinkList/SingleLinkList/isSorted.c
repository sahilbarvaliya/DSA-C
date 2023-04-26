#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void isSorted(struct Node *p)
{
    int x = -32768, i;

    while (p)
    {
        x = p->data;
        if (p->data < x)
        {
            printf("Link list is not sorted");
            break;
        }
        p = p->next;
    }

    printf("Link list is sorted");
}

int main()
{

    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    isSorted(first);
    return 0;
}