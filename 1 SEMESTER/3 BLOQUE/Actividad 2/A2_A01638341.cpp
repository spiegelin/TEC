/*
Actividad estructuras de control y funciones 

Diego Espejo 06/11/2022
*/
#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

float operaNumeros(float, float);
void numeroImpar();
int sumaPares();
float mediaAritmetica();
int numeroMagico(int&);
void conversionCelsiusFarenheit();
void serieAritmetica(int,int,int);
void mediasGeometricaArmonica();

int main(void){
    // Menú
    while(true){
        int opc;
        printf("\nBienvenido al menú de opciones, escoja una porfavor: \n");
        printf("1. operaNumeros \n2. numeroImpar \n3. sumaPares \n4. mediaAritmetica \n5. numeroMagico \n6. conversionCelsiusFarenheit \n7. serieAritmetica \n8. mediasGeometricaArmonica \n0. Salir\n");
        printf("Escoja una opción: "); cin >> opc;

        switch(opc) {
            case 0: {
                return 1;
            }
            case 1: {
                float num1, num2;
                printf("\nIngrese el primer número: "); cin >> num1;
                printf("Ingrese el segundo número: "); cin >> num2;
                printf("Resultado: %f\n", operaNumeros(num1, num2));
                break;
            }
            case 2: {
                numeroImpar();
                break;
            }
            case 3: {
                printf("La suma de los números enteros pares del 0 al 100 es de: %i\n", sumaPares());
                break;
            }
            case 4: {
                printf("Media: %f\n", mediaAritmetica());
                break;
            }
            case 5: {
                int intentos = 0;
                printf("Acertaste con el valor mágico %i después de %i intentos\n", numeroMagico(intentos), intentos);
                break;
            }
            case 6: {
                conversionCelsiusFarenheit();
                break;
            }
            case 7: {
                serieAritmetica(1, 3, 25);
                break;
            }
            case 8: {
                mediasGeometricaArmonica();
                break;
            }
            default:
                cout << "Elija una opción válida" << endl;
        }
    }
}

// Función 1
float operaNumeros(float num1, float num2) {
    char opc;
    printf("<S> Suma de dos números \n<R> Resta del primero menos el segundo \n<M> Multplicación\n");
    printf("Escoja una opción: "); cin >> opc; toupper(opc);

    switch(opc) {
        case 'S':
            return num1 + num2;
        case 'R':
            return num1 - num2;
        case 'M':
            return num1 * num2;
        default:
            printf("No es correcto \n");
            return 1;

    }
}

// Función 2
void numeroImpar(void) {
    int num;
    do {
        printf("\nIngrese un número: "); cin >> num;
    } while (num % 2 == 0);
}

// Función 3
int sumaPares(void) {
    int suma = 0;
    for (int i = 0; i<=100; i++) {
        if (i % 2 == 0) {
            suma = suma + i;
        }
    }
    return suma;
}

// Función 4
float mediaAritmetica(void) {
    int lim;
    int suma = 0;
    printf("\nNúmeros a introducir: "); cin >> lim;

    for (int i = 0; i < lim; i++) {
        float num;
        printf("Ingrese el número %i: ", i+1); cin >> num;
        suma = suma + num;
    }

    return (suma / (float)lim);
}

// Función 5
/*
Inicia  generando  un  número  aleatorio  entero  positivo  entre  1  y  100.  Después,  se 
solicita al usuario digite un número en el mismo rango. Dentro de un ciclo, se orientará al usuario con 
letreros  “MÁS”  o  “MENOS”  para  llevarlo  a  introducir  nuevos  valores  hasta  que,  en  algún  intento,  
introduzca el valor coincida con el valor aleatorio original. El código también deberá llevar la cuenta 
de intentos requeridos para llegar al valor buscado. Al terminar el ciclo, la función deberá desplegar: 
“Acertaste con el valor mágico X después de Y intentos”.  
*/
int numeroMagico(int& intentos){
    int num_aleatorio = (rand()%(100-2) + 1), adivina = 0;
    
    do {
        printf("\nIngrese un número: "); cin >> adivina;

        if (adivina > num_aleatorio) {
            printf("MENOS\n");
        } else {
            printf("MÁS\n");
        }
        intentos++;
    } while (adivina != num_aleatorio);
    return num_aleatorio;
}

// Función 6
void conversionCelsiusFarenheit() {
    float celsius, farenheit, incremento; int conversiones;
    printf("Valor inicial en Celsius: "); cin >> celsius;
    printf("Número de conversiones: "); cin >> conversiones;
    printf("Incremento: "); cin >> incremento;

    for (int i = 0; i < conversiones; i++) {
        farenheit = ((9.0/(float)5.0)*celsius + 32) + farenheit;
        celsius = celsius + incremento;
        printf("Farenheit\t Celsius\n %f\t %f\n", farenheit, celsius); 
    }
}

// Función 7
/*
Una  serie  aritmética  permite  modelar  diferentes  problemas  que  pueden  modelar 
fenómenos físicos y se define por:

a + (a+d) + (a + 2d) + (a + 3d) + ... + [a + (n-1)d]

Donde a es el primer término, d es la “diferencia común” y n es el número de términos que se van 
a sumar. Usando esta información, diseña e implementa una función en C++ que use un ciclo para 
desplegar cada término y para determinar la suma de la serie aritmética, si se tiene que a = 1, d = 
3 y n = 25
*/
void serieAritmetica(int a = 1, int d = 3, int n = 25) {
    int suma = 0;
    for (int i = 0; i < 25; i++) {
        suma = (a + i*d) + suma;
        printf("Término %i: %i\n", i + 1, suma);
    }
    printf("Valor total de la serie: %i\n", suma);
}

// Función 8
// Media geométrica = nsqrt(x1*x2*...*xn)
// Media armónica = n / [(1 / x1) + (1 / x2) + ... + (1 / xn)]
// Al teclear 0 se acaban ambas medias
void mediasGeometricaArmonica(void) {
    printf("\n");
    int n = 0, x, multi_geometrica = 1;
    float media_geometrica = 0, suma_armonica = 0, media_armonica = 0;
    while (true) {
        printf("x%i: ", n+1); cin >> x;
        if (x == 0) {
            break;
        } else {
            multi_geometrica = x * multi_geometrica;
            suma_armonica = (1/(float)x) + suma_armonica;
            n++;
        } 
    }
    media_geometrica = pow(multi_geometrica, (1/(float)n));
    media_armonica = n / (float)(suma_armonica);

    printf("Media Geométrica: %f \nMedia Armónica: %f\n", media_geometrica, media_armonica);
}