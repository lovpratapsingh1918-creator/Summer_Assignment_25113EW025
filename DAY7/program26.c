#include <stdio.h>
int fabonacci(int n){
    if (n == 0){
        return 0 ;
    }
    else if (n == 1){
        return 1 ;
    }
    else {
        return fabonacci(n-1) + fabonacci(n-2);
    }
}
int main(){
    int terms , i ;
    printf("enter the number of terms=");
    scanf("%d",&terms);
    printf("the fabonacci series is=");
    for (i = 0 ; i < terms ; i++){
        printf(" %d ",fabonacci(i));
    }
}