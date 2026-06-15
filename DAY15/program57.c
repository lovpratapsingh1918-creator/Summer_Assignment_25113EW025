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
    
    for (i = 0 ; i < len/2; i++ ){
    temp = A[i] ;
    A[i] = A[len - 1 -i] ;
    A[len - 1 - i] = temp ;
    }
    printf("\nthe reversed array is = [");
    for ( i = 0 ; i < len ; i++){
    printf(" %d ",A[i]);
    if (i < len - 1){
        printf(",");
    }
    }

    printf("]");
}