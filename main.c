#include <stdio.h>
#include <stdlib.h>

// Nó para Lista Encadeada Simples (LES)
typedef struct No {
    int valor;
    struct No* proximo;
} No;

// Nó para Lista Duplamente Encadeada (LDE)
typedef struct NoDuplo {
    int valor;
    struct NoDuplo* proximo;
    struct NoDuplo* anterior;
    struct NoDuplo* proximo;
    struct NoDuplo* anterior;
} NoDuplo;

// Aloca memória e inicializa um nó simples
No* criar_no(int valor){
    No* novo_no = (No*)malloc(sizeof(No));

    if(novo_no){
        novo_no->valor = valor;
        novo_no->proximo = NULL;
    }

    return novo_no;
}

// Libera toda a memória da lista
void liberar_les(No** cabeca) {
    No* atual = *cabeca;

    while (atual) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    *cabeca = NULL;
}

// Remove um elemento específico buscando pelo valor
void remover_les(No** cabeca, int valor) {
    if (!*cabeca) return;

    No* temp = *cabeca;

    // O alvo é o primeiro nó da lista
    if (temp->valor == valor) {
        *cabeca = temp->proximo;
        free(temp);
        return;
    }

    No* anterior = NULL;

    // Passa pela lista até achar o valor ou chegar no NULL
    while (temp && temp->valor != valor) {
        anterior = temp;
        temp = temp->proximo;
    }

    if (!temp) return; // Não achou

    // O valor está no meio ou no fim
    anterior->proximo = temp->proximo;
    free(temp);
}

// Aloca memória e inicializa um nó duplo
NoDuplo* criar_noDuplo(int valor){
    NoDuplo* novo_no = (NoDuplo*)malloc(sizeof(NoDuplo));

    if(novo_no){
        novo_no->valor = valor;
        novo_no->proximo = NULL;
        novo_no->anterior = NULL;
    }

    return novo_no;
}

