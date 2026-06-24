#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char compressed[200];
    int len, i, j, count, index;

    printf("enter the string = ");
    scanf("%99[^\n]", str) ;

    len = strlen(str);
    index = 0; 
    for (i = 0; i < len; ) { 
        char temp = str[i];
        count = 0;

        for (j = i; j < len; j++) {
            if (str[j] == temp) {
                count++;
            } else {
                break; 
            }
        }

        compressed[index] = temp;
        index++;
        int written = sprintf(&compressed[index], "%d", count);
        index += written;
        i = j; 
    }

    compressed[index] = '\0'; 

    printf("the string after compression is = %s\n", compressed);
    return 0;
}