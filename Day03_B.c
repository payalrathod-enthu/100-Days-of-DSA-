#include <stdio.h>

int main() {
    int n, i;
    
    printf("Enter size of array (n-1): ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int total = (n + 1) * (n + 2) / 2;   // sum from 1 to n+1
    int sum = 0;

    for(i = 0; i < n; i++) {
        sum += arr[i];
    }

    int missing = total - sum;

    printf("Missing number is: %d", missing);

    return 0;
}


