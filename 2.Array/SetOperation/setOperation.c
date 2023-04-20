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
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}

struct Array* Union(struct Array *arr1,struct Array *arr2){
    
}


int main()
{
    struct Array arr1 = {{2, 9, 21, 28, 35}, 10, 5};
    struct Array arr2 = {{2, 3, 16, 18, 28}, 10, 5};
    struct Array *arr3;
    arr3 = Union(&arr1, &arr2);
    Display(*arr3);
    return 0;
}