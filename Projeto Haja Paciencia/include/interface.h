#ifndef __INTERFACE_H__
#define __INTERFACE_H__

typedef char bool;
const int false = 0;
const int true = 1;

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "cor.h"

SDL_Window* window;
SDL_Renderer* renderer = NULL;
SDL_Event event;
const int SCREEN_WIDTH = 1428; // Largura da janela
const int SCREEN_HEIGHT = 918; // Altura da janela

SDL_Texture* background_texture = NULL;

SDL_Rect background_rect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

// Cabeçario de funções
bool InitializeSDL();
void colorir_rect(SDL_Rect* rect, cor c);
void colorir_fundo(cor c);
SDL_Texture* load_image_to_texture(const char* image_path);
bool is_clicking_on_rect(SDL_Rect* r);

#endif