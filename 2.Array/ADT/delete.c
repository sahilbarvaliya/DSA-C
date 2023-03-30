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

int delete(struct Array *arr,int index){
    int x=0,i;

    if (index>0 && index<arr->length)
    {
        x=arr->A[index];
        for ( i = index; i < arr->length-1; i++)
        {
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
        return x;
    }

    return 0;
}


int main(int argc, char const *argv[])
{
    struct Array arr = {{1, 2, 3, 4, 5},10,5};
    Display(arr);
    int deletedItem = delete(&arr,2);
    printf("Deleted items: %d\n",deletedItem);
    Display(arr);
    
    return 0;
}
