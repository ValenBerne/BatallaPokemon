#include <stdio.h>
#include <stdlib.h>
#include "batallas.h"
#define NO_QUEDAN_MAS_ENTRENADORES 100

/*
 * Reservo el espacio de memoria para el Entrenador y sus Pokemon
 * devuelvo el resultado del malloc, si es NULL es porque hubo un error
 * */
entrenador_t* reservar_memoria_entrenador(){
    //Creo un puntero
    entrenador_t* entrenador_base    =   NULL;
    //Reservo memoria para el entrenador
    entrenador_base  =   (entrenador_t *) malloc(sizeof(entrenador_t));

    if(entrenador_base   ==  NULL){
        return NULL;
    }

    //Reservo memoria para los Pokemon
    entrenador_base->pokemones  =   (pokemon_t *) malloc(sizeof(pokemon_t[3]));

    if(entrenador_base->pokemones   ==  NULL){
        return NULL;
    }

    return entrenador_base;
}

/*
 * Cargo 1 entrenador (1 linea en el txt)
 * */
int cargar_una_linea(FILE* archivo_entrenadores, entrenador_t* entrenador1){
    //Reservo el espacio en memoria para el entrenador
    entrenador1  =   reservar_memoria_entrenador();
    //Si me devuelve un NULL, no lo pudo reservar, devuelvo error
    if(entrenador1  ==  NULL) {
        return ERROR;
    }

    //Creo variables de los datos del entrenador y los pokemones, y se las asigno
    //Nombre del entrenador
    //char nombre_entrenador[MAX_NOMBRE];
    //Datos Pokemon 1
    //char nombre_p1[MAX_NOMBRE];
    int fuerza_p1;
    int agilidad_p1;
    int inteligencia_p1;
    //Datos Pokemon 2
    //char nombre_p2[MAX_NOMBRE];
    int fuerza_p2;
    int agilidad_p2;
    int inteligencia_p2;
    //Datos Pokemon 3
    //char nombre_p3[MAX_NOMBRE];
    int fuerza_p3;
    int agilidad_p3;
    int inteligencia_p3;

    // -> cuando es un puntero
    // . cuando es una constante
    int leidos  =   fscanf(archivo_entrenadores,"%[^;];%[^;];%i;%i;%i;%[^;];%i;%i;%i;%[^;];%i;%i;%i\r\n",
                             entrenador1->nombre,
                             entrenador1->pokemones[0].nombre, &fuerza_p1, &agilidad_p1, &inteligencia_p1,
                             entrenador1->pokemones[1].nombre, &fuerza_p2, &agilidad_p2, &inteligencia_p2,
                             entrenador1->pokemones[2].nombre, &fuerza_p3, &agilidad_p3, &inteligencia_p3);
    if(leidos   ==   ERROR){
        free(entrenador1);
        return NO_QUEDAN_MAS_ENTRENADORES;
    }//Si leidos me devuelve -1 es porque no quedan más entrenadores

    //Inicializo los datos del entrenador en el Fscanf
    //Inicializo los datos del Pokemon 1
    entrenador1->pokemones[0].fuerza   =   fuerza_p1;
    entrenador1->pokemones[0].agilidad   =   agilidad_p1;
    entrenador1->pokemones[0].inteligencia   =   inteligencia_p1;
    //Inicializo los datos del Pokemon 2
    entrenador1->pokemones[1].fuerza   =   fuerza_p2;
    entrenador1->pokemones[1].agilidad   =   agilidad_p2;
    entrenador1->pokemones[1].inteligencia   =   inteligencia_p2;
    //Inicializo los datos del Pokemon 3
    entrenador1->pokemones[2].fuerza   =   fuerza_p3;
    entrenador1->pokemones[2].agilidad   =   agilidad_p3;
    entrenador1->pokemones[2].inteligencia   =   inteligencia_p3;

    return leidos;
}

/*
 * Cargo los entrenadores (TENGO QUE CREAR UN MALLOC POR CADA UNO?)
 * Devuelvo un puntero al torneo con los entrenadores cargados
 * */
