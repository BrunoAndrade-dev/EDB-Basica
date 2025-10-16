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

//Função maior valor da lista

Lista*Maior_Valor (Lista *list ){
    Lista *Mvalor=NULL;
    if (isempty(list)){
        printf("\nNULL");
        return 0 ;
    }
    Lista *p;
    Mvalor = list;
    for (p=list->next ; p!=NULL; p=p->next){
        if (p->info >Mvalor-> info) {
            Mvalor = p;
        }
    }
    printf("\nOmaior valor da lista é ");
    return Mvalor ;
}

//  Função Recursiva de Maior valor
Lista *obterMaiorvaloR (Lista *list){
    if(list==NULL || list->next==NULL ){
        return list ;
    }
    Lista*maiorValor = obterMaiorvaloR(list->next);
    if(list->info >maiorValor->info){
        return list ;
    }else{
        return maiorValor;
    }

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
    listar (mylista) ;
    printf("Lista Iterativa:\n");
    listar(mylista) ;

    printf("\nLista Recursiva:\n");
    listar2(mylista);

    printf("\nContagem: %d ns.\n", contagem(mylista));

    if (buscaR(mylista, 3) != NULL) {
        printf("\nValor 3 encontrado.\n");
    }

    Maior_Valor(mylista);
    obterMaiorvaloR(mylista);
    mylista = retirar(mylista, 3);
    printf("\nAps remover o 3:\n");
    listar(mylista);


    mylista = liberar(mylista);

    return 0 ;
}

