# include <stdio.h>
int main(){
    int num1, num2, i, count;

    printf("enter a number:");
    scanf("%d",&num1);
    printf("enter a number:");
    scanf("%d",&num2);
    

    for(i=2;i<=num1;i++){
        if(num1%i==0 && num2%i==0){
            count=i;
        }
    }
    printf("the greatest common divisor of %d and %d is %d",num1,num2,count);
}