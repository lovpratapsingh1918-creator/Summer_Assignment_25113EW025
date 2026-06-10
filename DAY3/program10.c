# include <stdio.h>
int main(){
    int num, i;

    printf("enter a number upto which you want to print prime numbers:");
    scanf("%d",&num);

    printf("the prime numbers in the range are:");

    for(i=2;i<=num/2;i++){
        if(num%i==0){
            printf("%d  ",i);
            
        }
    }
    }