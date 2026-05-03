#include <stdio.h>
#include <stdlib.h>

// comparator to sort by start time
int cmp(const void* a, const void* b) {
    int* i1 = *(int**)a;
    int* i2 = *(int**)b;
    return i1[0] - i2[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize,
             int* returnSize, int** returnColumnSizes) {

    // Step 1: sort intervals
    qsort(intervals, intervalsSize, sizeof(int*), cmp);

    int** result = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));

    int index = 0;

    for (int i = 0; i < intervalsSize; i++) {
        // if first interval OR no overlap
        if (index == 0 || intervals[i][0] > result[index - 1][1]) {
            result[index] = (int*)malloc(2 * sizeof(int));
            result[index][0] = intervals[i][0];
            result[index][1] = intervals[i][1];
            (*returnColumnSizes)[index] = 2;
            index++;
        } else {
            // merge intervals
            if (intervals[i][1] > result[index - 1][1]) {
                result[index - 1][1] = intervals[i][1];
            }
        }
    }

    *returnSize = index;
    return result;
}
