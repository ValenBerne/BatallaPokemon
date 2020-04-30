# BatallaPokemon

1) Como funciona el trabajo:

Torneo Crear:
Reservo la memoria del torneo y mando a "Cargar_entrenadores" a que los cargue.
Cargar entrenadores: abre el archivo, lo procesa y lo cierra. Para cargar cada linea de entrenadores llama a "cargar_una_linea", que carga 1 entrenador (Pero antes pide reserva su lugar en memoria).

Torneo destruir: 
Hago un for para recorrer todos los entrenadores y pokemones, liberandolos.

2)Compilalo con:

Ejecutalo con:


3)Puntero: La dirección de memoria de algo. Paso un puntero del Torneo en el "Cargar_Entrenadores".
Aritmética de punteros: Sabiendo la direccion de memoria de algo, te moves N lugares sabiendo la cantidad de memoria que ocupa lo que estás salteando. Por ejemplo sabiendo la direccion del primer lugar de un vector, a ese punero le sumas lo que ocupa en memoria N lugares del vector. Todavía no lo use
Punteros a funciones: Pasar por una variable la funcion con la que queres que se haga algo. Lo voy a usar en el torneo jugar ronda.
Malloc: Te guarda en el heap una X cantidad de memoria. Lo use cuando guarde memoria para el Torneo y para los entrenadores.
Realloc: Te cambia la cantidad de memoria que tenes guardada en el heap por un malloc. Lo voy a usar cuando haga juegue una ronda.


http://tps.algoritmos7541mendez.com.ar/students/assignment/2/list/
