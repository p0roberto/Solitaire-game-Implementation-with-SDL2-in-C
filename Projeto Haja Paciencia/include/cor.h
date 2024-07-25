#ifndef __COR_H__
#define __COR_H__

typedef struct {
    int r,g,b,a;
} cor;

cor marrom = {168, 123, 50, 255};
cor cinza = {203, 212, 201, 255};
cor verde = {115, 168, 50, 255};
cor vermelho = {255, 0, 0, 255};
cor azul = {0, 0, 255, 255};
cor preto = {255, 255, 255, 255};

cor random_color();

#endif