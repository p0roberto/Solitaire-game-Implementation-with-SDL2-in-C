#include "geral.h"

void iniciar_cartas(){ // Inicializa as cartas no vetor
    int index = 0;
    for(int i = 0; i < NAIPES; i++){
        for(int j = 1; j <= MAX; j++){
            baralho[index].naipe = i; // i_esimo naipe
            baralho[index].numero = j; // j_esimo numero
            baralho[index].virada = true; // inicializa todas de costas
            baralho[index].rect.w = largura_carta; // dimensoes
            baralho[index].rect.h = altura_carta; // dimensoes
            index++;
        }
    }
    embaralhar();
    distribuir_cartas();
}

void embaralhar(){ // Embaralha as cartas, trocando-as de posição com outra carta aleatoria
    bool usados[TOTAL_CARTAS];

    for(int i = 0; i < TOTAL_CARTAS; i++){
        usados[i] = false;
    }

    int cont = 0;

    for(int i = 0; i <= TOTAL_CARTAS/2; i++){
        if(usados[i] == true) continue;
        usados[i] = true;

        int destino = 0;

        while(usados[destino] == true){
            destino = rand() % TOTAL_CARTAS;
        }

        carta temp = baralho[i];
        baralho[i] = baralho[destino];
        baralho[destino] = temp;
        usados[destino] = true;
    }
}


// funcões load_texture, que carregam a textura para a variavel de textura dos elementos
void load_texture_naipes(){
    for(int i = 0; i < NAIPES; i++){
        texture_naipes[i] = load_image_to_texture(naipes_background_path[i]);
    }
}

void load_texture_deck(){
    texture_deck = load_image_to_texture("imagens/fundos/deck_background.png");
}

void load_texture_cartas(){
    for(int i = 0; i < NAIPES; i++){        
        for(int j = 1; j <= MAX; j++){
            texture_cartas[i][j] = load_image_to_texture(imagens_cartas_path[i][j]);
        }
    }
    texture_cartas_background = load_image_to_texture("imagens/cartas/background_cartas_geral.png");
}

void atualizar_background(){  // Função que posiciona os backgrounds
    
    SDL_RenderCopy(renderer, background_texture, NULL, &background_rect); // Renderiza o fundo
    SDL_RenderCopy(renderer, texture_button_new_game, NULL, &new_game); // Renderiza o botão

    for(int i = 0; i < 2; i++){ // Renderiza os decks de compra
        SDL_RenderCopy(renderer, texture_deck, NULL, &deck_rect[i]);
    }

    for(int i = 0; i < NAIPES; i++){ // Renderiza o local de guardar
        SDL_RenderCopy(renderer, texture_naipes[i], NULL, &naipes_rect[i]);
    }

    for(int i = 0; i < 7; i++){ // Renderiza o background dos montes iniciais
        SDL_RenderCopy(renderer, texture_deck, NULL, &montes[i]);
    }
}

void distribuir_cartas(){ // Distribui as cartas iniciais, utilizando o baralho embaralhado
    int carta_atual = 0;
    
    for(int i = 0; i < TAM_P; i++){
        for(int j = 0; j <= i; j++){
            insert(&listas[i], &baralho[carta_atual]);
            carta_atual++;
        }
    }
    // As cartas restantes são colocadas no deck de compras
    for( ; carta_atual < TOTAL_CARTAS; carta_atual++){
        push(&deck_pilha[0], &baralho[carta_atual]);
    }
}