void listar_NoSimples(No* inicio){
    No* atual = inicio;
    while(atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}
void listar_NoDuplo(NoDuplo* inicio){
    NoDuplo* atual = inicio;
    while(atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

void apagar_Primeiro_NoSimples (No** cabeca) {
    No* tmp = *cabeca;
    *cabeca = (*cabeca)->proximo;
    free(tmp);
}
void apagar_Primeiro_NoDuplo (NoDuplo** cabeca) {
    NoDuplo* tmp = *cabeca;
    *cabeca = (*cabeca)->proximo;
    free(tmp);
}

void push_front_simples(No** cabeca, int valor){
    No* novo = criar_no(valor);

    //Verifica se o nó é null
    if (!novo) return;

    //Avisa que o novo cabeça da lista eh ele
    novo->proximo = *cabeca;
    *cabeca = novo;
}

void push_back_simples(No** cabeca, int valor){
    No* novo = criar_no(valor);
    //Verifica se o nó é null
    if (!novo) return;

    // Verifica se nao tem nenhum nó na lista
    if(*cabeca == NULL){
        *cabeca = novo;
        return;
    }

    // Procura o ultimo nó da lista
    No* aux = *cabeca;
    while(aux->proximo != NULL){
        aux = aux->proximo;
    }

    // Adiciona o novo nó no final da lista que foi encontrado
    aux->proximo = novo;
}

void push_front_duplo(NoDuplo** cabeca, int valor){
    NoDuplo* novo = criar_noDuplo(valor);
    if (!novo) return;

    novo->proximo = *cabeca;

    // Se a lista nao estiver vazia, ele liga pra trás tbm
    if(*cabeca != NULL){
        (*cabeca)->anterior = novo;
    }

    // Faz o ponteiro principal da lista apontar pro novo
    *cabeca = novo;
}

void push_back_duplo(NoDuplo** cabeca, int valor) {
    NoDuplo* novo = criar_noDuplo(valor);
    if (!novo) return;

    // Ve se a lista nao ta vazia
    if (*cabeca == NULL) {
        *cabeca = novo;
        return;
    }

    // Como no simples, ele procura o ultimo elemento
    NoDuplo* aux = *cabeca;
    while (aux->proximo != NULL) {
        aux = aux->proximo;
    }

    // Faz o encadeamento duplo do ultimo elemento com o novo
    aux->proximo = novo;
    novo->anterior = aux;
}

// Libera a memória da LDE
void liberar_lde(NoDuplo** cabeca) {
    NoDuplo* atual = *cabeca;

    while (atual) {
        NoDuplo* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    *cabeca = NULL;
}

// Remove elemento da lista dupla reconectando vizinhos
void remover_lde(NoDuplo** cabeca, int valor) {
    if (!*cabeca) return;

    NoDuplo* temp = *cabeca;

    // Busca o nó a ser removido
    while (temp && temp->valor != valor) {
        temp = temp->proximo;
    }

    if (!temp) return; // Não achou

    // O alvo é o primeiro, move a cabeça
    if (temp == *cabeca) {
        *cabeca = temp->proximo;
    }

    // Reconecta o nó anterior com o próximo (pula o temp)
    if (temp->proximo) {
        temp->proximo->anterior = temp->anterior;
    }
    
    // Reconecta o próximo com o anterior
    if (temp->anterior) {
        temp->anterior->proximo = temp->proximo;
    }

    free(temp);
}

void menuSimples(No** lista){
    int opcao = -1, valor, pos;

    while (opcao != -1){
        printf("\n=== MENU LISTA SIMPLESMENTE ENCADEADA ===\n");
        printf("1. Inserir em posição específica\n");
        printf("2. Inserir no final\n");
        printf("3. Remover de uma posição\n");
        printf("4. Buscar valor\n");
        printf("5. Listar\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                printf("Digite a posição (a partir de 1): ");
                scanf("%d", &pos);
                inserir_posicao(&lista, valor, pos);
                break;
            case 2:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                inserir_final(&lista, valor);
                printf("Nó inserido no final da lista.\n");
                break;
            case 3:
                printf("Digite a posição a ser removida: ");
                scanf("%d", &pos);
                remover_posicao(&lista, pos);
                break;
            case 4:
                printf("Digite o valor para busca: ");
                scanf("%d", &valor);
                pos = buscar_valor(lista, valor);
                if (pos != -1) {
                    printf("Resultado: Valor %d encontrado na POSIÇÃO %d.\n", valor, pos);
                } else {
                    printf("Resultado: Valor %d NÃO encontrado na lista.\n", valor);
                }
                break;
            case 5:
                listar(lista);
                break;
            case 0:
                liberar_lista(&lista);
                printf("Memória liberada. Encerrando programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }
    

}

void menuDuplamente(NoDuplo** lista){
    int opcao = -1, valor, pos;

    while(opcao != 0){
        printf("\n=== MENU LISTA DUPLAMENTE ENCADEADA ===\n");
        printf("1. Inserir em posição específica\n");
        printf("2. Inserir no final\n");
        printf("3. Remover de uma posição\n");
        printf("4. Buscar valor\n");
        printf("5. Listar\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                printf("Digite a posição (a partir de 1): ");
                scanf("%d", &pos);
                inserir_posicao(&lista, valor, pos);
                break;
            case 2:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                inserir_final(&lista, valor);
                printf("Nó inserido no final da lista.\n");
                break;
            case 3:
                printf("Digite a posição a ser removida: ");
                scanf("%d", &pos);
                remover_posicao(&lista, pos);
                break;
            case 4:
                printf("Digite o valor para busca: ");
                scanf("%d", &valor);
                pos = buscar_valor(lista, valor);
                if (pos != -1) {
                    printf("Resultado: Valor %d encontrado na POSIÇÃO %d.\n", valor, pos);
                } else {
                    printf("Resultado: Valor %d NÃO encontrado na lista.\n", valor);
                }
                break;
            case 5:
                listar(lista);
                break;
            case 0:
                liberar_lista(&lista);
                printf("Memória liberada. Encerrando programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }
}

int main() {
    No* simples = NULL;
    NoDuplo* duplo = NULL;

    int resp;
    printf("Deseja utilizar a lista simples(1) ou duplamente encadeada(2)?\nResposta: ");
    scanf("%d", &resp);

    if(resp == 1){
        menuSimples(simples);
    } else if(resp == 2){
       menuDuplamente(duplo);
    }

    return 0;
}