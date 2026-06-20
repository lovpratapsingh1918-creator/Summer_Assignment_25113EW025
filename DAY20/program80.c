# include <stdio.h>
int main(){
    int i , j , k , A[10][10] , row , column , sum;
    printf("enter the order of matrix A \n");
    printf("enter the number of row=");
    scanf("%d",&row);
    printf("enter the number of column=");
    scanf("%d",&column);
    printf("\nenter the elements of matrix A=\n");
    for(i = 0 ; i < row ; i++){
        for(j = 0 ; j < column ; j++){
            printf("enter the value of A[%d][%d]=",i,j);
            scanf("%d",&A[i][j]);
        }
    }
    printf("entered elements of array A=\n");
    for(i = 0 ; i < row ; i++){
        printf("[");
        for(j = 0 ; j < column ; j++){
            printf("%d  ",A[i][j]) ;
        }
        printf("]\n") ;
    }

    for(i = 0 ; i < column ; i++){
        sum = 0 ;
        for(j = 0 ; j < row ; j++){
            sum = sum + A[j][i] ;
            }
        printf("the sum of column%d = %d \n",i + 1, sum);
        }
    return 0 ;
}