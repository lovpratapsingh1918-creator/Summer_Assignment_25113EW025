# include <stdio.h>
int palindrome(int n){
    int a , rem , sum ;
    a = n ;
    sum = 0 ;
    while(a > 0){
        rem = a % 10 ;
        sum = sum * 10 + rem ;
        a = a / 10 ;
    }
    if (sum == n){
        printf("the %d is a palindrome number",n);
    }
    else {
        printf("the %d is not a palindrome number",n);
    }
}
int main(){
    int num ;

    printf("enter a number=");
    scanf("%d",&num);
    palindrome(num);
}