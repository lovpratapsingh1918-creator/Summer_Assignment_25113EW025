# include <stdio.h>
int prime(int a){
    int i , count = 0 ;
    for ( i = 2; i <= a/2; i++)
    {
      if (a % i == 0){
        count++ ;
        break ;
      }
    }
    if (count == 0){
        printf("%d is prime number",a);
    }
    else{
        printf("%d is not prime number",a);
    }
    
}
int main(){
    int num1 ;

    printf("enter a number=");
    scanf("%d",&num1);

    prime(num1);
    return 0 ;
}