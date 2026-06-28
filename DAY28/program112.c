#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
    char address[100];
    int active;
} Contact;

Contact contacts[MAX_CONTACTS];
int contactCount = 0;

void flushInput(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void addContact(void) {
    if (contactCount >= MAX_CONTACTS) {
        printf("Contact list is full.\n");
        return;
    }

    printf("\nEnter name: ");
    fgets(contacts[contactCount].name, sizeof(contacts[contactCount].name), stdin);
    contacts[contactCount].name[strcspn(contacts[contactCount].name, "\n")] = '\0';

    printf("Enter phone number: ");
    fgets(contacts[contactCount].phone, sizeof(contacts[contactCount].phone), stdin);
    contacts[contactCount].phone[strcspn(contacts[contactCount].phone, "\n")] = '\0';

    printf("Enter email address: ");
    fgets(contacts[contactCount].email, sizeof(contacts[contactCount].email), stdin);
    contacts[contactCount].email[strcspn(contacts[contactCount].email, "\n")] = '\0';

    printf("Enter address: ");
    fgets(contacts[contactCount].address, sizeof(contacts[contactCount].address), stdin);
    contacts[contactCount].address[strcspn(contacts[contactCount].address, "\n")] = '\0';

    contacts[contactCount].active = 1;
    contactCount++;
    printf("Contact added successfully.\n");
}

int findContactIndex(const char *name) {
    for (int i = 0; i < contactCount; i++) {
        if (contacts[i].active && strcmp(contacts[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void displayContacts(void) {
    int found = 0;
    printf("\nContact List:\n");
    printf("%-20s %-15s %-25s %-30s\n", "Name", "Phone", "Email", "Address");
    for (int i = 0; i < contactCount; i++) {
        if (contacts[i].active) {
            printf("%-20s %-15s %-25s %-30s\n",
                   contacts[i].name,
                   contacts[i].phone,
                   contacts[i].email,
                   contacts[i].address);
            found = 1;
        }
    }
    if (!found) {
        printf("No contacts found.\n");
    }
}

void searchContact(void) {
    char name[50];
    printf("\nEnter name to search: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    int index = findContactIndex(name);
    if (index < 0) {
        printf("Contact not found.\n");
        return;
    }

    printf("\nContact Details:\n");
    printf("Name: %s\n", contacts[index].name);
    printf("Phone: %s\n", contacts[index].phone);
    printf("Email: %s\n", contacts[index].email);
    printf("Address: %s\n", contacts[index].address);
}

void updateContact(void) {
    char name[50];
    printf("\nEnter name of the contact to update: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    int index = findContactIndex(name);
    if (index < 0) {
        printf("Contact not found.\n");
        return;
    }

    printf("Enter new phone number: ");
    fgets(contacts[index].phone, sizeof(contacts[index].phone), stdin);
    contacts[index].phone[strcspn(contacts[index].phone, "\n")] = '\0';

    printf("Enter new email address: ");
    fgets(contacts[index].email, sizeof(contacts[index].email), stdin);
    contacts[index].email[strcspn(contacts[index].email, "\n")] = '\0';

    printf("Enter new address: ");
    fgets(contacts[index].address, sizeof(contacts[index].address), stdin);
    contacts[index].address[strcspn(contacts[index].address, "\n")] = '\0';

    printf("Contact updated successfully.\n");
}

void deleteContact(void) {
    char name[50];
    printf("\nEnter name of the contact to delete: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    int index = findContactIndex(name);
    if (index < 0) {
        printf("Contact not found.\n");
        return;
    }

    contacts[index].active = 0;
    printf("Contact deleted successfully.\n");
}

int main(void) {
    int choice;

    printf("============================\n");
    printf("Contact Management System\n");
    printf("============================\n");

    while (1) {
        printf("\n1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Update Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        flushInput();

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                updateContact();
                break;
            case 5:
                deleteContact();
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
