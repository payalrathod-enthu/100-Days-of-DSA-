#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;

    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Function to rotate list right by k places
struct Node* rotateRight(struct Node* head, int k) {
    if (!head || !head->next || k == 0)
        return head;

    // Step 1: Find length and last node
    struct Node* temp = head;
    int length = 1;

    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }

    // Step 2: Make list circular
    temp->next = head;

    // Step 3: Normalize k
    k = k % length;
    int stepsToNewHead = length - k;

    // Step 4: Move to new tail
    struct Node* newTail = head;
    for (int i = 1; i < stepsToNewHead; i++) {
        newTail = newTail->next;
    }

    // Step 5: Set new head and break circle
    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

// Function to display list
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

// Main function
int main() {
    int n, k;
    scanf("%d", &n);

    struct Node* head = createList(n);

    scanf("%d", &k);

    head = rotateRight(head, k);

    display(head);

    return 0;
}
