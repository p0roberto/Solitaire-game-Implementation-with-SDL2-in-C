#include "geral.h"

void zerar_mouse(){
    mouseX = 0;
    mouseY = 0;
    mouse_list.first = mouse_list.last = NULL;
    mouse_list.tamanho = 0;    
}

void atualizar_mouse(){
    SDL_GetMouseState(&mouseX, &mouseY);
    mouse_list.base.x = mouseX;
    mouse_list.base.y = mouseY;

    int renderizadas = 0;
    for(node* at = mouse_list.first; at; at = at->proximo){
        at->c->rect.x = mouseX - largura_carta/2;

        int variacao_y = renderizadas * altura_carta / divisao;
        at->c->rect.y = mouse_list.base.y + variacao_y;

        int numero = at->c->numero;
        int naipe = at->c->naipe;
        SDL_RenderCopy(renderer, texture_cartas[naipe][numero], NULL, &at->c->rect);
        renderizadas++;
    }
}

void handle_click(){
    // checando se esta clicando em um dos sete montes
    for(int i = 0; i < TAM_P; i++){
        node* at = listas[i].last;
        bool adicionar = false;
        for(int j = 0; j < listas[i].tamanho && at != NULL; j++){
            if(is_clicking_on_rect(&at->c->rect) && !at->c->virada){
                adicionar = true;   
            }
            if(adicionar){
                at = at->proximo;
                carta* algo = delete(&listas[i], j);
                j--;
                insert(&mouse_list, algo);
                break;
            }

            j++;
            at = at->anterior;
        }

        if(adicionar) break;
    }


    //checando se esta clicando no deck


    // checando se esta clicando nos naipes
}