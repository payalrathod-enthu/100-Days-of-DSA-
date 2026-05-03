#include <stdio.h>

// check if allocation possible with maxPages limit
int canAllocate(int books[], int n, int m, int maxPages) {
    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {
        if (pages + books[i] > maxPages) {
            students++;
            pages = books[i];
        } else {
            pages += books[i];
        }

        if (students > m)
            return 0;
    }

    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int books[n];
    int sum = 0, maxBook = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &books[i]);
        sum += books[i];
        if (books[i] > maxBook)
            maxBook = books[i];
    }

    int left = maxBook;
    int right = sum;
    int ans = sum;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canAllocate(books, n, m, mid)) {
            ans = mid;        // possible answer
            right = mid - 1;  // try smaller max
        } else {
            left = mid + 1;   // increase limit
        }
    }

    printf("%d", ans);
    return 0;
}
