#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} *TreeNODE;

TreeNODE createNode(int value) {
    TreeNODE newNode = (TreeNODE)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNODE insert(TreeNODE root, int value) {
    TreeNODE newNode = createNode(value);

    if (root == NULL)
        return newNode;

    TreeNODE queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        TreeNODE temp = queue[front++];

        if (temp->left == NULL) {
            temp->left = newNode;
            return root;
        } else
            queue[rear++] = temp->left;

        if (temp->right == NULL) {
            temp->right = newNode;
            return root;
        } else
            queue[rear++] = temp->right;
    }
    return root;
}

void displayTree(TreeNODE root) {
    if (root != NULL) {
        displayTree(root->left);
        printf("%d ", root->data);
        displayTree(root->right);
    }
}

void displayNodeRelation(TreeNODE root) {
    if (root == NULL)
        return;

    printf("Node %d : ", root->data);

    if (root->left)
        printf("Left = %d ", root->left->data);
    else
        printf("Left = NULL ");

    if (root->right)
        printf("Right = %d\n", root->right->data);
    else
        printf("Right = NULL\n");

    displayNodeRelation(root->left);
    displayNodeRelation(root->right);
}

void displayParent(TreeNODE root, int key, TreeNODE parent) {
    if (root == NULL)
        return;

    if (root->data == key) {
        if (parent == NULL)
            printf("Node %d is ROOT (no parent)\n", key);
        else
            printf("Parent of %d is %d\n", key, parent->data);
        return;
    }

    displayParent(root->left, key, root);
    displayParent(root->right, key, root);
}

void displayLeftChild(TreeNODE root, int key) {
    if (root == NULL)
        return;

    if (root->data == key) {
        if (root->left)
            printf("Left child of %d is %d\n", key, root->left->data);
        else
            printf("Left child of %d is NULL\n", key);
        return;
    }

    displayLeftChild(root->left, key);
    displayLeftChild(root->right, key);
}

void displayRightChild(TreeNODE root, int key) {
    if (root == NULL)
        return;

    if (root->data == key) {
        if (root->right)
            printf("Right child of %d is %d\n", key, root->right->data);
        else
            printf("Right child of %d is NULL\n", key);
        return;
    }

    displayRightChild(root->left, key);
    displayRightChild(root->right, key);
}

void bfs(TreeNODE root) {
    TreeNODE queue[MAX];
    int front = 0, rear = 0;

    printf("BFS Traversal: ");
    queue[rear++] = root;

    while (front < rear) {
        TreeNODE temp = queue[front++];
        printf("%d ", temp->data);

        if (temp->left)
            queue[rear++] = temp->left;
        if (temp->right)
            queue[rear++] = temp->right;
    }
}

void dfs(TreeNODE root) {
    TreeNODE stack[MAX];
    int top = -1;

    printf("\nDFS Traversal (Non-Recursive Preorder): ");
    stack[++top] = root;

    while (top != -1) {
        TreeNODE temp = stack[top--];
        printf("%d ", temp->data);

        if (temp->right)
            stack[++top] = temp->right;
        if (temp->left)
            stack[++top] = temp->left;
    }
}

int main() {
    TreeNODE root = NULL;
    int values[15] = {23,89,96,85,12,74,36,56,47,23,8,5,6,77,39};
    int n = sizeof(values)/sizeof(values[0]);
    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);

    printf("DISPLAY TREE (Inorder DFS): ");
    displayTree(root);

    printf("\n\nNODE RELATIONSHIPS:\n");
    displayNodeRelation(root);

    printf("\nPARENT / CHILD INFO:\n");
    displayParent(root, 89, NULL);
    displayLeftChild(root, 13);
    displayRightChild(root, 56);

    printf("\n");
    bfs(root);
    dfs(root);

    return 0;
}


