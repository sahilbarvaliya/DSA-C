#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Node *root = NULL;

struct Node *Insert(struct Node *p, int key)
{
    struct Node *t = NULL;

    if (p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }

    if (key < p->data)
    {
        p->lchild = Insert(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Insert(p->rchild, key);
    }
    return p;
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

struct Node *InPre(struct Node *p)
{
    while (p && p->rchild != NULL)
    {
        p = p->rchild;
    }
    return p;
}

struct Node *InSucc(struct Node *p)
{
    while (p && p->lchild != NULL)
    {
        p = p->lchild;
    }
    return p;
}

int Height(struct Node *p)
{
    return p == NULL ? 0 : Height(p->lchild) > Height(p->rchild) ? Height(p->lchild) + 1
                                                                 : Height(p->rchild) + 1;
}

struct Node *Delete(struct Node *p, int key)
{
    struct Node *q;

    if (p == NULL)
    {
        return NULL;
    }

    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == root)
        {
            root = NULL;
        }
        free(p);
        return NULL;
    }

    if (key < p->data)
    {
        p->lchild = Delete(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Delete(p->rchild, key);
    }
    else
    {
        if (Height(p->lchild) > Height(p->rchild))
        {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

int main()
{
    struct Node *temp;
    root = Insert(root, 50);
    Insert(root, 10);
    Insert(root, 40);
    Insert(root, 20);
    Insert(root, 30);

    printf("\n");
    printf("Before delete\n");
    Inoreder(root);
    printf("\n");
    printf("After delete\n");
    Delete(root, 50);
    Inoreder(root);

    return 0;
}