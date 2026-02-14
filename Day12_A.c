#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    // Symmetric matrix must be square
    if (m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    int matrix[m][n];

    // Input matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check symmetry
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < n; j++) {  // Only check above diagonal
            if (matrix[i][j] != matrix[j][i]) {
                printf("Not a Symmetric Matrix");
                return 0;
            }
        }
    }

    printf("Symmetric Matrix");
    return 0;
}
