//
//  main.c
//  (#9022) Tree distance
//

#include <stdio.h>
#include <stdlib.h>

int FindDistance(int* node, int A, int B){
    if(A>B){
        return 1+FindDistance(node, node[A], B);
    }
    if(B>A){
        return 1+FindDistance(node, A, node[B]);
    }
    if(A==B) return 0;
    return 0;
}
int main() {
    int j = 1,N;
    while(scanf("%d",&N)){
        int i,k;
        int *node = malloc((N+1)*sizeof(int));
        int *A = malloc((10000)*sizeof(int));
        int *B = malloc((10000)*sizeof(int));
        node[0] = 0;
        for(i = 1; i <= N; i++){
            scanf("%d", &node[i]);
        }
        k=0;
        do{
            scanf("%d %d", &A[k],&B[k]);
            k++;
        }while(A[k-1]!=0 || B[k-1]!=0);
        
        printf("Case %d:",j);
        for(i = 0; i < k-1; i++)printf(" %d",FindDistance(node,A[i],B[i]));
        printf("\n");
        j++;
        free(node);
        free(A);
        free(B);
    }
    return 0;
}
