#include <stdio.h>
#include <stdlib.h>
#include "Pares.h"

int gerarSenhaAleatoria();

int main() {
    Fila *fila_pares = criar();
    Fila *fila_impares = criar();


    if (fila_pares == NULL || fila_impares == NULL) {
        printf("Erro ao criar a fila.\n");
        return 1;
    }

    int total_pessoas;
    char nome[50];

    printf("Quantas pessoas chegaram ao evento: ");
    scanf("%d", &total_pessoas);

    for (int i = 0; i < total_pessoas; i++) {
        printf("Informe o nome da pessoa: ");
        scanf("%s", nome);

        // Gera uma senha aleatória entre 1 e 100
        int senhaAleatoria = gerarSenhaAleatoria(1, 100);

        Pessoa pessoa;
        pessoa.senha = senhaAleatoria;
        strcpy(pessoa.nome, nome);

        if (senhaAleatoria % 2 == 0) {
            inserir(fila_pares, pessoa);
            printf("Senha gerada para %s: %d\n", pessoa.nome, pessoa.senha);
        } else {
            inserir(fila_impares, pessoa);
            printf("Senha gerada para %s: %d\n", pessoa.nome, pessoa.senha);
        }
    }
    printf("\nPares formados para a dinâmica:\n");

    while (!vazia(fila_pares) && !vazia(fila_impares)) {
        Pessoa pessoa_par, pessoa_impar;
        if (acessar(fila_pares, &pessoa_par) && acessar(fila_impares, &pessoa_impar)) {
            remover(fila_pares);
            remover(fila_impares);
            printf("%s (Senha: %d) | %s (Senha: %d)\n", pessoa_par.nome, pessoa_par.senha, pessoa_impar.nome, pessoa_impar.senha);
        }
    }

    if (!vazia(fila_pares)) {
        printf("\nPessoas com senhas pares aguardando na fila:\n");
        while (!vazia(fila_pares)) {
            Pessoa pessoa;
            if (acessar(fila_pares, &pessoa)) {
                remover(fila_pares);
                printf("%s (Senha: %d)\n", pessoa.nome, pessoa.senha);
            }
        }
    }

    if (!vazia(fila_impares)) {
        printf("\nPessoas com senhas impares aguardando na fila:\n");
        while (!vazia(fila_impares)) {
            Pessoa pessoa;
            if (acessar(fila_impares, &pessoa)) {
                remover(fila_impares);
                printf("%s (Senha: %d)\n", pessoa.nome, pessoa.senha);
            }
        }
    }
    destruir(fila_pares);
    destruir(fila_impares);

    return 0;
}

int gerarSenhaAleatoria(int min, int max) {
    srand(time(NULL));
    int senha = (rand() % (max - min + 1)) + min;

    return senha;
}

