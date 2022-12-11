'''
Programa donde el usuario ingrese una palabra y automáticamente calcule cuantos puntos son en total. 
Se deberá imprimir la palabra analizada y el número de puntos en la misma línea como lo muestra el ejemplo. 
Después, se le preguntará al usuario si quiere ingresar otra palabra o si prefiere salir. 
Al final imprimirá el promedio de puntos que se obtuvieron por cada palabra. 

En la versión en español de Scrabble tenemos que cada letra vale:

1 punto: A,E, O, S, I, U, N, L, R, T
2 puntos: C,D, G
3 puntos: M,B, P
4 puntos: F,H, V, Y
6 puntos: J
8 puntos: K,LL, Ñ, Q, W, X
10 puntos: Z

Diego Espejo 09/09/2022
'''
contador_puntos = 0 # Variable para puntos totales del usuario
puntos = 0 # Variable para almacenar los puntos de una sola palabra

while True:
    palabra = input("Ingresa una palabra: ")
    
    for i in palabra.upper(): # Se hace todo mayúscula en caso de que el usuario intercale entre Mayúsucla y Minúscula
        if i == "A" or i == "E" or i == "O" or i == "S" or i == "I" or i == "U" or i == "N" or i == "L" or i == "R" or i == "T":
            puntos += 1
        elif i == "C" or i == "D" or i == "G":
            puntos += 2
        elif i == "M" or i == "B" or i == "P":
            puntos += 3
        elif i == "F" or i == "H" or i == "V" or i == "Y":
            puntos += 4
        elif i == "J":
            puntos += 6
        elif i == "K" or i == "Ñ" or i == "Q" or i == "W" or i == "X":
            puntos += 8
        else:
            puntos += 10

    print(f"{palabra} vale {puntos} puntos")
    contador_puntos += puntos

    seguir = input("¿Desea continuar? (s/n): ")
        
    if seguir == "n":
        print(f"\nPuntos totales: {contador_puntos}")
        break
    else:
        puntos = 0 # Reiniciar el contador