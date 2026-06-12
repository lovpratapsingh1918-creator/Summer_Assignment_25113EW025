# include <stdio.h>
int factorial(int a){
    int i , fact = 1 ;
    for(i = 1 ; i <= a ; i++){
        fact = fact * i ;
    }
    return fact ;
}
int main(){
    int num1 ;

    printf("enter a number=");
    scanf("%d",&num1);

    printf("the factorial of %d is %d",num1, factorial(num1));
    return 0 ;
}