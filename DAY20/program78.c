# include <stdio.h>
int main(){
    int i , j , A[10][10] , order ;
    printf("enter the order of matrix A \n");
    scanf("%d",&order);
    printf("\nenter the elements of matrix A=\n");
    for(i = 0 ; i < order ; i++){
        for(j = 0 ; j < order ; j++){
            printf("enter the value of A[%d][%d]=",i,j);
            scanf("%d",&A[i][j]);
        }
    }
    printf("entered elements of A=\n");
    for(i = 0 ; i < order ; i++){
        printf("[");
        for(j = 0 ; j < order ; j++){
            printf("%d  ",A[i][j]) ;
        }
        printf("]\n") ;
    }

    for(i = 0 ; i < order ; i++){
        for(j = 0 ; j < order ; j++){
            if (A[i][j] != A[j][i]){
                printf("A is not a symmetric matrix");
                return 0 ;
            }
        }
    }
    printf("\n A is a symmetric matrix \n ");
    return 0 ;
            
}