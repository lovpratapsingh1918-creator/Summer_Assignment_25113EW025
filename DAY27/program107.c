#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define FILE_NAME "salary_data.txt"

typedef struct {
    int id;
    char name[50];
    char department[30];
    float basicSalary;
    float allowance;
    float deduction;
    float netSalary;
} Employee;

Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void calculateNetSalary(Employee *e) {
    e->netSalary = e->basicSalary + e->allowance - e->deduction;
}

void loadEmployeesFromFile(void) {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        return;
    }

    while (!feof(fp) && employeeCount < MAX_EMPLOYEES) {
        Employee e;
        if (fscanf(fp, "%d|%49[^|]|%29[^|]|%f|%f|%f\n",
                   &e.id, e.name, e.department,
                   &e.basicSalary, &e.allowance, &e.deduction) == 6) {
            calculateNetSalary(&e);
            employees[employeeCount++] = e;
        }
    }

    fclose(fp);
}

void saveEmployeesToFile(void) {
    FILE *fp = fopen(FILE_NAME, "w");
    if (fp == NULL) {
        printf("Error: Unable to save data to file.\n");
        return;
    }

    for (int i = 0; i < employeeCount; i++) {
        fprintf(fp, "%d|%s|%s|%.2f|%.2f|%.2f\n",
                employees[i].id,
                employees[i].name,
                employees[i].department,
                employees[i].basicSalary,
                employees[i].allowance,
                employees[i].deduction);
    }

    fclose(fp);
}

void addEmployee(void) {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("Employee list is full.\n");
        return;
    }

    Employee e;
    printf("\nEnter Employee ID: ");
    scanf("%d", &e.id);
    clearInputBuffer();

    printf("Enter Employee Name: ");
    fgets(e.name, sizeof(e.name), stdin);
    e.name[strcspn(e.name, "\n")] = '\0';

    printf("Enter Department: ");
    fgets(e.department, sizeof(e.department), stdin);
    e.department[strcspn(e.department, "\n")] = '\0';

    printf("Enter Basic Salary: ");
    scanf("%f", &e.basicSalary);
    printf("Enter Allowance: ");
    scanf("%f", &e.allowance);
    printf("Enter Deduction: ");
    scanf("%f", &e.deduction);
    clearInputBuffer();

    calculateNetSalary(&e);
    employees[employeeCount++] = e;
    saveEmployeesToFile();

    printf("Employee added successfully.\n");
}

void displayEmployees(void) {
    if (employeeCount == 0) {
        printf("No employee records found.\n");
        return;
    }

    printf("\n===== Salary Management System =====\n");
    printf("ID\tName\t\tDepartment\tBasic\tAllowance\tDeduction\tNet Salary\n");
    printf("---------------------------------------------------------------------\n");

    for (int i = 0; i < employeeCount; i++) {
        printf("%d\t%-15s\t%-10s\t%.2f\t%.2f\t\t%.2f\t\t%.2f\n",
               employees[i].id,
               employees[i].name,
               employees[i].department,
               employees[i].basicSalary,
               employees[i].allowance,
               employees[i].deduction,
               employees[i].netSalary);
    }
}

void searchEmployee(void) {
    int targetId;
    int found = 0;

    printf("Enter Employee ID to search: ");
    scanf("%d", &targetId);
    clearInputBuffer();

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == targetId) {
            printf("\nEmployee Found\n");
            printf("ID: %d\n", employees[i].id);
            printf("Name: %s\n", employees[i].name);
            printf("Department: %s\n", employees[i].department);
            printf("Basic Salary: %.2f\n", employees[i].basicSalary);
            printf("Allowance: %.2f\n", employees[i].allowance);
            printf("Deduction: %.2f\n", employees[i].deduction);
            printf("Net Salary: %.2f\n", employees[i].netSalary);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee not found.\n");
    }
}

void updateEmployee(void) {
    int targetId;
    int found = 0;

    printf("Enter Employee ID to update: ");
    scanf("%d", &targetId);
    clearInputBuffer();

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == targetId) {
            printf("Enter new Basic Salary: ");
            scanf("%f", &employees[i].basicSalary);
            printf("Enter new Allowance: ");
            scanf("%f", &employees[i].allowance);
            printf("Enter new Deduction: ");
            scanf("%f", &employees[i].deduction);
            clearInputBuffer();

            calculateNetSalary(&employees[i]);
            saveEmployeesToFile();
            printf("Employee updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee not found.\n");
    }
}

void deleteEmployee(void) {
    int targetId;
    int found = 0;

    printf("Enter Employee ID to delete: ");
    scanf("%d", &targetId);
    clearInputBuffer();

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == targetId) {
            for (int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            saveEmployeesToFile();
            printf("Employee deleted successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee not found.\n");
    }
}

int main(void) {
    int choice;

    loadEmployeesFromFile();

    while (1) {
        printf("\n===== Salary Management System =====\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee Salary\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                updateEmployee();
                break;
            case 5:
                deleteEmployee();
                break;
            case 6:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
