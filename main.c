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

int main() {
    No* simples = NULL;
    NoDuplo* duplo = NULL;

    return 0;
}