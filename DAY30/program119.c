#include <stdio.h>
#include <string.h>

#define MAX 100

struct Employee {
    int id;
    char name[50];
    char department[50];
    float salary;
};

void readLine(char str[], int size) {
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0';
}

int main() {
    struct Employee employees[MAX];
    int count = 0;
    int choice;

    do {
        printf("\n===== Mini Employee Management System =====\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Update Salary\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                if (count < MAX) {
                    printf("\nEnter Employee ID: ");
                    scanf("%d", &employees[count].id);
                    getchar();

                    printf("Enter Name: ");
                    readLine(employees[count].name, sizeof(employees[count].name));

                    printf("Enter Department: ");
                    readLine(employees[count].department, sizeof(employees[count].department));

                    printf("Enter Salary: ");
                    scanf("%f", &employees[count].salary);
                    getchar();

                    count++;
                    printf("Employee added successfully!\n");
                } else {
                    printf("Employee list is full!\n");
                }
                break;

            case 2:
                if (count == 0) {
                    printf("\nNo employees found.\n");
                } else {
                    printf("\nEmployee Records:\n");
                    for (int i = 0; i < count; i++) {
                        printf("\nEmployee ID: %d\n", employees[i].id);
                        printf("Name: %s\n", employees[i].name);
                        printf("Department: %s\n", employees[i].department);
                        printf("Salary: %.2f\n", employees[i].salary);
                    }
                }
                break;

            case 3:
                if (count == 0) {
                    printf("\nNo employees available to search.\n");
                } else {
                    int searchId;
                    int found = 0;

                    printf("\nEnter Employee ID to search: ");
                    scanf("%d", &searchId);
                    getchar();

                    for (int i = 0; i < count; i++) {
                        if (employees[i].id == searchId) {
                            printf("\nEmployee found!\n");
                            printf("Employee ID: %d\n", employees[i].id);
                            printf("Name: %s\n", employees[i].name);
                            printf("Department: %s\n", employees[i].department);
                            printf("Salary: %.2f\n", employees[i].salary);
                            found = 1;
                            break;
                        }
                    }

                    if (!found) {
                        printf("\nEmployee not found.\n");
                    }
                }
                break;

            case 4:
                if (count == 0) {
                    printf("\nNo employees available to update.\n");
                } else {
                    int updateId;
                    int found = 0;

                    printf("\nEnter Employee ID to update salary: ");
                    scanf("%d", &updateId);
                    getchar();

                    for (int i = 0; i < count; i++) {
                        if (employees[i].id == updateId) {
                            printf("Enter new salary: ");
                            scanf("%f", &employees[i].salary);
                            getchar();
                            printf("\nSalary updated successfully!\n");
                            found = 1;
                            break;
                        }
                    }

                    if (!found) {
                        printf("\nEmployee not found.\n");
                    }
                }
                break;

            case 5:
                if (count == 0) {
                    printf("\nNo employees available to delete.\n");
                } else {
                    int deleteId;
                    int found = 0;

                    printf("\nEnter Employee ID to delete: ");
                    scanf("%d", &deleteId);
                    getchar();

                    for (int i = 0; i < count; i++) {
                        if (employees[i].id == deleteId) {
                            for (int j = i; j < count - 1; j++) {
                                employees[j] = employees[j + 1];
                            }
                            count--;
                            printf("\nEmployee deleted successfully!\n");
                            found = 1;
                            break;
                        }
                    }

                    if (!found) {
                        printf("\nEmployee not found.\n");
                    }
                }
                break;

            case 6:
                printf("\nExiting Mini Employee Management System. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
