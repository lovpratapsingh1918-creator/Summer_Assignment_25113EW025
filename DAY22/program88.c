# include <stdio.h>
int main(){
    int i = 0 , j , frequency = 0 ;
    char str[100] , alpha ;
    
    printf("enter the string=");
    scanf("%[^\n]",str);
    while(str[i] != '\0'){
    if (str[i] == ' '){
        j = i ;
        while (str[j] != '\0'){
        str[j] = str[j + 1] ;
        j++ ;
        }
    }
    i++ ;
    }
    printf("\nthe string is = %s",str);
    return 0 ;
}