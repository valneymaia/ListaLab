#include <stdio.h>
#include <stdlib.h>
#include "Pares.h"

struct elemento{
    Pessoa dados; // Correção aqui
    struct elemento *proximo;
};

typedef struct elemento Elemento;

struct fila{
    Elemento *inicio;
    Elemento *fim;
};

Fila* criar(){
    Fila *fd;
    fd = (Fila*)malloc(sizeof(Fila));
    if(fd != NULL){
        fd->inicio = NULL;
        fd->fim = NULL;
    }
    return fd;
}

int vazia(Fila *fd){
    if(fd == NULL){
        return -1;
    }else if(fd->inicio == NULL){
        return 1;
    }else{
        return 0;
    }
}

int cheia (Fila *fd){
    return 0;
}

int tamanho(Fila *fd){
    if(vazia(fd)){
        return 0;
    }
    int cont = 0;
    Elemento *aux = fd->inicio;
    while(aux != NULL){
        cont++;
        aux = aux->proximo;
    }
    return cont;
}

void destruir(Fila *fd){
    if(fd != NULL){
        Elemento *aux;
        while(fd->inicio != NULL){
            aux = fd->inicio;
            fd->inicio = fd->inicio->proximo;
            free(aux);
        }
        fd->fim = NULL;
        free(fd);
    }
}

int inserir(Fila* fd, Pessoa dados){ // Correção aqui
    if(fd == NULL){
        return 0;
    }else{
        Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
        if(novo == NULL){
            return 0;
        }else{
            novo->dados = dados;
            novo->proximo = NULL;
            if(fd->fim == NULL){
                fd->inicio = novo;
            }else{
                fd->fim->proximo = novo;
            }
            fd->fim = novo;
            return 1;
        }
    }
}

int remover(Fila *fd){
    if(fd == NULL){
        return 0;
    }else if(vazia(fd)){
        return 0;
    }else{
        Elemento *aux = fd->inicio;
        fd->inicio = fd->inicio->proximo;
        if(fd->inicio == NULL){
            fd->fim = NULL;
        }
        free(aux);
        return 1;
    }
}

int acessar(Fila *fd, Pessoa *pessoa){ // Correção aqui
    if(fd == NULL){
        return 0;
    }else if(vazia(fd)){
        return 0;
    }else{
        *pessoa = fd->inicio->dados;
        return 1;
    }
}

int imprimeFila(Fila* fd){
    if(fd == NULL){
        return 0;
    }else{
        Elemento *aux = fd->inicio;
        while(aux != NULL){
            printf("--------------------------------\n");
            printf("Nome: %s\nSenha: %d\n", aux->dados.nome, aux->dados.senha); // Correção aqui
            printf("--------------------------------\n");
            aux = aux->proximo;
        }
        return 1;
    }
}
