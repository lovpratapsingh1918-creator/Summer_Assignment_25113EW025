#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define FILE_NAME "marksheet_data.txt"

typedef struct {
    int rollNo;
    char name[50];
    int marks[5];
    int total;
    float percentage;
    char grade;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void calculateResult(Student *s) {
    int i;
    s->total = 0;
    for (i = 0; i < 5; i++) {
        s->total += s->marks[i];
    }
    s->percentage = (float)s->total / 5.0;

    if (s->percentage >= 90) {
        s->grade = 'A';
    } else if (s->percentage >= 80) {
        s->grade = 'B';
    } else if (s->percentage >= 70) {
        s->grade = 'C';
    } else if (s->percentage >= 60) {
        s->grade = 'D';
    } else if (s->percentage >= 50) {
        s->grade = 'E';
    } else {
        s->grade = 'F';
    }
}

void loadStudentsFromFile(void) {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        return;
    }

    while (!feof(fp) && studentCount < MAX_STUDENTS) {
        Student s;
        if (fscanf(fp, "%d|%49[^|]|%d|%d|%d|%d|%d\n",
                   &s.rollNo, s.name,
                   &s.marks[0], &s.marks[1], &s.marks[2], &s.marks[3], &s.marks[4]) == 7) {
            calculateResult(&s);
            students[studentCount++] = s;
        }
    }

    fclose(fp);
}

void saveStudentsToFile(void) {
    FILE *fp = fopen(FILE_NAME, "w");
    if (fp == NULL) {
        printf("Error: Unable to save data to file.\n");
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        fprintf(fp, "%d|%s|%d|%d|%d|%d|%d\n",
                students[i].rollNo,
                students[i].name,
                students[i].marks[0], students[i].marks[1], students[i].marks[2],
                students[i].marks[3], students[i].marks[4]);
    }

    fclose(fp);
}

void addStudent(void) {
    if (studentCount >= MAX_STUDENTS) {
        printf("Student list is full.\n");
        return;
    }

    Student s;
    printf("\nEnter Roll Number: ");
    scanf("%d", &s.rollNo);
    clearInputBuffer();

    printf("Enter Student Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0';

    printf("Enter marks for 5 subjects:\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%d", &s.marks[i]);
    }
    clearInputBuffer();

    calculateResult(&s);
    students[studentCount++] = s;
    saveStudentsToFile();

    printf("Student record added successfully.\n");
}

void displayMarksheet(void) {
    if (studentCount == 0) {
        printf("No student records found.\n");
        return;
    }

    printf("\n===== Marksheet Generation System =====\n");
    for (int i = 0; i < studentCount; i++) {
        printf("\nRoll No: %d\n", students[i].rollNo);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %d, %d, %d, %d, %d\n",
               students[i].marks[0], students[i].marks[1], students[i].marks[2],
               students[i].marks[3], students[i].marks[4]);
        printf("Total: %d\n", students[i].total);
        printf("Percentage: %.2f\n", students[i].percentage);
        printf("Grade: %c\n", students[i].grade);
        printf("-----------------------------------\n");
    }
}

void searchStudent(void) {
    int targetRoll;
    int found = 0;

    printf("Enter Roll Number to search: ");
    scanf("%d", &targetRoll);
    clearInputBuffer();

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == targetRoll) {
            printf("\nStudent Found\n");
            printf("Roll No: %d\n", students[i].rollNo);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %d, %d, %d, %d, %d\n",
                   students[i].marks[0], students[i].marks[1], students[i].marks[2],
                   students[i].marks[3], students[i].marks[4]);
            printf("Total: %d\n", students[i].total);
            printf("Percentage: %.2f\n", students[i].percentage);
            printf("Grade: %c\n", students[i].grade);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }
}

int main(void) {
    int choice;

    loadStudentsFromFile();

    while (1) {
        printf("\n===== Marksheet Generation System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Marksheet\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayMarksheet();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
