# include <stdio.h>
int max(int a,int b,int c){
    int d ;
    d = (a>b)?((a>c)?a:c):((b>c)?b:c) ;
    return d ;
}
int main(){
    int num1 , num2 , num3 ;

    printf("enter first number=");
    scanf("%d",&num1);

    printf("enter second number=");
    scanf("%d",&num2);

    printf("enter the third number=");
    scanf("%d",&num3);

    printf("the maximum number between %d , %d and %d is %d",num1, num2, num3, max(num1,num2,num3));
    return 0 ;
}