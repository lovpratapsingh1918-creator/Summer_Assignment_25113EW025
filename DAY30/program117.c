#include <stdio.h>

#define MAX 100

struct Student {
    int rollNo;
    char name[50];
    char branch[30];
    float marks;
};

int main() {
    int n, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student students[MAX];

    for (i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);

        printf("Roll Number: ");
        scanf("%d", &students[i].rollNo);

        printf("Name: ");
        scanf("%s", students[i].name);

        printf("Branch: ");
        scanf("%s", students[i].branch);

        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    printf("\nStudent Records:\n");

    for (i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Roll Number: %d\n", students[i].rollNo);
        printf("Name: %s\n", students[i].name);
        printf("Branch: %s\n", students[i].branch);
        printf("Marks: %.2f\n", students[i].marks);
    }

    return 0;
}
