#include "geral.h"

void zerar_mouse(){
    mouseX = 0;
    mouseY = 0;
    mouse_list.first = mouse_list.last = NULL;
    mouse_list.tamanho = 0;    
}

void atualizar_mouse(){
    SDL_GetMouseState(&mouseX, &mouseY); // Atualiza as coordenadas do cursor
    mouse_list.base.x = mouseX;
    mouse_list.base.y = mouseY;

    int renderizadas = 0;
    for(node* at = mouse_list.first; at; at = at->proximo){ // Renderiza as cartas da lista do mouse
        at->c->rect.x = mouseX - largura_carta/2;

        int variacao_y = renderizadas * altura_carta / divisao;
        at->c->rect.y = mouse_list.base.y + variacao_y;

        int numero = at->c->numero;
        int naipe = at->c->naipe;
        SDL_RenderCopy(renderer, texture_cartas[naipe][numero], NULL, &at->c->rect);
        renderizadas++;
    }
}

void handle_first_click(){
    if(mouse_list.tamanho) return;

    // checando se esta clicando em um dos sete monte
    for(int i = 0; i < TAM_P; i++){
        if(!listas[i].tamanho) continue;
        node* at = listas[i].last;
        for(int j = listas[i].tamanho - 1; j >= 0 && at != NULL; j--){
            if(is_clicking_on_rect(&at->c->rect) && !at->c->virada){
                int qtd = listas[i].tamanho - j;
                while(qtd--){
                    insert(&mouse_list, delete(&listas[i], j)); // Adiciona as cartas selecionadas na lista do mouse
                }
                i = TAM_P;
                return;
            }
            at = at->anterior;
        }
    }


    //checando se esta clicando no deck 0
    if(is_clicking_on_rect(&deck_pilha[0].base)){
        if(deck_pilha[0].tamanho) swap_deck_animation = true;
        else{
            while(deck_pilha[1].tamanho){   
                push(&deck_pilha[0], pop(&deck_pilha[1]));
                deck_pilha[0].topo->c->virada = true;
            }
        }
    }

    //checando se esta clicando no deck 1
    if(is_clicking_on_rect(&deck_pilha[1].base)){
        insert(&mouse_list, pop(&deck_pilha[1]));
    }
    

    // checando se esta clicando nos naipes
    for(int i = 0; i < NAIPES; i++){
        if(is_clicking_on_rect(&naipes_rect[i]) && pilhas_g[i].tamanho){
            insert(&mouse_list, pop(&pilhas_g[i]));
            return;
        }
    }
}

void handle_second_click(){
    // checando se esta clicando em um dos sete monte
    for(int i = 0; i < TAM_P; i++){       
        SDL_Rect gambiarra = (listas[i].tamanho) ?  listas[i].last->c->rect : listas[i].base;
        if(is_clicking_on_rect(&gambiarra)){  
            while(mouse_list.tamanho){
                insert(&listas[i], delete(&mouse_list, 0));
            }
            return;
        }
    }


    //checando se esta clicando no deck


    // checando se esta clicando nos naipes
    for(int i = 0; i < NAIPES && mouse_list.tamanho == 1; i++){
        if(is_clicking_on_rect(&naipes_rect[i])){
            while(mouse_list.tamanho){
                push(&pilhas_g[i], delete(&mouse_list, 0));
            }
            return;
        }
    }
}

void handle_click(){
    if(!mouse_list.tamanho){
        handle_first_click();
    }
    else{
        handle_second_click();
    }    
}
