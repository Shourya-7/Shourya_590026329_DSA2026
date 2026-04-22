#include <stdio.h>

int main() {
    int n, adj[20][20], flag = 1;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    for (int i = 0; i < n && flag; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] != adj[j][i]) {
                flag = 0;
                break;
            }
        }
    }

    if (flag)
        printf("Graph is Undirected\n");
    else
        printf("Graph is Directed\n");

    return 0;
}
