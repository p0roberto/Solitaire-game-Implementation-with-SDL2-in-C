#ifndef __TIMER_H__
#define __TIMER_H__

#include "interface.h"
#include <SDL2/SDL_ttf.h>

const char* FONT_PATH = "fonts/aakar-medium.ttf";
const int FONT_SIZE = 75; //tamanho da fonte em pixels

TTF_Font* font = NULL;

int movimentos = 0;
double tempo_atual = 0.0;
double tempo_inicial = 0.0;

const int timer_rect_w = 100;
const int timer_rect_h = 100;
SDL_Rect timer_rect = {SCREEN_WIDTH - timer_rect_w, SCREEN_HEIGHT - timer_rect_h, timer_rect_w, timer_rect_h};
SDL_Rect movimentos_rect = {0, SCREEN_HEIGHT - timer_rect_h*2, 0, 0};

SDL_Texture* texture_time = NULL;
SDL_Texture* texture_movimentos = NULL;

void atualizar_texto();
void renderText(const char* text, SDL_Texture* texture, SDL_Rect* rect);

#endif