// Count and Height of a Tree
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
// #include "Stack.h"
    struct Node *root = NULL;

void Treecreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);
    printf("Eneter root value ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);
    while (!isEmpty(q))
    {
        p = dequeue(&q);
        printf("eneter left child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("eneter right child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}
int count(struct Node *root)
{
    if (root)
        return count(root->lchild) + count(root->rchild) + 1;
    return 0;
}

int leafCount(struct Node *root)
{
    if (root == NULL)
        return 0;
    if (root->lchild == NULL && root->rchild == NULL)
        return 1;
    return leafCount(root->lchild) + leafCount(root->rchild);
}

int height(struct Node *root)
{
    int x = 0, y = 0;
    if (root == 0)
        return 0;
    x = height(root->lchild);
    y = height(root->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}



void getWidth(struct Node *root, int *count, int level)
{
    if (root)
    {
        count[level]++;
        getWidth(root->lchild, count, level + 1);
        getWidth(root->rchild, count, level + 1);
    }
}

int getMax(int *count, int h)
{
    int max = count[0];
    int i;
    for (i = 0; i < h; i++)
    {
        if (count[i] > max)
            max = count[i];
    }
    return max;
}

int width(struct Node *root)
{
    int h = height(root);
    int *count = (int *)calloc(h, sizeof(int));
    count[0] = 1;
    int level = 0;
    getWidth(root, count, level);
    int max = getMax(count, h);
    return max;
}
int main()
{
    Treecreate();
    printf("Number of Nodes: %d", count(root));
    printf("\n");
    printf("Height of a tree: %d", height(root));
    printf("\n");
    printf("Number of leaf nodes: %d", leafCount(root));
    printf("\n");
    printf("Width of a tree: %d", width(root));
    return 0;
}