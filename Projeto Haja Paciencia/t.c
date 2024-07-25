#include <stdio.h>

#define l 2
#define c 3
#define tam 100

char matriz[l][c][tam] = {
    "BOM DIA", "BOA NOITE", "BOA TARDETARDETARDE",
    "UFGUFGUFG",  "UFMGUFMGUFMG", "UFMTUFMTUFMT"
};

int main(){

    for(int i = 0; i < l; i++){
        for(int j =0 ; j < c; j++){
            printf("(%d,%d) = %s\n", i, j, matriz[i][j]);
        }
    }

    return 0;
}