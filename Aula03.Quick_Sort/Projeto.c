#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#define PATH "data/contatos.txt"
#include <locale.h>

typedef struct {
    char nome[50];
    char telefone[20];
    char email[50];
} Contato;

// ==== PROTÓTIPOS ====
void inicializarArquivo();
Contato criarContato();
void adicionarContato(Contato **lista, int *total);
void listarContatos(Contato *lista, int total);
void editarContato(Contato *lista, int total);
void excluirContato(Contato **lista, int *total);
void buscarNome(Contato *lista, int total);
void buscarTelefone(Contato *lista, int total);
void salvarTXT(Contato *lista, int total);
void importarTXT(Contato **lista, int *total);
void limparBuffer();
int menu();
void ordenarContatos(Contato *lista, int total);

// ===================== MAIN ===================== //
int main(){
    setlocale(LC_ALL, "Portuguese");
    Contato *lista = NULL;
    int total = 0;

    inicializarArquivo();
    importarTXT(&lista, &total);

    int opc;
    do {
        opc = menu();
        switch(opc){
            case 1: adicionarContato(&lista, &total); break;
            case 2: editarContato(lista, total); break;
            case 3: excluirContato(&lista, &total); break;
            case 4: buscarNome(lista, total); break;
            case 5: buscarTelefone(lista, total); break;
            case 6: listarContatos(lista, total); break;
            case 7: salvarTXT(lista, total); printf("\nArquivo TXT exportado!\n"); break;
            case 8: importarTXT(&lista, &total); printf("\nArquivo TXT importado!\n"); break;
            case 0: salvarTXT(lista,total); printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n");
        }
    }while(opc != 0);

    free(lista);
    return 0;
}

// ================= FUNÇÕES ================= //

void limparBuffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void inicializarArquivo(){
    if (_mkdir("data") == -1) { }
    FILE *arq = fopen(PATH,"a");
    if (arq) fclose(arq);
}

Contato criarContato(){
    Contato c;

    printf("Nome: ");
    fgets(c.nome, 50, stdin);
    c.nome[strcspn(c.nome, "\n")] = 0;

    do {
        printf("Telefone (somente números, até 12 dígitos): ");
        fgets(c.telefone, 20, stdin);
        c.telefone[strcspn(c.telefone, "\n")] = 0;

        int valido = 1;

        if (strlen(c.telefone) > 12) {
            printf("Erro: o telefone deve ter no máximo 12 dígitos!\n");
            valido = 0;
        }

        for (int i = 0; i < strlen(c.telefone); i++) {
            if (c.telefone[i] < '0' || c.telefone[i] > '9') {
                printf("Erro: o telefone deve conter somente números (0-9)!\n");
                valido = 0;
                break;
            }
        }

        if (!valido) {
            printf("Tente novamente.\n");
        }

    } while (
        strlen(c.telefone) == 0 ||
        strlen(c.telefone) > 12 ||
        strspn(c.telefone, "0123456789") != strlen(c.telefone)
    );

    printf("Email: ");
    fgets(c.email, 50, stdin);
    c.email[strcspn(c.email, "\n")] = 0;

    return c;
}


void adicionarContato(Contato **lista, int *total){
    *lista = realloc(*lista, (*total+1)*sizeof(Contato));
    if(*lista == NULL){
        printf("Erro ao alocar memoria.\n");
        return;
    }
    printf("\n=== Adicionar Contato ===\n");
    (*lista)[*total] = criarContato();
    (*total)++;
    salvarTXT(*lista,*total);
}

