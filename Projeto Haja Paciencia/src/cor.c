#include "geral.h"

cor random_color(){
    cor c;
    c.r = rand() % 266;
    c.g = rand() % 266;
    c.b = rand() % 266;
    c.a = 255;
    return c;
}