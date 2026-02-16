#include <stdio.h>

int main() {
    int m, n;
    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    printf("Enter matrix elements:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int isToeplitz = 1;  // assume true

    // Check diagonals
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(matrix[i][j] != matrix[i-1][j-1]) {
                isToeplitz = 0;
                break;
            }
        }
        if(isToeplitz == 0)
            break;
    }

    if(isToeplitz)
        printf("True (Toeplitz Matrix)");
    else
        printf("False (Not a Toeplitz Matrix)");

    return 0;
}

