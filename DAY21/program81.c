# include <stdio.h>
int main(){
    int i = 0 , len = 0;
    char str[100] ;
    
    printf("enter the string=");
    scanf("%[^\n]",&str);
    while(str[i] != '\0'){
    len++ ;
    i++ ;
    }
    printf("length of string = %d",len);
    return 0 ;
}