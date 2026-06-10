# include <stdio.h>
int main(){
    int num, i, count=0;

    printf("enter a number:");
    scanf("%d",&num);

    for(i=2;i<=num/2;i++){
        if(num%i==0){
            count+=1;
        }
    }
    if(count==0){
        printf("the given number is prime");
    }
    else{
        printf("the given number is not prime");
    }
}