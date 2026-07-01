#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    int rollNo;
    char name[50];
    char course[30];
    float marks;
};

void readLine(char str[], int size) {
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0';
}

void addStudent(struct Student students[], int *count) {
    if (*count < MAX) {
        printf("\nEnter Roll Number: ");
        scanf("%d", &students[*count].rollNo);
        getchar();

        printf("Enter Name: ");
        readLine(students[*count].name, sizeof(students[*count].name));

        printf("Enter Course: ");
        readLine(students[*count].course, sizeof(students[*count].course));

        printf("Enter Marks: ");
        scanf("%f", &students[*count].marks);
        getchar();

        (*count)++;
        printf("Student added successfully!\n");
    } else {
        printf("Record list is full!\n");
    }
}

void displayStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo student records found.\n");
    } else {
        printf("\nStudent Records:\n");
        for (int i = 0; i < count; i++) {
            printf("\nRoll Number: %d\n", students[i].rollNo);
            printf("Name: %s\n", students[i].name);
            printf("Course: %s\n", students[i].course);
            printf("Marks: %.2f\n", students[i].marks);
        }
    }
}

void searchStudent(struct Student students[], int count) {
    int roll;
    int found = 0;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);
    getchar();

    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == roll) {
            printf("\nStudent found!\n");
            printf("Roll Number: %d\n", students[i].rollNo);
            printf("Name: %s\n", students[i].name);
            printf("Course: %s\n", students[i].course);
            printf("Marks: %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent not found.\n");
    }
}

void updateMarks(struct Student students[], int count) {
    int roll;
    int found = 0;

    printf("\nEnter Roll Number to update marks: ");
    scanf("%d", &roll);
    getchar();

    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == roll) {
            printf("Enter new marks: ");
            scanf("%f", &students[i].marks);
            getchar();
            printf("\nMarks updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent not found.\n");
    }
}

void deleteStudent(struct Student students[], int *count) {
    int roll;
    int found = 0;

    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);
    getchar();

    for (int i = 0; i < *count; i++) {
        if (students[i].rollNo == roll) {
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }
            (*count)--;
            printf("\nStudent deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent not found.\n");
    }
}

int main() {
    struct Student students[MAX];
    int count = 0;
    int choice;

    do {
        printf("\n===== Mini Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Marks\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                updateMarks(students, count);
                break;
            case 5:
                deleteStudent(students, &count);
                break;
            case 6:
                printf("\nExiting Student Management System. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
