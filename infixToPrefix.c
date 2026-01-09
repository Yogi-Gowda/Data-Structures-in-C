#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char stack[MAX];
char infix[MAX], prefix[MAX], temp[MAX];
int top = -1;

void push(char symbol){
    if(top == MAX-1){
        return;
    }
    stack[++top] = symbol;
}

char pop(){
    if(top == -1){
        return '\0';
    }
    return stack[top--];
}

int isempty(){
    return top == -1;
}

int precedence(char symbol){
    switch(symbol){
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default : return 0;
    }
}

void reverse(char *s){
    int i, j;
    char t;
    for(i = 0, j = strlen(s)-1; i < j; i++, j--){
        t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}

void inToPost(char exp[], char post[]){
    int i, j = 0;
    char symbol, next;

    top = -1; 

    for(i = 0; i < strlen(exp); i++){
        symbol = exp[i];

        switch(symbol){
            case '(':
                push(symbol);
                break;

            case ')':
                while((next = pop()) != '(')
                    post[j++] = next;
                break;

            case '+':
            case '-':
            case '*':
            case '/':
                while(!isempty() && precedence(stack[top]) >= precedence(symbol))
                    post[j++] = pop();
                push(symbol);
                break;

            default:
                post[j++] = symbol;
        }
    }

    while(!isempty())
        post[j++] = pop();

    post[j] = '\0';
}

void inToPre(){
    strcpy(temp, infix);
    reverse(temp);

    for(int i = 0; i < strlen(temp); i++){
        if(temp[i] == '(') temp[i] = ')';
        else if(temp[i] == ')') temp[i] = '(';
    }

    char post[MAX];
    inToPost(temp, post);

    reverse(post);
    strcpy(prefix, post);
}

int main(){
    printf("Enter infix expression : ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0';

    inToPre();

    printf("Prefix expression : %s\n", prefix);
}
