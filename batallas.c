#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "batallas.h"
#define NO_QUEDAN_MAS_ENTRENADORES 100
#define MAX_POKEMON 3
#define CANTIDAD_DE_ELEMENTOS_ENTRENADOR_MAS_POKEMON 13

/*
 * Pre: Que los valores que me pasan sean validos
 * Pos: Si es fue mal devolver NULL, si me fue bien devolver el puntero al Pokemon
 * */
pokemon_t* reservar_memoria_pokemon(pokemon_t*   pokemon1,   pokemon_t*   pokemon2,   pokemon_t*   pokemon3){
    pokemon_t* pokemon  =   NULL;
    pokemon  =   (pokemon_t *) malloc(3*sizeof(pokemon_t));
    if(pokemon   ==  NULL){
        return NULL;
    }

    strcpy(pokemon[0].nombre, pokemon1->nombre);
    pokemon[0].fuerza   =   pokemon1->fuerza;
    pokemon[0].agilidad =   pokemon1->agilidad;
    pokemon[0].inteligencia =   pokemon1->inteligencia;
    strcpy(pokemon[1].nombre, pokemon2->nombre);
    pokemon[1].fuerza   =   pokemon2->fuerza;
    pokemon[1].agilidad =   pokemon2->agilidad;
    pokemon[1].inteligencia =   pokemon2->inteligencia;
    strcpy(pokemon[2].nombre, pokemon3->nombre);
    pokemon[2].fuerza   =   pokemon3->fuerza;
    pokemon[2].agilidad =   pokemon3->agilidad;
    pokemon[2].inteligencia =   pokemon3->inteligencia;

    return pokemon;
}

/*
 * Pre: Que el torneo tenga valores validos
 * Pos: Entregar el puntero a la memoria reservada en el Heap o el NULL
 * */
entrenador_t* reservar_memoria_entrenador(torneo_t* torneo){
    entrenador_t* entrenador_auxiliar;
    if(torneo->cantidad_entrenadores ==  0){
        entrenador_auxiliar  =   (entrenador_t *) malloc(sizeof(entrenador_t));
    }
    else{
        entrenador_auxiliar  =   realloc(torneo->entrenadores,(long unsigned int)(torneo->cantidad_entrenadores + 1)*sizeof(entrenador_t));
    }
    return entrenador_auxiliar;
}

/*
 *Pre: Que los valores que me pasen sean validos y que el archivo este avierto en modo lectura
 * Pos: Cargo 1 entrenador (1 linea en el txt)
 * */
int cargar_una_linea(FILE* archivo_entrenadores, entrenador_t* entrenador1, pokemon_t* pokemon1, pokemon_t* pokemon2, pokemon_t* pokemon3, torneo_t* torneo){

    int leidos;
    leidos = fscanf(archivo_entrenadores, "%[^;];%[^;];%i;%i;%i;%[^;];%i;%i;%i;%[^;];%i;%i;%i\r\n",
                    entrenador1->nombre,
                    pokemon1->nombre, &pokemon1->fuerza, &pokemon1->agilidad, &pokemon1->inteligencia,
                    pokemon2->nombre, &pokemon2->fuerza, &pokemon2->agilidad, &pokemon2->inteligencia,
                    pokemon3->nombre, &pokemon3->fuerza, &pokemon3->agilidad, &pokemon3->inteligencia);
    if(leidos   ==   ERROR){
        return NO_QUEDAN_MAS_ENTRENADORES;
    }//Si leidos me devuelve -1 es porque no quedan más entrenadores

    return leidos;
}

/*
 * Pre: Recibir el archivo avierto en lectura y un torneo valido
 * Pos: Cargar todos los entrenadores y pokemones en el torneo (Estan todos en el heap)
 * Devuelve -1 si hubo algun error y 0 si fue todo bien
 * */
int cargar_entrenadores(FILE* lector, torneo_t *torneo){
    entrenador_t entrenador_aux;
    pokemon_t pokemon[MAX_POKEMON];
    int leidos;

    leidos  =    cargar_una_linea(lector, &entrenador_aux, &pokemon[0], &pokemon[1], &pokemon[2], torneo);
    if(leidos   ==  NO_QUEDAN_MAS_ENTRENADORES){
        return EXITO;
    }//Preguntar que hago si hay un solo entrenador
    else if(leidos  !=  CANTIDAD_DE_ELEMENTOS_ENTRENADOR_MAS_POKEMON){
        return ERROR;
    }

    torneo->entrenadores    =   reservar_memoria_entrenador(torneo);
    if(torneo->entrenadores ==  NULL){
        return ERROR;
    }

    torneo->entrenadores[torneo->cantidad_entrenadores].pokemones    =   reservar_memoria_pokemon(&pokemon[0], &pokemon[1], &pokemon[2]);
    if(torneo->entrenadores[torneo->cantidad_entrenadores].pokemones ==  NULL){
        return ERROR;
    }
    strcpy(torneo->entrenadores[torneo->cantidad_entrenadores].nombre, entrenador_aux.nombre);
    torneo->cantidad_entrenadores++;

    int como_va=cargar_entrenadores(lector, torneo);
    if(como_va==EXITO){
        return EXITO;
    }
    return ERROR;
}

