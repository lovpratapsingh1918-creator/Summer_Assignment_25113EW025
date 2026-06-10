# include <stdio.h>
int main (){
    int num, i, sum;

    printf("enter a number=");
    scanf("%d",&num);

    sum = 0 ;

    for (i = 1 ; i <= num/2 ; i++){
        if (num % i == 0){
            sum = sum + i ;
        }
    }
    if (sum == num){
        printf("%d is perfect number",num);
    }
    else{
        printf("%d is not perfect number",num);
    }

}