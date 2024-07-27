
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

lista* handle_first_click(){ // Retorna a carta clicada pelo usuário, se for o caso
    if(mouse_list.tamanho) return NULL;

    // Checando se esta clicando em um dos sete monte
    for(int i = 0; i < TAM_P; i++){
        if(!listas[i].tamanho) continue;
        node* at = listas[i].last;
        for(int j = listas[i].tamanho - 1; j >= 0 && at != NULL; j--){
            if(is_clicking_on_rect(&at->c->rect) && !at->c->virada){
                origem = i + 2 + NAIPE + MONTE + i;
                printf("## clicou no monte %d\n", i);
                printf("## origem = %d\n", origem);
                int qtd = listas[i].tamanho - j;
                while(qtd--){
                    insert(&mouse_list, delete(&listas[i], j)); // Adiciona as cartas selecionadas na lista do mouse
                }
                i = TAM_P;
                return &mouse_list;
            }
            at = at->anterior;
        }
    }

    // Checando se esta clicando no deck 0
    if(is_clicking_on_rect(&deck_pilha[0].base)){
        if(deck_pilha[0].tamanho) swap_deck_animation = true;
        else{
            while(deck_pilha[1].tamanho){   
                push(&deck_pilha[0], pop(&deck_pilha[1]));
                deck_pilha[0].topo->c->virada = true;
            }
        }
        return NULL;
    }

    // Checando se esta clicando no deck 1
    if(is_clicking_on_rect(&deck_pilha[1].base)){
        printf("clicou deck 1\n");
        origem = DECK + 1;
        insert(&mouse_list, pop(&deck_pilha[1]));
        return &mouse_list;
    }
    
    // Checando se esta clicando nas pilhas de guardar
    for(int i = 0; i < NAIPES; i++){
        if(is_clicking_on_rect(&naipes_rect[i]) && pilhas_g[i].tamanho){
            origem = 2 + NAIPE + i;
            insert(&mouse_list, pop(&pilhas_g[i]));
            return &mouse_list;
        }
    }

    origem = -1;
    return &mouse_list;
}

void handle_second_click(){
    if(mouse_list.tamanho == 0) return;
    if(origem == -1){
        printf("origem = -1\n");
        return;
    }

    /*
    if(!verifica()){
        printf("click invalido!\n");
        printf("origem = %d\n", origem);
        while(mouse_list.tamanho){
            switch(get_base_tipo(origem)){
                case DECK:
                    printf("origem no deck!\n");
                    push(&deck_pilha[1], delete(&mouse_list, 0));
                    break;

                case NAIPE:
                    printf("origem no naipe!\n");
                    push(&pilhas_g[origem - 2], delete(&mouse_list, 0));
                    break;

                case MONTE:
                    printf("origem no monte!\n");
                    printf("!! vo inserir no monte %d\n", origem - MONTE - NAIPE - 2);
                    insert(&listas[origem - MONTE - NAIPE - 2], delete(&mouse_list, 0));
                    break;

                default:
                    printf("deu erro\n");
            }

        }
        return;
    }
    */

    // Checando se esta clicando em um dos sete monte
    for(int i = 0; i < TAM_P; i++){       
        SDL_Rect gambiarra = (listas[i].tamanho) ?  listas[i].last->c->rect : listas[i].base;
        if(is_clicking_on_rect(&gambiarra)){
            if(verifica_lista(&mouse_list, &listas[i])){  // Chamar a verificar com a carta retornada por click1 e lista clicada agora 
                while(mouse_list.tamanho){
                    insert(&listas[i], delete(&mouse_list, 0));
                }
                return;
            }
        }
    }

    // Checando se esta clicando nas pilhas de guardar
    for(int i = 0; i < NAIPES && mouse_list.tamanho == 1; i++){
        if(is_clicking_on_rect(&naipes_rect[i])){
            if(verifica_pilha(&mouse_list, &pilhas_g[i], i)){  // Chamar a verificar com a carta retornada por click1 e pilha clicada agora 
                while(mouse_list.tamanho){
                    push(&pilhas_g[i], delete(&mouse_list, 0));
                }
            }
            return;
        }
    }
}

void handle_click(){
    if(!mouse_list.tamanho){ // Se não houver cartas na lista do mouse, é o primeiro clique
        handle_first_click(); 
    }
    else{ // Se houver cartas na lista do mouse, é o segundo clique
        handle_second_click();
    }    
}

