# include <stdio.h>
int main (){
    int i , A[20] , len , totalsum , sum , num , missing ;

    printf("enter number of elements=");
    scanf("%d",&len);

    for(i = 0 ; i < len ; i++){
    printf("enter value for A[%d]=",i);
    scanf("%d",&A[i]);
    }

    printf("entered array is = [");

    for ( i = 0 ; i < len ; i++){
    printf(" %d ",A[i]);
    if (i < len - 1){
        printf(",");
    }
    }

    printf("]");

    num = A[0] ;
    for(i=1 ; i <len ; i++){
    if (num < A[i]){
        num = A[i] ;
    }
    }
    totalsum = (num * (num + 1)) / 2 ;
    sum = 0 ;

    for ( i = 0 ; i < len ; i++){
    sum = sum + A[i] ;
    }
    missing = totalsum - sum ;
    printf("\n the missing element is = %d",missing);
}