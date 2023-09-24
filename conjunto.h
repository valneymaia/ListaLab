#ifndef CONJUNTO_H_INCLUDED
#define CONJUNTO_H_INCLUDED

struct Elemento {
    int valor;
    struct Elemento *proximo;
};

typedef struct Elemento Elemento;

typedef struct {
    Elemento *inicio;
    int tamanho;
} Lista;

Lista criarLista();
void destruirLista(Lista *lista);
int inserirElemento(Lista *lista, int elemento);
int pertenceLista(const Lista *lista, int elemento);
Lista uniao(const Lista *c1, const Lista *c2);
Lista intersecao(const Lista *c1, const Lista *c2);
Lista diferenca(const Lista *c1, const Lista *c2);

#endif // CONJUNTO_H_INCLUDED
