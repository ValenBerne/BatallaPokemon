#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "batallas.h"
#define NO_QUEDAN_MAS_ENTRENADORES 100
#define ERROR_AL_ABRIR_EL_ARCHIVO 200
#define ERROR_RESERVANDO_MEMORIA_ENTRENADOR 201
#define ERROR_RESERVANDO_MEMORIA_POKEMON 202
#define ERROR_REALOCANDO_MEMORIA_ENTRENADOR 203
#define MAX_POKEMON 3
#define CANTIDAD_DE_ELEMENTOS_ENTRENADOR_MAS_POKEMON 13
#define MAX_MAX 100000

/*
 * Reservo el espacio de memoria para el Entrenador y sus Pokemon
 * devuelvo el resultado del malloc, si es NULL es porque hubo un error
 * */
entrenador_t* reservar_memoria_entrenador(long unsigned int cantidad_de_entrenadores, torneo_t* torneo){
    //Creo un puntero
    entrenador_t* entrenador_base = NULL;

    //Modifico el tamaño de la memoria del entrenador
    realloc(&torneo->entrenadores, (long unsigned int)cantidad_de_entrenadores*sizeof(entrenador_t));
    entrenador_base =   torneo->entrenadores;

    if (entrenador_base == NULL) {
        return NULL;
    }
    return entrenador_base;
}

