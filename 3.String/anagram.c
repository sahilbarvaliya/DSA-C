#include<stdio.h>

int main(){

    char A[] = "listen";
    char B[] = "silent";

    int H[26] = {0};

    for (int i = 0; A[i] != '\0'; i++)
    {
        H[A[i]-97] += 1;
    }
    
    for (int i = 0; B[i] != '\0'; i++)
    {
        H[B[i]-97] -= 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if (H[i] != 0)
        {
            printf("Not Anagram");
            return 0;
        }
    }
    printf("Anagram");

    return 0;
}