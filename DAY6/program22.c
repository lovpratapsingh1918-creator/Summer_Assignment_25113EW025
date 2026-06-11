# include <stdio.h>
# include <math.h>
int main (){
    int binary[32], decimal = 0, num, i, rem, len;
    
    printf("enter the number of bits=");
    scanf("%d",&len);

    for (i = 0 ; i <= len-1 ; i++){
        printf(" enter the value of a[%d]=",i);
        scanf("%d",&binary[i]);
    }
    printf("the entered binary number is=");
    for (i = 0 ; i <= len-1 ; i++){
        printf(" %d ",binary[i]);
    }

    for (i = len-1 ; i >= 0 ; i--){
    decimal = decimal + binary[len - 1 -i] * pow(2,i);
    }
    printf("the decimal number is=%d",decimal);
    return 0 ;


}