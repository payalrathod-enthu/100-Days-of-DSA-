#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    // Allocate memory for result array
    int* answer = (int*)malloc(numsSize * sizeof(int));

    // Step 1: Store left products
    answer[0] = 1;  // No element to the left of index 0
    for (int i = 1; i < numsSize; i++) {
        answer[i] = answer[i - 1] * nums[i - 1];
    }

    // Step 2: Multiply with right products
    int rightProduct = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        answer[i] = answer[i] * rightProduct;
        rightProduct *= nums[i];
    }

    return answer;
}
