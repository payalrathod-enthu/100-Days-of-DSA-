#include <stdio.h>
#include <stdlib.h>

// structure for meeting
typedef struct {
    int start;
    int end;
} Meeting;

// comparator for sorting by start time
int cmp(const void* a, const void* b) {
    Meeting* m1 = (Meeting*)a;
    Meeting* m2 = (Meeting*)b;
    return m1->start - m2->start;
}

// ----------- Min Heap Functions -----------
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] > heap[index]) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else break;
    }
}

void heapifyDown(int heap[], int size, int index) {
    while (1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index) {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        } else break;
    }
}

void push(int heap[], int* size, int value) {
    heap[*size] = value;
    (*size)++;
    heapifyUp(heap, (*size) - 1);
}

void pop(int heap[], int* size) {
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
}

int top(int heap[]) {
    return heap[0];
}

// ----------- Main Function -----------
int minMeetingRooms(int start[], int end[], int n) {
    Meeting meetings[n];

    // create meeting pairs
    for (int i = 0; i < n; i++) {
        meetings[i].start = start[i];
        meetings[i].end = end[i];
    }

    // sort by start time
    qsort(meetings, n, sizeof(Meeting), cmp);

    int heap[n];  // min heap for end times
    int heapSize = 0;

    // first meeting
    push(heap, &heapSize, meetings[0].end);

    for (int i = 1; i < n; i++) {
        // if room free → reuse
        if (meetings[i].start >= top(heap)) {
            pop(heap, &heapSize);
        }
        // assign room
        push(heap, &heapSize, meetings[i].end);
    }

    return heapSize;
}

// ----------- Driver Code -----------
int main() {
    int n;
    scanf("%d", &n);

    int start[n], end[n];

    for (int i = 0; i < n; i++) scanf("%d", &start[i]);
    for (int i = 0; i < n; i++) scanf("%d", &end[i]);

    printf("%d", minMeetingRooms(start, end, n));

    return 0;
}
