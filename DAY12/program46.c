# include <stdio.h>
# include <math.h>
int armstrong(int n){
    int i , a , sum , len , rem ;
    a = n ;
    len = 0 ;
    while (a > 0){
        len++ ;
        a = a / 10 ;
    }
    a = n ;
    sum = 0 ;
    while(a > 0){
        rem = a % 10 ;
        sum = sum + pow(rem,len) ;
        a = a / 10 ;
    }
    if (sum == n){
        printf("the %d is an armstrong number",n);
    }
    else{
        printf("the %d is not an armstrong number",n);
    }

}
int main (){
    int num ;

    printf("enter a number=");
    scanf("%d",&num);

    armstrong(num);

    return 0 ;
}