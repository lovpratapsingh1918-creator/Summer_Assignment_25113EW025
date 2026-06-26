#include <stdio.h>

int main() {
    int pin = 1234;
    int enteredPin;
    float balance = 5000.0;
    int choice;
    float amount;

    printf("Welcome to the ATM Simulation\n");
    printf("Enter your PIN: ");
    scanf("%d", &enteredPin);

    if (enteredPin != pin) {
        printf("Incorrect PIN. Access denied.\n");
        return 0;
    }

    do {
        printf("\n1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Your balance is: %.2f\n", balance);
                break;
            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                if (amount > 0) {
                    balance += amount;
                    printf("Deposit successful. New balance: %.2f\n", balance);
                } else {
                    printf("Invalid amount.\n");
                }
                break;
            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                if (amount > 0 && amount <= balance) {
                    balance -= amount;
                    printf("Withdrawal successful. New balance: %.2f\n", balance);
                } else {
                    printf("Insufficient balance or invalid amount.\n");
                }
                break;
            case 4:
                printf("Thank you for using ATM.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}
