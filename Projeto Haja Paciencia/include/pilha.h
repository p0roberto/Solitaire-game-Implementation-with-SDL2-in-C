#ifndef __PILHA_H__
#define __PILHA_H__

#include "carta.h"

typedef struct no{
    carta *c;
    struct no* anterior;
} no;

typedef struct{
    int tamanho;
    no *topo;
    SDL_Rect base;
} pilha;

pilha pilhas_g[NAIPES]; // Vetor de pilhas, que contem as quatro pilhas de guardar cartas ordenadas
pilha deck_pilha[2]; // Vetor de pilhas, que contem os deckes de compra

// Cabeçario de funções
bool push(pilha *p, carta *c);
carta* pop(pilha *p);
void zerar_pilhas();
void atualizar_pilhas();

#endif