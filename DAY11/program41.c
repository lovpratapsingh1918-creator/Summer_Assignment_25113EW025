# include <stdio.h>
int sum(int a,int b){
    int c ;
    c = a + b ;
    return c ;
}
int main(){
    int num1 , num2 ;

    printf("enter a number=");
    scanf("%d",&num1);

    printf("enter another number=");
    scanf("%d",&num2);

    printf("the sum of %d and %d is %d",num1, num2, sum(num1,num2));
    return 0 ;
}