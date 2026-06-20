# include <stdio.h>
int main(){
    int i , j , k , A[10][10] , B[10][10] , C[10][10] , row1 , column1 , row2 , column2 ;
    printf("enter the order of matrix A \n");
    printf("enter the number of rows=");
    scanf("%d",&row1);
    printf("enter the number of columns=");
    scanf("%d",&column1);
    printf("enter the order of matrix B \n");
    printf("enter the number of rows=");
    scanf("%d",&row2);
    printf("enter the number of columns=");
    scanf("%d",&column2);
    printf("enter the elements in matrix A =\n");
    if (column1 != row2){
        printf("multiplication of matrixes is not possible");
        return 0;
    }
    for(i = 0 ; i < row1 ; i++){
        for(j = 0 ; j < column1 ; j++){
            printf("enter the value of A[%d][%d]=",i,j);
            scanf("%d",&A[i][j]);
        }
    }
    printf("\nenter the elements in matrix B=\n");
    for(i = 0 ; i < row2 ; i++){
        for(j = 0 ; j < column2 ; j++){
            printf("enter the value of B[%d][%d]=",i,j);
            scanf("%d",&B[i][j]);
        }
    }
    printf("entered elements of A=\n");
    for(i = 0 ; i < row1 ; i++){
        printf("[");
        for(j = 0 ; j < column1 ; j++){
            printf("%d  ",A[i][j]) ;
        }
        printf("]\n") ;
    }
    printf("entered elements of B=\n");
    for(i = 0 ; i < row2 ; i++){
        printf("[");
        for(j = 0 ; j < column2 ; j++){
            printf("%d  ",B[i][j]) ;
        }
        printf("]\n") ;
    }

    for(i = 0 ; i < row1 ; i++){
        for(j = 0 ; j < column2 ; j++){
            C[i][j] = 0 ;
            for (k = 0 ; k < column1 ; k++){
                C[i][j] += A[i][k] * B[k][j] ;
            }
        }
    }
    printf("\n multiplication of matrixes= \n ");
    for(i = 0 ; i < row1 ; i++){
        printf("[");
        for(j = 0 ; j < column2 ; j++){
            printf("%d  ",C[i][j]) ;
        }
        printf("]\n") ;
    }
    return 0 ;
            
}