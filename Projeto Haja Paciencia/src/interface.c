#include "geral.h"

/**
 * @brief inicia o SDL, fazendo coisas como criar janela e alocar o renderer
 * @return true, caso tenha conseguido iniciar tudo com sucesso, false caso contrario
*/

bool InitializeSDL(){
    srand(time(NULL));

    SDL_Init(SDL_INIT_VIDEO);

    //inicializando a janela
    window = SDL_CreateWindow(
        "CLUDE DE REGATAS DO FLAMENGO", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN
    );

    if(!window){
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit(); 
        return false;
    }

    //inicializando o renderer (para carregar coisas na janela)
    renderer = SDL_CreateRenderer(window, -1, 0); //SDL_RENDERER_ACCELERATED);
    if(!renderer){
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        return false;
    }

    return true;
}

void colorir_rect(SDL_Rect* rect, cor c){
    SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
    SDL_RenderFillRect(renderer, rect);
}

void colorir_fundo(cor c){
    SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
    SDL_RenderClear(renderer); 
}

// Recebe o caminho para determinada imagem e cria uma textura com base nela
SDL_Texture* load_image_to_texture(const char* image_path){
    SDL_Texture* texture = NULL;

    SDL_Surface* surface = IMG_Load(image_path);

    if(!surface){
        printf("load_image_to_texture error: %s\n", IMG_GetError());
        return NULL;
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    return texture;
}

// Verifica colisão do cursor
bool is_clicking_on_rect(SDL_Rect* r){
    if(!clicked) return false;
    if(mouseX < r->x) return false;
    if(mouseX > r->x + r->w) return false;
    if(mouseY < r->y) return false;
    if(mouseY > r->y + r->h) return false;
    return true;
}