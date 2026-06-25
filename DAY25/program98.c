# include <stdio.h>
int main(){
    int i , j ;
    char str1[100] , str2[100] ;
    printf("enter the first string = ");
    scanf("%[^\n]",&str1);
    printf("enter the second string = ");
    scanf(" %[^\n]",&str2);
    printf("common characters in both strings are = ");
    for(i = 0 ; str1[i] != '\0' ; i++){
        for(j = 0 ; str2[j] != '\0' ; j++){
            if(str1[i] == str2[j]){
                printf("%c ",str1[i]);
                break ;
            }
        }
    }
    return 0;
}