#include <stdio.h>

#define EMPTY -1

int main() {
    int m, q;
    scanf("%d", &m);   // table size
    scanf("%d", &q);   // number of operations

    int table[m];

    // initialize table
    for(int i = 0; i < m; i++)
        table[i] = EMPTY;

    char op[10];
    int key;

    while(q--) {
        scanf("%s %d", op, &key);

        int h = key % m;

        if(op[0] == 'I') {  // INSERT
            for(int i = 0; i < m; i++) {
                int idx = (h + i*i) % m;

                if(table[idx] == EMPTY) {
                    table[idx] = key;
                    break;
                }
            }
        }
        else if(op[0] == 'S') {  // SEARCH
            int found = 0;

            for(int i = 0; i < m; i++) {
                int idx = (h + i*i) % m;

                if(table[idx] == key) {
                    found = 1;
                    break;
                }

                if(table[idx] == EMPTY)
                    break;
            }

            if(found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}
