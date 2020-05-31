#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "batallas.h"
#define ARCHIVO_DE_ENTRENADORES "kokemone3.txt"
#define GANO_ENTRENADOR1 0
#define GANO_ENTRENADOR2 1

/*
 * Pre: Que me den dos entrenadores validos
 * Pos: Si gano el primero devuelvo 0, si gano el segundo devuelvo 1
 * */
int coding_battle(entrenador_t* entrenador1, entrenador_t* entrenador2){
    if(entrenador1->pokemones[0].inteligencia > entrenador2->pokemones[0].inteligencia){
        return GANO_ENTRENADOR1;
    }
    else if(entrenador1->pokemones[0].inteligencia < entrenador2->pokemones[0].inteligencia){
        return GANO_ENTRENADOR2;
    }

    if(entrenador1->pokemones[1].inteligencia > entrenador2->pokemones[1].inteligencia){
        return GANO_ENTRENADOR1;
    }
    else if(entrenador1->pokemones[1].inteligencia < entrenador2->pokemones[1].inteligencia){
        return GANO_ENTRENADOR2;
    }

    if(entrenador1->pokemones[2].inteligencia > entrenador2->pokemones[2].inteligencia){
        return GANO_ENTRENADOR1;
    }
    else if(entrenador1->pokemones[2].inteligencia < entrenador2->pokemones[2].inteligencia){
        return GANO_ENTRENADOR2;
    }

    return GANO_ENTRENADOR1;//Por anotarse antes
}

/*
 * Pre: Que me den dos entrenadores validos
 * Pos: Si gano el primero devuelvo 0, si gano el segundo devuelvo 1
 * */
int pulseadas(entrenador_t* entrenador1, entrenador_t* entrenador2){
    if(entrenador1->pokemones[0].fuerza > entrenador2->pokemones[0].fuerza){
        return GANO_ENTRENADOR1;
    }
    else if(entrenador1->pokemones[0].fuerza < entrenador2->pokemones[0].fuerza){
        return GANO_ENTRENADOR2;
    }

    if(entrenador1->pokemones[1].fuerza > entrenador2->pokemones[1].fuerza){
        return GANO_ENTRENADOR1;
    }
    else if(entrenador1->pokemones[1].fuerza < entrenador2->pokemones[1].fuerza){
        return GANO_ENTRENADOR2;
    }

    if(entrenador1->pokemones[2].fuerza > entrenador2->pokemones[2].fuerza){
        return GANO_ENTRENADOR1;
    }
    else if(entrenador1->pokemones[2].fuerza < entrenador2->pokemones[2].fuerza){
        return GANO_ENTRENADOR2;
    }

    return GANO_ENTRENADOR1;//Por anotarse antes
}

/*
 * Pre: Que me den dos entrenadores validos
 * Pos: Si gano el primero devuelvo 0, si gano el segundo devuelvo 1
 * */
int malabares(entrenador_t* entrenador1, entrenador_t* entrenador2){
    if(entrenador1->pokemones[0].agilidad > entrenador2->pokemones[0].agilidad){
        return GANO_ENTRENADOR1;
    }
    else if(entrenador1->pokemones[0].agilidad < entrenador2->pokemones[0].agilidad){
        return GANO_ENTRENADOR2;
    }

    if(entrenador1->pokemones[1].agilidad > entrenador2->pokemones[1].agilidad){
        return GANO_ENTRENADOR1;
    }
    else if(entrenador1->pokemones[1].agilidad < entrenador2->pokemones[1].agilidad){
        return GANO_ENTRENADOR2;
    }

    if(entrenador1->pokemones[2].agilidad > entrenador2->pokemones[2].agilidad){
        return GANO_ENTRENADOR1;
    }
    else if(entrenador1->pokemones[2].agilidad < entrenador2->pokemones[2].agilidad){
        return GANO_ENTRENADOR2;
    }

    return GANO_ENTRENADOR1;//Por anotarse antes
}

/*
 * Pre: Que el entrenador no sea nulo
 * Pos: Que imprima todo
 * */
