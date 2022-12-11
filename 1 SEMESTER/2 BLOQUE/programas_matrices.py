'''
Programas que utilizan matrices (listas de listas)

Diego Espejo 07/10/2022
'''
def matriz_consecutiva():
    '''
    Realiza un programa que cree una matriz de n renglones (número de listas) y m columnas (número de elementos) que deberá estar llena de 
    números consecutivos por renglón comenzando por 1.
    n x m
    '''
    n = int(input())
    m = int(input())

    if n < 2 and m < 2:
        print("Error")
    else:
        matriz = []
        num = 1
        for i in range(n):
            elemento = []
            for j in range(m):
                elemento.append(num)
                num += 1
            matriz.append(elemento)
    return matriz

print(matriz_consecutiva())      

'''
Escribe un programa que pida al usuario el tamaño de una matriz cuadrada n y luego cree una matriz con n renglones, 
cada renglón debe tener n datos con el número correspondiente al número de renglón. Observa el ejemplo. 

Crea dos funciones: 
1) una función crea_matriz_numeros que recibe el tamaño de la matriz y crea la matriz con los números, y
2) una función muestra_matriz que muestra en la pantalla los elementos en forma de matriz 

n x n
'''
def crea_matriz_numeros(tamaño = 3):
    matriz = []
    for i in range(tamaño):
        elemento = []
        for j in range(tamaño):
            elemento.append(i)
        matriz.append(elemento)

    matriz = muestra_matriz(matriz)
            
def muestra_matriz(matriz):
    for i in range(len(matriz)):
        for j in range(len(matriz)):
           print(matriz[i][j], end=" ")
        print("\n", end="")

crea_matriz_numeros(4)

def determinante(a, b, c, d):
    '''
    Desarrolla una función que reciba una matriz de números enteros de tamaño 2x2 y calcule su determinante.
    El determinante de una matriz es un número real asociado a una matriz cuadrada.
    Para una matriz de tamaño 2x2 el determinante se calcula de la siguiente forma:

    | a   b |
    | c   d |
    determinante = a*d - c*b
    '''
    determinante = a*d - c*b
    return determinante
    
def main():
    '''
    Escribe ahora otra función que pida los valores de los dos renglones de la matriz y la cree.
    Después escribe la función main que debe construir la matriz y posteriormente calcular el determinante llamando las funciones 
    que creaste.

    En caso de que la matriz no corresponda a una matriz de 2X2 deberá desplegar el mensaje "La matriz no es una matriz de 2x2".
    '''
    x = input().split()
    y = input().split()
    a,b,c,d  = int(x[0]), int(x[1]), int(y[0]), int(y[1])

    if len(x) > 2 or len(x) <= 1:
        print("La matriz no es una matriz de 2x2")
    else:
        print(determinante(a, b, c, d))
    
main()

def pares_renglon(matriz):
    '''
    Desarrolla una función que reciba una matriz de números enteros y regrese como valor de retorno una lista con la cantidad de números 
    pares que se encuentran en cada renglón.
    '''
    enteros = [0 for i in range(len(matriz))] # Crear matriz de ceros según la cantidad de renglones en la matriz original
    for i in range(len(matriz)):
        for j in range(len(matriz[0])):
            if matriz[i][j] % 2 == 0:
                enteros[i] += 1
    return enteros
   
def main2():
    '''
    La función main deberá leer los datos: cantidad de renglones, cantidad de columnas y los valores de cada una de las casillas de la 
    matriz. Llamar a la función, la cual le regresará una lista con la cantidad de valores pares en cada renglón y mostrar la lista.
    '''   
    renglones = int(input())
    columnas = int(input())

    matriz = []
    for i in range(renglones):
        elemento = []
        for j in range(columnas):
            elemento.append(int(input()))
        matriz.append(elemento)
    print(pares_renglon(matriz))

main2()

def suma_matriz():
    '''
    Escribe un programa que pregunte el número de renglones y número de columnas de una matriz, después pregunte cada número de la 
    matriz y regrese una lista con la suma de cada columna de la matriz.
    '''
    renglones = int(input())
    columnas = int(input())

    if renglones < 1 or columnas < 1:
        print("Error")
    else:
        matriz = []
        for i in range(renglones):
            elemento = []
            for j in range(columnas):
                elemento.append(int(input()))
            matriz.append(elemento)

        suma = [] 
        for i in range(columnas):
            sum = 0 
            for j in range(renglones):
                sum += matriz[j][i]
            suma.append(sum)

        print(suma)

suma_matriz()

def diagonal_principal():
    '''
    Desarrolla una función que reciba una matriz de números enteros y regrese como valor de retorno una lista con los elementos de la 
    diagonal principal (como lista).

    El programa deberá leer los datos: cantidad de renglones, cantidad de columnas y los valores de cada casilla de la matriz. 
    Llamar a la función, la cual le regresará una lista con los datos de la diagonal de la matriz y mostrar la lista. 
    En caso de que la matriz no sea una matriz cuadrada, deberá de mostrar el mensaje "la matriz no es cuadrada", esta verificación 
    se debe hacer al leer la cantidad de renglones y columnas, de modo que si la matriz no es cuadrada el programa ya no continúa. 
    '''
    renglones = int(input())
    columnas = int(input())
    
    if renglones < 1 or columnas < 1:
        print("Error")
    elif renglones != columnas:
        print("La matriz no es cuadrada")
    else:
        matriz = []
        for i in range(renglones):
            elemento = []
            for j in range(columnas):
                elemento.append(int(input()))
            matriz.append(elemento)

        diagonal = []
        for i in range(len(matriz)):
            diagonal.append(matriz[i][i])

        print(diagonal)
        
diagonal_principal()
