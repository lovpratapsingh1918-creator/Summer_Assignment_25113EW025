# include <stdio.h>
int main (){
    int num, i, maxprime = -1;

    printf("enter a number=");
    scanf("%d",&num);

    while (num % 2 == 0){
        maxprime = 2;
        num /= 2;
    } 
    for (i = 3; i * i <= num; i += 2){
        while(num % i == 0) {
            maxprime = i;
            num /= i;
        }
    }
    if (num > 2) {
        maxprime = num;
    }
    printf("largest prime factore: %d", maxprime);
    return 0;
}
