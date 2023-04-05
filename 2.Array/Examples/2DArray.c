#include<stdio.h>
#include<stdlib.h>

int main(){

    int A[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int *B[3];
    int **C;
    int i,j;

    B[0]=(int *)malloc(4*sizeof(int));
    B[1]=(int *)malloc(4*sizeof(int));
    B[2]=(int *)malloc(4*sizeof(int));

    C=(int **)malloc(3*sizeof(int *));
    C[0]=(int *)malloc(4*sizeof(int));
    C[1]=(int *)malloc(4*sizeof(int));
    C[2]=(int *)malloc(4*sizeof(int));


    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         printf("%d ",A[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         printf("%d ",B[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    
    
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         printf("%d ",C[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

    int S[4][3]={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%u ",&S[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("%d ",S+3);
    printf("%d ",*(S+3));
    printf("%d ",*(S+2)+3);
    
    return 0;
}