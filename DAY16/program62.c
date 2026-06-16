# include <stdio.h>
int main (){
    int i , j , A[20] , len , search = 0 , count , max = 0 ;

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

    for(j = 0 ; j < len ; j++){
        count = 0 ;
    for (i = j ; i < len ; i++){
        if (A[j] == A[i]){
            count++ ;
        }
    }
    if (count > max){
        max = count ;
        search = A[j] ;
    }
    }
        printf("\n the maximum frequency in array is of  %d - %d",search , max);
    
    return 0 ;
}