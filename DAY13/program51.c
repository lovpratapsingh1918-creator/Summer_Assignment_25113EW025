# include <stdio.h>
int main (){
    int i , A[20] , max , min , len ;

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
    max = A[0] ;
    min = A[0] ;
    for (i = 0 ; i < len ; i++){
        if (max < A[i]){
            max = A[i] ;
        }
        if (min > A[i]){
            min = A[i] ;
        }
    }
    printf(" \n the maximum element= %d \n",max);
    printf("the minimum element= %d \n",min);
    return 0 ;

}