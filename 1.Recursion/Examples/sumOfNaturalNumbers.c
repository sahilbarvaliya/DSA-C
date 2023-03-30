#include<stdio.h>

// int sum(int n){
//     static int ans = 0;
//     if (n>0)
//     {   
//         ans += n;
//         return sum(n-1);
//     }
//     return ans;
// }

int sum(int n){
    if(n==0){
        return 0;
    }else{
        return sum(n-1)+n;
    }
}

int main(){
    int n=10,ans;

    ans = sum(n);
    printf("%d",ans);
    return 0;
}