void ordenarContatos(Contato *lista, int total){
    for(int i=0;i<total-1;i++){
        for(int j=i+1;j<total;j++){
            if(strcmp(lista[i].nome, lista[j].nome) > 0){
                Contato temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    }
}

void listarContatos(Contato *lista, int total){
    printf("\n=== Lista de Contatos (Ordenados) ===\n");
    if(total == 0){
        printf("Nenhum contato cadastrado!\n");
        return;
    }

    ordenarContatos(lista,total);

    for(int i=0;i<total;i++){
        printf("[%d] %s - %s - %s\n", i, lista[i].nome, lista[i].telefone, lista[i].email);
    }
}

void editarContato(Contato *lista, int total){
    listarContatos(lista,total);
    int i;
    printf("\nDigite o índice do contato para editar: ");
    scanf("%d",&i); limparBuffer();
    if(i<0||i>=total) return;

    printf("Alterando %s\n",lista[i].nome);
    lista[i] = criarContato();
    salvarTXT(lista,total);
}

void excluirContato(Contato **lista, int *total){
    listarContatos(*lista,*total);
    int i;
    printf("\nDigite índice para remover: ");
    scanf("%d",&i); limparBuffer();
    if(i<0||i>=*total) return;

    for(int j=i;j<*total-1;j++){
        (*lista)[j] = (*lista)[j+1];
    }
    (*total)--;
    *lista = realloc(*lista, (*total)*sizeof(Contato));
    salvarTXT(*lista,*total);
}

void buscarNome(Contato *lista, int total){
    char nome[50];
    printf("Nome a buscar: "); fgets(nome,50,stdin); nome[strcspn(nome,"\n")]=0;
    for(int i=0;i<total;i++){
        if(strcasecmp(lista[i].nome,nome)==0){
            printf("\nEncontrado:\n%s - %s - %s\n",lista[i].nome,lista[i].telefone,lista[i].email);
            return;
        }
    }
    printf("Contato não encontrado!\n");
}

void buscarTelefone(Contato *lista, int total){
    char tel[20];
    printf("Telefone a buscar: "); fgets(tel,20,stdin); tel[strcspn(tel,"\n")]=0;
    for(int i=0;i<total;i++){
        if(strcmp(lista[i].telefone,tel)==0){
            printf("\nEncontrado:\n%s - %s - %s\n",lista[i].nome,lista[i].telefone,lista[i].email);
            return;
        }
    }
    printf("Contato não encontrado!\n");
}

void salvarTXT(Contato *lista, int total){
    FILE *arq = fopen(PATH,"w");
    if(arq == NULL) return;
    for(int i=0;i<total;i++)
        fprintf(arq,"%s;%s;%s\n",lista[i].nome,lista[i].telefone,lista[i].email);
    fclose(arq);
}

void importarTXT(Contato **lista, int *total){
    FILE *arq = fopen(PATH,"r");
    if(arq == NULL) return;

    char linha[200];
    *total = 0;
    *lista = NULL;

    while(fgets(linha,200,arq)){

        if (strlen(linha) <= 2) continue;

        char *nome = strtok(linha,";");
        char *tel = strtok(NULL,";");
        char *email = strtok(NULL,"\n");

        if (nome == NULL || tel == NULL || email == NULL)
            continue;

        *lista = realloc(*lista, (*total+1)*sizeof(Contato));
        if (*lista == NULL) {
            printf("Erro de memória!\n");
            fclose(arq);
            return;
        }

        strcpy((*lista)[*total].nome, nome);
        strcpy((*lista)[*total].telefone, tel);
        strcpy((*lista)[*total].email, email);

        (*total)++;
    }
    fclose(arq);
}


int menu(){
    int opc;
    printf("\n========= AGENDA =========\n");
    printf("1 - Adicionar contato\n");
    printf("2 - Editar contato\n");
    printf("3 - Excluir contato\n");
    printf("4 - Buscar por nome\n");
    printf("5 - Buscar por telefone\n");
    printf("6 - Listar contatos\n");
    printf("7 - Exportar TXT\n");
    printf("8 - Importar TXT\n");
    printf("0 - Sair\n");
    printf("Escolha: ");
    scanf("%d",&opc); limparBuffer();
    return opc;
}
