#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#define max(a,b) a>b ? a : b

int maior_preco(int *precos, int tam_haste){
    int i, j, q;
    int r[tam_haste+1];
    r[0]=0;
    
    for(i=1; i<=tam_haste; i++){
        q=INT_MIN;
        for(j=0; j<i; j++)
            q=max(q, precos[j]+r[i-j-1]);
        r[i]=q;
    }
    return r[tam_haste];
}

int main(){
    int tamHast, tamT;
    scanf("%d", &tamHast);
    scanf("%d", &tamT);
    int *vet=(int*)malloc(sizeof(int)*tamT);
    for(int i=0; i<tamT; i++)
        scanf("%d", &vet[i]);
    printf("%d", maior_preco(vet, tamHast));
    free(vet);
    return 0;
}
