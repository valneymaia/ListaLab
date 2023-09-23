#include <stdio.h>
#include <stdlib.h>
#include "binario.h"

int main(void)
{
    Pilha *pilha = NULL;

    int n, opcao;

        do {
        printf("\nMenu:\n");
        printf("1. Converter um numero decimal em binario\n");
        printf("2. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:

                printf("Digite um numero decimal: ");
                scanf("%d", &n);

                if (n < 0) {
                    printf("O numero decimal não pode ser negativo.\n");
                } else {
                    decimal_para_binario(&pilha, n);
                    printf("em binario: ");
                    imprimir(pilha);
                    limpar_pilha(&pilha);
                }

                break;

            case 2:
                printf("Saindo do programa.\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 2);

    return 0;
}








/* Faça um programa em C que recebe como entrada um número inteiro no sistema decimal
 e retorna ao usuário a representação desse número em binário. Para esse programa, utilize uma pilha
(estática ou dinâmica) como estrutura de dados para armazenar os 0s e 1s na conversão do número.*/
