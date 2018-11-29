#ifndef ARVORE_BIN_H_INCLUDED
#define ARVORE_BIN_H_INCLUDED

typedef struct NO* Arvore;

Arvore* load (Arvore a);
Arvore* cria();
int insere(Arvore* raiz, int valor);
void exibe(Arvore *raiz);
int busca(Arvore *raiz, int valor);
int retira(Arvore *raiz, int valor);
struct NO* remove_atual(struct NO* atual);

#endif // ARVORE_BIN_H_INCLUDED
