#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct mystack {
    int stack[MAX];
    int top;
} MyStack;

int empty(MyStack *ps) {
    return (ps->top == -1);
}

int full(MyStack *ps) {
    return (ps->top == MAX - 1);
}

int pop(MyStack *ps) {
    if (empty(ps)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    int temp;
    temp = ps->stack[ps->top];
    ps->top--;
    return temp;
}

void push(MyStack *ps, int value) {
    if (full(ps)) {
        printf("Stack Overflow\n");
        exit(1);
    }
    ps->top++;
    ps->stack[ps->top] = value;
}

int peek(MyStack *ps){
    if(empty(ps)){
        printf("%s","Stack Underflow");
        exit(1);
    }
    return(ps->stack[ps->top]);
}

void display(MyStack *ps) {
    if (empty(ps)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = ps->top; i >= 0; i--) {
        printf("%d ", ps->stack[i]);
    }
    printf("\n");
}

int main() {
    MyStack S;
    S.top = -1;

    int choice, value;

    while (1) {
        printf("Enter 1 for push opeartion\n");
        printf("Enter 2 for pop opeartion\n");
        printf("Enter 3 for display the stack\n");
        printf("Enter 4 for top element of stack\n");
        printf("Enter 5 for exit the stack operations\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &value);
            push(&S, value);
        }
        else if (choice == 2) {
            int delete = pop(&S);
            printf("Popped element is %d\n", delete);
        }
        else if (choice == 3) {
            display(&S);
        }
        else if (choice == 4) {
            if (empty(&S))
                printf("Stack is empty\n");
            else
                printf("Top element of stack is %d\n", peek(&S));
        }
        else if (choice == 5) {
            printf("Exited the loop\n");
            break;
        }
        else {
            printf("Invalid choice,try again.\n");
        }
    }

    return 0;
}

/*
PS D:\MCA Program\1st Sem\Data Structures using C\Problems(Coding)> gcc PES1PG25CA440_Yogesh_K_Stacks.c -o PES1PG25CA440_Yogesh_K_Stacks.exe

PS D:\MCA Program\1st Sem\Data Structures using C\Problems(Coding)> .\PES1PG25CA440_Yogesh_K_Stacks.exe
Enter 1 for push opeartion
Enter 2 for pop opeartion
Enter 3 for display the stack
Enter 4 for top element of stack
Enter 5 for exit the stack operations
Enter choice: 1
Enter value: 8
Enter 1 for push opeartion
Enter 2 for pop opeartion
Enter 3 for display the stack
Enter 4 for top element of stack
Enter 5 for exit the stack operations
Enter choice: 1
Enter value: 23
Enter 1 for push opeartion
Enter 2 for pop opeartion
Enter 3 for display the stack
Enter 4 for top element of stack
Enter 5 for exit the stack operations
Enter choice: 7
Invalid choice,try again.
Enter 1 for push opeartion
Enter 2 for pop opeartion
Enter 3 for display the stack
Enter 4 for top element of stack
Enter 5 for exit the stack operations
Enter choice: 1
Enter value: 12
Enter 1 for push opeartion
Enter 2 for pop opeartion
Enter 3 for display the stack
Enter 4 for top element of stack
Enter 5 for exit the stack operations
Enter choice: 3
Stack elements: 12 23 8 
Enter 1 for push opeartion
Enter 2 for pop opeartion
Enter 3 for display the stack
Enter 4 for top element of stack
Enter 5 for exit the stack operations
Enter choice: 2
Popped element is 12
Enter 1 for push opeartion
Enter 2 for pop opeartion
Enter 3 for display the stack
Enter 4 for top element of stack
Enter 5 for exit the stack operations
Enter choice: 4
Top element of stack is 23
Enter 1 for push opeartion
Enter 2 for pop opeartion
Enter 3 for display the stack
Enter 4 for top element of stack
Enter 5 for exit the stack operations
Enter choice: 5
Exited the loop
*/