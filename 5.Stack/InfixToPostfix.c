#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int infixsize;
    int postfixsize;
    char *infixarr;
    char *postfixarr;
};

int isEmpty(struct Stack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct Stack *s)
{
    if (s->top == s->infixsize - 1)
        return 1;
    else
        return 0;
}

void push(struct Stack *s, char ch)
{
    if (isFull(s))
        printf("Stack Overflow\n");
    else
    {
        s->top++;
        s->infixarr[s->top] = ch;
    }
}

char pop(struct Stack *s)
{
    char ch = -1;
    if (isEmpty(s))
        printf("Stack Underflow\n");
    else
    {
        ch = s->infixarr[s->top];
        s->top--;
    }
    return ch;
}

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    else
        return 0;
}

int isOperand(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '(' || ch == ')')
        return 0;
    else
        return 1;
}   

char *InfixToPostfix(struct Stack *s, char *infix)
{
    int i = 0, j = 0;
    char *postfix = (char *)malloc((s->postfixsize + 1) * sizeof(char));
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (precedence(infix[i]) > precedence(s->infixarr[s->top]))
                push(s, infix[i++]);
            else
                postfix[j++] = pop(s);
        }
    }
    while (!isEmpty(s))
        postfix[j++] = pop(s);
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    struct Stack s;
    s.top = -1;
    printf("Enter the size of infix expression: ");
    scanf("%d", &s.infixsize);
    printf("Enter the size of postfix expression: ");
    scanf("%d", &s.postfixsize);
    s.infixarr = (char *)malloc(s.infixsize * sizeof(char));
    s.postfixarr = (char *)malloc(s.postfixsize * sizeof(char));
    printf("Enter the infix expression: ");
    scanf("%s", s.infixarr);
    printf("The postfix expression is: %s\n", InfixToPostfix(&s, s.infixarr));
    return 0;
}