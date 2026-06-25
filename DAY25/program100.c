#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j;
    char words[20][100];
    char temp[100];

    printf("Enter the number of words: ");
    scanf("%d", &n);
    getchar();

    for (i = 0; i < n; i++) {
        printf("Enter word %d: ", i + 1);
        fgets(words[i], sizeof(words[i]), stdin);
        words[i][strcspn(words[i], "\n")] = '\0';
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strlen(words[i]) > strlen(words[j])) {
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }

    printf("\nWords sorted by length:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}
