#include "geral.h"

bool verifica(){
    // return rand()%2;
    return false;
}

/*bool verifica_2(carta *c1, carta *c2){
    // verifica local carta 1 e local carta 2;
    // verifica se é possível pela matriz de adjacencias;
    // se carta 2 for das pilhas de naipe, verificar se carta 1 condiz com naipe e sequencia
    // se carta 2 for das sete listas, verificar se carta 1 condiz com a sequencia e cor
    // return true
}*/

bool win_check(){ // Verifica se o usuário venceu
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