#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void troco(int *vet, int valor, int n, int x){
    int trocoN=valor, y;

    y=valor/vet[x];
    if(trocoN>0){
        for(int i=0; i<y; i++)
            printf("%d\n", vet[x]);
        trocoN=valor%vet[x];
        troco(vet, trocoN, n, x+1);
    }
}
    

int main (){
    int valor;
    int moedas;
    scanf("%d", &valor);
    scanf("%d", &moedas);
    int *vet=(malloc(moedas*sizeof(int)));
    
    for(int i=0; i<moedas; i++)
        scanf("%d", &vet[i]);
    troco(vet, valor, moedas, 0);
    return 0;
}
