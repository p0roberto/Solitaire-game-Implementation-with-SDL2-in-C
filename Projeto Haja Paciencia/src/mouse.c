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

void handle_click(){
    // checando se esta clicando em um dos sete montes
    for(int i = 0; i < TAM_P; i++){ // Percorre os montes
        node* at = listas[i].first; // auxiliar
        for(int j = 0; j < listas[i].tamanho && at != NULL; j++){ // Percorre as cartas no monte
            if(is_clicking_on_rect(&at->c->rect) && !at->c->virada){ // Clicou em uma carta e ela está virada?
                int qtd = listas[i].tamanho - j; // Quantidade de cartas que deseja mover
                while(qtd--){
                    insert(&mouse_list, delete(&listas[i], j)); // Adiciona as cartas selecionadas na lista do mouse
                }
                i = TAM_P;
                break;
            }
            at = at->proximo;
        }
    }


    //checando se esta clicando no deck


    // checando se esta clicando nos naipes
}