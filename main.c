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