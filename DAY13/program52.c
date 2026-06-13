# include <stdio.h>
int main (){
    int i , A[20] , even , odd , len ;

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
    printf("]") ;
    even = 0 ;
    odd = 0 ;
    for (i = 0 ; i < len ; i++){
        if (A[i] % 2 == 0){
            even++ ;
        }
        else {
            odd++ ;
        }
    }
    printf(" \n the number of even element= %d \n",even);
    printf("the number of odd element= %d \n",odd);
    return 0 ;

}