#include <stdio.h>
#include <stdlib.h>

/* Node definition */
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} *NODE;

NODE top = NULL;

/* Push operation */
void push(int item)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    temp->data = item;
    temp->prev = NULL;
    temp->next = top;

    if (top != NULL)
        top->prev = temp;

    top = temp;
    printf("%d pushed into stack\n", item);
}

/* Pop operation */
void pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }

    NODE temp = top;
    printf("%d popped from stack\n", temp->data);

    top = top->next;
    if (top != NULL)
        top->prev = NULL;

    free(temp);
}

/* Peek operation */
void peek()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Top element: %d\n", top->data);
}

/* Display stack */
void display()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    NODE cur = top;
    printf("Stack elements:\n");
    while (cur != NULL)
    {
        printf("%d\n", cur->data);
        cur = cur->next;
    }
}

/* Main */
int main()
{
    int choice, item;

    while (1)
    {
        printf("\n--- STACK USING DLL ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}
