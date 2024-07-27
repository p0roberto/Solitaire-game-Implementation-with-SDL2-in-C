#ifndef __MOUSE_H__
#define __MOUSE_H__

#include "interface.h"
#include "lista.h"

int mouseX = 0, mouseY = 0;
bool clicked = false;
lista mouse_list; 
int origem = -1;

// Cabeçario de funções
void zerar_mouse();
void atualizar_mouse();
lista* handle_first_click();
void handle_second_click();
void handle_click();

#endif