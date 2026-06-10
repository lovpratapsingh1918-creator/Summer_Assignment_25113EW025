# include <stdio.h>
int main(){
    int num, fact, i, sum, n, rem;

    printf("enter a number=");
    scanf("%d",&num);
    
    n = num ;
    sum = 0 ;

    while(n>0){
        fact = 1 ;
        rem = n % 10 ;
        for (i=1 ; i <= rem ; i++){
            fact = fact * i ;
        }
        sum = sum + fact ;
        n = n / 10 ;
    }
    if (sum == num){
        printf("%d is strong number",num);
    }
    else{
        printf("%d is not a strong number",num);
    }

}