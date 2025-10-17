#include <stdio.h>
#include <stdlib.h>
typedef struct no {
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
Lista* insere (Lista*list , int valor){
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    novo -> info = valor ;
    novo -> next = list;
    return novo;
}

//Listando valores
void listar (Lista*list) {
    if (isempty(list)){
        printf ("\n lista est� vazia") ;
        return ;
    }
    Lista *aux = list ;
    while (aux != NULL) {
        printf ("%d ->" , aux -> info);
        aux = aux-> next;
    }
    printf ("\n NULL") ;
}

// implementando a funcção LISTAR de forma recursiva
void listar2(Lista *list){
    if (list ==NULL){
        printf ("\n Lista vazia");
        return ;
    }
    printf ("%d", list-> info ) ;
    listar2 (list ->next);
}

//int contagem_No(Lista *list) {
  //  Lista *p ;
    //int x =0 ;
    //for (p = l ; p!=NULL ; p=p ->next){
      //  x++ ;
    //}
    //return x ;
//}
//Contagem utilizando a recursividade
int contagem (Lista *list){
    if (list == NULL){
        printf("\n NULL ");
        return 0;
    }
    return 1 + contagem(list->next) ;
}

//Buscando valores dentro da lista
/*int buscar (Lista *list ,int v) {
    Lista *aux = list ;
    while (aux != NULL){
        if (aux->info == v) {
            return 1;
        }
        aux = aux->next;
    }
    return 0 ;// Nao encontrado

}
*/
//forma alternativa de implementar a fun��o busca utilizando for
 //Lista *busca (Lista*list , int v ){
   // Lista *aux ;
    //for (aux = list ; aux != NULL ; aux = aux -> next){
      //  if (aux - >info == v) {
            //return aux ;
       // }
    //}
   // return  NULL ; se n�o for encontrado
//}
//Função Busca de forma recursiva
Lista*buscaR(Lista *list , int v){
    if (list ==NULL) {
        printf("\nNULL");
        return 0 ;
    }
    if (list ->info ==v){
        return list ;
    }
    buscaR(list->next, v) ;
}
Lista *retirar (Lista *list , int v) {
    Lista *ant = NULL ;
    Lista *p = list; //list aponta para o primeiro n� da lista
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
    } else {
       ant ->next = p-> next;
    }

    free(p);
    return list;
}

//Revertendo Lista de modo iterativo
Lista*reverter(Lista*list){
    Lista*anterior = NULL;
    Lista*atual = list ;
    Lista*proximo=NULL ;
    while (atual!=NULL){
        proximo = atual->next ;
        atual->next = anterior ;
        anterior=atual ;
        atual = proximo;
    }
    printf("LISTA INVERTIDA : ");
    return anterior;
}
//Liberar a lista
Lista* liberar(Lista *list){
    Lista *p=list ;
    while (p!=NULL){
        list =p-> next ;
        free(p);
        p=list;
    }
}
//Main
int main(){
    Lista *mylista = createList();
    mylista = insere(mylista , 10);
    mylista = insere(mylista , 3 );
    mylista = insere(mylista , 8) ;
    listar (mylista) ;
    printf("Lista Iterativa:\n");
    listar(mylista) ;

    printf("\nLista Recursiva:\n");
    listar2(mylista);

    printf("\nContagem: %d ns.\n", contagem(mylista));

    if (buscaR(mylista, 3) != NULL) {
        printf("\nValor 3 encontrado.\n");
    }

    Lista *novacabeca = reverter(mylista) ;
    printf("Lista invertida") ;
    listar(novacabeca);
    mylista = retirar(mylista, 3);
    printf("\n Aps remover o 3:\n");
    listar(mylista);


    mylista = liberar(mylista);

    return 0 ;
}

