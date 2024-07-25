#include "geral.h"

void load_game(){

    // Inicializando a textura de tudo
    load_texture_naipes();
    load_texture_deck();
    load_texture_cartas();
    background_texture = load_image_to_texture("imagens/fundos/background.jpg");

    // Inicializando constantes
    const int border_distance_x = 20;
    const int border_distance_y = 15;
    const int distance_between_cards_y = 10;
    const int distance_between_cards_x = 30;

    // Carregando os rects gerais
    int y = border_distance_y;
    int x = border_distance_x;
    int i = 0;

    // Carregando os rects do deck de compras
    for(i = 0; i < 2; i++){
        deck_rect[i].x = x;
        deck_rect[i].y = y;
        deck_rect[i].w = largura_carta;
        deck_rect[i].h = altura_carta;
        x += largura_carta + distance_between_cards_x;
    }

    // Carregando os rects das pilhas de guardar
    y += altura_carta + distance_between_cards_y + 28;
    for(int j = 0; j < NAIPES; j++, i++){
        naipes_rect[j].x = border_distance_x;
        naipes_rect[j].y = y;
        naipes_rect[j].w = largura_carta;
        naipes_rect[j].h = altura_carta;
        y += altura_carta + distance_between_cards_y;
    }

    // Carregando os rects dos montes
    x += largura_carta + 2*distance_between_cards_x;
    for(int i = 0; i < 7; i++){
        montes[i].x = x;
        montes[i].y = border_distance_y;
        montes[i].w = largura_carta;
        montes[i].h = altura_carta;
        x += distance_between_cards_x + largura_carta;
    }    

    zerar_pilhas();
    zerar_listas();
    zerar_mouse();
    iniciar_cartas();
}

void update_all(){
    atualizar_background(); // Renderiza o background das pilhas
    atualizar_pilhas(); // Renderiza as cartas nas pilhas
    atualizar_listas(); // Renderiza as cartas nas listas
    atualizar_mouse(); // 
}


int main(){
    InitializeSDL(); // Inicializa o jogo

    bool quit = false;

    load_game();
    while(!quit){

        while(SDL_PollEvent(&event) != 0){
            if(event.type == SDL_QUIT){
                quit = true;
            }
            if(event.type == SDL_MOUSEBUTTONDOWN){
                clicked = true;
            }
        }

        update_all();

        if(clicked){
            handle_click();
            clicked = false;   
        }


        SDL_RenderPresent(renderer); 

        SDL_Delay(3);
    }

    SDL_Quit();

    return 0;
}
