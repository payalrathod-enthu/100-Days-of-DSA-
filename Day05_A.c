#include <stdio.h>
#include <stdlib.h>

int main() {
    int p, q;

    // Input size of first log
    scanf("%d", &p);
    int *log1 = (int *)malloc(p * sizeof(int));

    // Input elements of first log
    for (int i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }

    // Input size of second log
    scanf("%d", &q);
    int *log2 = (int *)malloc(q * sizeof(int));

    // Input elements of second log
    for (int i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }

    // Create merged array
    int *merged = (int *)malloc((p + q) * sizeof(int));

    int i = 0, j = 0, k = 0;

    // Merge both arrays
    while (i < p && j < q) {
        if (log1[i] <= log2[j]) {
            merged[k++] = log1[i++];
        } else {
            merged[k++] = log2[j++];
        }
    }

    // Copy remaining elements of log1 (if any)
    while (i < p) {
        merged[k++] = log1[i++];
    }

    // Copy remaining elements of log2 (if any)
    while (j < q) {
        merged[k++] = log2[j++];
    }

    // Output merged log
    for (int x = 0; x < p + q; x++) {
        printf("%d ", merged[x]);
    }

    // Free allocated memory
    free(log1);
    free(log2);
    free(merged);

    return 0;
}
