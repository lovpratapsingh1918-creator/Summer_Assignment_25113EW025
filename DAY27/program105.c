#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    int id;
    char name[50];
    int age;
    char branch[30];
    float marks;
};

void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Student list is full. Cannot add more records.\n");
        return;
    }

    struct Student s;

    printf("\nEnter student ID: ");
    scanf("%d", &s.id);
    getchar(); // consume newline

    printf("Enter student name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0';

    printf("Enter student age: ");
    scanf("%d", &s.age);
    getchar();

    printf("Enter branch: ");
    fgets(s.branch, sizeof(s.branch), stdin);
    s.branch[strcspn(s.branch, "\n")] = '\0';

    printf("Enter marks: ");
    scanf("%f", &s.marks);
    getchar();

    students[*count] = s;
    (*count)++;

    printf("\nStudent record added successfully.\n");
}

void displayAllStudents(const struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo student records to display.\n");
        return;
    }

    printf("\nStudent Records:\n");
    printf("%-6s %-20s %-6s %-15s %-7s\n", "ID", "Name", "Age", "Branch", "Marks");
    printf("-----------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-6d %-20s %-6d %-15s %-7.2f\n",
               students[i].id,
               students[i].name,
               students[i].age,
               students[i].branch,
               students[i].marks);
    }
}

int findStudentById(const struct Student students[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            return i;
        }
    }
    return -1;
}

void searchStudent(const struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo student records available to search.\n");
        return;
    }

    int id;
    printf("\nEnter student ID to search: ");
    scanf("%d", &id);
    getchar();

    int index = findStudentById(students, count, id);
    if (index == -1) {
        printf("\nStudent with ID %d not found.\n", id);
        return;
    }

    printf("\nStudent found:\n");
    printf("ID: %d\n", students[index].id);
    printf("Name: %s\n", students[index].name);
    printf("Age: %d\n", students[index].age);
    printf("Branch: %s\n", students[index].branch);
    printf("Marks: %.2f\n", students[index].marks);
}

void updateStudent(struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo student records available to update.\n");
        return;
    }

    int id;
    printf("\nEnter student ID to update: ");
    scanf("%d", &id);
    getchar();

    int index = findStudentById(students, count, id);
    if (index == -1) {
        printf("\nStudent with ID %d not found.\n", id);
        return;
    }

    printf("\nUpdating record for ID %d\n", id);
    printf("Enter new name (leave blank to keep unchanged): ");
    char buffer[50];
    fgets(buffer, sizeof(buffer), stdin);
    if (buffer[0] != '\n') {
        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy(students[index].name, buffer, sizeof(students[index].name));
        students[index].name[sizeof(students[index].name) - 1] = '\0';
    }

    printf("Enter new age (0 to keep unchanged): ");
    int age;
    scanf("%d", &age);
    getchar();
    if (age > 0) {
        students[index].age = age;
    }

    printf("Enter new branch (leave blank to keep unchanged): ");
    fgets(buffer, sizeof(buffer), stdin);
    if (buffer[0] != '\n') {
        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy(students[index].branch, buffer, sizeof(students[index].branch));
        students[index].branch[sizeof(students[index].branch) - 1] = '\0';
    }

    printf("Enter new marks (-1 to keep unchanged): ");
    float marks;
    scanf("%f", &marks);
    getchar();
    if (marks >= 0.0f) {
        students[index].marks = marks;
    }

    printf("\nStudent record updated successfully.\n");
}

void deleteStudent(struct Student students[], int *count) {
    if (*count == 0) {
        printf("\nNo student records available to delete.\n");
        return;
    }

    int id;
    printf("\nEnter student ID to delete: ");
    scanf("%d", &id);
    getchar();

    int index = findStudentById(students, *count, id);
    if (index == -1) {
        printf("\nStudent with ID %d not found.\n", id);
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        students[i] = students[i + 1];
    }
    (*count)--;

    printf("\nStudent record deleted successfully.\n");
}

int main(void) {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("\nStudent Record Management System\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Student Records\n");
        printf("3. Search Student Record by ID\n");
        printf("4. Update Student Record\n");
        printf("5. Delete Student Record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayAllStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                updateStudent(students, count);
                break;
            case 5:
                deleteStudent(students, &count);
                break;
            case 6:
                printf("\nExiting the program.\n");
                break;
            default:
                printf("\nInvalid choice. Please enter a number from 1 to 6.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
