#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "binario.h"

Pilha* criar_no(int valor)
{
    Pilha *novo_no = malloc(sizeof(Pilha));
    novo_no->valor = valor;
    novo_no->proximo = NULL;

    return novo_no;
}

int inserir(Pilha **pilha, int valor)
{
    Pilha *no = criar_no(valor);
    if (no == NULL) {
        return 0;
    }
    no->proximo = *pilha;
    *pilha = no;
    return 1;
}


void imprimir(Pilha *topo)
{
    if (topo == NULL) {
        printf("Pilha vazia.\n");
        return;
    }

    Pilha *temp = topo;
    while (temp != NULL) {
        printf("%d", temp->valor);
        temp = temp->proximo;
    }
    printf("\n");
}


void limpar_pilha(Pilha **pilha) {
    while (*pilha != NULL) {
         Pilha *temp = *pilha;
        *pilha = (*pilha)->proximo;
        free(temp);
    }
}

void decimal_para_binario(Pilha **pilha, int n)
{
     if (n == 0) {
        inserir(pilha, 0);
        return;
    }
    int quociente, resto;

    while (n > 0) {
            quociente= n / 2;
            resto = n % 2;
            inserir(pilha, resto);
            n = quociente;
    }
}

