# include <stdio.h>
int main (){
    int i , j , A[20] , len , isduplicate ;
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
    }   }
    printf("]\n"); 

    printf(" \n duplicate elements are =");
    for (i = 0 ; i < len ; i++){
        isduplicate = 0 ;
        for (j = 0 ; j < i ; j++){
        if (A[i] == A[j]){
            isduplicate = 1 ;
            break ;
        }  }
    if (!isduplicate){
       for (j = i + 1 ; j < len ; j++){
        if (A[i] == A[j]){
            printf("%d ",A[i]);
            break;
    } } } }
    return 0 ; 
}