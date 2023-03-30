#include <stdio.h>
struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("Elements are :");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ",arr.A[i]);
    }
        printf("\n ");
}

void Append(struct Array *arr,int x){
    if (arr->size>arr->length)
    {
        arr->A[arr->length++]=x;
    }
}

void  insert(struct Array *arr,int index,int x){
    if (index>=0 && index<= arr->length)
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=x;
        arr->length++;
        
    }
    
}

int main(int argc, char const *argv[])
{
    struct Array arr = {{1, 2, 3, 4, 5},10,5};
    Append(&arr, 6);
    Display(arr);
    insert(&arr, 5,10);
    Display(arr);
    return 0;
}
