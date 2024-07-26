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

    // Carregando os rects da base dos montes
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
    atualizar_listas(); // Renderiza as cartas nas listas (sete "pilhas" principais)
    atualizar_mouse(); // Renderiza as cartas do mouse
}


int main(){
    InitializeSDL(); // Inicializa o jogo

    bool quit = false;

    load_game(); // Carrega a tela do jogo inicial
    
    SDL_Rect roberto = {500,SCREEN_HEIGHT - 100, 150, 50};

    int paulo_w = 200;
    int paulo_h = 200;
    SDL_Rect paulo = {(SCREEN_WIDTH - paulo_w) /2 , (SCREEN_HEIGHT - paulo_h)/2, paulo_w, paulo_h};

    while(!quit){ // Loop principal
        while(SDL_PollEvent(&event) != 0){ // Se houver interação
            if(event.type == SDL_QUIT){
                quit = true;
            }
            if(event.type == SDL_MOUSEBUTTONDOWN){
                clicked = true;
            }
        }

        update_all(); // Renderiza
        if(win_check()){
            colorir_rect(&paulo, verde);
            if(is_clicking_on_rect(&paulo)){
                load_game();
            }
        }


        colorir_rect(&roberto, vermelho);
        if(is_clicking_on_rect(&roberto)){
            load_game();
        }
      
        if(clicked){ // Se houver click, onde ele é?
            handle_click();
            clicked = false;
        }

        SDL_RenderPresent(renderer); // Mostra na tela os elementos renderizados pelo renderer
        SDL_RenderClear(renderer);

        SDL_Delay(2);
    }

    SDL_Quit();

    return 0;
}
