'''
Llama a una función para generar una lista de 10 elementos con números random. 
Pregunta en el programa principal el tope para los números random y pásalo como parámetro. 
Crea una función llamada estadísticas que recibe una lista e imprima 
    - Cuál es el número máximo generado.
    - Cuál es el número mínimo.
    - Cuál es el promedio de los datos. 
    
Crea una función llamada adivina que recibirá una lista y preguntará al usuario un número. 
Si el número que ingresó el usuario está en la lista, el programa terminará e imprimirá "Atinaste!", 
si el usuario no acertó el número le pedirá números hasta que encuentre alguno y pueda terminar el programa.

Diego Espejo 30/09/2022
'''
from random import randint

def main():
    tope = int(input("Tope para números random: "))
    lista = lista_random(tope)
    estadistica = estadisticas(lista)
    adivinador = adivina(lista)

def lista_random(tope):
    lista = []
    for i in range(10): lista.append(randint(0,tope))
    return lista

def estadisticas(lista):
    maximo = max(lista)
    minimo = min(lista)
    promedio = sum(lista) / len(lista)

    print(f"Máximo: {maximo}, Mínimo: {minimo}, Promedio: {promedio}")

def adivina(lista):
    num = int(input("Número: "))
    while True:
        if num in lista:
            print("Atinaste")
            break
        else:
            num = int(input("Número: "))
   
main()
