# include <stdio.h>
int fabonacci(int t){
    int firstterm , secondterm , nextterm , i ;
    firstterm = 0 ;
    secondterm = 1 ;
    printf("the %d terms of fabonacci series are=",t);
    for (i = 1 ; i <= t ; i++){
    printf(" %d ",firstterm);
    nextterm = firstterm + secondterm ;
    firstterm = secondterm ;
    secondterm = nextterm ;
    }
}
int main(){
    int terms ;

    printf("enter the number of terms=");
    scanf("%d",&terms);

    fabonacci(terms) ;

    return 0 ;
}