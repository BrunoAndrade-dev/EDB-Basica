#include <stdio.h>
#include <stdlib.h>
typedef struct arvALV{
    int info ;
    struct arvAVL *esq ;
    struct arvAVL *dir;
    int fb;
}ArvAVL ;

int obtermax ( struct ArvAVL * no) {
    if (no == NUL) {
        return 0 ;
    return no->altura ;
    }
}

struct ArvAVL *novoNo (int valor) {
   struct ArvAVL* no = (struct ArvAVL*)malloc(sizeof(struct ArvAVL)) ;
   if (no == NULL ){
        perror ("\nErro de alocação de memória ");
        exit(EXIT_FAILURE) ;
   }
   no -> valor = valor ;
   no -> esq = NULL ;
   no -> dir = NULL ;
   no -> altura = 1 ;
   return no ;
}

int ObterFatorBalancemento (struct ArvAVL *no) {
   if (no == NULL ){
    return 0 ;
   }
   return obterAltura(no->esq) - (no->dir) ;
}

struct ArvAVL* rotacaoesquerda (struct ArvAVL *Z) {
    struct ArvAVL * Y = Z->dir ;
    struct ArvAVL * T2 = Y-> esq ;

    Y-> esq = Z;
    Z->dir = T2;
    Z-> altura = max(obterAltura(z-> esq) , obterAltura(Z->dir)) + 1 ;
    Y-> altura = max(obterAltura(Y-> esq) , obterAltura(Y->dir)) +1 ;

    return Y ;
}
