#include<stdio.h>
int gcd(int a, int b);
int main() {
    printf("Program-7: Implement of Euclidian algorithms. \n");
    int a,b,g;
    printf("Enter first and second number. \n");
    scanf("%d%d",&a,&b);
    g = gcd (a,b);
    printf("The gcd of %d and %d = %d.\n",a,b,g);
    return 0;
}
int gcd(int a, int b){
    if(a==0)
    return b;
    else
    return gcd(b%a,a);
}