#include <stdio.h>
#include <stdlib.h>

int main() {
    double num1, num2, result;
    int choice;
    int continueProgram = 1;

    printf("\n");
    printf("=====================================\n");
    printf("       MENU-DRIVEN CALCULATOR       \n");
    printf("=====================================\n");

    while (continueProgram) {
        // Display menu
        printf("\n");
        printf("------------ MENU -----------\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Modulo (%%)\n");
        printf("6. Exit\n");
        printf("-----------------------------\n");

        // Get user choice
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        // Process based on choice
        if (choice == 6) {
            printf("\nThank you for using the calculator. Goodbye!\n");
            printf("=====================================\n\n");
            break;  // Exit the loop
        }

        if (choice < 1 || choice > 5) {
            printf("\n*** Invalid choice! Please enter a number between 1 and 6. ***\n");
            continue;  // Skip to next iteration
        }

        // Get two numbers from user
        printf("Enter first number: ");
        scanf("%lf", &num1);

        printf("Enter second number: ");
        scanf("%lf", &num2);

        printf("\n");

        // Perform calculation based on choice
        switch (choice) {
            case 1:
                result = num1 + num2;
                printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 2:
                result = num1 - num2;
                printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 3:
                result = num1 * num2;
                printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 4:
                if (num2 == 0) {
                    printf("*** Error: Division by zero is not allowed! ***\n");
                } else {
                    result = num1 / num2;
                    printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
                }
                break;

            case 5:
                if ((int)num2 == 0) {
                    printf("*** Error: Modulo by zero is not allowed! ***\n");
                } else {
                    result = (int)num1 % (int)num2;
                    printf("%d %% %d = %.0lf\n", (int)num1, (int)num2, result);
                }
                break;

            default:
                printf("*** Invalid choice! ***\n");
        }

        printf("\n");
    }

    return 0;
}
