#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int info ;
    struct Arvbb *esq ;
    struct Arvbb * dir ;
}Arvbb ;

Arvbb *criarArvorebb () {
    return NULL ;
}

int estvazia (Arvbb * a ){
    return ( a== NULL );
}
Arvbb *inserir (Arvbb * a , int valor  ) {
   if (estvazia(a))  {
        Arvbb * novo = (Arvbb*) malloc(sizeof(Arvbb)) ;
        novo ->  info  = valor;
        novo -> esq = NULL ;
        novo -> dir = NULL ;
        return novo ;
   }else {
        if (valor < a -> info ){
            a -> esq = inserir(a-> esq , valor) ;
        }else{
            a-> dir = inserir (a-> dir , valor) ;
        }
        return a ;
   }
}
void pre_ordem(Arvbb *a) {
    if(estvazia(a)){
        printf("%d" , a->info) ;
        pre_ordem (a->esq) ;
        pre_ordem (a->dir) ;
    }
}

void in_ordem (Arvbb * a ){
    if (estvazia(a)) {
        in_ordem (a->esq) ;
        printf("%d" , a->info) ;
        in_ordem (a->dir) ;
    }
}
void pos_ordem (Arvbb * a){
   if (estvazia(a)) {
        pos_ordem (a->esq) ;
        pos_ordem (a->dir) ;
        printf("%d" , a->info) ;
   }
}
int main () {
    Arvbb * myarvbb = criarArvorebb();
    myarvbb = inserir (myarvbb , 5) ;
    myarvbb = inserir (myarvbb , 8 );
    myarvbb = inserir (myarvbb , 7) ;
    myarvbb = inserir (myarvbb , 2) ;
    myarvbb = inserir (myarvbb , 10) ;

    printf ("\n\n Pré-ordem: ");
    pre_ordem(myarvbb) ;
    printf("\n\n In-ordem : ") ;
    in_ordem (myarvbb) ;
    printf ("\n\nPos_ordem : ");
    pos_ordem(myarvbb) ;
    return 0 ;
}




