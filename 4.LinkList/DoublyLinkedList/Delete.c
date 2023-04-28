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

void Delete(struct Node *p, int index)
{
    int x = -1, i;

    if (index < 1 || index > Length(p))
    {
        printf("Invalid Position");
        return;
    }
    if (index == 1)
    {
        head = head->next;
        if (head)
            head->prev = NULL;
        x = p->data;
        free(p);
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next)
        {
            p->next->prev = p->prev;
        }
        x = p->data;
        free(p);
    }
}

int main()
{

    int A[] = {10, 20, 30, 40, 50};
    head = create(head, A, 5);

    Delete(head, 1);
    Display(head);
    return 0;
}
