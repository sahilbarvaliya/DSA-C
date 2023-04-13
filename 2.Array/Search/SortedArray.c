#include <stdio.h>
struct Array
{
    int A[10];
    int size;
    int lenght;
};

void Display(struct Array arr)
{
    for (int i = 0; i < arr.lenght; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

void swap(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

void InsertSort(struct Array *arr, int x)
{
    int i = arr->lenght - 1;
    if (arr->lenght == arr->size)
    {
        return;
    }

    while (i >= 0 && arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->lenght++;
}

int isSorted(struct Array arr)
{
    for (int i = 0; i < arr.lenght - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

int Rearrange(struct Array *arr){
    int i,j;
    i=0;
    j=arr->lenght-1;

    while (i<j)
    {
        while(arr->A[i]<0)i++;
        while(arr->A[i]>=0)j--;
        if (i<j)
        {
            swap(&arr->A[i],&arr->A[j]);
        }
        
    }
    
}

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    struct Array arr1={{2,-3,25,10,-15},10,5};

    // InsertSort(&arr, 1);
    // Display(arr);
    // printf("\n%d\n",isSorted(arr));
    Rearrange(&arr1);
    Display(arr1);
    return 0;
}