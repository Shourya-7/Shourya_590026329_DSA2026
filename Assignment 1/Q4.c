#include <stdio.h>
#include <stdlib.h>

int main() {
    int r,c,i,j;
    scanf("%d%d",&r,&c);

    int **A = malloc(r*sizeof(int*));
    int **B = malloc(r*sizeof(int*));

    for(i=0;i<r;i++){
        A[i]=malloc(c*sizeof(int));
        B[i]=malloc(c*sizeof(int));
    }

    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d",&A[i][j]);

    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d",&B[i][j]);

    printf("Addition:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
            printf("%d ",A[i][j]+B[i][j]);
        printf("\n");
    }

    printf("Subtraction:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
            printf("%d ",A[i][j]-B[i][j]);
        printf("\n");
    }

    for(i=0;i<r;i++){
        free(A[i]);
        free(B[i]);
    }
    free(A);
    free(B);
}
