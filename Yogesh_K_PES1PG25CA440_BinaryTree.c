#include <stdio.h>
#include <stdlib.h>

#define MAX 50

void insert_array(int tree[], int *size, int value) {
    tree[(*size)++] = value;
}

void display_array(int tree[], int size) {
    printf("\nArray Binary Tree (Level Order): ");
    for (int i = 0; i < size; i++)
        printf("%d ", tree[i]);
}

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

TreeNODE insert_List(TreeNODE root, int value) {
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

void display_List(TreeNODE root) {
    if (root != NULL) {
        display_List(root->left);
        printf("%d ", root->data);
        display_List(root->right);
    }
    return 0;
}

int main() {
    int arrTree[MAX];
    int size = 0;

    int values[] = {23,8,5,12,4,19,24,49,75,1,28,85,90,41,37};
    int n = sizeof(values)/sizeof(values[0]);

    for (int i = 0; i < n; i++)
        insert_array(arrTree, &size, values[i]);

    display_array(arrTree, size);

    TreeNODE root = NULL;

    for (int i = 0; i < n; i++)
        root = insert_List(root, values[i]);
    printf("\nLinked List Binary Tree(Inorder Traversal) :");
    display_List(root);

    return 0;
}
