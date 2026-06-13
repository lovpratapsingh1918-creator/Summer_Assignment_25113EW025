# include <stdio.h>
int main (){
    int i , len , A[20] ;
    float sum = 0.0 ;

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

    for(i = 0 ; i < len ; i++){
        sum = sum + A[i] ;
    } 

    printf(" \n the sum of array is = %.2f\n",sum);
    printf("the average of array elements is = %.2f\n ",(sum/len));

    return 0 ;
}