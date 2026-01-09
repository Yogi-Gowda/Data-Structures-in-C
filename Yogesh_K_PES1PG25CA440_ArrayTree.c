#include<stdio.h>
#include<stdlib.h>

#define MAX 50

void insert(int tree[],int *size,int value){
    tree[(*size)++] = value;
}

int parent(int index){
    return(index-1)/2;
}

int leftChild(int index){
    return 2*index+1;
}

int rightChild(int index){
    return 2*index+2;
}

void displayNodeRelation(int tree[],int size,int index){
    if(index < 0 || index >= size){
        printf("Invalid index");
        return;
    }
    printf("Node at index %d\n",index,tree[index]);

    if(index > 0)
        printf("Parent: %d\n",tree[parent(index)]);
    
    if(leftChild(index) < size)
        printf("Left child:%d\n",tree[leftChild(index)]);

    if(rightChild(index) < size)
        printf("Right child:%d\n",tree[rightChild(index)]);
}

void bfs(int tree[], int size){
    printf("\nBFS Traversal: ");
    for(int i = 0; i < size; i++)
        printf("%d ", tree[i]);
}

void dfs(int tree[], int size){
    int stack[MAX];
    int top = -1;

    printf("\nDFS Traversal (Non-Recursive Preorder): ");

    stack[++top] = 0;  

    while(top != -1){
        int index = stack[top--];
        printf("%d ", tree[index]);

        if(rightChild(index) < size)
            stack[++top] = rightChild(index);

        if(leftChild(index) < size)
            stack[++top] = leftChild(index);
    }
}

void display(int tree[],int size){
    if(size == 0){
        printf("Tree is empty");
        return;
    }
    printf("Binary Tree(Level Order)");
    for(int i=0;i<size;i++)
        printf("%d ",tree[i]);
}

int main(){
    int tree[MAX];
    int size = 0;

    int values[15] = {23,89,96,85,12,74,36,56,47,23,8,5,6,77,39};

    for(int i = 0; i < 15; i++)
        insert(tree, &size, values[i]);

    display(tree, size);
    bfs(tree, size);
    dfs(tree, size);
    displayNodeRelation(tree, size, 3);

    return 0;
}