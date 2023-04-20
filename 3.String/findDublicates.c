#include<stdio.h>

int main(){

    char A[] = "finding for dublicates";  
    int H[26] = {0};
    int i;

    for(i=0; A[i]!='\0'; i++){
        H[A[i]-97] += 1;
    }

    for(i=0; i<26; i++){
        if(H[i]>1){
            printf("%c is dublicate %d times\n", i+97, H[i]);
        }
    }

    return 0;
}