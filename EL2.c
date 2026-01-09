#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* makeNode(int v) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = v;
    n->next = NULL;
    return n;
}

void addFront(struct Node **head, int v) {
    struct Node* n = makeNode(v);
    n->next = *head;
    *head = n;
}

void addEnd(struct Node **head, int v) {
    struct Node* n = makeNode(v);

    if (*head == NULL) {
        *head = n;
        return;
    }

    struct Node *t = *head;
    while (t->next)
        t = t->next;

    t->next = n;
}

void removeFront(struct Node **head) {
    if (*head == NULL) {
        printf("List empty!\n");
        return;
    }
    struct Node *t = *head;
    *head = (*head)->next;
    free(t);
}

void removeEnd(struct Node **head) {
    if (*head == NULL) {
        printf("List empty!\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node *t = *head;
    while (t->next->next)
        t = t->next;

    free(t->next);
    t->next = NULL;
}

void insertAt(struct Node **head, int v, int pos) {
    if (pos <= 1) {
        addFront(head, v);
        return;
    }

    struct Node *t = *head;
    for (int i = 1; t != NULL && i < pos - 1; i++) {
        t = t->next;
    }

    if (t == NULL) {
        printf("Position out of range!\n");
        return;
    }

    struct Node *n = makeNode(v);
    n->next = t->next;
    t->next = n;
}

void show(struct Node *head) {
    printf("\nList: ");
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;

    addFront(&head, 10);
    addFront(&head, 20);
    addFront(&head, 30);
    show(head);

    addEnd(&head, 40);
    addEnd(&head, 50);
    addEnd(&head, 60);
    show(head);

    removeFront(&head);
    show(head);

    removeEnd(&head);
    show(head);

    insertAt(&head, 0, 3);
    show(head);

    return 0;
}
