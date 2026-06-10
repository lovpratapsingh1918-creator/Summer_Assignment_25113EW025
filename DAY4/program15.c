# include <stdio.h>
# include <math.h>
int main(){
    int num, n, rem, sum, len = 0 ;

    printf("enter a number=");
    scanf("%d",&num);
    
    n = num;

    while(n>0){
    n=n/10 ;
    len = len + 1;
    }

    n = num ;
    sum = 0 ; 

    while(n > 0){
        rem = n % 10 ;
        sum = sum + pow( rem , len );
        n = n / 10 ;
    }

    if (sum == num){
        printf("%d is a armstrong number", num);
    }
    else{
        printf("%d is not a armstrong number", num);
    }

}