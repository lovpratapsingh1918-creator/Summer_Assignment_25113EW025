#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], temp[100];

    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    if (strcmp(str1, str2) > 0) {
        strcpy(temp, str1);
        strcpy(str1, str2);
        strcpy(str2, temp);
    }

    printf("\nStrings in alphabetical order:\n");
    printf("1. %s\n", str1);
    printf("2. %s\n", str2);

    return 0;
}
