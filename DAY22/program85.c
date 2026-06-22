# include <stdio.h>
int main(){
    int i = 0 , len = 0 ;
    char str[100] , reverse[100] ;
    
    printf("enter the string=");
    scanf("%[^\n]",&str);
    while(str[i] != '\0'){
    len++ ;
    i++ ;
    }
    for (i = 0 ; i < len  ; i++){
    reverse[i] = str[len - 1 - i] ;
    }
    for (i = 0 ; i < len ; i++){
    if (str[i] != reverse[i]){
        printf("this is not a palindrome string");
        return 0 ;
    }
    }
    printf("this is a palindrome string");
    return 0 ;
}