#include <stdio.h>

int main() {
    int n, adj[20][20];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        int indeg = 0, outdeg = 0;

        for (int j = 0; j < n; j++) {
            outdeg += adj[i][j];
            indeg += adj[j][i];
        }

        printf("Vertex %d: In-degree = %d, Out-degree = %d\n", i, indeg, outdeg);
    }

    return 0;
}
