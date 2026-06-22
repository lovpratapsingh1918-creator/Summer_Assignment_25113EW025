# include <stdio.h>
int main(){
    int i = 0 , frequency = 0 ;
    char str[100] , alpha ;
    
    printf("enter the string=");
    scanf("%[^\n]",str);
    printf("enter the character to search = ");
    scanf(" %c",&alpha) ;
    while(str[i] != '\0'){
    if (str[i] == alpha || str[i] == alpha - 32){
        frequency++ ;
    }
    i++ ;
    }
    printf("\nthe frequency of %c in string = %d",alpha , frequency);
    return 0 ;
}