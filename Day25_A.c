#include <stdio.h>
#include <stdlib.h>

// Define structure of node
struct Node {
    int data;
    struct Node* next;
};

// Function to create linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int value;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {   // first node
            head = newNode;
            temp = newNode;
        } else {              // remaining nodes
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Function to count occurrences of key
int countOccurrences(struct Node* head, int key) {
    int count = 0;
    struct Node* current = head;

    while (current != NULL) {
        if (current->data == key) {
            count++;
        }
        current = current->next;
    }
    return count;
}

int main() {
    int n, key;

    scanf("%d", &n);

    // Create linked list
    struct Node* head = createList(n);

    // Read key
    scanf("%d", &key);

    // Count occurrences
    int result = countOccurrences(head, key);

    // Print result
    printf("%d\n", result);

    return 0;
}
