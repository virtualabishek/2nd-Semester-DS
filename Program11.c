#include <stdio.h>

// A function to convert a decimal number to binary
void decToBinary(int n)
{
    int binaryNum[32], i = 0;
    // Conversion process
    while (n > 0)
    {
        binaryNum[i++] = n % 2;
        n /= 2;
    }
    // Display the binary number in reverse order
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}

int main()
{
    long int binary1, binary2, quotient = 0, remainder = 0;
    int divisor, digit;
    printf("Program-11: Dividend of 2 binary Numbers.\n");

    printf("Enter the binary dividend: ");
    scanf("%ld", &binary1);

    printf("Enter the binary divisor: ");
    scanf("%d", &divisor);

    while (binary1 >= divisor)
    {
        digit = 0;

        while (binary1 >= (divisor << 1))
        {
            divisor <<= 1;
            digit++;
        }

        binary1 -= divisor;
        quotient = (quotient << 1) + digit;
        divisor = 1;
    }

    remainder = binary1;

    // Print the quotient and remainder in decimal
    printf("Quotient: %ld\n", quotient);
    printf("Remainder: %ld\n", remainder);

    // Print the quotient and remainder in binary
    printf("Quotient in binary: ");
    decToBinary(quotient);
    printf("\n");
    printf("Remainder in binary: ");
    decToBinary(remainder);
    printf("\n");

    return 0;
}
