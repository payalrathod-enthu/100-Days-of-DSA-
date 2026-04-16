#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    int freq[26] = {0};

    printf("Enter string: ");
    scanf("%s", str);

    int n = strlen(str);

    // count frequency of each character
    for(int i = 0; i < n; i++) {
        freq[str[i] - 'a']++;
    }

    // find first non-repeating character
    for(int i = 0; i < n; i++) {
        if(freq[str[i] - 'a'] == 1) {
            printf("%c\n", str[i]);
            return 0;
        }
    }

    // if none found
    printf("$\n");

    return 0;
}
