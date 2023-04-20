// Input: queries = [3,1,2,1], m = 5
// Output: [2,1,2,1]
// Explanation: The queries are processed as follow:
// For i=0: queries[i]=3, P=[1,2,3,4,5], position of 3 in P is 2, then we move 3 to the beginning of P resulting in P=[3,1,2,4,5].
// For i=1: queries[i]=1, P=[3,1,2,4,5], position of 1 in P is 1, then we move 1 to the beginning of P resulting in P=[1,3,2,4,5].
// For i=2: queries[i]=2, P=[1,3,2,4,5], position of 2 in P is 2, then we move 2 to the beginning of P resulting in P=[2,1,3,4,5].
// For i=3: queries[i]=1, P=[2,1,3,4,5], position of 1 in P is 1, then we move 1 to the beginning of P resulting in P=[1,2,3,4,5].
// Therefore, the array containing the result is [2,1,2,1].

#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
    int m;
};

void processQueries(struct Array arr)
{
    int queryLength = arr.m, k = 0;
    int B[10];
    int *res = malloc(sizeof(int) * queryLength);

    for (int i = 0; i < queryLength; i++)
    {
        B[i] = i + 1;
    }

    for (int i = 0; i < arr.length; i++)
    {
        int temp = arr.A[i];

        for (int j = 0; j < queryLength; j++)
        {
            if (B[j] == temp)
            {
                res[k++] = j;
                move(&B,queryLength,j);
            }
        }
    }

    for (int i = 0; i < queryLength; i++)
    {
        printf("%d ", res[i]);
    }
}

void move(int arr,int queryLength,int pos){

    for (int i = 1; i <= pos; i++)
    {
        B[i]=
    }
    
}

int main()
{
    struct Array arr = {{3, 1, 2, 1}, 10, 4, 5};

    processQueries(arr);
    return 0;
}