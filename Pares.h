#ifndef PARES_H_INCLUDED
#define PARES_H_INCLUDED

struct pessoa{
    int senha;
    char nome[50];
};

typedef struct pessoa Pessoa;
typedef struct fila Fila;

Fila* criar();
void destruir(Fila *);
int tamanho(Fila*);
int cheia(Fila *);
int vazia(Fila *);
int inserir(Fila *, Pessoa); // Correção aqui
int remover(Fila *);
int acessar(Fila *, Pessoa *); // Correção aqui
int imprimeFila(Fila *);

#endif // PARES_H_INCLUDED

