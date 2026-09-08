#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef struct NoDuplo {
    int valor;
    struct NoDuplo* proximo;
    struct NoDuplo* anterior;
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

int main() {
    No* simples = NULL;
    NoDuplo* duplo = NULL;

    duplo = criar_noDuplo(1);
    duplo->proximo = criar_noDuplo(4);
    duplo->proximo->anterior = duplo;

    apagar_Primeiro_NoDuplo(&duplo);
    listar_NoDuplo(duplo);

    return 0;
}