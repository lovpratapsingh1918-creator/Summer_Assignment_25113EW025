# include <stdio.h>
int main (){
    int i , j , A[20] , len , sum , search = -1 ;

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
    printf("\n enter the sum of pairs =");
    scanf("%d",&sum);

    for(i = 0 ; i < len ; i++){
        for (j = i + 1 ; j < len ; j++){
            if (sum == A[i] + A[j]){
                printf("the %d is the sum of %d and %d \n",sum , A[i] , A[j]);
                search = 0 ;
            }
        }
    }
    if (search == -1){
        printf("no such pair exist");
    }
    return 0 ;
}