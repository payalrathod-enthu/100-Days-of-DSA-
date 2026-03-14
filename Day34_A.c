#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Node structure for stack
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Push operation
void push(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

// Pop operation
int pop() {
    if (top == NULL) {
        return 0;
    }

    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main() {
    char expr[100];
    char *token;

    fgets(expr, sizeof(expr), stdin);

    token = strtok(expr, " ");

    while (token != NULL) {

        // If number → push
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(atoi(token));
        }
        else {
            int b = pop();
            int a = pop();
            int result;

            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            push(result);
        }

        token = strtok(NULL, " ");
    }

    printf("%d", pop());

    return 0;
}
