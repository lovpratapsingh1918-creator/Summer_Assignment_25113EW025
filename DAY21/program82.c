# include <stdio.h>
int main(){
    int i = 0 , len = 0 ;
    char str[100] , temp ;
    
    printf("enter the string=");
    scanf("%[^\n]",&str);
    while(str[i] != '\0'){
    len++ ;
    i++ ;
    }
    printf("length of string = %d\n",len);
    for (i = 0 ; i < len / 2 ; i++){
    temp = str[i] ;
    str[i] = str[len - 1 - i] ;
    str[len - 1 - i] = temp ;
    }
    printf("reversed string is = ") ;
    for (i = 0 ; i < len ; i++){
    printf("%c",str[i]) ;
    }
    return 0 ;
}