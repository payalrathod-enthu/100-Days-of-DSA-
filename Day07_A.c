#include <stdio.h>

// Recursive function to compute Fibonacci number
int fib(int n) {
    if (n == 0)
        return 0;           // Base case
    else if (n == 1)
        return 1;           // Base case
    else
        return fib(n - 1) + fib(n - 2);  // Recursive case
}

int main() {
    int n;

    // Input from user
    printf("Enter value of n: ");
    scanf("%d", &n);

    // Output Fibonacci number
    printf("The %d-th Fibonacci number is: %d\n", n, fib(n));

    return 0;
}
