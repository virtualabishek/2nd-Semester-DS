#include <stdio.h>
#include <stdbool.h>

#define MAX 40

void Create(int set[], int);
int Union(int set1[], int, int set2[], int, int set3[]);
int Intersection(int set1[], int, int set2[], int, int set3[]);
int Difference(int set1[], int, int set2[], int, int set3[]);

int main() {
    printf("Program-6: SET Operation. \n");
    int set1[MAX], set2[MAX], set3[MAX], l, i;
    int N, M;

    printf("Enter the number of elements in SET 1 and SET 2: \n");
    scanf("%d%d", &N, &M);

    printf("------------------------------\n");
    printf("Enter elements of SET 1. \n");
    Create(set1, N);

    printf("Enter elements of SET 2. \n");
    Create(set2, M);

    printf("------------------------------");

    l = Union(set1, N, set2, M, set3);
    printf("\nUnion of SET: ");
    for (i = 0; i < l; i++) {
        printf("%d ", set3[i]);
    }

    l = Intersection(set1, N, set2, M, set3);
    printf("\nIntersection of SET: ");
    for (i = 0; i < l; i++) {
        printf("%d ", set3[i]);
    }

    l = Difference(set1, N, set2, M, set3);
    printf("\nDifference of SET: ");
    for (i = 0; i < l; i++) {
        printf("%d ", set3[i]);
    }

    printf("\nSet Operation Complete. ");
    return 0;
}

void Create(int set[], int size) {
    if (size > MAX) {
        printf("Error: Size exceeds the maximum allowed size (%d).\n", MAX);
        return;
    }

    printf("Enter elements: \n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &set[i]);
    }
}

int Union(int set1[], int n, int set2[], int m, int set3[]) {
    int i, j, k;
    i = j = k = 0;

    while (i < n && j < m) {
        if (set1[i] < set2[j]) {
            set3[k++] = set1[i++];
        } else if (set1[i] > set2[j]) {
            set3[k++] = set2[j++];
        } else {
            // Handle duplicates, add only one instance to the union
            set3[k++] = set1[i++];
            j++;
        }
    }

    // Add remaining elements of set1 (if any)
    while (i < n) {
        set3[k++] = set1[i++];
    }

    // Add remaining elements of set2 (if any)
    while (j < m) {
        set3[k++] = set2[j++];
    }

    return k;
}

int Intersection(int set1[], int n, int set2[], int m, int set3[]) {
    int i, j, k;
    i = j = k = 0;

    while (i < n && j < m) {
        if (set1[i] < set2[j]) {
            i++;
        } else if (set1[i] > set2[j]) {
            j++;
        } else {
            // Handle duplicates, add only one instance to the intersection
            set3[k++] = set1[i++];
            j++;
        }
    }

    return k;
}

int Difference(int set1[], int n, int set2[], int m, int set3[]) {
    int i, j, k;
    i = j = k = 0;

    while (i < n && j < m) {
        if (set1[i] < set2[j]) {
            set3[k++] = set1[i++];
        } else if (set1[i] > set2[j]) {
            j++;
        } else {
            // Handle duplicates, skip both instances
            i++;
            j++;
        }
    }

    // Add remaining elements of set1 (if any)
    while (i < n) {
        set3[k++] = set1[i++];
    }

    return k;
}
