#include <stdio.h>
#include <stdlib.h>
typedef strcut no {
    int info ;
    struct no *next ;
}Lista;
//Criando Lista
Lista* createList() {
    return NULL ;
}
//Verificando se a lista esta vazia
int isempty (Lista *list) {
    return list == NULL ;
}
//INSERINDO ELEMENTOS NA LISTA
Lista insere (Lista*list , int valor){
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    novo -> info = valor ;
    novo -> next = list;
    return  novo;
}

//Listando valores
void listar (Lista*list) {
    if (isempty){
        printf ("\n lista está vazia") ;
        return ;
    }
    Lista *aux = list ;
    while (aux != NULL) {
        printf ("%d ->" , aux -> info);
        aux = aux-> next;
    }
    printf ("\n NULL") ;
}

//Buscando valores dentro da lista
int buscar (Lista *list ,int v) {
    Lista *aux = list ;
    while (aux != NULL){
        if (aux->info == v) {
            return 1;
        }
        aux = aux->next
    }
    return 0 // Nao encontrado

}
//forma alternativa de implementar a função busca utilizando for
// Lista *busca (Lista*list , int v ){
    //Lista *aux ;
    //for (aux = list ; aux != NULL ; aux = aux -> next){
       // if (aux - >info == v) {
           // return aux ;
        //}
    //}
    //return  NULL ; se não for encontrado
//}

Lista *retirar (Lista *list , int v) {
    Lista ant = NULL ;
    Lista *p = list; //list aponta para o primeiro nó da lista
    while (p!=NULL && p->info != v){
        ant = p;
        p= p->next ;
    }
    if (p==NULL){
        return list;
    }
    if (ant == NULL){
        list = p->next;
        free(p) ;
    } else (ant -> next == p-> next) {
       ant ->next = p-> next;
    }

    free(p);
    return list;
}
//Liberar a lista
Lista liberar(Lista *list){
    Lista *p=list ;
    while (p!=NULL){
        list =p-> next ;
        free(p);
        p=list;
    }
}
//Main
int main(){
    Lista mylista = createList();
    mylista = insere(mylista , 10);
    mylista = insere(mylista , 3 );
    listar (mylista) ;
    return 0 ;
