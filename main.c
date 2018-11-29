#include <stdio.h>
#include <stdlib.h>
#include "Arvore_bin.h"
int main(){
    int menu,q,r,valor;
    Arvore a;
    while(menu!=0){
    system("cls");
    printf("\t\t\t***Bem vindo ao programa de controle de avioes*** \n");
    printf("\nEscolha uma opcao\n\n");
    printf("\n1-Carregar o arquivo voo.txt");
    printf("\n2-Buscar aviao no arquivo");
    printf("\n3-Adicionar elemento");
    printf("\n4-Remover elemento");
    printf("\n5-Exibir todos os elementos");
    printf("\n0-Sair");
    scanf("%d",&menu);
    switch(menu){
        case 1:
            a=load(a);
            break;
        case 2:
            printf("Qual tempo disponivel de voo da aeronave que voce procura ?");
            scanf("%d",&q);
            r=busca(a,q);
            if(r>0) printf("\n Esse aviao se encontra no nosso registro! \n foi encontrado apos %d comparacoes",r);
            else printf("\n Desculpe, nao encontramos o aviao que procura...");
            break;
        case 3:
            printf("\n Qual o tempo disponivel de voo da aeronave que voce quer inserir? ");
            scanf("%d",&valor);
            insere(a,valor);
            break;
        case 4:
            printf("\n Qual tempo disponivel de voo da aeronave que voce quer retirar? ");
            scanf("%d",&valor);
            retira(a,valor);
            break;
        case 5:
            exibe(a);
            break;
        default:
            system("cls");
            printf("OPCAO INVALIDA!!!\n\n por favor digite novamente\n\n\n");
            break;

    }
    printf("\n\n\n\n");
    system("pause");
    }
}
