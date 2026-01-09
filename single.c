#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}Node;

Node *create_node(int value){
    Node *newnode = (Node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->link = NULL;
    return newnode;
}

Node *ins_fr(Node *head,int value){
    Node *newnode = create_node(value);
    if (head == NULL){
        return newnode;
    }
    newnode->link = head;
    return newnode;
}

Node *ins_end(Node *head,int value){
    Node *newnode = create_node(value);
    if (head == NULL){
        return newnode;
    }
    Node *temp = head;
    while(temp->link != NULL){
        temp=temp->link;
    }
    temp->link = newnode;
    return temp;
}

void display(Node *head){
    Node *temp = head;
    printf("List :");
    while(temp != NULL){
        printf(" %d ",temp->data);
        temp=temp->link;
    }
}

int main(){
    Node *head = NULL;
    head = ins_fr(head,10);
    display(head);
    head = ins_end(head,20);
    display(head);
}