# include <stdio.h>
int main (){
    int A[30] , i , j , len , temp ;
    printf("enter the number of elements=");
    scanf("%d",&len);
    for(i = 0 ; i < len ; i++){
        printf("enter the value of A[%d]=",i);
        scanf("%d",&A[i]);
    }
    printf("entered elements are = [");
    for(i = 0 ; i < len ; i++){
    printf("%d",A[i]);
    if (i < len -1){
        printf(",");
    }
    }
    printf("]");
    for(i = 0 ; i < len -1 ; i++){
        for (j = 0 ; j < len - 1 - i ;j++){
        if (A[j] > A[j + 1]){
        temp = A[j] ;
        A[j] = A[j + 1] ;
        A[j + 1] = temp ; 
        }
        }
    }
    printf("\nthe sorted array = [");
    for(i = 0 ; i < len ; i++){
    printf("%d",A[i]);
    if (i < len -1){
        printf(",");
    }
    }
    printf("]");
    return 0 ;
}