pokemon_t* reservar_memoria_pokemon(pokemon_t*   pokemon1,   pokemon_t*   pokemon2,   pokemon_t*   pokemon3){
    //Creo un puntero
    pokemon_t* pokemon  =   NULL;
    //Reservo memoria para los Pokemon
    pokemon  =   (pokemon_t *) malloc(3*sizeof(pokemon_t));

    //Checkeo que no me de un error
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
 * Cargo 1 entrenador (1 linea en el txt)
 * */
int cargar_una_linea(FILE* archivo_entrenadores, entrenador_t* entrenador1, pokemon_t* pokemon1, pokemon_t* pokemon2, pokemon_t* pokemon3){

    // -> cuando es un puntero
    // . cuando es una constante
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
 * Devuelvo un puntero al torneo con los entrenadores cargados
 * */
int cargar_entrenadores(char *archivo_entrenadores, torneo_t *torneo){

    //Apertura del archivo
    FILE *lector;
    lector = fopen(archivo_entrenadores, "r");
    if(lector   ==  NULL){
        return ERROR_AL_ABRIR_EL_ARCHIVO;
    }

    //Procesamiento del archivo
    //Tengo que recorrer todas las lineas hasta que no queden más
    int leidos;
    entrenador_t entrenador;
    pokemon_t pokemon[MAX_POKEMON];
    leidos  =   cargar_una_linea(lector, &entrenador, &pokemon[0], &pokemon[1], &pokemon[2]);
    if(leidos   !=  CANTIDAD_DE_ELEMENTOS_ENTRENADOR_MAS_POKEMON){
        return ERROR;
    }

    torneo->entrenadores = (entrenador_t *) malloc(sizeof(entrenador_t));
    if (torneo->entrenadores == NULL) {
        return ERROR_RESERVANDO_MEMORIA_ENTRENADOR;
    }

    torneo->entrenadores[torneo->cantidad_entrenadores].pokemones    =   reservar_memoria_pokemon(&pokemon[0], &pokemon[1], &pokemon[2]);
    printf("%d\n", torneo->entrenadores[torneo->cantidad_entrenadores].pokemones[2].fuerza);
    if(torneo->entrenadores[torneo->cantidad_entrenadores].pokemones ==  NULL){
        return ERROR_RESERVANDO_MEMORIA_POKEMON;
    }
    printf("%s\n", torneo->entrenadores[torneo->cantidad_entrenadores].pokemones[2].nombre);

    strcpy(torneo->entrenadores[torneo->cantidad_entrenadores].nombre, entrenador.nombre);
    printf("%s\n", torneo->entrenadores[torneo->cantidad_entrenadores].nombre);

    torneo->cantidad_entrenadores++;

    do{
        leidos  =   cargar_una_linea(lector, &entrenador, &pokemon[0], &pokemon[1], &pokemon[2]);
        if(leidos   ==  ERROR){
            return ERROR;
        }

        entrenador_t* entrenador_aux  =   realloc(torneo->entrenadores, (long unsigned int)(torneo->cantidad_entrenadores+1)*sizeof(entrenador_t));
        if(entrenador_aux   ==  NULL){
            return ERROR_REALOCANDO_MEMORIA_ENTRENADOR;
        }
        else{
            //entrenador_t*   aux2    =   torneo->entrenadores;
            free(torneo->entrenadores);
            torneo->entrenadores  =   entrenador_aux;
            //free(&aux2);
        }

        torneo->entrenadores[torneo->cantidad_entrenadores].pokemones    =   reservar_memoria_pokemon(&pokemon[0], &pokemon[1], &pokemon[2]);
        printf("%d\n", torneo->entrenadores[torneo->cantidad_entrenadores].pokemones[2].fuerza);
        if(entrenador.pokemones ==  NULL){
            return ERROR_RESERVANDO_MEMORIA_POKEMON;
        }
        printf("%s\n", torneo->entrenadores[torneo->cantidad_entrenadores].pokemones[2].nombre);

        strcpy(torneo->entrenadores[torneo->cantidad_entrenadores].nombre, entrenador.nombre);
        printf("%s\n", torneo->entrenadores[torneo->cantidad_entrenadores].nombre);

        torneo->cantidad_entrenadores++;

    }while(leidos   ==  CANTIDAD_DE_ELEMENTOS_ENTRENADOR_MAS_POKEMON);

    //Cierro del archivo
    fclose((FILE *) archivo_entrenadores);

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

    //Inicializo la cantidad minima de entrenadores
    torneo->cantidad_entrenadores   =   0;
    //Inicializo los entrenadores
    torneo->entrenadores    =   NULL;
    //Depende que me devuelva cargar entrenadores, depende como fue
    int checkeador  =   cargar_entrenadores(ruta_archivo, torneo);
    //Si tuve algun error, devolví el entrenador vacio
    if(checkeador ==  ERROR_AL_ABRIR_EL_ARCHIVO ||  checkeador  ==  ERROR_RESERVANDO_MEMORIA_ENTRENADOR ||  checkeador  ==  ERROR_RESERVANDO_MEMORIA_POKEMON){
        free(torneo);
        return NULL;
    }
    //Inicializo la ronda
    torneo->ronda   =   0;

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
int torneo_jugar_ronda(torneo_t* torneo, int (*ganador_batalla)(entrenador_t* ,entrenador_t*)){
    if(torneo->cantidad_entrenadores    <=  1){
        return ERROR;
    }

    int cantidad_final  =   torneo->cantidad_entrenadores/2;
    int hay_impar   =   torneo->cantidad_entrenadores%2;
    cantidad_final  =   cantidad_final  +   hay_impar;
    int quien_gano[MAX_MAX];
    entrenador_t entrenador[MAX_MAX];

    for(int i=0; i  <   cantidad_final; i++){
        if(i    ==  cantidad_final-1    &&  hay_impar   >   0){
            //El impar
            quien_gano[cantidad_final-1]    =   0;
            //Doble i para establecer la posicion
            entrenador[i]  =   torneo->entrenadores[i+i];
        }
        else{
            //El resto
            int posicion    =   i   +   i;  //Tengo que duplicar I porque le sumo 1 por cada 2 que analizo
            //Si gano el primero guardo 0, si gano el segundo guardo 1
            quien_gano[i]   =   (*ganador_batalla)(&torneo->entrenadores[posicion], &torneo->entrenadores[posicion+1]);
            //posicion para establecer el lugar del vector + Le sumo quien gano, porque si gano el primero ya esta bien,
            //pero si gano el segundo, se suma uno
            entrenador[i]  =   torneo->entrenadores[posicion+quien_gano[i]];
        }
    }

    entrenador_t* entrenador_aux    =   (entrenador_t *) malloc((long unsigned int)cantidad_final*sizeof(entrenador_t));
    if(entrenador_aux   ==  NULL){
        return ERROR;
    }

    for(int i=0; i<cantidad_final; i++){
        memcpy(entrenador_aux, entrenador, (long unsigned int)cantidad_final*sizeof(entrenador_t));
        free(torneo->entrenadores);
        torneo->entrenadores    =   entrenador_aux;
    }

    return EXITO;

}

/*
 * Mostrará por pantalla el nombre de cada entrenador, junto a sus pokémones.
 * Dependiendo de la función enviada por parametros (la cual refiere a una batalla), mostrará
 * distintas caracteristicas de dichos pokémones.
 */
void torneo_listar(torneo_t* torneo, void (*formatear_entrenador)(entrenador_t*)){
    printf("Bienvenidos a la %d ronda del torneo Pokemon\n\n", torneo->ronda);
    for(int i=0; i<torneo->cantidad_entrenadores; i++){
        printf("Nombre de entrenador: %s\n", torneo->entrenadores[i].nombre);
        (*formatear_entrenador)(&torneo->entrenadores[i]);
        /*printf("Con sus Pokemon:\n");
        printf("%s: que tiene de fuerza %d, de agilidad %d y de inteligencia %d",
                torneo->entrenadores[i].pokemones[0].nombre, torneo->entrenadores[i].pokemones[0].fuerza,
               torneo->entrenadores[i].pokemones[0].agilidad, torneo->entrenadores[i].pokemones[0].inteligencia);
        printf("%s: que tiene de fuerza %d, de agilidad %d y de inteligencia %d",
               torneo->entrenadores[i].pokemones[1].nombre, torneo->entrenadores[i].pokemones[1].fuerza,
               torneo->entrenadores[i].pokemones[1].agilidad, torneo->entrenadores[i].pokemones[1].inteligencia);
        printf("%s: que tiene de fuerza %d, de agilidad %d y de inteligencia %d",
               torneo->entrenadores[i].pokemones[2].nombre, torneo->entrenadores[i].pokemones[2].fuerza,
               torneo->entrenadores[i].pokemones[2].agilidad, torneo->entrenadores[i].pokemones[2].inteligencia);*/
    }
}

/*
 * Destruirá la estructura del torneo, liberando la memoria reservada para él y los entrenadores.
 */
void torneo_destruir(torneo_t* torneo){
    for(int i = 0; i <   torneo->cantidad_entrenadores; i++){
        free(&torneo->entrenadores[i].pokemones);
    }
    free(torneo->entrenadores);
    free(torneo);
}


//
// Created by valentin.berne on 4/25/2020.
//