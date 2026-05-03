#include <stdio.h>
#include <stdlib.h>

long long merge(int arr[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int size = right - left + 1;

    int* temp = (int*)malloc(size * sizeof(int));
    long long invCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1); // key step
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (int x = 0; x < size; x++) {
        arr[left + x] = temp[x];
    }

    free(temp);
    return invCount;
}

long long mergeSort(int arr[], int left, int right) {
    if (left >= right) return 0;

    int mid = left + (right - left) / 2;

    long long invCount = 0;
    invCount += mergeSort(arr, left, mid);
    invCount += mergeSort(arr, mid + 1, right);
    invCount += merge(arr, left, mid, right);

    return invCount;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long result = mergeSort(arr, 0, n - 1);

    printf("%lld", result);
    return 0;
}
