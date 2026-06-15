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

    temp = A[0] ;
    for (i = 0 ; i < len - 1; i++ ){
    A[i] = A[i + 1] ;
    }
    A[len - 1] = temp ;
    printf("\nthe left rotataed array is = [");
    for ( i = 0 ; i < len ; i++){
    printf(" %d ",A[i]);
    if (i < len - 1){
        printf(",");
    }
    }

    printf("]");
}