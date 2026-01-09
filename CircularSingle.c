#include <stdio.h>
#include <stdlib.h>

/* Node definition */
typedef struct node
{
    int data;
    struct node *next;
} *NODE;

/* Create a new node */
NODE createNode(int data)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        exit(0);
    }
    temp->data = data;
    temp->next = temp;   // circular link
    return temp;
}

/* Insert at front */
NODE insertFront(NODE head, int data)
{
    NODE temp = createNode(data);

    if (head == NULL)
        return temp;

    NODE cur = head;
    while (cur->next != head)
        cur = cur->next;

    temp->next = head;
    cur->next = temp;
    head = temp;

    return head;
}

/* Insert at end */
NODE insertEnd(NODE head, int data)
{
    NODE temp = createNode(data);

    if (head == NULL)
        return temp;

    NODE cur = head;
    while (cur->next != head)
        cur = cur->next;

    cur->next = temp;
    temp->next = head;

    return head;
}

/* Insert at position (1-based) */
NODE insertAtPosition(NODE head, int data, int pos)
{
    if (pos == 1)
        return insertFront(head, data);

    if (head == NULL)
    {
        printf("Invalid position\n");
        return head;
    }

    NODE cur = head;
    for (int i = 1; i < pos - 1 && cur->next != head; i++)
        cur = cur->next;

    if (cur->next == head && pos != 2)
    {
        printf("Invalid position\n");
        return head;
    }

    NODE temp = createNode(data);
    temp->next = cur->next;
    cur->next = temp;

    return head;
}

/* Insert after a value */
NODE insertAfterValue(NODE head, int data, int value)
{
    if (head == NULL)
        return head;

    NODE cur = head;
    do
    {
        if (cur->data == value)
        {
            NODE temp = createNode(data);
            temp->next = cur->next;
            cur->next = temp;
            return head;
        }
        cur = cur->next;
    } while (cur != head);

    printf("Value not found\n");
    return head;
}

/* Insert before a value */
NODE insertBeforeValue(NODE head, int data, int value)
{
    if (head == NULL)
        return head;

    if (head->data == value)
        return insertFront(head, data);

    NODE cur = head;
    while (cur->next != head && cur->next->data != value)
        cur = cur->next;

    if (cur->next == head)
    {
        printf("Value not found\n");
        return head;
    }

    NODE temp = createNode(data);
    temp->next = cur->next;
    cur->next = temp;

    return head;
}

/* Delete front */
NODE deleteFront(NODE head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }

    if (head->next == head)
    {
        free(head);
        return NULL;
    }

    NODE cur = head;
    while (cur->next != head)
        cur = cur->next;

    NODE temp = head;
    cur->next = head->next;
    head = head->next;
    free(temp);

    return head;
}

/* Delete end */
NODE deleteEnd(NODE head)
{
    if (head == NULL)
        return NULL;

    if (head->next == head)
    {
        free(head);
        return NULL;
    }

    NODE cur = head;
    while (cur->next->next != head)
        cur = cur->next;

    free(cur->next);
    cur->next = head;

    return head;
}

/* Delete at position */
NODE deleteAtPosition(NODE head, int pos)
{
    if (pos == 1)
        return deleteFront(head);

    NODE cur = head;
    for (int i = 1; i < pos - 1 && cur->next != head; i++)
        cur = cur->next;

    if (cur->next == head)
    {
        printf("Invalid position\n");
        return head;
    }

    NODE temp = cur->next;
    cur->next = temp->next;
    free(temp);

    return head;
}

/* Delete a given value */
NODE deleteValue(NODE head, int value)
{
    if (head == NULL)
        return NULL;

    if (head->data == value)
        return deleteFront(head);

    NODE cur = head;
    while (cur->next != head && cur->next->data != value)
        cur = cur->next;

    if (cur->next == head)
    {
        printf("Value not found\n");
        return head;
    }

    NODE temp = cur->next;
    cur->next = temp->next;
    free(temp);

    return head;
}

/* Display circular list */
void display(NODE head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    NODE cur = head;
    do
    {
        printf("%d -> ", cur->data);
        cur = cur->next;
    } while (cur != head);

    printf("(back to head)\n");
}

/* Main function */
int main()
{
    NODE head = NULL;

    head = insertFront(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertAtPosition(head, 15, 2);
    head = insertAfterValue(head, 20, 25);
    head = insertBeforeValue(head, 10, 5);

    printf("Circular Linked List:\n");
    display(head);

    head = deleteFront(head);
    head = deleteEnd(head);
    head = deleteAtPosition(head, 2);
    head = deleteValue(head, 20);

    printf("\nAfter Deletions:\n");
    display(head);

    return 0;
}
