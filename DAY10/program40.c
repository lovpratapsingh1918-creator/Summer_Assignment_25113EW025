# include <stdio.h>
int main(){
    int num , i , j , k;
    printf("enter the height of pattern=");
    scanf("%d",&num);

    for ( i = 1 ; i <= num ;  i++){
        for (k = 1 ; k <= num - i ; k++){
            printf(" ");
        }
        for ( j = 1 ; j <= i; j++){
        printf("%c",'A' + j -1);
        }
        for ( j = i - 1 ; j >= 1 ; j--){
            printf("%c",'A' + j - 1 );
        }
        printf("\n");
    }
    return 0 ;
}
