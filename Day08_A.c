#include <stdio.h>

// Recursive function to compute a^b
long long power(int a, int b) {
    if (b == 0)
        return 1;               // Base case: a^0 = 1
    else
        return a * power(a, b - 1);  // Recursive call
}

int main() {
    int a, b;

    // Input from user
    printf("Enter base (a) and exponent (b): ");
    scanf("%d %d", &a, &b);

    // Compute and print result
    long long result = power(a, b);
    printf("%d raised to the power %d is: %lld\n", a, b, result);

    return 0;
}
