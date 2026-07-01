#include <stdio.h>
#include <string.h>

#define MAX 100

struct Book {
    int id;
    char title[50];
    char author[50];
    int available;  // 1 = available, 0 = issued
};

void readLine(char str[], int size) {
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0';
}

int main() {
    struct Book library[MAX];
    int count = 0;
    int choice;

    do {
        printf("\n===== Mini Library System =====\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by Title\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                if (count < MAX) {
                    printf("\nEnter Book ID: ");
                    scanf("%d", &library[count].id);
                    getchar();

                    printf("Enter Title: ");
                    readLine(library[count].title, sizeof(library[count].title));

                    printf("Enter Author: ");
                    readLine(library[count].author, sizeof(library[count].author));

                    library[count].available = 1;
                    count++;

                    printf("Book added successfully!\n");
                } else {
                    printf("Library is full!\n");
                }
                break;

            case 2:
                if (count == 0) {
                    printf("\nNo books in the library.\n");
                } else {
                    printf("\nBooks in Library:\n");
                    for (int i = 0; i < count; i++) {
                        printf("\nBook ID: %d\n", library[i].id);
                        printf("Title: %s\n", library[i].title);
                        printf("Author: %s\n", library[i].author);
                        printf("Status: %s\n", library[i].available ? "Available" : "Issued");
                    }
                }
                break;

            case 3:
                if (count == 0) {
                    printf("\nNo books available to search.\n");
                } else {
                    char searchTitle[50];
                    int found = 0;

                    printf("\nEnter title to search: ");
                    readLine(searchTitle, sizeof(searchTitle));

                    for (int i = 0; i < count; i++) {
                        if (strcmp(library[i].title, searchTitle) == 0) {
                            printf("\nBook found!\n");
                            printf("Book ID: %d\n", library[i].id);
                            printf("Title: %s\n", library[i].title);
                            printf("Author: %s\n", library[i].author);
                            printf("Status: %s\n", library[i].available ? "Available" : "Issued");
                            found = 1;
                            break;
                        }
                    }

                    if (!found) {
                        printf("\nBook not found.\n");
                    }
                }
                break;

            case 4:
                if (count == 0) {
                    printf("\nNo books available to issue.\n");
                } else {
                    char issueTitle[50];
                    int found = 0;

                    printf("\nEnter title of the book to issue: ");
                    readLine(issueTitle, sizeof(issueTitle));

                    for (int i = 0; i < count; i++) {
                        if (strcmp(library[i].title, issueTitle) == 0) {
                            if (library[i].available == 1) {
                                library[i].available = 0;
                                printf("\nBook issued successfully!\n");
                            } else {
                                printf("\nBook is already issued.\n");
                            }
                            found = 1;
                            break;
                        }
                    }

                    if (!found) {
                        printf("\nBook not found.\n");
                    }
                }
                break;

            case 5:
                if (count == 0) {
                    printf("\nNo books available to return.\n");
                } else {
                    char returnTitle[50];
                    int found = 0;

                    printf("\nEnter title of the book to return: ");
                    readLine(returnTitle, sizeof(returnTitle));

                    for (int i = 0; i < count; i++) {
                        if (strcmp(library[i].title, returnTitle) == 0) {
                            if (library[i].available == 0) {
                                library[i].available = 1;
                                printf("\nBook returned successfully!\n");
                            } else {
                                printf("\nBook is already available.\n");
                            }
                            found = 1;
                            break;
                        }
                    }

                    if (!found) {
                        printf("\nBook not found.\n");
                    }
                }
                break;

            case 6:
                printf("\nExiting Mini Library System. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
