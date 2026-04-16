#include <stdio.h>

#define MAX 1000

int main() {
    int arr[MAX];
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // prefix sum
    int sum = 0, maxLen = 0;

    // store first occurrence of prefix sum
    int hash[20001];   // range handling (-10000 to +10000)
    
    // initialize with -1
    for(int i = 0; i < 20001; i++)
        hash[i] = -1;

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        // case 1: sum becomes 0
        if(sum == 0) {
            maxLen = i + 1;
        }

        // shift index for negative sums
        int index = sum + 10000;

        // if sum seen before
        if(hash[index] != -1) {
            int len = i - hash[index];
            if(len > maxLen)
                maxLen = len;
        } else {
            hash[index] = i;
        }
    }

    printf("Length of longest subarray: %d\n", maxLen);

    return 0;
}
