#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int *A;
    int size;
    int len;
};

void Display(struct Array arr){
    for (int i = 0; i < arr.len; i++)
    {
        printf("%d ",arr.A[i]);
    }
    
}

int main(){

    struct Array arr;
    int i,n;

    printf("Enter the size of array:");
    scanf("%d",&arr.len);

    arr.A=(int *)malloc(arr.size*sizeof(int));
    arr.len=0;

    printf("Enter numbers of elements:");
    scanf("%d",&n);

    for (i = 0; i < n; i++)
    {
        scanf("%d",&arr.A[i]);
    }
    
    arr.len=n;

    Display(arr);



    return 0;
}