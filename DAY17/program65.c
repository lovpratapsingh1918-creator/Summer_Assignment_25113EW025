# include <stdio.h>
int main (){
    int i , A[10] , B[10] , C[20] ;
    printf("enter the elements in array A \n");

    for(i = 0 ; i < 10 ; i++){
    printf("enter value for A[%d]=",i);
    scanf("%d",&A[i]);
    }
    
   printf("enter the elements in array B=\n");

    for(i = 0 ; i < 10; i++){
    printf("enter value for B[%d]=",i);
    scanf("%d",&B[i]);
    }

    printf("entered elements in array A are = [");

    for ( i = 0 ; i < 10 ; i++){
    printf(" %d ",A[i]);
    if (i < 9){
        printf(",");
    }
    }
    printf("]\n");
    printf("entered elements in array B are = [");

    for ( i = 0 ; i < 10 ; i++){
    printf(" %d ",B[i]);
    if (i < 9){
        printf(",");
    }
    }
    printf("]\n");
    for (i = 0 ; i < 20 ; i++){
        if (i < 10){
            C[i] = A[i] ;
        }
        if (i > 9){
            C[i] = B[i - 10] ;
        }
    }
    printf("array after union= [") ;
     for ( i = 0 ; i < 20 ; i++){
    printf(" %d ",C[i]);
    if (i < 19){
        printf(",");
    }
    }
    printf("]\n");
    return 0 ;
}