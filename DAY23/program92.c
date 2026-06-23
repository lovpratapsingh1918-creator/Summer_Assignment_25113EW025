# include <stdio.h>
int main(){
int i = 0 , j = 0, num , index = 0 , count[256] , max = 0;
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
    count[str[i]] = num ;  
    i++ ;
}
for(i = 0 ; str[i] != '\0' ; i++){
    if (count[str[i]] > max){
        max = count[str[i]] ;
        index = i ;
    }
}
printf("the maximum occuring character is :'%c'",str[index]);
return 0 ;
}