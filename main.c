#include <stdio.h>
#include "batallas.h"
//#define "kokemone.txt" LISTA_DE_ENTRENADORES

int main() {
    printf("Hello, World!\n");
    torneo_t* torneo =   torneo_crear("kokemone2.txt");
    torneo_destruir(torneo);
    return 0;
}
