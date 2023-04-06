#include <stdio.h>
struct Array
{
    int A[10];
    int size;
    int lenght;
};

void Display(struct Array arr){
    for (int i = 0; i < arr.lenght; i++)
    {
        printf("%d ",arr.A[i]);
    }
    
}

void swap(int *x,int *y){
    int temp;

    temp=*x;
    *x=*y;
    *y=temp;
}

void reverse(struct Array *arr){
    int i,j;
    for (int i = 0,j=arr->lenght-1; i < j; i++,j--)
    {
        swap(&arr->A[i],&arr->A[j]);
    }
    
}

void rightShift(struct Array *arr){
    for (int i = arr->lenght-1; i > 0; i--)
    {
        arr->A[i]=arr->A[i-1];
    }
    
}

void leftShift(struct Array *arr){
    for (int i = 0; i < arr->lenght-1; i++)
    {
        arr->A[i]=arr->A[i+1];
    }
    
}

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    reverse(&arr);
    Display(arr);
    printf("\n");
    rightShift(&arr);
    Display(arr);
    printf("\n");
    leftShift(&arr);
    Display(arr);
    
    return 0;
}