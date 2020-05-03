#include <stdio.h>
#include "batallas.h"
#define ARCHIVO_DE_ENTRENADORES "kokemone.txt"

int main() {
    printf("Hello, World!\n");
    torneo_t* torneo =   torneo_crear(ARCHIVO_DE_ENTRENADORES);
    torneo_destruir(torneo);
    return 0;
}
