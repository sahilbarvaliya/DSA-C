#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *S;
};

void Create(struct Stack *st)
{
    printf("Enter the size of stack: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));
}

void Dispaly(struct Stack st)
{
    for (int i = st.top; i >= 0; i--)
        printf("%d ", st.S[i]);
    printf("\n");
}

int isFull(struct Stack *st)
{
    return st->size - 1 == st->top ? 1 : 0;
}

int isEmpty(struct Stack *st)
{
    return st->top == -1 ? 1 : 0;
}

void Push(struct Stack *st, int data)
{
    if (isFull(st))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        st->top++;
        st->S[st->top] = data;
    }
}

int Pop(struct Stack *st)
{
    int x = -1;

    if (isEmpty(st))
    {
        printf("Stack underflow\n");
    }
    else
    {
        x = st->S[st->top--];
    }
    return x;
}

int peek(struct Stack *st, int index)
{
    int x = -1;
    if (st->top - index + 1 < 0)
    {
        printf("Invalid Index \n");
    }
    x = st->S[st->top - index + 1];

    return x;
}

int stackTop(struct Stack *st)
{
    if (isEmpty(st))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        return st->S[st->top];
    }
    return -1;
}

int main()
{
    struct Stack st;
    Create(&st);
    Push(&st, 10);
    Push(&st, 20);
    Push(&st, 30);
    Push(&st, 40);
    Push(&st, 50);
    Push(&st, 60);

    Dispaly(st);
    printf("Poped element : %d\n", Pop(&st));
    Dispaly(st);
    printf("Peek element: %d\n", peek(&st, 2));
    printf("Top element: %d\n", stackTop(&st));

    return 0;
}