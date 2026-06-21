# include <stdio.h>
int main(){
    int i = 0 , vowel = 0 , consonant = 0 , space = 0 ;
    char str[100] ;
    
    printf("enter the string=");
    scanf("%[^\n]",&str);
    while(str[i] != '\0'){
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
    vowel++ ;
    }
    else {
        consonant++ ;
    }
    if ( str[i] == ' '){
        space++ ;
    }
    i++ ;
    }
    printf("the number of vowels =%d\n",vowel);
    printf("the number of consonants = %d",consonant - space);
    return 0 ;
}