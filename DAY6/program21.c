# include <stdio.h>
int main (){
    int num, binary[32], decimal, j, i = 0 ;
    printf("enter a number=");
    scanf("%d",&num);
    decimal = num ;
    if (decimal == 0){
    printf("the binary number for 0 is 0");
    return 0 ;
    }
    while (decimal > 0){
        binary[i] = decimal % 2 ;
        decimal = decimal / 2;
        i++ ;
    }
    printf("the binary number for %d is ",num);
    for (j = i - 1 ; j >= 0 ; j--){
        printf("%d",binary[j]);
    }
    return 0 ;

}