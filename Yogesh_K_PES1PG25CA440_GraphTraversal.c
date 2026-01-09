#include <stdio.h>

#define MAX 5

int graph[MAX][MAX] = {
    {0, 1, 1, 1, 0},
    {1, 0, 0, 1, 1},
    {1, 0, 0, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 1, 0, 1, 0}
};

void bfs(int startNode) {
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;

    visited[startNode] = 1;
    queue[rear++] = startNode;

    printf("BFS Traversal: ");

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < MAX; i++) {
            if (graph[node][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

void dfs(int startNode) {
    int visited[MAX] = {0};
    int stack[MAX];
    int top = -1;

    printf("\nDFS Traversal: ");

    stack[++top] = startNode;

    while (top != -1) {
        int node = stack[top--];

        if (!visited[node]) {
            printf("%d ", node);
            visited[node] = 1;
        }

        for (int i = MAX - 1; i >= 0; i--) {
            if (graph[node][i] == 1 && visited[i] == 0) {
                stack[++top] = i;
            }
        }
    }
}

int main() {
    int startNode = 0;
    bfs(startNode);
    dfs(startNode);
    return 0;
}
