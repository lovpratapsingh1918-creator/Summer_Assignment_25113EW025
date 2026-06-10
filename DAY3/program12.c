# include <stdio.h>
int main(){
    int num1, num2, i;

    printf("enter a number:");
    scanf("%d",&num1);
    printf("enter a number:");
    scanf("%d",&num2);
    
    i=(num1>num2)? num1 : num2;
    while(i % num1 != 0 || i % num2 != 0){
        i++;
    }
    printf(" the lowest common multiple of %d and %d is %d",num1,num2,i);
    return 0;
}