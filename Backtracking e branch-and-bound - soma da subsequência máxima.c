#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int soma_max(int *v, int tam){
    int somaMax=INT_MIN;
    int soma=INT_MIN;
    
    for(int i=0; i<tam; i++){
        if(soma>0)
            soma=soma+v[i];
        else
            soma=v[i];
        if(soma>somaMax)
            somaMax=soma;
    }
    return somaMax;
}

int main (){
    int tam;
    scanf("%d", &tam);
    int *vet=(malloc(tam*sizeof(int)));
    
    for(int i=0; i<tam; i++)
        scanf("%d", &vet[i]);
    printf("%d", soma_max(vet, tam));
    free(vet);
    return 0;
}
