# include <stdio.h>
int main (){
    int i , A[20] , len , search , index = -1 ;

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
    
    printf (" \n enter the element to search = ");
    scanf("%d",&search);

    for (i = 0 ; i < len ; i++){
        if (search == A[i]){
            index = i ;
        }
    }
    if (index == -1){
        printf("element is not found");
    }
    else{
        printf("the index of searched element is %d",index);
    }
    return 0 ;
}