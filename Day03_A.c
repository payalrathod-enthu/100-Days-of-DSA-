#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k, i;
    int *arr;              // dynamic array
    int comparisons = 0;
    int foundIndex = -1;

    // Input size of array
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Allocate memory using malloc
    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input key to search
    printf("Enter key to search: ");
    scanf("%d", &k);

    // Linear Search
    for (i = 0; i < n; i++) {
        comparisons++;         // count each comparison

        if (arr[i] == k) {
            foundIndex = i;
            break;
        }
    }

    // Output result
    if (foundIndex != -1)
