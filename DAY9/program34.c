# include <stdio.h>
int main(){
    int num , i , j ;
    printf("enter the height of pattern=");
    scanf("%d",&num);

    for ( i = num ; i > 0 ;  i--){
        for ( j = 1 ; j <= i ; j++){
        printf("%d",j);
        }
        printf("\n");
    }
    return 0 ;
}