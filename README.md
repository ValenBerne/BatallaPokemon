# BatallaPokemon

Como funciona el trabajo:
Torneo Crear: Reservo la memoria del torneo, lo inicializo y mando a "Cargar_entrenadores" a que cargue los entrenadores.
Cargar entrenadores: abre el archivo, lo procesa y lo cierra. Crea dos variables en el stack, una de pokemon_t y otra de entrenador_t
Para cargar cada linea de entrenadores llama a "cargar_una_linea", las guarda en las variables del stack y si no es NULL las pasa al heap.
Para reservar memoria para los poquemones llama a reservar_memoria_pokemon. En cambio para la del entrenador, lo hace en el lugar
(Lo sé, lo debería modularizar, pero antes estoy intentando que ande, ya trate de modularizarla).

Torneo_jugar_ronda: Es un for que recorre los entrenadores y los manda a la funcion por parametro a que se enfrenten. Después los guarda
en una funcion en el stack que después pasamos al heap.

Torneo_listar: Es un for que recorre los entrenadores, printea su nombre y llama a la funcion por parametro para que printee a los
Pokemon de ese entrenador.

Torneo destruir: Hago un for para recorrer todos los entrenadores y pokemones, liberandolos.

2)Compilalo y ejecutalo con un IDE, porque estoy usando la computadora del trabajo, pero deberían correr con las que dice el PDF.

3)Puntero: La dirección de memoria de algo. Paso un puntero del Torneo en el "Cargar_Entrenadores". 
Aritmética de punteros: Sabiendo la direccion de memoria de algo, te moves N lugares sabiendo la cantidad de memoria que ocupa lo que estás salteando. 
Por ejemplo sabiendo la direccion del primer lugar de un vector, a ese punero le sumas lo que ocupa en memoria N lugares del vector. 
Todavía no lo use 
Punteros a funciones: Pasar por una variable la funcion con la que queres que se haga algo. Lo voy a usar en el torneo jugar ronda. 
Malloc: Te guarda en el heap una X cantidad de memoria. Lo use cuando guarde memoria para el Torneo y para los Pokemon.
Realloc: Te cambia la cantidad de memoria que tenes guardada en el heap por un malloc. Lo uso cuando agrando la cantidad de entrenadores.


http://tps.algoritmos7541mendez.com.ar/students/assignment/2/list/
