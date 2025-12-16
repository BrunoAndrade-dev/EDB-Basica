#include <stdio.h>
#include <stdlib.h>

typedef struct arvAVL {
    int valor ;
    struct arvAVL *esq , *dir ;
    int altura;
} ArvAVL ;

ArvAVL *novoNo(int x ){
    ArvAVL * novoNo = malloc(sizeof(ArvAVL));
    if(novoNo) {
        novoNo -> valor = x ;
        novoNo -> esq = NULL ;
        novoNo -> dir = NULL ;
        novoNo -> altura = 0 ;
    }
    return novoNo;
}

int maior (int a , int b){
    return (a>b)? a:b ;
}

int alturaNo(ArvAVL *arvAVL){
    if(arvAVL == NULL ){
        return -1 ;
    } else {
        return arvAVL -> altura;
    }
}

int FatorB (ArvAVL * arvAVL){
    if (arvAVL){
        return(alturaNo(arvAVL->esq) - alturaNo(arvAVL->dir));
    } else {
        return 0 ;
    }
}

ArvAVL* rotacaoESQ (ArvAVL*r ){
    ArvAVL * y , *f ;
    y = r -> dir ;
    f = y-> esq ;
    y->esq = r ;
    r->dir = f;
    r-> altura = maior(alturaNo(r->esq), alturaNo(r->dir)) + 1 ;
    y-> altura = maior(alturaNo(y->esq) , alturaNo(y->dir)) + 1 ;
    return y ;
}

ArvAVL *rotacaodir (ArvAVL*r) {
    ArvAVL * y , *f ;
    y = r -> esq ;
    f = y-> dir ;
    y->dir = r ;
    r->esq = f;
    r-> altura = maior(alturaNo(r->esq), alturaNo(r->dir)) + 1 ;
    y-> altura = maior(alturaNo(y->esq) , alturaNo(y->dir)) + 1 ;
    return y ;
}

ArvAVL *rotacaoDirEsq(ArvAVL *r) {
    r->dir = rotacaodir(r->dir);
    return rotacaoESQ(r);
}

ArvAVL *rotacaoEsqDir(ArvAVL *r) {
    r-> esq = rotacaoESQ(r->esq);
    return rotacaoESQ(r);
}

ArvAVL* balancear (ArvAVL *raiz) {
    int f = FatorB(raiz);
    if (f < -1 && FatorB(raiz->dir) <= 0) {
        raiz = rotacaoESQ(raiz);
    }
    else if (f > 1 && FatorB(raiz->esq) >= 0) {

        raiz = rotacaodir(raiz);
    }
    else if (f > 1 && FatorB(raiz->esq) < 0) {

        raiz = rotacaoEsqDir(raiz);
    }
    else if (f < -1 && FatorB(raiz->dir) > 0) {

        raiz = rotacaoDirEsq(raiz);
    }

    return raiz;
}

ArvAVL *inserir (ArvAVL * raiz , int v) {
    if (raiz==NULL ) {
        return novoNo(v) ;
    } else{
        if (v < raiz-> valor) {
            raiz->esq=inserir(raiz->esq , v) ;
        }else{
            if(v>raiz->valor) {
                raiz->dir=inserir(raiz->dir, v) ;
            }else {
                printf("Inserção não realizada...");
            }
        }
    }
    raiz -> altura=maior(alturaNo(raiz->esq) , alturaNo(raiz->dir)) + 1 ;
    raiz = balancear(raiz) ;
    return raiz;
}




ArvAVL *remover (ArvAVL *raiz , int chave) {
    if (raiz == NULL) {
        printf("Valor n encontrado...\n");
        return NULL;
    }
    if (chave < raiz->valor) {
        raiz->esq = remover(raiz->esq, chave);
    } else if (chave > raiz->valor) {
        raiz->dir = remover(raiz->dir, chave);
    }
    else {
        printf("Elemento encontrado...\n");
        if ((raiz->esq == NULL) || (raiz->dir == NULL)) {
            ArvAVL *aux = NULL;
            if (raiz->esq != NULL) {
                aux = raiz->esq;
            } else {
                aux = raiz->dir;
            }
            if (aux == NULL) {
                free(raiz);
                printf("Elemento Removido (Folha)...\n");
                return NULL;
            }
            else {
                *raiz = *aux;
                free(aux);
                printf("Elemento Removido (1 filho)...\n");
            }
        }
        else {
            ArvAVL *aux = raiz->esq;
            while (aux->dir != NULL) {
                aux = aux->dir;
            }
            raiz->valor = aux->valor;
            printf("Elemento Trocado e Removido recursivamente...\n");
            raiz->esq = remover(raiz->esq, aux->valor);
        }
    }
    if (raiz == NULL)
        return NULL;
    raiz->altura = 1 + maior(alturaNo(raiz->esq), alturaNo(raiz->dir)); // Corrigido ','
    raiz = balancear(raiz);

    return raiz;
}

void preOrdem(ArvAVL *raiz) {
    if (raiz != NULL) {
        printf("%d (h:%d) | ", raiz->valor, raiz->altura);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}


int main() {
    ArvAVL *myarvore = NULL;
    printf("--- Inserindo Elementos (10, 20, 30, 40, 50) ---\n");
    myarvore = inserir(myarvore, 10);
    myarvore = inserir(myarvore, 20);
    myarvore = inserir(myarvore, 30);
    myarvore = inserir(myarvore, 40);
    myarvore = inserir(myarvore, 50);

    printf("Percurso Pre-Ordem (Valor e Altura):\n");
    preOrdem(myarvore);

    printf("\n\nAltura final da arvore: %d\n", alturaNo(myarvore));
    printf("\n--- Removendo o no 10 ---\n");
    myarvore = remover(myarvore, 10);

    printf("Percurso Apos Remocao:\n");
    preOrdem(myarvore);
    printf("\nAltura final da arvore: %d\n", alturaNo(myarvore));


    return 0;
}

