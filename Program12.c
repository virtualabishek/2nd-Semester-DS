#include<stdio.h>
int power(int a, int n){
    if(n==0)
    return 1;
    else
    return (a*power(a,n-1));
}
int main() {
    printf("Program-12: Recursive function to implement power(a,b).\n");
    int a,n,result;
    printf("Enter the value of a and n to calculate power.\n");
    scanf("%d%d",&a,&n);
    result = power(a,n);
    printf("Power(%d,%d) = %d \n",a,n,result);
    return 0;
}