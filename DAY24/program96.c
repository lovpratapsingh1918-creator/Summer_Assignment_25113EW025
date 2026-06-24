# include <stdio.h>
# include <string.h>
int main(){
    int i , j , k , len ; 
    char str[100] , ch ;
    printf("enter the string=");
    scanf("%[^\n]",str);
    len = strlen(str) ;
    for (i = 0 ; i < len ; i++){
        for (j = i + 1 ; j < len ; ){
        if (str[i] == str[j]){
        for (k = j ; k < len ; k++){
            str[k] = str[k+1] ;
        }
        len-- ;
        }
        else{
            j++;
        }
        }
    }
    printf("the string after removal of duplicate elements = %s",str);
}