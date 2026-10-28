#include <stdio.h>
#include <string.h>

#define MAX 20

int n;                      /* number of nodes (files/directories) */
int adj[MAX][MAX];          /* adjacency matrix */
char name[MAX][30];         /* name of each node */

int find_index(char *s) {
    for (int i = 0; i < n; i++)
        if (strcmp(name[i], s) == 0) return i;
    return -1;
}

void bfs(int start, char *target) {
    int visited[MAX] = {0}, queue[MAX], front = 0, rear = 0, found = 0;
    printf("\nBFS traversal: ");
    queue[rear++] = start;
    visited[start] = 1;
    while (front < rear) {
        int u = queue[front++];
        printf("%s ", name[u]);
        if (strcmp(name[u], target) == 0) { found = 1; break; }
        for (int v = 0; v < n; v++)
            if (adj[u][v] && !visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
    }
    printf("\nBFS result: %s %s\n", target, found ? "FOUND" : "NOT FOUND");
}

int dfs_visit(int u, int visited[], char *target) {
    visited[u] = 1;
    printf("%s ", name[u]);
    if (strcmp(name[u], target) == 0) return 1;
    for (int v = 0; v < n; v++)
        if (adj[u][v] && !visited[v])
            if (dfs_visit(v, visited, target)) return 1;
    return 0;
}

void dfs(int start, char *target) {
    int visited[MAX] = {0};
    printf("\nDFS traversal: ");
    int found = dfs_visit(start, visited, target);
    printf("\nDFS result: %s %s\n", target, found ? "FOUND" : "NOT FOUND");
}

int main() {
    int e;
    char a[30], b[30], start[30], target[30];

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter names of nodes (no spaces):\n");
    for (int i = 0; i < n; i++) scanf("%s", name[i]);

    printf("Enter number of connections: ");
    scanf("%d", &e);
    printf("Enter each connection (parent child):\n");
    for (int i = 0; i < e; i++) {
        scanf("%s %s", a, b);
        int x = find_index(a), y = find_index(b);
        if (x == -1 || y == -1) { printf("Invalid node name!\n"); i--; continue; }
        adj[x][y] = adj[y][x] = 1;
    }

    printf("\nAdjacency Matrix:\n      ");
    for (int i = 0; i < n; i++) printf("%-5.4s ", name[i]);
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%-5.4s ", name[i]);
        for (int j = 0; j < n; j++) printf("%-5d ", adj[i][j]);
        printf("\n");
    }

    printf("\nEnter starting node: ");
    scanf("%s", start);
    printf("Enter file to search: ");
    scanf("%s", target);

    int s = find_index(start);
    if (s == -1) { printf("Starting node not found!\n"); return 1; }

    bfs(s, target);
    dfs(s, target);
    return 0;
}