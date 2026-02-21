#include <stdio.h>
#include <stdlib.h>

// Define Node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert at the end
struct Node* insertEnd(struct Node* head, int value) {
    // Create new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // If list is empty
    if (head == NULL) {
        return newNode;
    }

    // Traverse to last node
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Link new node
    temp->next = newNode;
    return head;
}

// Function to traverse and print list
void display(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, value;
    struct Node* head = NULL;

    // Input size
    scanf("%d", &n);

    // Input elements and create list
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    // Display linked list
    display(head);

    return 0;
}
