#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Cell Cell;
typedef struct GrafoLA GrafoLA;
typedef struct FilaE FilaE;

struct Cell{
    int item;
    Cell *next;
};

typedef struct{
    Cell *head;
}ListaE;

Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;
    c->next = NULL;
    return c;
}

ListaE* criar_listaE(){
    ListaE* l = (ListaE*) malloc(sizeof(ListaE));
    l->head = NULL;
    return l;
}

int listaE_vazia(ListaE *l){
    return (l == NULL) || (l->head == NULL);
}

void inserirLE(int key, ListaE *l){
    Cell *aux, *novo;
    if(l == NULL)
    {
        l = criar_listaE();
    }
    if(listaE_vazia(l))
    {
        aux = criar_celula(key);
        aux->next = l->head;
        l->head = aux;
    }
    else
    {
        aux = l->head;
        while(aux->next != NULL)
        {
            aux = aux->next;
        }
        novo=criar_celula(key);
        aux->next=novo;
    }
}

int removerListaE(int key, ListaE *l){
    Cell *auxA, *auxP;

    if (!listaE_vazia(l))
    {
        auxA = l->head;
        if(auxA->item == key)
            l->head = l->head->next;
        else
        {
            auxP = auxA;
            while((auxA != NULL) && (key < auxA->item))
            {
                auxP = auxA;
                auxA = auxA->next;
            }
            if (auxA->item == key)
                auxP->next = auxA->next;
            else
                auxA = NULL;
        }
        if (auxA != NULL)
            free(auxA);
        return 1;
    }
        return 0;
}

int procurar(int key, ListaE *l){
    Cell *aux;

    if (l != NULL){
        aux = l->head;

        while ((aux != NULL) && (key < aux->item))
            aux = aux->next;
    }

    if ((aux != NULL) && (key == aux->item))
        return 1;
    else
        return 0;
}

int liberar_listaE(ListaE *l){
    Cell *aux;
    if ((l != NULL) && !listaE_vazia(l))
    {
        while(l->head != NULL)
        {
            aux = l->head;
            l->head = aux->next;
            free(aux);
        }
        free(l);
        return 1;
    }
    return 0;
}

void imprimir(ListaE *l){
    Cell *aux;
    if(!listaE_vazia(l))
    {
        aux = l->head;
        while (aux != NULL){
            printf("%d ", aux->item);
            aux = aux->next;
        }
        printf("\n");
    }
}

struct GrafoLA{
   int V;
   int A;
   int *cor, *pai, *d, *f;
   ListaE **adj;
};

static ListaE** iniciar_LA(int n){
    int i;
    ListaE **adj = (ListaE**) malloc(n * sizeof(ListaE*));
    for (i = 0; i < n; i++)
        adj[i] = criar_listaE();
    return adj;
}

GrafoLA* iniciar_grafoLA(int v){
    GrafoLA* G = (GrafoLA*) malloc(sizeof(GrafoLA));
    G->pai = (int*) malloc(sizeof(int) * v);
    G->cor = (int*) malloc(sizeof(int) * v);
    G->d = (int*) malloc(sizeof(int) * v);
    G->f = (int*) malloc(sizeof(int) * v);
    G->V = v;
    G->A = 0;
    G->adj = iniciar_LA(G->V);
    return G;
}

int aresta_existeLA(GrafoLA* G, int v1, int v2){
    if ((G!= NULL) && (G->adj[v1]->head != NULL))
        return procurar(v2, G->adj[v1]);
    return 0;
}

void inserir_arestaLA(GrafoLA* G, int v1, int v2){
    if (!aresta_existeLA(G, v1, v2)){
        inserirLE(v2, G->adj[v1]);
        G->A++;
    }
}

void remover_arestaLA(GrafoLA* G, int v1, int v2){
    if (aresta_existeLA(G, v1, v2)){
        removerListaE(v2, G->adj[v1]);
        G->A--;
    }
}

void imprimir_arestasLA(GrafoLA* G){
    int i;
    Cell *aux;
    if (G != NULL)
        for (i = 0; i < G->V; i++)
        {
            aux = G->adj[i]->head;
            while (aux != NULL)
            {
                printf("(%d, %d)\n", i, aux->item);
                aux = aux->next;
            }
        }
}

void liberarGLA(GrafoLA* G){
    int i;
    if (G != NULL)
    {
        for (i = 0; i < G->V; i++)
            liberar_listaE(G->adj[i]);
        free(G);
    }
}

struct FilaE{
    Cell *inicio;
    Cell *fim;
};

FilaE* criar_filaE(){
    FilaE *f = (FilaE*) malloc(sizeof(FilaE));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

int filaE_vazia(FilaE* f){
    return (f == NULL) || (f->inicio == NULL);
}

void enfileirar(int key, FilaE* f){
    Cell *aux; 
    if (f == NULL)
        f = criar_filaE();
    aux = criar_celula(key);
    if (f->inicio == NULL)
        f->inicio = f->fim = aux;
    else{
        f->fim->next = aux;
        f->fim = f->fim->next;
    }

}

int desenfileirar(FilaE* f){
    Cell *aux;
    int item = INT_MIN;

    if (!filaE_vazia(f)){
        aux = f->inicio;
        f->inicio = aux->next;
        item = aux->item;
        free(aux);
    }

    return item;
}


void imprimir_fila(FilaE* f){
    Cell *aux; 
    if (!filaE_vazia(f)){
        aux = f->inicio;

        while (aux != NULL){
            printf("%d\n", aux->item);
            aux = aux->next;
        }
    }
}

int liberar_filaE(FilaE* f){
    if (!filaE_vazia(f)){
        while (f->inicio != NULL)
            desenfileirar(f);

        free(f);

        return 1;
    }

    return 0;
}

static int valida_vertice(GrafoLA* G, int v){
    return (v >= 0) && (v < G->V);
}

void visitar_vertice(GrafoLA *G, int u, int *tempo){
    G->cor[u]=1;
    *tempo=*tempo+1;
    G->d[u]=*tempo;
    Cell *aux=G->adj[u]->head;
    while(aux!=NULL){
        if(G->cor[aux->item]==0){
            G->pai[aux->item]=u;
            visitar_vertice(G, aux->item, tempo);
        }
        aux=aux->next;
    }
    G->cor[u]=2;
    *tempo=*tempo+1;
    G->f[u]=*tempo;
}

void busca_profundidade(GrafoLA *G){
    int u, v, tempo=0;
    
    for(u=0; u<G->V; u++){
        G->pai[u]=-1;
        G->cor[u]=0;
    }
    
    for(u=0; u<G->V; u++){
        if(G->cor[u]==0)
            visitar_vertice(G, u, &tempo);
    }
        
    printf("v d f p\n");
    for(v=0; v<G->V; v++){
        printf("%d %d %d ", v, G->d[v], G->f[v]);
        if(G->pai[v]>=0)
             printf("%d\n", G->pai[v]);
        else
            printf("-\n");
    }
}

int main(){
    int n, x;
    scanf("%d", &n);
    GrafoLA *grafo=iniciar_grafoLA(n);
    for(int i=0; i<n; i++){
        do{
            scanf("%d", &x);
            if(x!=-1)
                inserir_arestaLA(grafo, i, x);
        }while(x!=-1);
    }
    scanf("%d", &x);
    busca_profundidade(grafo);
    return 0;
}
