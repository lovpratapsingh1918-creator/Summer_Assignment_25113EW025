#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    int id;
    char title[50];
    char author[50];
    int available;
} Book;

Book books[MAX_BOOKS];
int count = 0;

void flushInput(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void addBook(void) {
    if (count >= MAX_BOOKS) {
        printf("Library is full.\n");
        return;
    }

    printf("\nEnter Book ID: ");
    scanf("%d", &books[count].id);
    flushInput();

    printf("Enter Book Title: ");
    fgets(books[count].title, sizeof(books[count].title), stdin);
    books[count].title[strcspn(books[count].title, "\n")] = '\0';

    printf("Enter Author Name: ");
    fgets(books[count].author, sizeof(books[count].author), stdin);
    books[count].author[strcspn(books[count].author, "\n")] = '\0';

    books[count].available = 1;
    count++;
    printf("Book added successfully.\n");
}

void displayBooks(void) {
    if (count == 0) {
        printf("No books available.\n");
        return;
    }

    printf("\nLibrary Books:\n");
    printf("ID\tTitle\t\tAuthor\t\tStatus\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%s\t\t%s\n",
               books[i].id,
               books[i].title,
               books[i].author,
               books[i].available ? "Available" : "Issued");
    }
}

void searchBook(void) {
    int id;
    printf("\nEnter Book ID to search: ");
    scanf("%d", &id);
    flushInput();

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            printf("\nBook Found:\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\nStatus: %s\n",
                   books[i].id,
                   books[i].title,
                   books[i].author,
                   books[i].available ? "Available" : "Issued");
            return;
        }
    }
    printf("Book not found.\n");
}

void issueBook(void) {
    int id;
    printf("\nEnter Book ID to issue: ");
    scanf("%d", &id);
    flushInput();

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            if (books[i].available) {
                books[i].available = 0;
                printf("Book issued successfully.\n");
            } else {
                printf("Book is already issued.\n");
            }
            return;
        }
    }
    printf("Book not found.\n");
}

void returnBook(void) {
    int id;
    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);
    flushInput();

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            if (!books[i].available) {
                books[i].available = 1;
                printf("Book returned successfully.\n");
            } else {
                printf("Book is already available.\n");
            }
            return;
        }
    }
    printf("Book not found.\n");
}

int main(void) {
    int choice;

    printf("============================\n");
    printf("Library Management System\n");
    printf("============================\n");

    while (1) {
        printf("\n1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        flushInput();

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                issueBook();
                break;
            case 5:
                returnBook();
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
