#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info ;
    struct no *next ;
}Lista;

// Criando Lista
Lista* createList() {
    return NULL ;
}

// Verificando se a lista esta vazia
int isempty (Lista *list) {
    return list == NULL ;
}

// INSERINDO ELEMENTOS NO INÍCIO DA LISTA
Lista* insere (Lista*list , int valor){
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        exit(1);
    }
    novo -> info = valor ;
    novo -> next = list;
    return novo;
}

// Listando valores
void listar (Lista*list) {
    if (isempty(list)){
        printf ("\n lista esta vazia") ;
        return ;
    }
    Lista *aux = list ;
    while (aux != NULL) {
        printf ("%d -> " , aux -> info);
        aux = aux-> next;
    }
    printf ("NULL") ;
}

// Implementando a função LISTAR de forma recursiva
void listar2(Lista *list){
    if (list ==NULL){
        printf ("NULL");
        return ;
    }
    printf ("%d -> ", list-> info ) ;
    listar2 (list ->next);
}

// Contagem utilizando a recursividade
int contagem (Lista *list){
    if (list == NULL){
        return 0;
    }
    return 1 + contagem(list->next) ;
}

// Função Busca de forma recursiva
Lista*buscaR(Lista *list , int v){
    if (list ==NULL) {
        return NULL ; // Alterado para retornar NULL em caso de não encontrado
    }
    if (list ->info ==v){
        return list ;
    }
    // Retornar o resultado da chamada recursiva
    return buscaR(list->next, v) ;
}

Lista *retirar (Lista *list , int v) {
    Lista *ant = NULL ;
    Lista *p = list; //list aponta para o primeiro nó da lista
    while (p!=NULL && p->info != v){
        ant = p;
        p= p->next ;
    }
    if (p==NULL){
        return list; // Não encontrou o elemento
    }

    // O nó p é o nó a ser removido
    if (ant == NULL){
        // Remover o primeiro nó
        list = p->next;
    } else {
        // Remover nó do meio ou fim
        ant ->next = p-> next;
    }

    free(p);
    return list;
}

// Revertendo Lista de modo iterativo
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
    // O novo início é 'anterior'
    return anterior;
}

// Função remover nós duplicados (assume que a lista não está necessariamente ordenada)
Lista *removerNO (Lista *topo){
    if (topo == NULL) {
        return NULL;
    }

    Lista *atual = topo;

    // Percorre a lista com o ponteiro 'atual'
    while (atual != NULL) {
        Lista *corrente = atual;
        // Percorre o resto da lista com 'corrente' para verificar duplicatas
        while (corrente->next != NULL) {
            if (atual->info == corrente->next->info) {
                // Encontrou duplicata: o nó a ser removido é corrente->next
                Lista *guardarduplicada = corrente->next;
                corrente->next = guardarduplicada->next;
                free(guardarduplicada);
            } else {
                // Não é duplicata, avança o ponteiro corrente
                corrente = corrente->next;
            }
        }
        // Avança para o próximo nó para verificar novas duplicatas
        atual = atual->next;
    }
    return topo; // Retorna o topo da lista
}

