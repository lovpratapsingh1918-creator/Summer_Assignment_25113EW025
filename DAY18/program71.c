# include <stdio.h>
int main (){
    int A[30] , i , j , len , key , mid , beg , end , min , index , temp , loc = -1;
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
    printf("]\n");
    printf("enter the element to search=");
    scanf("%d",&key);
    beg = 0;
    end = len - 1 ;
    while(beg <= end){
        mid = (beg + end) / 2 ;
        if (key == A[mid]){
            printf("the %d is found at index %d",key , mid);
            loc = 0 ;
            break ;}
        if (key > A[mid]){
            beg = mid + 1 ;
        }
        else {
            end = mid - 1 ;
        }
    }
    if (loc == -1){
        printf("searched element is not found");
    }
    return 0 ;
}