#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int accountNumber;
    char name[50];
    double balance;
    int active;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void flushInput(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void createAccount(void) {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Bank account storage is full.\n");
        return;
    }

    printf("\nEnter account number: ");
    scanf("%d", &accounts[accountCount].accountNumber);
    flushInput();

    printf("Enter account holder name: ");
    fgets(accounts[accountCount].name, sizeof(accounts[accountCount].name), stdin);
    accounts[accountCount].name[strcspn(accounts[accountCount].name, "\n")] = '\0';

    printf("Enter opening balance: ");
    scanf("%lf", &accounts[accountCount].balance);
    flushInput();

    accounts[accountCount].active = 1;
    accountCount++;

    printf("Account created successfully.\n");
}

int findAccountIndex(int accountNumber) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].active && accounts[i].accountNumber == accountNumber) {
            return i;
        }
    }
    return -1;
}

void displayAccounts(void) {
    if (accountCount == 0) {
        printf("No accounts available.\n");
        return;
    }

    printf("\nAccount List:\n");
    printf("%-15s %-20s %-12s\n", "Account No", "Name", "Balance");
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].active) {
            printf("%-15d %-20s $%.2f\n",
                   accounts[i].accountNumber,
                   accounts[i].name,
                   accounts[i].balance);
        }
    }
}

void searchAccount(void) {
    int accountNumber;
    printf("\nEnter account number to search: ");
    scanf("%d", &accountNumber);
    flushInput();

    int index = findAccountIndex(accountNumber);
    if (index < 0) {
        printf("Account not found.\n");
        return;
    }

    printf("\nAccount Details:\n");
    printf("Account Number: %d\n", accounts[index].accountNumber);
    printf("Name: %s\n", accounts[index].name);
    printf("Balance: $%.2f\n", accounts[index].balance);
}

void depositAmount(void) {
    int accountNumber;
    double amount;

    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);
    flushInput();

    int index = findAccountIndex(accountNumber);
    if (index < 0) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter deposit amount: ");
    scanf("%lf", &amount);
    flushInput();

    if (amount <= 0) {
        printf("Deposit amount must be positive.\n");
        return;
    }

    accounts[index].balance += amount;
    printf("Deposit successful. New balance: $%.2f\n", accounts[index].balance);
}

void withdrawAmount(void) {
    int accountNumber;
    double amount;

    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);
    flushInput();

    int index = findAccountIndex(accountNumber);
    if (index < 0) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter withdrawal amount: ");
    scanf("%lf", &amount);
    flushInput();

    if (amount <= 0) {
        printf("Withdrawal amount must be positive.\n");
        return;
    }
    if (amount > accounts[index].balance) {
        printf("Insufficient balance. Available balance: $%.2f\n", accounts[index].balance);
        return;
    }

    accounts[index].balance -= amount;
    printf("Withdrawal successful. Remaining balance: $%.2f\n", accounts[index].balance);
}

void closeAccount(void) {
    int accountNumber;
    printf("\nEnter account number to close: ");
    scanf("%d", &accountNumber);
    flushInput();

    int index = findAccountIndex(accountNumber);
    if (index < 0) {
        printf("Account not found.\n");
        return;
    }

    accounts[index].active = 0;
    printf("Account closed successfully.\n");
}

int main(void) {
    int choice;

    printf("============================\n");
    printf("Bank Account Management System\n");
    printf("============================\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Search Account\n");
        printf("4. Deposit\n");
        printf("5. Withdraw\n");
        printf("6. Close Account\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        flushInput();

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                displayAccounts();
                break;
            case 3:
                searchAccount();
                break;
            case 4:
                depositAmount();
                break;
            case 5:
                withdrawAmount();
                break;
            case 6:
                closeAccount();
                break;
            case 7:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
