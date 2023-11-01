#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

typedef struct{
    int id;
    int e;
    int d;
}Atividade;

void seq_ativ(Atividade *v, int tam){
    int *vet=(malloc(tam*sizeof(int)));
    int soma=0; 
    
    for(int i=0; i<tam; i++){
        vet[i]=v[i].d-v[i].e;
        soma+=v[i].d-v[i].e; 
    }
    
    for(int i=0; i<tam; i++){
        for (int j=i; j<tam; j++){
            if (vet[i] < vet[j]){
                int aux=vet[i];
                vet[i]=vet[j];
                vet[j]=aux;
            }
        }
    }
        
    for(int i=0; i<tam; i++){
        for(int j=0; j<tam; j++){
            if((vet[i]==v[j].d-v[j].e)){
                printf("%d ", v[j].id);
                v[j].d=INT_MAX;
            }
        }
    }
    
    if(soma>=0)
        printf("\n0");
    else if(soma<0)
        printf("\n%d", soma*(-1));
    free(vet);
}

int main (){
    int tarefas;
    scanf("%d", &tarefas);
    Atividade *vet=(malloc(tarefas*sizeof(Atividade)));
   
    for(int i=0; i<tarefas; i++){
        scanf("%d %d", &vet[i].e, &vet[i].d);
        vet[i].id=i;
    }
    seq_ativ(vet, tarefas);
    free(vet);
}
