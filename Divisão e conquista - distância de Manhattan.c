#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>

int soma_manhattan(int *v1, int *v2, int ini, int fim){
    int meio, val1, val2; 
    if(fim-ini==0)
        return abs(v1[ini]-v2[ini]);
    else
    {
        meio=(ini+fim)/2;
        val1=soma_manhattan(v1, v2, ini, meio);
        val2=soma_manhattan(v1, v2, meio+1, fim);
        return val1+val2;
    }
}

int main (){
    int tam;
    scanf("%d", &tam);
    int *vet1=(malloc(tam*sizeof(int)));
    int *vet2=(malloc(tam*sizeof(int)));

    for(int i=0; i<tam; i++)
        scanf("%d", &vet1[i]);
    for(int i=0; i<tam; i++)
        scanf("%d", &vet2[i]);
    
    printf("%d", soma_manhattan(vet1, vet2, 0, tam-1));
    free(vet1);
    free(vet2);
    return 0;
}
