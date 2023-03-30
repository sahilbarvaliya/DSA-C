// algorithm for counting sort

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    int B[10], C[21];
    int i, j, k = 0;

    for (i = 0; i < 21; i++)
    {
        C[i] = 0;
    }

    for (i = 0; i < 10; i++)
    {
        C[A[i]]++;
    }

    

    for (i = 0; i < 21; i++)
    {
        if (C[i] > 0)
        {
            for (j = 0; j < C[i]; j++)
            {
                B[k++] = i;
            }
        }
    }

    for (i = 0; i < 10; i++)
    {
        printf("%d ", B[i]);
    }

    return 0;
}

// algorithm for counting sort

// 1. Find the maximum element in the array
// 2. Create an array of size max+1
// 3. Initialize all the elements of the array to 0
// 4. Iterate through the array and increment the value of the index of the count array by 1
// 5. Iterate through the count array and print the index of the count array for the number of times the value of the count array is greater than 0
// 6. The index of the count array is the sorted array
// 7. Time complexity is O(n+k) where n is the number of elements in the array and k is the range of the elements in the array
// 8. Space complexity is O(n+k)
// 9. Counting sort is used when the range of the elements in the array is small
// 10. Counting sort is not a comparison based sorting algorithm
// 11. Counting sort is a stable sorting algorithm
// 12. Counting sort is not a comparison based sorting algorithm
// 13. Counting sort is not a comparison based sorting algorithm
// 14. Counting sort is not a comparison based sorting algorithm


