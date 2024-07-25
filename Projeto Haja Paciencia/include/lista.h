#ifndef __LISTA_H__
#define __LISTA_H__

#include "carta.h"

typedef struct node{
    carta *c;
    struct node *proximo;
    struct node *anterior;
} node;

typedef struct{
    node *first;
    int tamanho;
    node *last;
    SDL_Rect base;
} lista;

#define TAM_P 7
lista listas[TAM_P]; // vetor de listas, que contem as sete "pilhas" (listas) de jogo

// Cabeçario de funções
void zerar_listas();
void insert(lista* l, carta *c);
void atualizar_listas();
carta* delete(lista *L, int indice);
carta* at(lista* l, int indice);

#endif