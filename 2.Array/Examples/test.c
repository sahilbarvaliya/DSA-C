#include<stdio.h>
#include<stdlib.h>

struct point
{
    int x;
    int y;
};

struct point* fun(int a,int b){
    struct point *ptr = (struct point *)malloc(sizeof(struct point));
    ptr->x=a;
    ptr->y=b+5;
    return ptr;

}

int main(){

    struct point *ptr1;
    ptr1=fun(2,3);

    return 0;
}