#include <stdio.h>
#include <stdlib.h>

int *stack;
int top = -1;
int size;

/* Push operation */
void push(int item)
{
    if (top == size - 1)
    {
        printf("Stack Overflow! Increasing size...\n");
        size *= 2;
        stack = (int *)realloc(stack, size * sizeof(int));
        if (stack == NULL)
        {
            printf("Memory allocation failed\n");
            exit(0);
        }
    }

    stack[++top] = item;
    printf("%d pushed into stack\n", item);
}

/* Pop operation */
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }

    printf("%d popped from stack\n", stack[top--]);
}

/* Peek operation */
void peek()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Top element: %d\n", stack[top]);
}

/* Display stack */
void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements:\n");
    for (int i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
}

/* Main function */
int main()
{
    int choice, item;

    printf("Enter initial stack size: ");
    scanf("%d", &size);

    stack = (int *)malloc(size * sizeof(int));
    if (stack == NULL)
    {
        printf("Memory allocation failed\n");
        return 0;
    }

    while (1)
    {
        printf("\n--- DYNAMIC STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to push: ");
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
            free(stack);
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}
