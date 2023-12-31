#include<stdio.h>
int AND(int p, int q) {
    if(p==1 && q==1)
    return 1;
    else
    return 0;
}
int OR(int p, int q) {
    if(p==1 || q==1)
    return 1;
    else
    return 0;
}
int IMP(int p, int q){
    if(p==1 && q==0)
    return 0;
    else
    return 1;
}
int main() {
    printf("Program-5: Tautology Operation.\n");
    int p,q,r;
    printf("P\tQ\tR\t(P->Q)^(Q->R)->(P->R)\n");
    for(p=0; p<=1; p++) {
        for(q=0; q<=1; q++) {
            for(r=0; r<=1; r++){
                printf("%d\t%d\t%d\t\t%d\n", p, q, r, IMP(AND(IMP(p, q), IMP(q, r)), IMP(p, r)));
            }
        }
    }
    return 0;
}