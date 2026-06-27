#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int id;
    char name[50];
    float salary;
    char department[30];
} Employee;

void addEmployee(Employee employees[], int *count) {
    if (*count >= MAX) {
        printf("Employee list is full.\n");
        return;
    }

    printf("\nEnter employee ID: ");
    scanf("%d", &employees[*count].id);
    printf("Enter employee name: ");
    scanf("%s", employees[*count].name);
    printf("Enter salary: ");
    scanf("%f", &employees[*count].salary);
    printf("Enter department: ");
    scanf("%s", employees[*count].department);

    (*count)++;
    printf("Employee added successfully!\n");
}

void displayEmployees(Employee employees[], int count) {
    int i;

    if (count == 0) {
        printf("\nNo employees found.\n");
        return;
    }

    printf("\nEmployee List:\n");
    printf("---------------------------------------------------\n");
    printf("ID\tName\tSalary\tDepartment\n");
    printf("---------------------------------------------------\n");

    for (i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f\t%s\n",
               employees[i].id,
               employees[i].name,
               employees[i].salary,
               employees[i].department);
    }
}

void searchEmployee(Employee employees[], int count) {
    int id, i;
    int found = 0;

    printf("\nEnter employee ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (employees[i].id == id) {
            printf("\nEmployee found!\n");
            printf("ID: %d\n", employees[i].id);
            printf("Name: %s\n", employees[i].name);
            printf("Salary: %.2f\n", employees[i].salary);
            printf("Department: %s\n", employees[i].department);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee not found.\n");
    }
}

void updateEmployee(Employee employees[], int count) {
    int id, i;
    printf("\nEnter employee ID to update: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (employees[i].id == id) {
            printf("Enter new name: ");
            scanf("%s", employees[i].name);
            printf("Enter new salary: ");
            scanf("%f", &employees[i].salary);
            printf("Enter new department: ");
            scanf("%s", employees[i].department);
            printf("Employee updated successfully!\n");
            return;
        }
    }

    printf("Employee not found.\n");
}

void deleteEmployee(Employee employees[], int *count) {
    int id, i, j;
    int found = 0;

    printf("\nEnter employee ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < *count; i++) {
        if (employees[i].id == id) {
            for (j = i; j < *count - 1; j++) {
                employees[j] = employees[j + 1];
            }
            (*count)--;
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Employee deleted successfully!\n");
    } else {
        printf("Employee not found.\n");
    }
}

int main() {
    Employee employees[MAX];
    int count = 0;
    int choice;

    do {
        printf("\n===== Employee Management System =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(employees, &count);
                break;
            case 2:
                displayEmployees(employees, count);
                break;
            case 3:
                searchEmployee(employees, count);
                break;
            case 4:
                updateEmployee(employees, count);
                break;
            case 5:
                deleteEmployee(employees, &count);
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
