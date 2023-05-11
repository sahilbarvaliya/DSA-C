#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int size;
    int top;
    char *S;
};

void Create(struct Stack *st, char *str)
{
    int len = strlen(str);
    st->size = len;
    st->top = -1;
    st->S = (char *)malloc(st->size * sizeof(char));
    strcpy(st->S, str);
}

void Dispaly(struct Stack st)
{
    for (int i = 0; st.S[i] != '\0'; i++)
        printf("%c ", st.S[i]);
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

void Push(struct Stack *st, char data)
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

char Pop(struct Stack *st)
{
    char x = -1;

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

int isBalanced(struct Stack st)
{
    for (int i = 0; st.S[i] != '\0'; i++)
    {
        if (st.S[i] == '(')
            Push(&st, st.S[i]);
        else if (st.S[i] == ')')
        {
            if (isEmpty(&st))
                return 0;
            Pop(&st);
        }
    }
    return isEmpty(&st) ? 1 : 0;
}

int main()
{

    struct Stack st;
    char *str = "((a+b)*(c-d))";

    Create(&st, str);
    isBalanced(st) ? printf("Balanced\n") : printf("Not Balanced\n");
    Dispaly(st);
    return 0;
}