void* listar_1(entrenador_t* entrenador){
    printf("Con sus Pokemon:\n\n");
    printf("%s: que tiene de fuerza %d, de agilidad %d y de inteligencia %d\n",
           entrenador->pokemones[0].nombre, entrenador->pokemones[0].fuerza,
           entrenador->pokemones[0].agilidad, entrenador->pokemones[0].inteligencia);
    printf("%s: que tiene de fuerza %d, de agilidad %d y de inteligencia %d\n",
           entrenador->pokemones[1].nombre, entrenador->pokemones[1].fuerza,
           entrenador->pokemones[1].agilidad, entrenador->pokemones[1].inteligencia);
    printf("%s: que tiene de fuerza %d, de agilidad %d y de inteligencia %d\n",
           entrenador->pokemones[2].nombre, entrenador->pokemones[2].fuerza,
           entrenador->pokemones[2].agilidad, entrenador->pokemones[2].inteligencia);
}

/*
 * Pre: Que el entrenador no sea nulo
 * Pos: Que imprima todo
 * */
void* listar_2(entrenador_t* entrenador){
    printf("Cuyos Pokemon son:\n");
    printf("%s: Fuerza: %d  Agilidad: %d    Inteligencia: %d\n",
           entrenador->pokemones[0].nombre, entrenador->pokemones[0].fuerza,
           entrenador->pokemones[0].agilidad, entrenador->pokemones[0].inteligencia);
    printf("%s: Fuerza: %d  Agilidad: %d    Inteligencia: %d\n",
           entrenador->pokemones[1].nombre, entrenador->pokemones[1].fuerza,
           entrenador->pokemones[1].agilidad, entrenador->pokemones[1].inteligencia);
    printf("%s: Fuerza: %d  Agilidad: %d    Inteligencia: %d\n",
           entrenador->pokemones[2].nombre, entrenador->pokemones[2].fuerza,
           entrenador->pokemones[2].agilidad, entrenador->pokemones[2].inteligencia);
}

/*
 * Pre: Que el entrenador no sea nulo
 * Pos: Que imprima todo
 * */
void* listar_3(entrenador_t* entrenador){
    printf("Los Pokemon son:\n");
    printf("%s: \n          %d de Fuerza\n          %d de Agilidad\n          %d de Inteligencia\n\n",
           entrenador->pokemones[0].nombre, entrenador->pokemones[0].fuerza,
           entrenador->pokemones[0].agilidad, entrenador->pokemones[0].inteligencia);
    printf("%s: \n          %d de Fuerza\n          %d de Agilidad\n          %d de Inteligencia\n\n",
           entrenador->pokemones[1].nombre, entrenador->pokemones[1].fuerza,
           entrenador->pokemones[1].agilidad, entrenador->pokemones[1].inteligencia);
    printf("%s: \n          %d de Fuerza\n          %d de Agilidad\n          %d de Inteligencia\n\n",
           entrenador->pokemones[2].nombre, entrenador->pokemones[2].fuerza,
           entrenador->pokemones[2].agilidad, entrenador->pokemones[2].inteligencia);
}

/*
 * Pre: que me den un torneo valido y un numero entre 0 y 2
 * Pos: Imprimir por pantalla los entrenadores, sus pokemones y sus estadisticas
 * */
void listando(torneo_t* torneo_aux, int cual){
    if(cual ==  1){
        torneo_listar(torneo_aux, (void (*)(entrenador_t *)) listar_1);
    }
    else if(cual    ==  2){
        torneo_listar(torneo_aux, (void (*)(entrenador_t *)) listar_2);
    }
    else{
        torneo_listar(torneo_aux, (void (*)(entrenador_t *)) listar_3);
    }
}

/*
 * Pre: Que me den un torneo valido y un numero entre 0 y 2
 * Pos: Devolver el torneo solo con los entrenadores ganadores
 * */
void jugando_ronda(torneo_t* torneo1, int cual){
    if(cual ==  1){
        torneo_jugar_ronda(torneo1, coding_battle);
    }
    else if(cual    ==  2){
        torneo_jugar_ronda(torneo1, pulseadas);
    }
    else{
        torneo_jugar_ronda(torneo1, malabares);
    }
}

int main() {
    printf("Bienvenidos entrenadores!\n");
    srand(getpid());
    torneo_t* torneo =   torneo_crear(ARCHIVO_DE_ENTRENADORES);
    if(torneo   ==  NULL){
        return ERROR;
    }

    bool jugando    =   true;
    int numero  =   rand()%3;
    while(jugando   ==  true){
        listando(torneo, numero);
        numero  =   rand()%3;
        jugando_ronda(torneo, numero);
        numero  =   rand()%3;
        if(torneo   ==  NULL){
            return ERROR;
        }
        if(torneo->cantidad_entrenadores    <   2){
            jugando =   false;
        }
    }
    if(torneo   !=  NULL){
        torneo_destruir(torneo);
    }
    return EXITO;
}
