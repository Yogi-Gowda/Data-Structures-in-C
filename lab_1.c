#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int info;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->info = value;
    new->next = NULL;
    return new;
}

Node* orderedInsert(Node* start, int value) {
    Node* new = createNode(value);

    if (start == NULL || value < start->info) {
        new->next = start;
        return new;
    }

    Node* temp = start;
    while (temp->next != NULL && temp->next->info < value) {
        temp = temp->next;
    }

    new->next = temp->next;
    temp->next = new;

    return start;
}

Node* reverseList(Node* start) {
    Node* prev = NULL;
    Node* curr = start;
    Node* next;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

Node* sortList(Node* start) {
    Node* sorted = NULL;
    Node* temp = start;

    while (temp != NULL) {
        sorted = orderedInsert(sorted, temp->info);
        temp = temp->next;
    }

    return sorted;
}

void display(Node* start) {
    while (start != NULL) {
        printf("%d -> ", start->info);
        start = start->next;
    }
    printf("NULL\n");
}

int main() {
    Node* start = NULL;

    start = orderedInsert(start, 30);
    start = orderedInsert(start, 10);
    start = orderedInsert(start, 20);
    start = orderedInsert(start, 50);
    start = orderedInsert(start, 40);

    printf("Original (unsorted) list:\n");
    display(start);

    start = reverseList(start);
    printf("\nAfter reverse:\n");
    display(start);

    start = sortList(start);
    printf("\nAfter sorting using orderedInsert():\n");
    display(start);

    return 0;
}
