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

void inserir_posicao_les(No** cabeca, int valor, int posicao) {
    if (posicao < 0) return;

    No* novo = criar_no(valor);
    if (!novo) return;

    // Caso inserção no início (índice 0)
    if (posicao == 0) {
        novo->proximo = *cabeca;
        *cabeca = novo;
        return;
    }

    No* atual = *cabeca;
    // Percorre até achar o nó anterior à posição desejada
    for (int i = 0; atual != NULL && i < posicao - 1; i++) {
        atual = atual->proximo;
    }

    // Posição inválida
    if (!atual) {
        free(novo);
        return;
    }

    novo->proximo = atual->proximo;
    atual->proximo = novo;
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

// Insere em uma posição específica na Lista Duplamente Encadeada

void inserir_posicao_lde(NoDuplo** cabeca, int valor, int posicao) {
    if (posicao < 0) return;

    NoDuplo* novo = criar_noDuplo(valor);
    if (!novo) return;

    // Caso inserção no início (índice 0)
    if (posicao == 0) {
        novo->proximo = *cabeca;
        if (*cabeca) {
            (*cabeca)->anterior = novo;
        }
        *cabeca = novo
        return;
    }

    NoDuplo* atual = *cabeca;
    // Percorre até achar o nó anterior à posição desejada
    for (int i = 0; atual != NULL && i < posicao - 1; i++) {
        atual = atual->proximo;
    }

    // Posição inválida
    if (!atual) {
        free(novo);
        return;
    }

    novo->proximo = atual->proximo;
    novo->anterior = atual;

    if (atual->proximo) {
        atual->proximo->anterior = novo;
    }
    atual->proximo = novo
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

int main() {
    No* simples = NULL;
    NoDuplo* duplo = NULL;

    // TODO: Testes de inserção e remoção podem ser feitos aqui

    return 0;
}
