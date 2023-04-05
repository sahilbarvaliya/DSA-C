#include <stdio.h>
struct Array
{
    int A[10];
    int size;
    int lenght;
};

int BinarySearch(struct Array arr, int key)
{
    int l = 0, mid, h;
    h = arr.lenght - 1;

    while (l <= h)
    {
        mid = (l + h) / 2;

        if (key == arr.A[mid])
        {
            return mid;
        }
        else if (key < arr.A[mid])
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

int BinarySearchRecursion(int a[], int l, int h, int key)
{
    int mid;
    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == a[mid])
        {
            return mid;
        }
        else if (key < a[mid])
        {
            return BinarySearchRecursion(a, l, mid - 1, key);
        }
        else
        {
            return BinarySearchRecursion(a, mid + 1, h, key);
        }
    }

    return -1;
}

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    printf("%d", BinarySearch(arr, 4));
    printf("\n%d", BinarySearchRecursion(arr.A, 0, arr.lenght, 4));
    return 0;
}