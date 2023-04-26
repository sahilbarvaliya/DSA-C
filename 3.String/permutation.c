#include <stdio.h>

void perm(char S[], int K)
{
    static int A[10] = {0};
    static char Res[10];

    int i;
    if (S[K] == '\0')
    {
        Res[K] = '\0';
        printf("%s\n", Res);
    }
    else
    {
        for (i = 0; S[i] != '\0'; i++)
        {
            if (A[i] == 0)
            {
                Res[K] = S[i];
                A[i] = 1;
                perm(S, K + 1);
                A[i] = '\0';
            }
        }
    }
}

void swap(char *x, char *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

void perms(char S[], int l, int h)
{
    int i;

    if (l == h)
    {
        printf("%s\n", S);
    }
    else
    {
        for (i = l; i <= h; i++)
        {
            swap(&S[l], &S[i]);
            perms(S, l + 1, h);
            swap(&S[l], &S[i]);
        }
    }
}

int main()
{
    char S[] = "ABCD";
    // perm(S,0);
    perms(S, 0, 3);
    return 0;
}