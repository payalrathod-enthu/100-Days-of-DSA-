#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    // Input size of array
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Array is empty.\n");
        return 0;
    }

    // Dynamic allocation using malloc
    int *arr = (int *)malloc(n * sizeof(int));

    // Input elements (sorted)
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Remove duplicates in-place
    int j = 1;  // Points to position for next unique element

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            arr[j] = arr[i];
            j++;
        }
    }

    // Print unique elements
    printf("Unique elements are:\n");
    for (int i = 0; i < j; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}
