# Listas Encadeadas em C

Implementação de **Lista Simplesmente Encadeada (LES)** e **Lista Duplamente Encadeada (LDE)** em C, com menu interativo no terminal para inserir, remover, buscar e listar elementos.

## Como compilar

```bash
gcc -Wall -Wextra -std=c11 -o listas listas_corrigido.c
```

## Como executar

```bash
./listas
```

O programa pergunta qual tipo de lista você quer usar:

```
Deseja utilizar a lista simples(1) ou duplamente encadeada(2)?
```

## Menu (igual para as duas listas)

| Opção | Ação |
|---|---|
| 1 | Inserir valor em uma posição específica (1 = início) |
| 2 | Inserir valor no final |
| 3 | Remover um valor (busca pelo valor, não pela posição) |
| 4 | Buscar um valor e mostrar sua posição |
| 5 | Listar todos os valores |
| 0 | Liberar memória e sair |

## Estrutura do código

**Structs**
- `No` — nó da lista simples (`valor` + `proximo`).
- `NoDuplo` — nó da lista dupla (`valor` + `proximo` + `anterior`).

**Criação**
- `criar_no`, `criar_noDuplo` — alocam e inicializam um nó.

**Inserção**
- `push_front_simples`, `push_front_duplo` — insere no início.
- `push_back_simples`, `push_back_duplo` — insere no final.
- `inserir_posicao_les`, `inserir_posicao_lde` — insere em posição arbitrária.

**Remoção**
- `remover_les`, `remover_lde` — remove pelo valor, reconectando os vizinhos.
- `apagar_Primeiro_NoSimples`, `apagar_Primeiro_NoDuplo` — remove o primeiro nó.

**Busca**
- `buscar_valor_les`, `buscar_valor_lde` — retorna a posição do valor (ou `-1`).

**Listagem e limpeza**
- `listar_NoSimples`, `listar_NoDuplo` — imprime a lista.
- `liberar_les`, `liberar_lde` — libera toda a memória (`free`) e zera a cabeça.

**Menus e `main`**
- `menuSimples`, `menuDuplamente` — loop de interação via terminal.
- `main` — escolhe qual tipo de lista usar.

## Observações

- A remoção (opção 3) busca pelo **valor**, não pelo índice.
- A inserção por posição (opção 1) usa numeração a partir de 1 na interface, convertida internamente para índice 0.
- Todo `malloc` é checado antes do uso; falha de alocação é tratada silenciosamente (a operação é ignorada).

## Colaboração

Este código contou com a ajuda de:

- [HenryKanemoto](https://github.com/HenryKanemoto)
- [enzocapitani (Enzo Capitani)](https://github.com/enzocapitani)
