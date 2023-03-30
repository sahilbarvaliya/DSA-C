#include<stdio.h>

// int fun(int n){
//     if (n>0)
//     {
//         return fun(n-1)+n;
//     }
//     return 0;
    
// }

// int main()
// {
//     int x = 5;

//     printf("%d",fun(x));
//     return 0;
// }

// Static variable


// int x=0; // work same as static variable
int fun(int n){
    static int x=0;
    if (n>0)
    {
        x++;
        return fun(n-1)+x;
    }
    return 0;
    
}

int main()
{
    int x = 5;

    printf("%d",fun(x));
    return 0;
}
