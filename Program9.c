#include <stdio.h>
#include <math.h>

long long addBinary(long long binary1, long long binary2);

int main() {
    long long binary1, binary2, sum;
    printf("Program-9: Addition of 2 binary Numbers.\n");

    printf("Enter the first and second binary number for add.: \n");
    scanf("%lld%lld", &binary1, &binary2);
    sum = addBinary(binary1, binary2);
    printf("Sum of binary numbers: %lld\n", sum);
    return 0;
}

long long addBinary(long long binary1, long long binary2) {
    int i = 0, carry = 0;
    long long sum = 0, digit1, digit2;

    while (binary1 != 0 || binary2 != 0) {
        digit1 = binary1 % 10;
        digit2 = binary2 % 10;

        sum += (digit1 + digit2 + carry) % 2 * (long long)pow(10, i);

        carry = (digit1 + digit2 + carry) / 2;

        binary1 /= 10;
        binary2 /= 10;
        i++;
    }

    if (carry != 0) {
        sum += carry * (long long)pow(10, i);
    }

    return sum;
}
