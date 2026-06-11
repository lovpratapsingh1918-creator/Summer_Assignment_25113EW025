# include <stdio.h>

int factorial(int x){
    if (x == 0 || x ==1 ){
        return 1;
    }
    return x * factorial(x-1);
}
int main(){
    int num ;
    printf("enter a number=");
    scanf("%d",&num);

    printf("the value of factorial of %d is %d ",num,factorial(num));

    return 0 ;

}