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
    temp = 0 ;
    for (i = 0 ; i < len ; i++ ){
    if (A[i] != 0){
        A[temp] = A[i] ;
        temp++ ;
    }
    }
    for (i = temp + 1 ; i < len ; i++){
        A[i] = 0 ;
    }

    printf("\nthe arranged array = [");
    for ( i = 0 ; i < len ; i++){
    printf(" %d ",A[i]);
    if (i < len - 1){
        printf(",");
    }
    }

    printf("]");
}