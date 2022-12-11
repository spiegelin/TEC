matriz = [
    # ____________ Columnas
    [1, 2, 3, 4, 5], # |
    [6, 7, 0, 0, 0], # | Renglón
    [0, 1, 0, 0, 0]  # |
]

# El primer for te permite cambiar de renglón |
# El segundo for te permite moverte en cada lista, o columnas -

ren = int(input("Dame el valor de los renglones: "))
col = int(input("Dame el valor de la columna: "))
matriz = []

# Llenado de Matriz
for renglon in range(ren):
    fila = []
    for columna in range(col):
        dato = int(input(f"Dame el valor {renglon} {columna}:"))
        fila.append(dato)
    matriz.append(fila)

# Opción de impresión 1
print(matriz)

# Opción 2
for renglon in matriz:
    for valor in renglon:
        print(valor, end=" ")
    print()

# Opción 3
print(*matriz, sep="\n") # Desempaqueta la matriz, (cada fila de la matriz por separado)

# Matriz de longitud dada por el usuario
ren = int(input("Dame el valor de los renglones: "))
col = int(input("Dame el valor de la columna: "))
matriz = []

for renglon in range(ren):
    fila = []
    for columna in range(col):
        dato = int(input("Dame el valor: "))
        fila.append(dato)
    matriz.append(fila)

# Funciones para imprimir
matriz = [
    # ____________ Columnas
    [1, 2, 3, 4, 5], # |
    [6, 7, 0, 0, 0], # | Renglón
    [0, 1, 0, 0, 0]  # |
]

def imprime_matriz(matriz):
    for renglon in range(len(matriz)):
        for columna in range(len(matriz[renglon])):
            print(matriz[renglon][columna], end=" ")
        print()
print("\n")
def imprime_elementos(matriz):
    for renglon in matriz:
        for valor in renglon:
            print(valor, end=" ")
        print()

imprime_matriz(matriz)
imprime_elementos(matriz)

# Sumando todos los elementos
matrix = [[1,2,3], [3,4,5], [10,12,1]]
total = 0
for row in matrix:
    for value in row:
        total += value

print(f"Total: {total}")

# Inicialización con números al azar
import random

matrix = []

rows = eval(input("Enter the number of rows: ")) # Evaluates the string given "(2 + 2)" = 4
columns = eval(input("Enter the number of columns: "))
for row in range(rows):
    matrix.append([])
    for column in range(columns):
        matrix[row].append(random.randint(0, 99))

print(matrix)

# Sumando por columna
matrix = [[1,2,3], [3,4,5], [10,12,1]]

for column in range(len(matrix[0])):
    total = 0
    for row in range(len(matrix)):
        total += matrix[row][column]
    print(f"The sum for column {column} is {total}")

# Función imprime matriz
def imprime_matriz(matriz):
    for renglon in matriz:
        for columna in renglon:
            print(f"{columna:3d}", end=" ")
        print()

# Función que suma todos los números de una matriz
def acumulado(matriz):
    acum = 0
    for renglon in matriz:
        acum += sum(renglon)
    return acum

answers = [
    ['A', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'],
    ['D', 'B', 'A', 'B', 'C', 'A', 'E', 'E', 'A', 'D'],
    ['E', 'D', 'D', 'A', 'C', 'B', 'E', 'E', 'A', 'D'],
    ['C', 'B', 'A', 'E', 'D', 'C', 'E', 'E', 'A', 'D'],
    ['A', 'B', 'D', 'C', 'C', 'D', 'E', 'E', 'A', 'D'],
    ['B', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'],
    ['B', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'],
    ['E', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D']]
 # Key to the questions
keys = ['D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D']
 # Grade all
for i in range(len(answers)):
     # Grade one student
     correctCount = 0
     for j in range(len(answers[i])):
         if answers[i][j] == keys[j]:
             correctCount += 1
     print("Student", i, " s correct count is", correctCount)
