#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} *NODE;

NODE createNode(int data)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        exit(0);
    }
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

NODE insertFront(NODE head, int data)
{
    NODE temp = createNode(data);

    if (head != NULL)
    {
        temp->next = head;
        head->prev = temp;
    }
    return temp;
}

NODE insertEnd(NODE head, int data)
{
    NODE temp = createNode(data);

    if (head == NULL)
        return temp;

    NODE cur = head;
    while (cur->next != NULL)
        cur = cur->next;

    cur->next = temp;
    temp->prev = cur;
    return head;
}

NODE insertAtPosition(NODE head, int data, int pos)
{
    if (pos == 1)
        return insertFront(head, data);

    NODE cur = head;
    for (int i = 1; i < pos - 1 && cur != NULL; i++)
        cur = cur->next;

    if (cur == NULL)
    {
        printf("Invalid position\n");
        return head;
    }

    NODE temp = createNode(data);
    temp->next = cur->next;
    temp->prev = cur;

    if (cur->next != NULL)
        cur->next->prev = temp;

    cur->next = temp;
    return head;
}

NODE insertAfterValue(NODE head, int data, int value)
{
    NODE cur = head;
    while (cur != NULL && cur->data != value)
        cur = cur->next;

    if (cur == NULL)
    {
        printf("Value not found\n");
        return head;
    }

    NODE temp = createNode(data);
    temp->next = cur->next;
    temp->prev = cur;

    if (cur->next != NULL)
        cur->next->prev = temp;

    cur->next = temp;
    return head;
}

NODE insertBeforeValue(NODE head, int data, int value)
{
    if (head == NULL)
        return head;

    if (head->data == value)
        return insertFront(head, data);

    NODE cur = head;
    while (cur != NULL && cur->data != value)
        cur = cur->next;

    if (cur == NULL)
    {
        printf("Value not found\n");
        return head;
    }

    NODE temp = createNode(data);
    temp->prev = cur->prev;
    temp->next = cur;

    cur->prev->next = temp;
    cur->prev = temp;

    return head;
}

NODE deleteFront(NODE head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }

    NODE temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
    return head;
}

NODE deleteEnd(NODE head)
{
    if (head == NULL)
        return NULL;

    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    NODE cur = head;
    while (cur->next != NULL)
        cur = cur->next;

    cur->prev->next = NULL;
    free(cur);
    return head;
}

NODE deleteAtPosition(NODE head, int pos)
{
    if (pos == 1)
        return deleteFront(head);

    NODE cur = head;
    for (int i = 1; i < pos && cur != NULL; i++)
        cur = cur->next;

    if (cur == NULL)
    {
        printf("Invalid position\n");
        return head;
    }

    if (cur->next != NULL)
        cur->next->prev = cur->prev;

    cur->prev->next = cur->next;
    free(cur);
    return head;
}

NODE deleteValue(NODE head, int value)
{
    NODE cur = head;
    while (cur != NULL && cur->data != value)
        cur = cur->next;

    if (cur == NULL)
    {
        printf("Value not found\n");
        return head;
    }

    if (cur == head)
        return deleteFront(head);

    if (cur->next != NULL)
        cur->next->prev = cur->prev;

    cur->prev->next = cur->next;
    free(cur);
    return head;
}

void displayForward(NODE head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    NODE cur = head;
    printf("NULL <-> ");
    while (cur != NULL)
    {
        printf("%d <-> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

int main()
{
    NODE head = NULL;

    head = insertFront(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertAtPosition(head, 15, 2);
    head = insertAfterValue(head, 25, 20);
    head = insertBeforeValue(head, 5, 10);

    printf("Doubly Linked List:\n");
    displayForward(head);

    head = deleteFront(head);
    head = deleteEnd(head);
    head = deleteAtPosition(head, 2);
    head = deleteValue(head, 20);

    printf("\nAfter Deletions:\n");
    displayForward(head);

    return 0;
}
