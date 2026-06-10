# include <stdio.h>
# include <math.h>
int main(){
    int num, n, rem, sum, i , len = 0 ;

    printf("enter the range =");
    scanf("%d", &num);

    for (i = 0 ; i <= num ; i++){
    
    n = i;
    len = 0;

    while(n>0){
    n=n/10 ;
    len = len + 1;
    }

    n = i ;
    sum = 0 ; 

    while(n > 0){
        rem = n % 10 ;
        sum = sum + pow( rem , len );
        n = n / 10 ;
    }

    if (sum == i){
        printf("%d is a armstrong number\n", i);
    }
    }

}