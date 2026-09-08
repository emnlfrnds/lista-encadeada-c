#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef struct NoDuplo {
    int valor;
    struct No* proximo;
    struct No* anterior;
} NoDuplo;

No* criar_no(int valor){
    No* novo_no = (No*)malloc(sizeof(No));

    if(novo_no){
        novo_no->valor = valor;
        novo_no->proximo = NULL;
    }

    return novo_no;
}

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

int main() {
    No* simples = NULL;
    NoDuplo* duplo = NULL;

    return 0;
}