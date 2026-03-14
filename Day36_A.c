#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = 0;
int rear = -1;
int size = 0;

// Enqueue operation
void enqueue(int val) {
    rear = (rear + 1) % MAX;
    queue[rear] = val;
    size++;
}

// Dequeue operation
void dequeue() {
    if(size > 0) {
        front = (front + 1) % MAX;
        size--;
    }
}

// Display queue
void display() {
    int count = size;
    int i = front;

    while(count--) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
    }
}

int main() {

    int n, m, x;

    scanf("%d", &n);

    // Enqueue elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    // Perform dequeue operations
    for(int i = 0; i < m; i++) {
        dequeue();
    }

    display();

    return 0;
}
