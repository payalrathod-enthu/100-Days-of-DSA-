#include <stdio.h>

// check if possible within maxTime
int canPaint(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int currTime = 0;

    for (int i = 0; i < n; i++) {
        if (currTime + boards[i] > maxTime) {
            painters++;
            currTime = boards[i];
        } else {
            currTime += boards[i];
        }

        if (painters > k)
            return 0;
    }

    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[n];
    int sum = 0, maxBoard = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
        sum += boards[i];
        if (boards[i] > maxBoard)
            maxBoard = boards[i];
    }

    int left = maxBoard;
    int right = sum;
    int ans = sum;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canPaint(boards, n, k, mid)) {
            ans = mid;        // possible answer
            right = mid - 1;  // try smaller time
        } else {
            left = mid + 1;   // increase time
        }
    }

    printf("%d", ans);
    return 0;
}
