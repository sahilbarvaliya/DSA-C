#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Node *root = NULL;

void Insert(int key)
{
    struct Node *t = root;
    struct Node *r, *p;

    if (root == NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while (t != NULL)
    {
        r = t;
        if (key < t->data)
        {
            t = t->lchild;
        }
        else if (key > t->data)
        {
            t = t->rchild;
        }
        else
        {
            return;
        }
    }
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;

    if (key < r->data)
    {
        r->lchild = p;
    }
    else
    {
        r->rchild = p;
    }
}

void Inoreder(struct Node *p)
{
    if (p)
    {
        Inoreder(p->lchild);
        printf("%d ", p->data);
        Inoreder(p->rchild);
    }
}

struct Node *Search(int key)
{
    struct Node *t = root;

    while (t != NULL)
    {
        if (key == t->data)
        {
            return t;
        }
        else if (key < t->data)
        {
            t = t->lchild;
        }
        else
        {
            t = t->rchild;
        }
    }
    return NULL;
}

int main()
{
    struct Node *temp;
    Insert(10);
    Insert(5);
    Insert(20);
    Insert(8);

    Inoreder(root);

    temp = Search(21);

    if (temp)
    {
        printf("element %d is found", temp->data);
    }
    else
    {
        printf("\nelememt is not found");
    }

    return 0;
}