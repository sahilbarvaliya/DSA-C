#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *first = NULL;

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

void Display(struct Node *p){
    while (p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

struct Node* Search(struct Node *P,int key){
    struct Node *q = NULL;

    while (P!=NULL)
    {
        if (key==P->data)
        {
            q->next=P->next;
            P->next=first;
            first = P;
            return P;
        }
        q=P;
        P=P->next;
    }

    return NULL;
    
}

int main()
{

    int A[] = {3, 5, 7, 12, 15};
    create(A, 5);
    struct Node *ans = Search(first,15);
    Display(first);
    // printf("%d",ans->data);
    return 0;
}
