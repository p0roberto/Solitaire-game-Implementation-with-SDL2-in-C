#include "geral.h"

void renderText(const char* text, SDL_Texture* texture, SDL_Rect* rect){
    SDL_Color textColor = {255, 0, 0}; //cor em rgb

    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, textColor);
    texture = SDL_CreateTextureFromSurface(renderer, textSurface);


    SDL_FreeSurface(textSurface);

    rect->w = textSurface->w;
    rect->h = textSurface->h;
    rect->x = (SCREEN_WIDTH - rect->w) / 2; 

    SDL_RenderCopy(renderer, texture, NULL, rect);
}

void atualizar_texto(){
    tempo_atual = SDL_GetTicks() / 1000.0;
    double tempo = tempo_atual - tempo_inicial;

    char tempo_string[25] = "";
    snprintf(tempo_string, 25, "%.2lf", tempo);
    renderText(tempo_string, texture_time, &timer_rect);
    
    char movimentos_string[25] = "";
    snprintf(movimentos_string, 25, "Clicks: %d", movimentos);
    renderText(movimentos_string, texture_movimentos, &movimentos_rect);
}