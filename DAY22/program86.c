# include <stdio.h>
int main(){
    int i = 0 , space = 1 ;
    char str[100] ;
    
    printf("enter the string=");
    scanf("%[^\n]",&str);
    while(str[i] != '\0'){
    if (str[i] == ' '){
        space++ ;
    }
    i++ ;
    }
    printf("the number of words in string = %d",space);
    return 0 ;
}