#include <stdio.h>
#include <stdlib.h>

#define SIZE 100003   // Hash table size (prime number for better distribution)

// Node for chaining in hash table
struct Node {
    long long key;
    int count;
    struct Node* next;
};

struct Node* hashTable[SIZE];

// Hash function
int hash(long long key) {
    if (key < 0) key = -key;
    return key % SIZE;
}

// Insert or update prefix sum frequency
void insert(long long key) {
    int idx = hash(key);
    struct Node* temp = hashTable[idx];

    while (temp) {
        if (temp->key == key) {
            temp->count++;
            return;
        }
        temp = temp->next;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->count = 1;
    newNode->next = hashTable[idx];
    hashTable[idx] = newNode;
}

// Get frequency of prefix sum
int getCount(long long key) {
    int idx = hash(key);
    struct Node* temp = hashTable[idx];

    while (temp) {
        if (temp->key == key)
            return temp->count;
        temp = temp->next;
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    long long prefixSum = 0;
    long long count = 0;

    // Important: prefix sum 0 occurs once initially
    insert(0);

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // If prefixSum seen before → zero-sum subarray found
        count += getCount(prefixSum);

        insert(prefixSum);
    }

    printf("%lld\n", count);
    return 0;
}
