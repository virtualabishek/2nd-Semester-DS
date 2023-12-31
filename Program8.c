#include<stdio.h>

int gcdExtended(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

int main() {
    printf("Program-8: Implementation of extended Euclidean algorithm.\n");
    int x, y, a, b;
    printf("Enter the values of a and b.\n");
    scanf("%d%d", &a, &b);
    int g = gcdExtended(a, b, &x, &y);
    printf("gcd(%d, %d) = %d, x = %d, y = %d\n", a, b, g, x, y);
    return 0;
}
