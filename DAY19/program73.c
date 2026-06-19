# include <stdio.h>
int main(){
    int i , j , A[5][5] , B[5][5] , C[5][5] , row , column ;
    printf("enter the order of matrix \n");
    printf("enter the number of rows=");
    scanf("%d",&row);
    printf("enter the number of columns=");
    scanf("%d",&column);
    printf("enter the elements in matrix A =\n");
    for(i = 0 ; i < row ; i++){
        for(j = 0 ; j < column ; j++){
            printf("enter the value of A[%d][%d]=",i,j);
            scanf("%d",&A[i][j]);
        }
    }
    printf("\nenter the elements in matrix B=\n");
    for(i = 0 ; i < row ; i++){
        for(j = 0 ; j < column ; j++){
            printf("enter the value of B[%d][%d]=",i,j);
            scanf("%d",&B[i][j]);
        }
    }
    for(i = 0 ; i < row ; i++){
        for(j = 0 ; j < column ; j++){
            C[i][j] = A[i][j] + B[i][j] ;
        }
    }
    printf("\nsum of matrixes=");
    for(i = 0 ; i < row ; i++){
        printf("[");
        for(j = 0 ; j < column ; j++){
            printf("%d  ",C[i][j]) ;
        }
        printf("]\n") ;
    }
    return 0 ;
            
}