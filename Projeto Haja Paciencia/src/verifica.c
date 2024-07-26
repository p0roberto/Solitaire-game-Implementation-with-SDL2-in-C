#include "geral.h"

bool verifica(){
    // return rand()%2;
    return false;
}

bool win_check(){
    int soma = 0;

    for(int i = 0; i < NAIPES; i++){
        soma += pilhas_g[i].tamanho;
    }

    return soma >= TOTAL_CARTAS;
}


int get_base_tipo(int base_index){
    printf("verificando %d\n", base_index);
    if(base_index >= 6) return MONTE;
    if(base_index >= 2) return NAIPE;
    return DECK;
}