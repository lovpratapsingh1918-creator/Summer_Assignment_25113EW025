# include <stdio.h>
int main (){
    int i , A[20] , max1 , max2 , len ;

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
    printf("]") ;
    }
    max1 = A[0] ;
    max2 = A[0] ;
    for (i = 0 ; i < len ; i++){
        if (max1 < A[i]){
            max2 = max1 ;
            max1 = A[i] ;
        }
    }
    printf(" \n the second largest element= %d \n",max2) ;
    return 0 ;

}