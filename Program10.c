#include <stdio.h>

int main() {
    long int binary1, binary2, product = 0;
    int digit, factor = 1;
    printf("Program-10: Product of 2 binary Numbers.\n");
    printf("Enter the first and second binary numbers for product: \n");
    scanf("%ld%ld", &binary1, &binary2);

    while (binary2 != 0) {
        digit = binary2 % 10;

        if (digit == 1) {
            product += binary1 * factor;
        }

        binary2 /= 10;
        factor *= 10;
    }

    printf("The product of two binary numbers is %ld\n", product);

    return 0;
}
