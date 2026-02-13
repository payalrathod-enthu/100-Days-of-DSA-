#include <stdio.h>
#include <string.h>

int main() {
    char str[100];

    // Input string
    printf("Enter the code name: ");
    scanf("%s", str);   // Reads string (no spaces as per problem)

    int left = 0;
    int right = strlen(str) - 1;

    // Reverse the string in-place
    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        left++;
        right--;
    }

    // Output mirrored string
    printf("Mirrored code name: %s\n", str);

    return 0;
}
