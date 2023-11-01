#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int soma_max(int *v, int ini, int fim){
    int meio, v1, v2; 
    if(fim-ini==0)
        if(v[ini]>0)
            return v[ini];
        else
            return 0;
    else{
        meio=(ini+fim)/2;
        v1=soma_max(v, ini, meio);
        v2=soma_max(v, meio+1, fim);
        return v1+v2;
    }
}

int main (){
    int tam;
    scanf("%d", &tam);
    int *vet=(malloc(tam*sizeof(int)));

    for(int i=0; i<tam; i++)
        scanf("%d", &vet[i]);
    printf("%d", soma_max(vet, 0, tam-1));
    free(vet);
    return 0;
}
