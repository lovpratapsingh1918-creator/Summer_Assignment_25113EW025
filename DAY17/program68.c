# include <stdio.h>
int main (){
    int i , j , A[10] , B[10] , found ;
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
    printf("the comman elements are= ");
    for(i = 0 ; i < 10 ; i++){
        found = 0;
        for (j = 0 ; j < 10 ; j++){
            if (A[i] == B[j]){
                found++ ;
                break ;
            }
        }
        if (found){
        printf("%d ",A[i]);
        }
    }
    return 0 ;
}