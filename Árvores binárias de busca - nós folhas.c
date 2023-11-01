#include <stdio.h>
#include <stdlib.h>

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

void imprimir_folhas(Node *arvore){
    if(arvore!=NULL){
        imprimir_folhas(arvore->left);
        imprimir_folhas(arvore->right);
        if(arvore->left==NULL && arvore->right==NULL)
            printf(" %d", arvore->item);
    }
}

int main(){
    Node *tree=NULL;
    int tam, x;
    scanf("%d", &tam);
    for(int i=0; i<tam; i++){
        scanf("%d", &x);
        tree=inserir(x, tree);
    }
    imprimir_folhas(tree);
    liberar_arvore(tree);
    return 0;
}
