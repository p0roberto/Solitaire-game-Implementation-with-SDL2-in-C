#ifndef __VERIFICA_H__
#define __VERIFICA_H__

#include "carta.h"

#define ADJ_SIZE 3

enum tipos{
    DECK = 0, NAIPE, MONTE
};

bool Matriz_ADJ[ADJ_SIZE][ADJ_SIZE] = {
    {0, 1, 1}, /*deck*/
    {0, 0, 1}, /*naipe*/
    {0, 1, 1} /*monte*/
};

//0 a 1 = deck , 2 a 5 = naipes, 6 a 12 = montes
SDL_Rect bases[2 + NAIPES + TAM_P];

// Cabeçario de funções 
int get_base_tipo(int base_index);
bool verifica_lista();
bool verifica_pilha();
bool win_check();

#endif