// Função para Intercalar duas listas
// Cria uma nova lista com os elementos de l1 e l2 alternadamente.
Lista *intercalar (Lista *l1, Lista *l2) {
    Lista *l3 = createList(); // Nova lista resultado
    Lista *aux1 = l1;
    Lista *aux2 = l2;
    Lista *ultimo = NULL; // Ponteiro para o último nó da l3

    while (aux1 != NULL || aux2 != NULL) {
        // Se houver elemento em l1, insere-o na l3
        if (aux1 != NULL) {
            // Cria novo nó com o valor de aux1->info
            Lista *novo = (Lista*)malloc(sizeof(Lista));
            if (novo == NULL) {
                printf("Erro de alocacao de memoria!\n");
                // Em um cenário real, você faria uma limpeza ou tratamento de erro mais robusto.
                exit(1);
            }
            novo->info = aux1->info;
            novo->next = NULL;

            if (l3 == NULL) {
                l3 = novo; // Primeiro nó da nova lista
            } else {
                ultimo->next = novo; // Anexa ao final da nova lista
            }
            ultimo = novo; // Atualiza o último nó

            aux1 = aux1->next; // Avança l1
        }

        // Se houver elemento em l2, insere-o na l3
        if (aux2 != NULL) {
            // Cria novo nó com o valor de aux2->info
            Lista *novo = (Lista*)malloc(sizeof(Lista));
            if (novo == NULL) {
                printf("Erro de alocacao de memoria!\n");
                exit(1);
            }
            novo->info = aux2->info;
            novo->next = NULL;

            if (l3 == NULL) {
                l3 = novo; // Este caso deve ser raro se l1 não for nula, mas é seguro
            } else {
                ultimo->next = novo; // Anexa ao final da nova lista
            }
            ultimo = novo; // Atualiza o último nó

            aux2 = aux2->next; // Avança l2
        }
    }
    while(l1!=NULL && l2=! NULL){
        fim = l1 ->next ;
        l1 = l1->next ;
        fim = fim -> next ;
    }

    return l3;
}
 /*

 Outra forma de intercalar
 Lista *intercalar(Lista *l1 , Lista * l2){
    Lista inicio;
    Lista *fim = &incio ;
    inicio ->next = NULL ;
    while (l1!=NULL && l2 != NULL){
        fim->next = l1 ;
        l1 = l1->next ;
        fim = fim -> next ;
        fim ->next = l2 ;
        l2 = l2->next;
        fim = fim-> next ;
    }
    if (l1!= NULL ){
        fim->next = l1 ;
    }
    if (l2!= NULL) {
        fim->next = l2 ;
    }
    return inicio -> prox

 }


 */
 // Função verificar se duas listas estão iguais
 int isIgual (Lista *l1 , Lista *l2){
    while (l1!= NULL && l2!=NULL){
        if (l1->info != l2->info){
            return 0 ;
        }
    }
    l1 = l1-> next ;
    l2 = l2-> next ;
    if (l2 ==NULL && l1 == NULL) {
        return 1 ; // VERDADEIRO,OU SEJA, SÃO IGUAIS
    }
    else{
        return 0 ; // FALSE,OU SEJA, N SÃO IGUAIS
    }
 }
// Liberar a lista
Lista* liberar(Lista *list){
    Lista *p=list ;
    while (p!=NULL){
        list =p-> next ;
        free(p);
        p=list;
    }
    return NULL; // Retorna NULL para indicar que a lista está vazia
}

// Main
int main(){
    // Teste original (adaptado para os ajustes e correção de bugs na função 'removerNO' e 'buscaR')
    Lista *mylista = createList();
    mylista = insere(mylista , 10);
    mylista = insere(mylista , 20); // Valor adicionado para ter mais um elemento
    mylista = insere(mylista , 10);
    mylista = insere(mylista , 3) ;

    printf("Lista Inicial:\n");
    listar (mylista) ;

    printf("\nLista Iterativa:\n");
    listar(mylista) ;

    printf("\nLista Recursiva:\n");
    listar2(mylista);

    printf("\nContagem: %d nos.\n", contagem(mylista));

    printf ("\nRemovendo duplicatas....");
    mylista = removerNO(mylista); // A função original tinha um bug no retorno e no loop
    printf("\nA nova lista (sem duplicatas) é: ");
    listar2(mylista);

    if (buscaR(mylista, 3) != NULL) {
        printf("\nValor 3 encontrado.\n");
    } else {
         printf("\nValor 3 nao encontrado.\n");
    }

    // Testando a função de intercale
    Lista *listA = createList();
    listA = insere(listA, 5);
    listA = insere(listA, 3);
    listA = insere(listA, 1);

    Lista *listB = createList();
    listB = insere(listB, 6);
    listB = insere(listB, 4);
    listB = insere(listB, 2);
    listB = insere(listB, 0); // L2 é maior

    printf("\n\n--- Teste de Intercalacao ---\n");
    printf("Lista A: ");
    listar(listA);
    printf("\nLista B: ");
    listar(listB);

    Lista *listC = intercalar(listA, listB);
    printf("\nLista Intercalada (C): ");
    listar(listC);

    // Continuacao do teste original
    Lista *novacabeca = reverter(mylista) ;
    printf("\nLista invertida: ");
    listar(novacabeca); // Imprime a lista invertida
    mylista = novacabeca; // mylista agora é a lista invertida

    mylista = retirar(mylista, 3);
    printf("\n\nApós remover o 3:\n");
    listar(mylista);

    // Liberar todas as listas
    mylista = liberar(mylista);
    listA = liberar(listA);
    listB = liberar(listB);
    listC = liberar(listC);

    printf("\nTodas as listas liberadas.\n");

    return 0 ;
}
