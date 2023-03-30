#include<stdio.h>

void TOH(int n,int A,int B,int C){
    if (n>0)
    {
        TOH(n-1,A,C,B);
        printf("Move %d to %d\n",A,C);
        TOH(n-1,B,A,C);
    }
    
}

void c(int n){
    static int d=1;
    printf("%d",n);
    printf("%d",d);
    d++;
    if (n>1)c(n-1);
    printf("%d",d);
}

int main(){
    c(3);
    // TOH(3,1,2,3);

    return 0;
} 