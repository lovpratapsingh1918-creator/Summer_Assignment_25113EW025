# include <stdio.h>
int main(){
int i = 0 , j = 0, num , count[100];
char str[100] ;
printf("enter the string= ");
scanf("%[^\n]",str);
while(str[i] != '\0'){
    j = 0 ;
    num = 0 ;
    while(str[j] != '\0' ){
        if(str[i] == str[j]){
        num++ ;
        }
        j++ ;
    }
    count[i] = num ;  
    i++ ;
}
for(i = 0 ; str[i] != '\0' ; i++){
    if(count[i] == 1){
        printf("the first non repeating character is '%c' ",str[i]);
        return 0 ;
    }
}
printf("there is not any character which is not repeating");
return 0 ;
}