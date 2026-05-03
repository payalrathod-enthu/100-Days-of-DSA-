#include <stdio.h>
#include <stdlib.h>

void merge(int* nums, int* indices, int left, int mid, int right, int* count) {
    int n = right - left + 1;
    int* temp = (int*)malloc(n * sizeof(int));

    int i = left, j = mid + 1, k = 0;
    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (nums[indices[j]] < nums[indices[i]]) {
            temp[k++] = indices[j++];
            rightCount++; // smaller element found
        } else {
            count[indices[i]] += rightCount;
            temp[k++] = indices[i++];
        }
    }

    while (i <= mid) {
        count[indices[i]] += rightCount;
        temp[k++] = indices[i++];
    }

    while (j <= right) {
        temp[k++] = indices[j++];
    }

    for (int x = 0; x < n; x++) {
        indices[left + x] = temp[x];
    }

    free(temp);
}

void mergeSort(int* nums, int* indices, int left, int right, int* count) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    mergeSort(nums, indices, left, mid, count);
    mergeSort(nums, indices, mid + 1, right, count);
    merge(nums, indices, left, mid, right, count);
}

int* countSmaller(int* nums, int numsSize) {
    int* count = (int*)calloc(numsSize, sizeof(int));
    int* indices = (int*)malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++)
        indices[i] = i;

    mergeSort(nums, indices, 0, numsSize - 1, count);

    free(indices);
    return count;
}

// -------- Driver --------
int main() {
    int nums[] = {5, 2, 6, 1};
    int n = 4;

    int* result = countSmaller(nums, n);

    for (int i = 0; i < n; i++)
        printf("%d ", result[i]);

    free(result);
    return 0;
}
