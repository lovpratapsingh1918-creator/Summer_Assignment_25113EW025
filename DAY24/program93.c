# include <stdio.h>
# include <string.h>
int main(){
    int i , j , len , num ;
    char str[50] , temp ;
    printf("enter the string =");
    scanf("%[^\n]",str);
    len = strlen(str) ;
    printf("enter the number of time to rotate the string anticlockwise=");
    scanf("%d",&num) ;
    for( i = 0 ; i < num ; i++ ){
        temp = str[len - 1] ;
        for( j = len - 2 ; j >= 0 ; j--){
        str[j + 1] = str[j] ;
        }
        str[0] = temp ;
    }
    printf("the string after rotation is = %s",str);
    return 0 ;
}