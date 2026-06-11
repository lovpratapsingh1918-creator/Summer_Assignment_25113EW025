# include <stdio.h>
int reverse(int n){
    int rem , sum = 0;  
    while( n > 0){
    rem = n % 10 ;
    sum = sum * 10 + rem ;
    n = n / 10 ;
    }
    if (n == 0){
        return sum;
    }
}
int main(){
    int num;
    printf("enter the number=");
    scanf("%d",&num);
    printf("sum of digits of %d is %d",num,reverse(num));
    return 0;
}