/*
 * Pre: Recibir un archivo y un torneo valido
 * Pos: Entregar el torneo cargado
 * */
int procesar_el_archivo(char *archivo_entrenadores, torneo_t *torneo){
    FILE *lector = fopen(archivo_entrenadores, "r");
    if(lector   ==  NULL){
        return ERROR;
    }

    int resultado=cargar_entrenadores(lector, torneo);

    fclose(lector);
    return resultado;
}

torneo_t* torneo_crear(char *ruta_archivo){
    if(ruta_archivo ==  NULL){
        return NULL;
    }
    torneo_t* torneo    =   (torneo_t*) malloc(sizeof(torneo_t));
    if(torneo   ==  NULL){
        return NULL;
    }

    torneo->cantidad_entrenadores   =   0;
    torneo->ronda   =   0;
    torneo->entrenadores    =   NULL;
    int checkeador  =   procesar_el_archivo(ruta_archivo, torneo);
    if(checkeador ==  ERROR){
        torneo_destruir(torneo);
        return NULL;
    }

    return torneo;
}

int torneo_jugar_ronda(torneo_t* torneo, int (*ganador_batalla)(entrenador_t* ,entrenador_t*)){
    if(torneo  ==  NULL){
        return ERROR;
    }
    if(torneo->cantidad_entrenadores    <=  1){
        return ERROR;
    }
    if((*ganador_batalla)  ==  NULL){
        return ERROR;
    }

    int cantidad_final  =   torneo->cantidad_entrenadores/2;
    int hay_impar   =   torneo->cantidad_entrenadores%2;
    int posicion;
    int quien_gano;
    entrenador_t* entrenador =   (entrenador_t *) malloc((long unsigned int)(cantidad_final+hay_impar)*sizeof(entrenador_t));
    if(entrenador   ==  NULL){
        return ERROR;
    }

    for(int i=0; i  <   cantidad_final; i++){
        posicion    =   i*2;
        quien_gano   =   ganador_batalla(&torneo->entrenadores[posicion], &torneo->entrenadores[posicion+1]);
        memcpy(&entrenador[i], &torneo->entrenadores[posicion+quien_gano], sizeof(entrenador_t));
        if(quien_gano   ==  0){
            free(torneo->entrenadores[posicion+1].pokemones);
        }
        else{
            free(torneo->entrenadores[posicion].pokemones);
        }
    }
    if(hay_impar   >   0){
        posicion    =   posicion    +   2;
        memcpy(&entrenador[cantidad_final], &torneo->entrenadores[posicion], sizeof(entrenador_t));
        cantidad_final++;
    }

    torneo->cantidad_entrenadores   =   cantidad_final;
    free(torneo->entrenadores);
    torneo->entrenadores    =   entrenador;
    torneo->ronda++;
    return EXITO;

}

/*
 * Mostrará por pantalla el nombre de cada entrenador, junto a sus pokémones.
 * Dependiendo de la función enviada por parametros (la cual refiere a una batalla), mostrará
 * distintas caracteristicas de dichos pokémones.
 */
void torneo_listar(torneo_t* torneo, void (*formatear_entrenador)(entrenador_t*)){
    if(torneo   !=  NULL    &&  (*formatear_entrenador) !=  NULL) {
        printf("Bienvenidos a la %d ronda del torneo Pokemon\n\n", torneo->ronda);
        for (int i = 0; i < torneo->cantidad_entrenadores; i++) {
            printf("Nombre de entrenador: %s\n", torneo->entrenadores[i].nombre);
            (*formatear_entrenador)(&torneo->entrenadores[i]);
        }
    }
}

/*
 * Destruirá la estructura del torneo, liberando la memoria reservada para él y los entrenadores.
 */
void torneo_destruir(torneo_t* torneo){
    if(torneo   !=  NULL){
        if(torneo->entrenadores !=  NULL){
            for(int i = 0; i < torneo->cantidad_entrenadores; i++){
                if(torneo->entrenadores[i].pokemones != NULL){
                    free(torneo->entrenadores[i].pokemones);
                }
            }
            free(torneo->entrenadores);
        }
        free(torneo);
    }
}


//
// Created by valentin.berne on 4/25/2020.
//