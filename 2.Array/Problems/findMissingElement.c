#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void findMissingElements(struct Array arr){
    int diff=arr.A[0]-0;

    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i]-i != diff)
        {
            printf("%d ",i+diff);
        }
    }
    
}

int main()
{
    struct Array arr = {{1, 2, 3, 4, 8}, 10, 5};

    findMissingElements(arr);
    return 0;
}