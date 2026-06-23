# include <stdio.h>
# include <string.h>
int main(){
    int i , j , num , temp ; 
    char str1[100] , str2[100] ;
    printf("enter the first string = ");
    scanf(" %[^\n]",str1) ;
    printf("enter the second string = ");
    scanf(" %[^\n]",str2) ;
    if (strlen(str1) != strlen(str2)){
        printf("these string are not anagram strings");
        return 0 ;
    }
    for(i = 0 ; i < strlen(str1) - 1 ; i++){
        for(j = i + 1 ; j < strlen(str1) ; j++){
            if(str1[i] > str1[j]){
                temp = str1[i] ;
                str1[i] = str1[j] ;
                str1[j] = temp ;
            }
        }
    }
    for(i = 0 ; i < strlen(str2) - 1 ; i++){
        for(j = i + 1 ; j < strlen(str2) ; j++){
            if(str2[i] > str2[j]){
                temp = str2[i] ;
                str2[i] = str2[j] ;
                str2[j] = temp ;
            }
        }
    }
    if(strcmp(str1,str2) == 0){
        printf("these strings are anagrams strings");
    }
    else{
        printf("these strings are not anagrams strings");
    }
return 0 ;
}