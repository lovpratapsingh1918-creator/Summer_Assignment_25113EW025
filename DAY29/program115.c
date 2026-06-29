#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

char str[MAX_SIZE];
char str2[MAX_SIZE];

// Function to display the string
void displayString() {
    if (strlen(str) == 0) {
        printf("\n*** String is empty! ***\n");
        return;
    }
    printf("\nString: %s\n", str);
}

// Function to get a string from user
void getString() {
    printf("Enter string: ");
    scanf("%99s", str);
    printf("String stored successfully!\n");
}

// Function to find length of string
void findLength() {
    if (strlen(str) == 0) {
        printf("\n*** String is empty! ***\n");
        return;
    }
    printf("\nLength of string: %lu\n", strlen(str));
}

// Function to concatenate strings
void concatenateStrings() {
    if (strlen(str) == 0) {
        printf("\n*** First string is empty! ***\n");
        return;
    }

    printf("Enter second string: ");
    scanf("%99s", str2);

    // Check if concatenation will exceed buffer
    if (strlen(str) + strlen(str2) >= MAX_SIZE) {
        printf("\n*** Concatenation would exceed buffer size! ***\n");
        return;
    }

    strcat(str, str2);
    printf("\nConcatenated string: %s\n", str);
}

// Function to compare two strings
void compareStrings() {
    if (strlen(str) == 0) {
        printf("\n*** First string is empty! ***\n");
        return;
    }

    printf("Enter second string: ");
    scanf("%99s", str2);

    int result = strcmp(str, str2);

    if (result == 0) {
        printf("\nBoth strings are equal!\n");
    } else if (result < 0) {
        printf("\nFirst string is lexicographically smaller!\n");
    } else {
        printf("\nFirst string is lexicographically larger!\n");
    }
}

// Function to reverse string
void reverseString() {
    if (strlen(str) == 0) {
        printf("\n*** String is empty! ***\n");
        return;
    }

    char reversed[MAX_SIZE];
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        reversed[i] = str[len - 1 - i];
    }
    reversed[len] = '\0';

    printf("\nReversed string: %s\n", reversed);
}

// Function to convert string to uppercase
void toUppercase() {
    if (strlen(str) == 0) {
        printf("\n*** String is empty! ***\n");
        return;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }

    printf("\nString converted to uppercase: %s\n", str);
}

// Function to convert string to lowercase
void toLowercase() {
    if (strlen(str) == 0) {
        printf("\n*** String is empty! ***\n");
        return;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }

    printf("\nString converted to lowercase: %s\n", str);
}

// Function to find substring
void findSubstring() {
    if (strlen(str) == 0) {
        printf("\n*** String is empty! ***\n");
        return;
    }

    printf("Enter substring to search: ");
    scanf("%99s", str2);

    char *found = strstr(str, str2);

    if (found == NULL) {
        printf("\n*** Substring not found! ***\n");
    } else {
        printf("\nSubstring found at position: %ld\n", found - str);
    }
}

// Function to replace character
void replaceCharacter() {
    if (strlen(str) == 0) {
        printf("\n*** String is empty! ***\n");
        return;
    }

    char oldChar, newChar;
    printf("Enter character to replace: ");
    scanf(" %c", &oldChar);

    printf("Enter new character: ");
    scanf(" %c", &newChar);

    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == oldChar) {
            str[i] = newChar;
            count++;
        }
    }

    printf("\n%d occurrence(s) of '%c' replaced with '%c'\n", count, oldChar, newChar);
    printf("Modified string: %s\n", str);
}

// Function to count character occurrences
void countCharacter() {
    if (strlen(str) == 0) {
        printf("\n*** String is empty! ***\n");
        return;
    }

    char ch;
    printf("Enter character to count: ");
    scanf(" %c", &ch);

    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            count++;
        }
    }

    printf("\nCharacter '%c' appears %d time(s) in the string!\n", ch, count);
}

// Function to clear the string
void clearString() {
    str[0] = '\0';
    printf("\nString cleared successfully!\n");
}

// Main menu function
void displayMenu() {
    printf("\n");
    printf("==========================================\n");
    printf("    MENU-DRIVEN STRING OPERATIONS       \n");
    printf("==========================================\n");
    printf("1.  Get/Store string\n");
    printf("2.  Display string\n");
    printf("3.  Find length\n");
    printf("4.  Concatenate strings\n");
    printf("5.  Compare strings\n");
    printf("6.  Reverse string\n");
    printf("7.  Convert to uppercase\n");
    printf("8.  Convert to lowercase\n");
    printf("9.  Find substring\n");
    printf("10. Replace character\n");
    printf("11. Count character\n");
    printf("12. Clear string\n");
    printf("13. Exit\n");
    printf("==========================================\n");
}

int main() {
    int choice;

    // Initialize string
    str[0] = '\0';
    str2[0] = '\0';

    printf("\n");
    printf("========================================\n");
    printf("  WELCOME TO STRING OPERATIONS SYSTEM  \n");
    printf("========================================\n");

    while (1) {
        displayMenu();
        printf("\nEnter your choice (1-13): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                getString();
                break;

            case 2:
                displayString();
                break;

            case 3:
                findLength();
                break;

            case 4:
                concatenateStrings();
                break;

            case 5:
                compareStrings();
                break;

            case 6:
                reverseString();
                break;

            case 7:
                toUppercase();
                break;

            case 8:
                toLowercase();
                break;

            case 9:
                findSubstring();
                break;

            case 10:
                replaceCharacter();
                break;

            case 11:
                countCharacter();
                break;

            case 12:
                clearString();
                break;

            case 13:
                printf("\nThank you for using String Operations System. Goodbye!\n");
                printf("========================================\n\n");
                return 0;

            default:
                printf("\n*** Invalid choice! Please enter a number between 1 and 13. ***\n");
        }
    }

    return 0;
}
