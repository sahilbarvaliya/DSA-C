#include<stdio.h>

// int fun(int m,int n){
//     if(n==0){
//         return 1;
//     }else{
//         return fun(m,n-1)*m;
//     }
// }

int fun(int m,int n){
    if(n==0)
        return 1;
    if (n%2==0)
    {
        return fun(m*m,n/2);
    }else{
        return m*fun(m*m,(n-1)/2);
    }
    
}

int main(){
    int m,n,ans;

    ans=fun(2,5);
    printf("%d",ans);

    return 0;
}