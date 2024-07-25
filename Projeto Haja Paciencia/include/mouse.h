#ifndef __MOUSE_H__
#define __MOUSE_H__

#include "interface.h"
#include "lista.h"

int mouseX = 0, mouseY = 0;
bool clicked = false;
lista mouse_list; 

// Cabeçario de funções
void zerar_mouse();
void atualizar_mouse();
void handle_click();

#endif
