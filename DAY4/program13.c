# include <stdio.h>
int main(){
    int term1, term2, nextterm, i, t;
    term1 = 0;
    term2 = 1;

    printf("enter number of terms=");
    scanf("%d", &t);
    printf("%d  %d  ",term1, term2);

    for(i=3 ; i<=t ; i++){
        nextterm = term1 + term2;
        printf("%d  ",nextterm); 
        term1 = term2;
        term2 = nextterm;
       }

        return 0;
}