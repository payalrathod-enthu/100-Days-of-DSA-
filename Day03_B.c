#include <stdio.h>

int findMissing(int arr[], int size) {
    int n = size + 1;  // because one number is missing

    // Expected sum from 1 to n
    long long expectedSum = (long long)n * (n + 1) / 2;

    // Actual sum of array
    long long actualSum = 0;
    for (int i = 0; i < size; i++) {
        actualSum += arr[i];
    }

    // Missing number
    return (int)(expectedSum - actualSum);
}

int main() {
    int arr[] = {1, 2, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int missing = findMissing(arr, size);
    printf("Missing number is: %d\n", missing);

    return 0;
}

