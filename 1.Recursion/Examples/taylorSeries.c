#include<stdio.h>

// double e(int x,int n){
//     static double p=1,f=1;
//     double r;

//     if (n==0)
//         return 1;
//     r=e(x,n-1);
//     p=p*x;
//     f=f*n;
//     return r+p/f;
    
// }

// double e(int x,int n){
//     static double s;
//     if (n==0)
//         return s;
//     s=1+x*s/n;
//     return e(x,n-1);
// }

double e(int x,int n){
    double s=1,num=1,den=1;
    int i;

    for(i=1;i<=n;i++){
        num*=x;
        den*=i;
        s+=num/den;
    }
    return s;
}


int main(){

    printf("%lf",e(1,15));


    return 0;
}