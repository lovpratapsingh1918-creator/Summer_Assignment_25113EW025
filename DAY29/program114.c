#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int array[MAX_SIZE];
int arraySize = 0;

// Function to display the array
void displayArray() {
    if (arraySize == 0) {
        printf("\n*** Array is empty! ***\n");
        return;
    }

    printf("\nArray elements: ");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to insert element at the end
void insertElement() {
    if (arraySize >= MAX_SIZE) {
        printf("\n*** Array is full! Cannot insert more elements. ***\n");
        return;
    }

    int element;
    printf("Enter element to insert: ");
    scanf("%d", &element);

    array[arraySize] = element;
    arraySize++;
    printf("\nElement %d inserted successfully!\n", element);
}

// Function to insert element at specific position
void insertAtPosition() {
    if (arraySize >= MAX_SIZE) {
        printf("\n*** Array is full! ***\n");
        return;
    }

    int position, element;
    printf("Enter position to insert at (0 to %d): ", arraySize);
    scanf("%d", &position);

    if (position < 0 || position > arraySize) {
        printf("\n*** Invalid position! ***\n");
        return;
    }

    printf("Enter element to insert: ");
    scanf("%d", &element);

    // Shift elements to the right
    for (int i = arraySize; i > position; i--) {
        array[i] = array[i - 1];
    }

    array[position] = element;
    arraySize++;
    printf("\nElement %d inserted at position %d!\n", element, position);
}

// Function to delete element at specific position
void deleteElement() {
    if (arraySize == 0) {
        printf("\n*** Array is empty! ***\n");
        return;
    }

    int position;
    printf("Enter position to delete (0 to %d): ", arraySize - 1);
    scanf("%d", &position);

    if (position < 0 || position >= arraySize) {
        printf("\n*** Invalid position! ***\n");
        return;
    }

    int deletedElement = array[position];

    // Shift elements to the left
    for (int i = position; i < arraySize - 1; i++) {
        array[i] = array[i + 1];
    }

    arraySize--;
    printf("\nElement %d deleted from position %d!\n", deletedElement, position);
}

// Function to search for an element
void searchElement() {
    if (arraySize == 0) {
        printf("\n*** Array is empty! ***\n");
        return;
    }

    int element;
    printf("Enter element to search: ");
    scanf("%d", &element);

    int found = 0;
    for (int i = 0; i < arraySize; i++) {
        if (array[i] == element) {
            printf("Element %d found at position %d\n", element, i);
            found = 1;
        }
    }

    if (!found) {
        printf("\n*** Element %d not found in the array! ***\n", element);
    }
}

// Function to sort array (Bubble sort)
void sortArray() {
    if (arraySize == 0) {
        printf("\n*** Array is empty! ***\n");
        return;
    }

    // Bubble sort
    for (int i = 0; i < arraySize - 1; i++) {
        for (int j = 0; j < arraySize - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Swap
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    printf("\nArray sorted successfully!\n");
}

// Function to calculate sum of array elements
void calculateSum() {
    if (arraySize == 0) {
        printf("\n*** Array is empty! ***\n");
        return;
    }

    int sum = 0;
    for (int i = 0; i < arraySize; i++) {
        sum += array[i];
    }

    printf("\nSum of array elements: %d\n", sum);
}

// Function to calculate average of array elements
void calculateAverage() {
    if (arraySize == 0) {
        printf("\n*** Array is empty! ***\n");
        return;
    }

    int sum = 0;
    for (int i = 0; i < arraySize; i++) {
        sum += array[i];
    }

    double average = (double)sum / arraySize;
    printf("\nAverage of array elements: %.2lf\n", average);
}

// Function to find minimum and maximum elements
void findMinMax() {
    if (arraySize == 0) {
        printf("\n*** Array is empty! ***\n");
        return;
    }

    int min = array[0];
    int max = array[0];

    for (int i = 1; i < arraySize; i++) {
        if (array[i] < min) {
            min = array[i];
        }
        if (array[i] > max) {
            max = array[i];
        }
    }

    printf("\nMinimum element: %d\n", min);
    printf("Maximum element: %d\n", max);
}

// Main menu function
void displayMenu() {
    printf("\n");
    printf("======================================\n");
    printf("    MENU-DRIVEN ARRAY OPERATIONS     \n");
    printf("======================================\n");
    printf("1.  Insert element at end\n");
    printf("2.  Insert element at position\n");
    printf("3.  Delete element at position\n");
    printf("4.  Search element\n");
    printf("5.  Display array\n");
    printf("6.  Sort array\n");
    printf("7.  Calculate sum\n");
    printf("8.  Calculate average\n");
    printf("9.  Find min and max\n");
    printf("10. Exit\n");
    printf("======================================\n");
}

int main() {
    int choice;

    printf("\n");
    printf("=====================================\n");
    printf("  WELCOME TO ARRAY OPERATIONS SYSTEM \n");
    printf("=====================================\n");

    while (1) {
        displayMenu();
        printf("\nEnter your choice (1-10): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertElement();
                break;

            case 2:
                insertAtPosition();
                break;

            case 3:
                deleteElement();
                break;

            case 4:
                searchElement();
                break;

            case 5:
                displayArray();
                break;

            case 6:
                sortArray();
                break;

            case 7:
                calculateSum();
                break;

            case 8:
                calculateAverage();
                break;

            case 9:
                findMinMax();
                break;

            case 10:
                printf("\nThank you for using Array Operations System. Goodbye!\n");
                printf("=====================================\n\n");
                return 0;

            default:
                printf("\n*** Invalid choice! Please enter a number between 1 and 10. ***\n");
        }
    }

    return 0;
}
