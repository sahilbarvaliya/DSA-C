#include <stdio.h>
struct Array
{
    int A[10];
    int size;
    int lenght;
};

int LinearSearch(struct Array arr, int key)
{
    for (int i = 0; i < arr.lenght; i++)
    {
        if (key == arr.A[i])
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    printf("%d", LinearSearch(arr, 5));
    return 0;
}