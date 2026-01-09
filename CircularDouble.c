#include <stdio.h>
#include <stdlib.h>

/* Node definition */
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} *NODE;

/* Create node */
NODE createNode(int data)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        exit(0);
    }
    temp->data = data;
    temp->prev = temp;
    temp->next = temp;
    return temp;
}

/* Insert at front */
NODE insertFront(NODE head, int data)
{
    NODE temp = createNode(data);

    if (head == NULL)
        return temp;

    NODE last = head->prev;

    temp->next = head;
    temp->prev = last;
    head->prev = temp;
    last->next = temp;

    return temp;
}

/* Insert at end */
NODE insertEnd(NODE head, int data)
{
    if (head == NULL)
        return createNode(data);

    NODE temp = createNode(data);
    NODE last = head->prev;

    temp->next = head;
    temp->prev = last;
    last->next = temp;
    head->prev = temp;

    return head;
}

/* Insert at position (1-based) */
NODE insertAtPosition(NODE head, int data, int pos)
{
    if (pos == 1)
        return insertFront(head, data);

    NODE cur = head;
    for (int i = 1; i < pos - 1; i++)
    {
        cur = cur->next;
        if (cur == head)
        {
            printf("Invalid position\n");
            return head;
        }
    }

    NODE temp = createNode(data);
    temp->next = cur->next;
    temp->prev = cur;
    cur->next->prev = temp;
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
            temp->prev = cur;
            cur->next->prev = temp;
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

    NODE cur = head->next;
    while (cur != head)
    {
        if (cur->data == value)
        {
            NODE temp = createNode(data);
            temp->next = cur;
            temp->prev = cur->prev;
            cur->prev->next = temp;
            cur->prev = temp;
            return head;
        }
        cur = cur->next;
    }

    printf("Value not found\n");
    return head;
}

/* Delete front */
NODE deleteFront(NODE head)
{
    if (head == NULL)
        return NULL;

    if (head->next == head)
    {
        free(head);
        return NULL;
    }

    NODE last = head->prev;
    NODE temp = head;

    head = head->next;
    head->prev = last;
    last->next = head;

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

    NODE last = head->prev;
    last->prev->next = head;
    head->prev = last->prev;

    free(last);
    return head;
}

/* Delete at position */
NODE deleteAtPosition(NODE head, int pos)
{
    if (pos == 1)
        return deleteFront(head);

    NODE cur = head;
    for (int i = 1; i < pos; i++)
    {
        cur = cur->next;
        if (cur == head)
        {
            printf("Invalid position\n");
            return head;
        }
    }

    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    free(cur);

    return head;
}

/* Delete a given value */
NODE deleteValue(NODE head, int value)
{
    if (head == NULL)
        return NULL;

    NODE cur = head;
    do
    {
        if (cur->data == value)
        {
            if (cur == head)
                return deleteFront(head);

            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            free(cur);
            return head;
        }
        cur = cur->next;
    } while (cur != head);

    printf("Value not found\n");
    return head;
}

/* Display list */
void display(NODE head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    NODE cur = head;
    printf("HEAD <-> ");
    do
    {
        printf("%d <-> ", cur->data);
        cur = cur->next;
    } while (cur != head);
    printf("HEAD\n");
}

/* Main */
int main()
{
    NODE head = NULL;

    head = insertFront(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertAtPosition(head, 15, 2);
    head = insertAfterValue(head, 20, 25);
    head = insertBeforeValue(head, 10, 5);

    printf("Doubly Circular Linked List:\n");
    display(head);

    head = deleteFront(head);
    head = deleteEnd(head);
    head = deleteAtPosition(head, 2);
    head = deleteValue(head, 20);

    printf("\nAfter Deletions:\n");
    display(head);

    return 0;
}
