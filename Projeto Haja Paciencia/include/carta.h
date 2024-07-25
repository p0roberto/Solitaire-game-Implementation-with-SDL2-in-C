#ifndef __CARTA_H__
#define __CARTA_H__

// #include "geral.h"
#include "interface.h"

#define NAIPES 4 // quantidade de naipes
#define MAX 13 // quantidade de cartas de cada naipe 
#define TOTAL_CARTAS 52

const int altura_carta = 160; // altura das cartas, para o rect; 
const int largura_carta = 105; // largura das carta, para o rect;
const int divisao = 4; //fracao da carta que fica visivel quando é tampada por outra (ex: 4 -> 1/4 da carta)

typedef struct{
    int numero; // A = 1, J = 11, Q = 12, K = 13, 
    int naipe;
    bool virada; //  se for true, virada pra baixo, se for false, virada pra cima
    SDL_Rect rect; // Coordenadas
} carta;

enum naipes{
    COPAS = 0, PAUS, OUROS, ESPADA // Espada = Ponta, Copas = Coração, Ouros = Losango, Paus = Trevo
};


// Variaveis que armazenam a textura dos elementos
SDL_Texture* texture_cartas[NAIPES][MAX+1]; // primeira coluna nula
SDL_Texture* texture_naipes[NAIPES];
SDL_Texture* texture_deck;
SDL_Texture* texture_cartas_background;

char imagens_cartas_path[NAIPES][MAX+1][100] = { // Matriz de strings, que armazena o nome do jpg das cartas
    //LINHA 0: COPAS
    ""," imagens/cartas/A_copas.png", "imagens/cartas/1_copas.png", "imagens/cartas/2_copas.png", "imagens/cartas/3_copas.png", "imagens/cartas/4_copas.png", "imagens/cartas/5_copas.png", "imagens/cartas/6_copas.png", "imagens/cartas/7_copas.png", "imagens/cartas/8_copas.png", "imagens/cartas/9_copas.png", "1imagens/cartas/0_copas.png", "imagens/cartas/J_copas.png", "imagens/cartas/Q_copas.png", "imagens/cartas/K_copas.png",
    //LINHA 1: PAUS
    "", "imagens/cartas/A_paus.png", "imagens/cartas/1_paus.png", "imagens/cartas/2_paus.png", "imagens/cartas/3_paus.png", "imagens/cartas/4_paus.png", "imagens/cartas/5_paus.png", "imagens/cartas/6_paus.png", "imagens/cartas/7_paus.png", "imagens/cartas/8_paus.png", "imagens/cartas/9_paus.png", "1imagens/cartas/0_paus.png", "imagens/cartas/J_paus.png", "imagens/cartas/Q_paus.png", "imagens/cartas/K_paus.png",
    //LINHA 2: OUROS
    "", "imagens/cartas/A_ouros.png", "imagens/cartas/1_ouros.png", "imagens/cartas/2_ouros.png", "imagens/cartas/3_ouros.png", "imagens/cartas/4_ouros.png", "imagens/cartas/5_ouros.png", "imagens/cartas/6_ouros.png", "imagens/cartas/7_ouros.png", "imagens/cartas/8_ouros.png", "imagens/cartas/9_ouros.png", "1imagens/cartas/0_ouros.png", "imagens/cartas/J_ouros.png", "imagens/cartas/Q_ouros.png", "imagens/cartas/K_ouros.png",
    //LINHA 3: ESPADA
    "", "imagens/cartas/A_espadas.png", "imagens/cartas/1_espadas.png", "imagens/cartas/2_espadas.png", "imagens/cartas/3_espadas.png", "imagens/cartas/4_espadas.png", "imagens/cartas/5_espadas.png", "imagens/cartas/6_espadas.png", "imagens/cartas/7_espadas.png", "imagens/cartas/8_espadas.png", "imagens/cartas/9_espadas.png", "1imagens/cartas/0_espadas.png", "imagens/cartas/J_espadas.png", "imagens/cartas/Q_espadas.png", "imagens/cartas/K_espadas.png"
};

// Variaveis do tipo rect, que armazenam as coordenadas
SDL_Rect naipes_rect[NAIPES];
SDL_Rect deck_rect[2];
SDL_Rect montes[7];

char naipes_background_path[NAIPES][70] = { // Vetor de strings, que armazena o nome do jpg dos background dos naipes
    "imagens/fundos/copas_background.png",
    "imagens/fundos/paus_background.png",
    "imagens/fundos/ouros_background.png",
    "imagens/fundos/espadas_background.png"
};

carta baralho[TOTAL_CARTAS]; // Vetor que armazena as cartas

// Cabeçario das funções
void iniciar_cartas();
void embaralhar();
void load_texture_naipes();
void load_texture_deck();
void load_texture_cartas();
void atualizar_background();
void distribuir_cartas();

#endif