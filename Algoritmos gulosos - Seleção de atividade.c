#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int id;
    int inicio;
    int fim;
}Atividades;

void ordenar(int tam, Atividades *v){
    Atividades aux;
    for(int i=0; i<tam-1; i++){
        for(int j=0; j<tam-1; j++){
            if(v[j].fim>v[j+1].fim){                            
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;          
            }
        }
    }
}

int descobrir_id(int tam, Atividades *v){
    int aux1, aux2=0;
    int start;
    int a=0;
    
    for(int j=0; j<tam; j++){
        start=v[j].fim;
        aux1=1;
        for(int i=0; i<tam; i++){
            if((v[i].inicio>=start)&&(i!=j)){
                start=v[i].fim;
                aux1++;
            }
        }
        if(aux1>aux2){
            a=j;
            aux2=aux1;
        }
    }
    return a;
}

void aulas(int tam, Atividades *v, int x){
    int aux1=1;
    int start=v[x].fim;
    int *vet=(malloc(sizeof(int)));
    vet[0]=v[x].id;
    
    for(int i=0; i<tam; i++){
        if((v[i].inicio>=start)&&(i!=x)){
            start=v[i].fim;
            vet[aux1]=v[i].id;
            aux1++;
        }
    }
    printf("Aulas alocadas:");
    for(int i=0; i<aux1; i++)
        printf(" %d", vet[i]);
    free(vet);
}

int main (){
    int qtd;
    scanf("%d", &qtd) ; 
    Atividades *vet=(malloc(qtd*sizeof(Atividades)));
    for(int i=0; i<qtd; i++)
        scanf("%d %d %d", &vet[i].id,  &vet[i].inicio,  &vet[i].fim);
    ordenar(qtd, vet);
    aulas(qtd, vet, descobrir_id(qtd, vet));
    free(vet);
    return 0;
}
