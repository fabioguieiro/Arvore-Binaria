#include <stdio.h>
#include <stdlib.h>
#include "Arvore_bin.h"

struct NO{
    int num;
    struct NO *esq;
    struct NO *dir;
};

Arvore* load (Arvore a){
    a=cria();
    FILE *arquivo;
    int n=0;
    int num[30],i=0,aux=0;
    char str[29];
    arquivo = fopen("voos.txt","r");
    if(arquivo==NULL){
        printf("ocorreu um erro ao abrir o arquivo...");
    }
    else {
        while( fscanf(arquivo,"%s %d",&str, &num[i])!= EOF ){
            printf("\n%s %d",&str, &num[i]);
                insere(a,num[i]);
        }
}
return a;
}


Arvore* cria(){
    Arvore* raiz = (Arvore*) malloc(sizeof(Arvore));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}
int retira(Arvore *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->num){
            if(atual == *raiz)
                *raiz = remove_atual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = remove_atual(atual);
                else
                    ant->esq = remove_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if(valor > atual->num)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

struct NO* remove_atual(struct NO* atual) {
    struct NO *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    // no2 é o nó anterior a r na ordem e-r-d
    // no1 é o pai de no2
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}



int insere(Arvore* raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    novo->num = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor > atual->num)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(valor > ant->num)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}

void exibe(Arvore *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        exibe(&((*raiz)->esq));
        exibe(&((*raiz)->dir));
        printf("%d\n",(*raiz)->num);
    }
}


int busca(Arvore *raiz, int valor){
    int cont=0;
    if(raiz == NULL)
        return 0;
    struct NO* atual = *raiz;
    while(atual != NULL){
            cont++;
        if(valor == atual->num){
            return cont;
        }
        if(valor > atual->num)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}
