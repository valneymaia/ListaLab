#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"

void menu();

int main() {
    Lista conjuntoA = criarLista();
    Lista conjuntoB = criarLista();
    char op;

    int tamanhoA, tamanhoB;

    printf("Digite o tamanho do conjunto A: ");
    scanf("%d", &tamanhoA);
    printf("Digite os elementos do conjunto A:\n");
    for (int i = 0; i < tamanhoA; i++) {
        int elemento;
        scanf("%d", &elemento);
        inserirElemento(&conjuntoA, elemento);
    }

    printf("Digite o tamanho do conjunto B: ");
    scanf("%d", &tamanhoB);
    printf("Digite os elementos do conjunto B:\n");
    for (int i = 0; i < tamanhoB; i++) {
        int elemento;
        scanf("%d", &elemento);
        inserirElemento(&conjuntoB, elemento);
    }

    for (;;) {
        menu();
        scanf(" %c", &op); // Usar um espaço em branco antes do %c para consumir a quebra de linha anterior

        switch (op) {
            case '1': {
                Lista uniaoResult = uniao(&conjuntoA, &conjuntoB);
                printf("Uniao: ");
                Elemento *atual = uniaoResult.inicio;
                while (atual != NULL) {
                    printf("%d ", atual->valor);
                    atual = atual->proximo;
                }
                destruirLista(&uniaoResult);
                break;
            }

            case '2': {
                Lista intersecaoResult = intersecao(&conjuntoA, &conjuntoB);
                printf("Intersecao: ");
                Elemento *atual = intersecaoResult.inicio;
                while (atual != NULL) {
                    printf("%d ", atual->valor);
                    atual = atual->proximo;
                }
                destruirLista(&intersecaoResult);
                break;
            }

            case '3': {
                Lista diferencaResult = diferenca(&conjuntoA, &conjuntoB);
                printf("Diferenca de A para B: ");
                Elemento *atual = diferencaResult.inicio;
                while (atual != NULL) {
                    printf("%d ", atual->valor);
                    atual = atual->proximo;
                }
                destruirLista(&diferencaResult);
                break;
            }

            default:
                printf("Opcao invalida!\n");
        }
        printf("\n");
    }

    destruirLista(&conjuntoA);
    destruirLista(&conjuntoB);

    return 0;
}

void menu() {
    printf("_______________________________________\n");
    printf("SELECIONE UMA OPCAO\n");
    printf("  1 - Uniao\n");
    printf("  2 - Intersecao\n");
    printf("  3 - Diferenca de A para B\n");
    printf("_______________________________________\nSua opcao: ");
}






/*Implemente um programa em C que l� elementos de 2 conjuntos de inteiros, grava esses elementos
em seus respectivos conjuntos e mostra para o usu�rio as seguintes op��es de opera��es sobre conjuntos:
1- uniao(c1, c2): imprime na tela um novo conjunto que � o resultado da uni�o dos conjuntos c1 e c2;
2- intersecao(c1,c2):  imprime na tela um novo conjunto que � o resultado da interse��o dos conjuntos c1 e c2;
3-diferenca(c1,c2): imprime na tela um novo conjunto que � o resultado da diferen�a de c1 para c2 (elementos em c1, que n�o s�o de c2);
Utilize listas para armazenar os conjuntos. Fa�a uma implementa��o otimizada para as opera��es pedidas nesta quest�o*/
