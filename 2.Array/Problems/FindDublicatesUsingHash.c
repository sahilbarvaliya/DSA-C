#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};
void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");

    
}

void *Elements(struct Array *arr1)
{
    int arr3[21]={0};

    
    for (int i = 0; i < arr1->length; i++)
    {   
        arr3[arr1->A[i]] = arr3[arr1->A[i]] + 1;
    }

    for (int i = 0; i < 21; i++)
    {
        if (arr.A[i] >= 1)
        {
            printf("%d is repeating %d times\n",i, arr3[i]);
        }
    }
}
int main()
{
    struct Array arr1 = {{3, 6, 8, 8, 10, 12, 15, 15, 15, 20}, 10, 10};
    Elements(&arr1);
    return 0;
}