# include <stdio.h>
int main(){
    int num , i , j ;
    printf("enter the height of pattern=");
    scanf("%d",&num);

    for ( i = 1 ; i <= num ;  i++){
        for ( j = 1 ; j <= num ; j++){
            if (i == 1 || i == 5 || j == 1 || j ==5 ){
            printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0 ;
}