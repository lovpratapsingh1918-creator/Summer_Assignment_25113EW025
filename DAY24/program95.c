# include <stdio.h>
# include <string.h>
int main(){
    int len , i , index ,count , max ;
    char str[100] ;
    printf("enter the string = ");
    scanf("%[^\n]",str);
    count = 0 ;
    max = 0 ;
    for(i = 0 ; i < strlen(str) ; i++){
        if (str[i] != ' '){
            count++ ;
            if (max < count){
                max = count ; 
                index = i ;
            }
        }
        else{
            count = 0 ;
        }
    }
    printf("the largest word in string = ");
    for(i = index - max ; i <= index ; i++){
        printf("%c",str[i]);
    }
    return 0 ;
}