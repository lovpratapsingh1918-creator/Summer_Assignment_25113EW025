# include <stdio.h>
int main (){
    int A[30] , i , j , len , min , index , temp ;
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
    for(i = 0 ; i < len ; i++){
        min = A[i] ;
        index = i ;
        for (j = i + 1 ; j < len ; j++){
        if (min > A[j]){
            min = A[j] ;
            index = j ;
        }
        }
        temp = A[i] ;
        A[i] = min ;
        A[index] = temp ;
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