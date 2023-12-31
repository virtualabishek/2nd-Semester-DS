#include <stdio.h>

int i, j, k, a, b, u, v, n = 1;
int find(int);
int uni(int, int);
int min, mincost = 0, cost[9][9], parent[9], ne = 1;

int main() {
    printf("Program-16 Implementation of Kruskal's algorithm for spanning trees\n");
    printf("Enter no of vertices:");
    scanf("%d", &n);
    printf("Enter the cost of the adjacency matrix \n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    printf("The edges of the minimum spanning tree are: \n");
    while (ne < n) {
        for (i = 1, min = 999; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }  // end for
        }      // end for

        u = find(u);
        v = find(v);
        if (u != v) {
            printf("Edge %d: (%d,%d) = %d\n", ne++, a, b, min);
            mincost += min;
            uni(u, v);
        }
        cost[a][b] = cost[b][a] = 999;
    }  // end while
    printf("Minimal cost = %d\n", mincost);
    return 0;
}

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}
