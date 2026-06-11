# include <stdio.h>

int main(){
    int num , power , i , sum;

    printf("enter a number=");
    scanf("%d",&num);

    printf("enter the power to calculate=");
    scanf("%d",&power);
    sum = 1 ;
    for(i = 1 ; i <= power ; i++){
    sum = sum * num ;    
    }
    printf(" the value of %d raised to power %d is= %d ",num,power,sum);

}