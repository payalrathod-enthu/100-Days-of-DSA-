#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

int stack[MAX];
int top = -1;

void enqueue(int x) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    int n, x;
    scanf("%d", &n);

    // insert into queue
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // move queue -> stack
    while(front <= rear) {
        push(dequeue());
    }

    // move stack -> queue
    front = rear = -1;
    while(top != -1) {
        enqueue(pop());
    }

    // print reversed queue
    for(int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}
Example
Input
5
