int missingNum(int *arr, int size) {
    // size = n-1, so n = size + 1
    long long n = size + 1;

    // Expected sum of numbers from 1 to n
    long long expectedSum = n * (n + 1) / 2;

    // Actual sum of given array
    long long actualSum = 0;
    for (int i = 0; i < size; i++) {
        actualSum += arr[i];
    }

    // Missing number
    return (int)(expectedSum - actualSum);
}
