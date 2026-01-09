#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} *NODE;

NODE createNode(int data){
    NODE temp = (NODE)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        exit(0);
    }
    temp->data = data;
    temp->next = NULL;
    return temp;
}

NODE insertFront(NODE head, int data){
    NODE temp = createNode(data);
    temp->next = head;
    return temp;
}

NODE insertEnd(NODE head, int data){
    NODE temp = createNode(data);
    if (head == NULL)
        return temp;

    NODE cur = head;
    while (cur->next != NULL)
        cur = cur->next;

    cur->next = temp;
    return head;
}

NODE insertAtPosition(NODE head, int data, int pos){
    if (pos == 1)
        return insertFront(head, data);

    NODE temp = createNode(data);
    NODE cur = head;

    for (int i = 1; i < pos - 1 && cur != NULL; i++)
        cur = cur->next;

    if (cur == NULL)
    {
        printf("Invalid position\n");
        free(temp);
        return head;
    }

    temp->next = cur->next;
    cur->next = temp;
    return head;
}

NODE insertAfterValue(NODE head, int data, int value){
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
    cur->next = temp;

    return head;
}

NODE insertBeforeValue(NODE head, int data, int value){
    if (head == NULL)
        return head;

    if (head->data == value)
        return insertFront(head, data);  

    NODE cur = head;

    while (cur->next != NULL && cur->next->data != value)
        cur = cur->next;

    if (cur->next == NULL)
    {
        printf("Value not found\n");
        return head;
    }

    NODE temp = createNode(data);
    temp->next = cur->next;
    cur->next = temp;

    return head;
}

NODE deleteFront(NODE head){
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }

    NODE temp = head;
    head = head->next;
    free(temp);
    return head;
}

NODE deleteEnd(NODE head){
    if (head == NULL || head->next == NULL)
    {
        free(head);
        return NULL;
    }

    NODE cur = head;
    while (cur->next->next != NULL)
        cur = cur->next;

    free(cur->next);
    cur->next = NULL;
    return head;
}

NODE deleteAtPosition(NODE head, int pos){
    if (pos == 1)
        return deleteFront(head);

    NODE cur = head;
    for (int i = 1; i < pos - 1 && cur != NULL; i++)
        cur = cur->next;

    if (cur == NULL || cur->next == NULL)
    {
        printf("Invalid position\n");
        return head;
    }

    NODE temp = cur->next;
    cur->next = temp->next;
    free(temp);
    return head;
}

NODE deleteValue(NODE head, int value){
    if (head == NULL)
        return NULL;

    if (head->data == value)
        return deleteFront(head);

    NODE cur = head;
    while (cur->next != NULL && cur->next->data != value)
        cur = cur->next;

    if (cur->next == NULL)
    {
        printf("Value not found\n");
        return head;
    }

    NODE temp = cur->next;
    cur->next = temp->next;
    free(temp);
    return head;
}

void display(NODE head){
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    NODE cur = head;
    while (cur != NULL)
    {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

int main(){
    NODE head = NULL;

    head = insertFront(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertAtPosition(head, 15, 2);
    head = insertAfterValue(head, 25, 20);
    head = insertBeforeValue(head, 5, 10);
    display(head);
    printf("Linked List:\n");
    display(head);

    head = deleteFront(head);
    head = deleteEnd(head);
    head = deleteAtPosition(head, 2);
    head = deleteValue(head, 25);

    printf("\nAfter Deletions:\n");
    display(head);

    return 0;
}
