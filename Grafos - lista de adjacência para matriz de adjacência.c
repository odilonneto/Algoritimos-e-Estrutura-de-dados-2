#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Cell Cell;
typedef struct GrafoLA GrafoLA;
typedef struct GrafoMA GrafoMA;

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

struct GrafoMA{
   int V;
   int A;
   int **mat;
};

static int** iniciar_MA(int n){
    int i;
    int **mat = (int**) malloc(n * sizeof(int*));
    for (i = 0; i < n; i++)
        mat[i] = (int*) calloc(n, sizeof(int));
    return mat;
}

static int valida_vertice(GrafoMA* G, int v){
    return (v >= 0) && (v < G->V);
}

GrafoMA* iniciar_grafoMA(int v){
    GrafoMA* G = (GrafoMA*) malloc(sizeof(GrafoMA));
    G->V = v;
    G->A = 0;
    G->mat = iniciar_MA(G->V);
    return G;
}

int aresta_existe(GrafoMA* G, int v1, int v2){
    return (G != NULL) && valida_vertice(G, v1) && valida_vertice(G, v2) && (G->mat[v1][v2] != 0);
}


void inserir_arestaMA(GrafoMA* G, int v1, int v2){
    if (!aresta_existe(G, v1, v2)){
        G->mat[v1][v2] = 1;
        G->A++;
    }
}

void remover_arestaMA(GrafoMA* G, int v1, int v2){
    if (aresta_existe(G, v1, v2)){
        G->mat[v2][v1] = 0;
        G->A--;
    }
}

void imprimir_arestasMA(GrafoMA* G){
    int i, j;

    for (i = 1; i < G->V; i++)
        for (j = 0; j < i; j++)
            if (G->mat[i][j] == 1)
                printf("(%d, %d)\n", i, j);
}


void liberarGMA(GrafoMA* G){
    if (G != NULL){
        free(G->mat);
        free(G);
    }
}

void converter(GrafoLA *g, GrafoMA *gr){
    if(g!=NULL){
        for(int i=0; i<g->V; i++){
            Cell *aux=g->adj[i]->head;
            while(aux!=NULL){
                inserir_arestaMA(gr, i, aux->item);
                aux=aux->next;
            }
        }
    }
}

void imprimirGrafoMA(GrafoMA *g){
    for(int i=0; i<g->V; i++){
        for(int j=0; j<g->V; j++)
            printf("%d ", g->mat[i][j]);
        printf("\n");
    }
}

int main(){
    int n, x;
    scanf("%d", &n);
    GrafoLA *grafo=iniciar_grafoLA(n);
    GrafoMA *graf=iniciar_grafoMA(n);
    for(int i=0; i<n; i++){
        do{
            scanf("%d", &x);
            if(x!=1)
                inserir_arestaLA(grafo, i, x);
        }while(x!=1);
    }
    converter(grafo, graf);
    imprimirGrafoMA(graf);
    return 0;
}
