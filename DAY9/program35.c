# include <stdio.h>
int main(){
    int num , i , j ;
    char a ;
    printf("enter the height of pattern=");
    scanf("%d",&num);

    a = 'A' ;
    for ( i = 1 ; i <= num ;  i++){
        for ( j = 1 ; j <= i ; j++){
        printf("%c",a);
        }
        a++ ;
        printf("\n");
    }
    return 0 ;
}