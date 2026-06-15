# include <stdio.h>
int main (){
    int i , A[20] , len , temp ;

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

    temp = A[len - 1] ;
    for (i = len -1 ; i > 0 ; i-- ){
    A[i] = A[i - 1] ;
    }
    A[0] = temp ;
    printf("\nthe right rotataed array is = [");
    for ( i = 0 ; i < len ; i++){
    printf(" %d ",A[i]);
    if (i < len - 1){
        printf(",");
    }
    }

    printf("]");
}