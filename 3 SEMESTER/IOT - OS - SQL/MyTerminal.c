#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>

#define MAX_LINE 80 // 80 chars per line, per command

char** div_args(char*); // Función (al final del programa) que divide la entrada del usuario
void free_args(char**); // Función (al final del programa) que libera la memoria usada en div_args

int main() {
    // Entrada del usuario
    char args[MAX_LINE/2 + 1];	// Línea de comandos (of 80) tiene máximo de 40 caracteres
    int should_run = 1; // Determina cuando salir del programa
    char* command; // Array de comandos ingresados por el usuario

    // Programa inicial
    while (should_run) {
        write(STDOUT_FILENO, "spiegel>", strlen("spiegel>")); // Imprimir el prompt
        read(STDIN_FILENO, args, MAX_LINE/2 + 1); // Leer el comando del usuario y almacenarlo en args

        // Elimina el carácter de nueva línea '\n' de la entrada del usuario
        args[strcspn(args, "\n")] = '\0';

        // Si el usuario escribe exit, termina
        if (strcmp(args, "exit") == 0) {
            should_run = 0;
        }

        // Fork un proceso del hijo
        pid_t pid = fork();

        // Error al crear el fork
        if (pid < 0) {
            fprintf(stderr, "Fork Failed");
            exit (-1) ;
        }

        // Se logró crear un hijo 
        else if (pid == 0) {
            // Proceso del hijo (Terminal como tal)
            // El proceso hijo ejecutará el comando ingresado por el usuario
            command = div_args(args);
            execvp(command[0], command);

            // Liberar memoria
            free_args(command);
            free(command);
        }

        // Proceso del padre
        else {
            // Padre espera a que el proceso del hijo termine y termina el programa
            wait(NULL);
        }
    }
    return 0;
}

// Función para dividir la entrada del usuario en argumentos
char** div_args(char* input) {
    char** args = malloc(sizeof(char*) * 10);
    char* token = strtok(input, " "); // Se divide la cadena en palabras divididas por espacios (apunta a primera palabra en la entrada)

    // Mientras haya palabras, se almacenan en el arreglo de argumentos
    int i = 0;
    while (token != NULL) {
        args[i] = token;
        token = strtok(NULL, " "); // Se usa NULL para seguir dividiendo la cadena e ir a la siguiente palabra
        i++;
    }
    args[i] = NULL;
    return args;
}

// Función para liberar la memoria de args en div_args
void free_args(char** args) {
    for (int i = 0; args[i] != NULL; i++) {
        free(args[i]);  // Libera cada palabra individual.
    }
    free(args);  // Libera el arreglo de punteros.
}