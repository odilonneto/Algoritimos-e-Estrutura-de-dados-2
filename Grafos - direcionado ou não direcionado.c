#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Cell Cell;
typedef struct GrafoLA GrafoLA;

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

int** create_matriz(int n, int m)
{
    int i; 
    int **mat;
    mat = (int**) calloc(n, sizeof(int*));
    for (i = 0; i < n; i++)
        mat[i] = (int*) calloc(m, sizeof(int));
    return mat;
}

void direcionado(GrafoLA *g){
    int cont=0;
    int **mat=create_matriz(g->V, g->V);
    if(g!=NULL){
        for(int i=0; i<g->V; i++){
            Cell *aux=g->adj[i]->head;
            while(aux!=NULL){
                mat[i][aux->item]=1;
                aux=aux->next;
            }
        }
    }
    
    for(int i=0; i<g->V; i++){
        for(int j=0; j<g->V; j++){
            if(mat[i][j]==mat[j][i])
                cont++;
            else{
                cont=0;
                break;
            }
        }
    }
    if(cont==0)
        printf("direcionado");
    else
        printf("nao direcionado");
    free(mat);
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
    direcionado(grafo);
    return 0;
}
