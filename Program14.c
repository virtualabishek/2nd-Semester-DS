#include <stdio.h>
#include <stdlib.h>

int indirgraph();
int undirgraph();
int readgraph(int adjmat[50][50], int n);

int main() {
    int option;
    do {
        printf("Program-14: Represent a Graph using Adjacency Matrix Method");
        printf("\n1. Directed Graph ");
        printf("\n2. Un-Directed Graph ");
        printf("\n3. Exit ");
        printf("\nEnter proper option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                indirgraph();
                break;
            case 2:
                undirgraph();
                break;
            case 3:
                exit(0);
        }
    } while (1);
}

int indirgraph() {
    int adjmat[50][50];
    int n;
    int indeg, outdeg, i, j;
    printf("\nHow Many Vertices ? : ");
    scanf("%d", &n);
    readgraph(adjmat, n);
    printf("\nVertex\tIn Degree\tOut Degree\t Total Degree ");
    for (i = 1; i <= n; i++) {
        indeg = outdeg = 0;
        for (j = 1; j <= n; j++) {
            if (adjmat[i][j] == 1)
                indeg++;
            if (adjmat[j][i] == 1)
                outdeg++;
        }
        printf("\n\n%d\t\t%d\t\t%d\t\t%d\n", i, indeg, outdeg, indeg + outdeg);
    }
    return 0;
}

int undirgraph() {
    int adjmat[50][50];
    int n;
    int deg, i, j;
    printf("How Many Vertices ? :");
    scanf("%d", &n);
    readgraph(adjmat, n);
    printf("Vertex \t Degree");
    for (i = 1; i <= n; i++) {
        deg = 0;
        for (j = 1; j <= n; j++)
            if (adjmat[i][j] == 1)
                deg++;
        printf("\n%d \t %d\n", i, deg);
    }
    return 0;
}

int readgraph(int adjmat[50][50], int n) {
    int i, j;
    char reply;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j)
                adjmat[i][j] = 0;
            else {
                printf("\n Vertices %d & %d are Adjacent ? (Y/N) :", i, j);
                fflush(stdin);
                scanf(" %c", &reply);

                if (reply == 'y' || reply == 'Y')
                    adjmat[i][j] = 1;
                else
                    adjmat[i][j] = 0;
            }
        }
    }
    return 0;
}
