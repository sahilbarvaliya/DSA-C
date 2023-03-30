#include<stdio.h>

// int fib(int n){
//     int t0=0,
//     t1=1,
//     s=0,i;

//     if (n<=1){
//         printf("%d",n);
//         return n;
//     } 
    
//     printf("%d %d ",t0,t1);
//     for (i = 2; i <= n; i++)
//     {
//         s=t0+t1;
//         printf("%d ",s);
//         t0=t1;
//         t1=s;
//     }

//     return s;

// }

// int fib(int n){
//     if (n<=1) return n;
//     return fib(n-2)+fib(n-1);    
// }

// memoizetion
int F[10];

int mfib(int n){
    if(n<=1){
        F[n]=n; 
        return n;
    }else{
        if (F[n-2]==-1)
        {
            F[n-2]=mfib(n-2);
        }
        if (F[n-1]==-1)
        {
            F[n-1]=mfib(n-1);
        }
        return F[n-2]+F[n-1];
    }
    
}

int main(){

    int i;
    for (i = 0; i < 10; i++)
    {
        F[i]=-1;
    }
    

    printf("\nAns=%d",mfib(10));
    // printf("\nAns=%d",fib(10));

    return 0;
}