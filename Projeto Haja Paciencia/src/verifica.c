#include "geral.h"

// Verifica a possibilidade de colocar cartas nas pilhas
bool verifica_lista(lista *l1, lista *l2){ // Incompleta
    if (l1 == NULL || l2 == NULL) {
        return false; // Verificação de ponteiros nulos
    }
    node *aux = l1->first; // carta do mouse
    node *aux2 = l2->last; // carta da pilha

    if(l2->tamanho == 0){ // Se não houver cartas na pilha
        if(aux->c->numero == 13){ // permetido guardar apenas se for K's
            return true;
        }
        return false;
    }
    if(((aux->c->naipe + 1) % 2) != ((aux2->c->naipe + 1) % 2)){ // Verificando se os naipes possuem a mesma cor
        if(aux->c->numero == (aux2->c->numero - 1)){ // Verificando se os numeros sao consecutivos
            return true;
        }
        return false;
    } 
    return false;
}

// Verifica a possibilidade de guardar carta na pilha
bool verifica_pilha(lista *list, pilha *p, int naipe_da_pilha){ // Recebe a lista do mouse, a pilha clicada e o indice da pilha clicada, que indica o naipe da pilha
    if (list == NULL || p == NULL) {
        return false; // Verificação de ponteiros nulos
    }

    node *aux = list->last; // carta do mouse
    no *aux2 = p->topo; // carta da pilha
    
    if(p->tamanho == 0){ // Se não houver cartas na pilha de guardar
        if((aux->c->numero == 1) && (aux->c->naipe == naipe_da_pilha)){ // permetido guardar apenas se for A's && naipe igual
            return true;
        }
        return false;
    }
    if((aux->c->naipe == naipe_da_pilha) && (aux->c->numero == aux2->c->numero + 1)){
    // permitido guardar apenas se for de mesmo naipe && sucessor
        return true;
    }
    return false;
}

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
