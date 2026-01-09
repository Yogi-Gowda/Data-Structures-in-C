#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char stack[MAX];
char infix[MAX], postfix[MAX];
int top = -1;

void push(char symbol){
    if(top == MAX - 1){
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = symbol;
}

char pop(){
    if(top == -1){
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}

int isempty(){
    return (top == -1);
}

int precedence(char symbol){
    switch(symbol){
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

void inToPost(){
    int i, j = 0;
    char symbol, next;

    for(i = 0; i < strlen(infix); i++){
        symbol = infix[i];

        switch(symbol){

            case '(':
                push(symbol);
                break;

            case ')':
                while((next = pop()) != '(')
                    postfix[j++] = next;
                break;

            case '+':
            case '-':
            case '*':
            case '/':
                while(!isempty() && precedence(stack[top]) >= precedence(symbol))
                    postfix[j++] = pop();
                push(symbol);
                break;

            default:
                postfix[j++] = symbol;
        }
    }

    while(!isempty())
        postfix[j++] = pop();

    postfix[j] = '\0';
}

int main() {
    printf("Enter the infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0';
    inToPost();
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
