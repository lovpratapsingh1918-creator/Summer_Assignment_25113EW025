# include <stdio.h>
int main (){
    int i , j , k , A[20] , len , num;

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
    num = len ;

    for (i = 0 ; i < len ; i++){
        for (j = i + 1 ; j < len ; j++){
            if (A[i] == A[j]){
                for (k = j + 1 ; k < len ; k++){
                A[k - 1] = A[k] ;
                }
            len-- ;
            j-- ;
            }
        }
    }
    for(i = len ; i < num ; i++){
        A[i] = 0 ;
    }
    printf("\n the resultant array is = [");

    for ( i = 0 ; i < num; i++){
    printf(" %d ",A[i]);
    if (i < num - 1){
        printf(",");
    }
    }

    printf("]") ;
    return 0 ;
}
