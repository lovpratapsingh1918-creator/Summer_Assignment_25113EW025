#include <stdio.h>

int main() {
    int i, j, k, len1, len2;
    int arr1[20], arr2[20], arr[40];
    printf("enter the number of elements in array1 = ");
    scanf("%d", &len1);
    printf("enter the first sorted array =\n");
    for (i = 0; i < len1; i++) {
        printf("enter the value of arr1[%d] = ", i);
        scanf("%d", &arr1[i]);
    }
    printf("enter the number of elements in array2 = ");
    scanf("%d", &len2);
    printf("enter the second sorted array =\n");
    for (i = 0; i < len2; i++) {
        printf("enter the value of arr2[%d] = ", i);
        scanf("%d", &arr2[i]);
    }
    i = 0;
    j = 0;
    for (k = 0; k < len1 + len2; k++) {
        if (i < len1 && j < len2) {
            if (arr1[i] <= arr2[j]) {
                arr[k] = arr1[i];
                i++;
            } else {
                arr[k] = arr2[j];
                j++;
            }
        } else if (i < len1) {
            arr[k] = arr1[i];
            i++;
        } else {
            arr[k] = arr2[j];
            j++;
        }
    }
    printf("array after merging = ");
    for (k = 0; k < len1 + len2; k++) {
        printf("%d ", arr[k]);
    }
    printf("\n");
    return 0;
}