int cargar_entrenadores(char *archivo_entrenadores, torneo_t *torneo){

    //Apertura del archivo
    FILE *lector;
    lector = fopen(archivo_entrenadores, "r");

    //Procesamiento del archivo
    //Tengo que recorrer todas las lineas hasta que no queden más
    int leidos  =   13;

    do{
        //Leo y cargo un entrenador, si me tira
         leidos =    cargar_una_linea(lector, &torneo->entrenadores[torneo->cantidad_entrenadores]);

        //Le sumo uno a la cantidad de entrenadores
        if(leidos   ==  13){
            torneo->cantidad_entrenadores++;
        }

    }while(leidos   ==  13);

    if(ERROR == leidos &&  torneo->cantidad_entrenadores  ==  0){
        return ERROR;
    }

    //Cierro del archivo
    fclose((FILE *) archivo_entrenadores);
    printf("Nombre del primer entrenador: %s\n", torneo->entrenadores[0].nombre);

    return EXITO;
}

/*
 * Creará la estructura torneo_t, reservando la memoria necesaria para el mismo.
 * Devolverá un puntero a un torneo, en el cual los participantes ya estarán cargados.
 * En caso de no poder crearlo, o que la ruta del archivo no sea válida, devolverá NULL.
 */
torneo_t* torneo_crear(char *ruta_archivo){

    //Creo un puntero
    torneo_t* torneo    =   NULL;
    //Reservo memoria para el torneo
    torneo  =   (torneo_t*) malloc(sizeof(torneo_t));
    //Si no pude reservar la memoria para el torneo, devuelvo NULL
    if(torneo   ==  NULL){
        return NULL;
    }

    //Inicializo la ronda
    torneo->ronda   =   0;
    //Inicializo la cantidad minima de entrenadores
    torneo->cantidad_entrenadores   =   0;
    //Inicializo los entrenadores
    torneo->entrenadores    =   NULL;
    //Depende que me devuelva cargar entrenadores, depende como fue
    int checkeador  =   cargar_entrenadores(ruta_archivo, torneo);
    //Si tuve algun error, devolví el entrenador vacio
    if(checkeador ==  ERROR){
        free(torneo);
        return NULL;
    }

    //Si va bien, devuelvo el torneo
    return torneo;

}


/*
 * Hará competir a los entrenadores, dejando en la siguiente ronda al ganador de la batalla.
 * El entrenador de la posición 0, lucha contra el de la posición 1, el de la 2 contra el de
 * la 3, etc.
 * Cuando un entrenador no tiene con quien luchar (cantidad impar de entrenadores en esa ronda)
 * pasa directamente a la siguiente.
 * El vector de entrenadores quedará solo con aquellos que ganaron la batalla (su tamaño se
 * ajustará luego de cada ronda).
 * Devolverá 0 si se jugó exitosamente, o -1 en caso contrario.
 * Si en el torneo hay sólo un entrenador, no se puede jugar y la funcion devuelve -1.
 */
/*int torneo_jugar_ronda(torneo_t* torneo, int (*ganador_batalla)(entrenador_t* ,entrenador_t*)){
    if(torneo->cantidad_entrenadores    <=  1){
        return ERROR;
    }


}*/

/*
 * Mostrará por pantalla el nombre de cada entrenador, junto a sus pokémones.
 * Dependiendo de la función enviada por parametros (la cual refiere a una batalla), mostrará
 * distintas caracteristicas de dichos pokémones.
 */
//void torneo_listar(torneo_t* torneo, void (*formatear_entrenador)(entrenador_t*));

/*
 * Destruirá la estructura del torneo, liberando la memoria reservada para él y los entrenadores.
 */
void torneo_destruir(torneo_t* torneo){
    printf("Entro a liberar\n");
    printf("Cantidad de entrenadores adentro de destruir: %d\n", torneo->cantidad_entrenadores);
    for(int i = 0; i <   torneo->cantidad_entrenadores; i++){
        printf("Valor de I: %d\n", i);
        free(&torneo->entrenadores[i].pokemones[0]);
        free(&torneo->entrenadores[i].pokemones[1]);
        free(&torneo->entrenadores[i].pokemones[2]);
        printf("Valor de I: %d\n", i);
    }
    free(torneo->entrenadores);
    printf("Libero");
    free(torneo);
}


//
// Created by valentin.berne on 4/25/2020.
//