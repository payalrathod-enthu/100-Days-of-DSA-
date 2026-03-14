#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

// Check empty
int empty() {
    return (front == -1);
}

// Size
int size() {
    if (front == -1) return 0;
    return rear - front + 1;
}

// Push front
void push_front(int val) {
    if (front == -1) {
        front = rear = 0;
        deque[front] = val;
    }
    else if (front > 0) {
        deque[--front] = val;
    }
    else {
        printf("Deque Overflow\n");
    }
}

// Push back
void push_back(int val) {
    if (rear == MAX - 1) {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1)
        front = rear = 0;
    else
        rear++;

    deque[rear] = val;
}

// Pop front
void pop_front() {
    if (empty()) {
        printf("Deque Underflow\n");
        return;
    }

    front++;

    if (front > rear)
        front = rear = -1;
}

// Pop back
void pop_back() {
    if (empty()) {
        printf("Deque Underflow\n");
        return;
    }

    rear--;

    if (rear < front)
        front = rear = -1;
}

// Front element
void getFront() {
    if (empty())
        printf("-1\n");
    else
        printf("%d\n", deque[front]);
}

// Rear element
void getBack() {
    if (empty())
        printf("-1\n");
    else
        printf("%d\n", deque[rear]);
}

// Display
void display() {
    if (empty()) {
        printf("Deque Empty\n");
        return;
    }

    for (int i = front; i <= rear; i++)
        printf("%d ", deque[i]);
    printf("\n");
}

int main() {

    push_back(10);
    push_back(20);
    push_front(5);
    push_back(30);

    display();

    pop_front();
    pop_back();

    display();

    getFront();
    getBack();

    printf("Size: %d\n", size());

    return 0;
}
