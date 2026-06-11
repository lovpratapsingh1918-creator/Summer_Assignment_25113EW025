# include <stdio.h>
int main (){
    int num , i , j ;
    char a;

    printf("enter height of pattern=");
    scanf("%d",&num);

    for (i = 1 ; i <= num ; i++){
        a = 'A' ;
        for (j = 1 ; j <= i ; j++){
            printf("%c", a);
            a++;
        }
    printf("\n");
    }
    return 0 ;
}