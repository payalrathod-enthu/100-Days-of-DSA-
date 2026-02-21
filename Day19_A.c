#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function for qsort (ascending order)
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 1: Sort the array
    qsort(arr, n, sizeof(int), compare);

    // Step 2: Two-pointer technique
    int left = 0;
    int right = n - 1;

    int minSum = INT_MAX;
    int first = arr[left], second = arr[right];

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < abs(minSum)) {
            minSum = sum;
            first = arr[left];
            second = arr[right];
        }

        // Move pointers
        if (sum < 0)
            left++;      // Need larger sum
        else
            right--;     // Need smaller sum
    }

    printf("%d %d\n", first, second);
    return 0;
}
