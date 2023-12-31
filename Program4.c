#include<stdio.h>
int IMP(int a,int b);
int main() {
    printf("Program-4: Implication Truth Table.\n");
    int a,b;
    printf("A\tB\tA-->B\n");
    for(a=0; a<=1; a++){
        for(b=0; b<=1; b++) {
            printf("%d\t%d\t  %d\n",a,b,IMP(a,b));
        }
    }
    return 0;
}
int IMP(int a, int b){
    if(a==1 && b==0)
    return 0;
    else
    return 1;  
}