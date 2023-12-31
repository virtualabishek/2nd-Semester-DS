#include<stdio.h>
int LinSearch(int a[], int l, int r, int key)
{
    if (r < l)
        return -1;
    if (a[l] == key)
        return l;
    if (a[r] == key)
        return r;
    return LinSearch(a, l+1, r-1, key);
}
int main()
{
    int n;
    printf("Program-13: Linear search algorithm using recursion.\n");
    int a[6];
    int key;
    printf("Enter the size of list: ");
    scanf("%d", &n);
    printf("Enter the elements of list:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
     printf("\nEnter the key to be searched:");
     scanf("%d", &key);
     int index = LinSearch(a, 0, n-1, key);
     if(index != -1)
         printf("Element %d is present at index %d", key, index);
     else
         printf("Element %d is not present", key);
     return 0;
}
