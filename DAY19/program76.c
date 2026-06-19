# include <stdio.h>
int main (){
    int i , j , A[5][5] , order , temp , sum1 , sum2 ;
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
    sum1 = 0 ;
    sum2 = 0 ;
    for (i = 1 ; i <= order ; i++){
    for (j = 1 ; j<= order ; j++){
        if (i == j){
        sum1 = sum1 + A[i][j];
        }
        if(i + j == order + 1){
            sum2 = sum2 + A[i][j] ;
        }
    }
    }
    printf("the sum of upper diagonal = %d\n",sum1);
    printf("the sum of lower diagonal = %d",sum2);
    return 0 ;
}