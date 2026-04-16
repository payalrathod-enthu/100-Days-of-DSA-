#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char names[n][100];

    // input names
    for(int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    char winner[100];
    int maxVotes = 0;

    for(int i = 0; i < n; i++) {
        int count = 1;

        // count votes for names[i]
        for(int j = i + 1; j < n; j++) {
            if(strcmp(names[i], names[j]) == 0) {
                count++;
            }
        }

        // update winner
        if(count > maxVotes) {
            maxVotes = count;
            strcpy(winner, names[i]);
        }
        else if(count == maxVotes) {
            // lexicographically smaller
            if(strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}
