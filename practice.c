#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newptr = (Node*)malloc(sizeof(Node));
    newptr->data = value;
    newptr->next = NULL;
    return newptr;
}

// Insert at front
void insertFront(Node** head, int value) {
    Node* newptr = createNode(value);
    newptr->next = *head;
    *head = newptr;
}

// Insert at end
void insertEnd(Node** head, int value) {
    Node* newptr = createNode(value);

    if (*head == NULL) {
        *head = newptr;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newptr;
}

// Insert at given position (1-based)
void insertAtPos(Node** head, int value, int pos) {
    if (pos <= 0) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        insertFront(head, value);
        return;
    }

    Node* newptr = createNode(value);
    Node* temp = *head;
    int i = 1;

    while (temp != NULL && i < pos - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        free(newptr);
        return;
    }

    newptr->next = temp->next;
    temp->next = newptr;
}

// Display list
void display(Node* head) {
    Node* t = head;
    printf("\nList: ");
    while (t != NULL) {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    insertFront(&head, 30);
    insertFront(&head, 20);
    display(head);
    insertEnd(&head, 40);
    display(head);
    insertAtPos(&head, 25, 3);
    display(head);

    return 0;
}
