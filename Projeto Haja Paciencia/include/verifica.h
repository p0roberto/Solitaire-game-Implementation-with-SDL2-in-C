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



#endif