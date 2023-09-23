#ifndef BINARIO_H_INCLUDED
#define BINARIO_H_INCLUDED

typedef struct pilha {
    int valor;
    struct pilha *proximo;
} Pilha;


Pilha * criar_pilha(int valor);
int inserir(Pilha **pilha, int valor);
void imprimir(Pilha *topo);
void decimal_para_binario(Pilha **pilha, int num);


#endif // BINARIO_H_INCLUDED
