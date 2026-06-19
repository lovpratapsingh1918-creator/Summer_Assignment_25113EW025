#include <stdio.h>
int main(){
    int i , j , A[5][5] , order , temp ;
    printf("enter the order of matrix=");
    scanf("%d",&order);
    printf("enter the elements in matrix A =\n");
    for(i = 1 ; i <= order ; i++){
        for(j = 1 ; j <= order ; j++){
            printf("enter the value of A[%d][%d]=",i,j);
            scanf("%d",&A[i][j]);
        }
    }
    printf("entered matrix =\n");
    for(i = 1 ; i <= order ; i++){
        printf("[");
        for(j = 1 ; j <= order ; j++){
            printf("%d  ",A[i][j]) ;
        }
        printf("]\n") ;
    }
    for(i = 1 ; i <= order ; i++){
        for(j = i + 1 ; j <= order ; j++){
            temp = A[i][j] ;
            A[i][j] = A[j][i] ;
            A[j][i] = temp ;
        }
    }
    printf("transpose of matrix =\n");
    for(i = 1 ; i <= order ; i++){
        printf("[");
        for(j = 1 ; j <= order ; j++){
            printf("%d  ",A[i][j]) ;
        }
        printf("]\n") ;
    }
}