# El regreso de los Madafanes

Este proyecto contiene el código fuente de un juego de aventura desarrollado en C++. El juego se centra en la lucha contra los trolls negros conocidos como Madafanes, con el objetivo de liberar los mundos de su opresión y restaurar la paz. El jugador asume el papel de un valiente guerrero y debe interactuar con diferentes personajes y explorar diversos mundos para cumplir su misión.

## Clases principales
- Mundo: Representa un mundo dentro del juego. Cada mundo tiene un nombre, una descripción y puede contener un item y un personaje.
- Item: Representa un objeto que puede ser recolectado por el jugador. Cada item tiene un nombre, una descripción y puede otorgar puntos de vida.
- Personaje: Clase base (abstracta) para los personajes del juego. Tiene los atributos de nombre, descripción y puntos de vida.
    - PersonajeGuerrero: Puede atacar a otros personajes y recibir ataques.
    - PersonajeAmistoso: Puede interactuar con el jugador y otorgar beneficios.

## Flujo del juego
- El juego comienza con una introducción y solicita al jugador que ingrese su nombre.
- Se crean los mundos, los items y los personajes secundarios.
- El jugador se crea como un personaje guerrero.
- Se muestra la historia introductoria.
- Comienza el bucle principal del juego.
- El jugador interactúa con el mundo actual, ya sea atacando a enemigos o interactuando con personajes amistosos.
- Dependiendo de la interacción, se actualiza la salud y el estado de los personajes.
- Si el jugador muere, el juego termina y se muestra un mensaje de derrota.
- Si el jugador completa el último mundo y derrota al personaje final, el juego termina y se muestra un mensaje de victoria.


## Descripción básica de la carpeta Proyecto

*Dentro de la carpeta Proyecto agrega los archivos necesarios para la solución de tu proyecto, no olvides que para compilar debes moverte a la carpeta Proyecto con el comando cd assignments/Proyecto*

La carpeta contiene el código fuente y el archivo de construcción ```make```.

La carpeta `build` contiene el codigo binario generado por el archivo de construcción ```make```.

Consulta el archivo assignments/README.md para instrucciones sobre la compilación y ejecución del proyecto.
