#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node Node;

struct Node{
    int item; 
    struct Node *left;
    struct Node *right;
};

Node* criar(int item){
    Node * tree = (Node *) malloc(sizeof(Node));
    tree->item = item;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

Node* inserir(int item, Node* tree){
    if (tree == NULL)
        tree = criar(item);
    else if (item < tree->item)
        tree->left = inserir(item, tree->left);
    else if (item > tree->item)
        tree->right = inserir(item, tree->right);
    return tree;
}

void liberar_arvore(Node* tree){
    if (tree != NULL){
        liberar_arvore(tree->left);
        liberar_arvore(tree->right);
        free(tree);
    }
}

int altura(Node *arvore){
    int dir, esq;
    if(arvore==NULL)
        return -1;
    if(arvore->left==NULL && arvore->right==NULL)
        return 0;
    else{
        dir=altura(arvore->right);
        esq=altura(arvore->left);
        return (dir>esq ? dir : esq)+1;
    }
}

int cont_no(Node *arvore){
    if(arvore==NULL)
        return 0;
    else 
        return 1+cont_no(arvore->left)+cont_no(arvore->right);
}

int node_faltantes(Node *arvore){
    int alt=altura(arvore);
    int x=(pow(2, alt+1))-1;
    return x-cont_no(arvore);
}

int main(){
    Node *tree=NULL;
    int tam, x;
    scanf("%d", &tam);
    for(int i=0; i<tam; i++){
        scanf("%d", &x);
        tree=inserir(x, tree);
    }
    printf("%d", node_faltantes(tree));
    liberar_arvore(tree);
    return 0;
}
