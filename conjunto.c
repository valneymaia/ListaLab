#include <stdlib.h>
#include "conjunto.h"

Lista criarLista() {
    Lista lista;
    lista.inicio = NULL;
    lista.tamanho = 0;
    return lista;
}

void destruirLista(Lista *lista) {
    Elemento *atual = lista->inicio;
    while (atual != NULL) {
        Elemento *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    lista->inicio = NULL;
    lista->tamanho = 0;
}

int inserirElemento(Lista *lista, int elemento) {
    if (!pertenceLista(lista, elemento)) {
        Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
        if (novo == NULL) {
            return 0; // Falha na alocação de memória
        }
        novo->valor = elemento;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        lista->tamanho++;
        return 1;
    }
    return 0; // Elemento já pertence à lista
}

int pertenceLista(const Lista *lista, int elemento) {
    Elemento *atual = lista->inicio;
    while (atual != NULL) {
        if (atual->valor == elemento) {
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

Lista uniao(const Lista *c1, const Lista *c2) {
    Lista resultado = criarLista();
    Elemento *atual = c1->inicio;

    while (atual != NULL) {
        inserirElemento(&resultado, atual->valor);
        atual = atual->proximo;
    }

    atual = c2->inicio;
    while (atual != NULL) {
        inserirElemento(&resultado, atual->valor);
        atual = atual->proximo;
    }

    return resultado;
}

Lista intersecao(const Lista *c1, const Lista *c2) {
    Lista resultado = criarLista();
    Elemento *atual = c1->inicio;

    while (atual != NULL) {
        if (pertenceLista(c2, atual->valor)) {
            inserirElemento(&resultado, atual->valor);
        }
        atual = atual->proximo;
    }

    return resultado;
}

Lista diferenca(const Lista *c1, const Lista *c2) {
    Lista resultado = criarLista();
    Elemento *atual = c1->inicio;

    while (atual != NULL) {
        if (!pertenceLista(c2, atual->valor)) {
            inserirElemento(&resultado, atual->valor);
        }
        atual = atual->proximo;
    }

    return resultado;
}
