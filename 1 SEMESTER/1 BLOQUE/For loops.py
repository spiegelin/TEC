'''
Problemas que utilizan repeticiones

Diego Espejo 04/09/2022
'''
def cuenta_numeros():
    '''
    Escribe un programa que lea un número positivo n, e imprima todos los números en orden desde el 1 
    hasta n. Cada uno de los números debe ser impreso en una linea por separado.
    '''
    n = int(input("Número: "))

    for i in range(1, n + 1):
        print(i)


def suma_n_numeros(num):
    '''
    Escribe un método que reciba un número entero positivo n, después debe calcular la suma 1+2+3+...+n. 
    Finalmente regrese el resultado de la suma y sea impreso en pantalla.
    '''
    suma = 0
    for i in range(num+1):
        suma += i

    print(suma)

def promedio():
    '''
    Escribe un programa que primero lea el valor n, que es la cantidad de números que se van a promediar.
    Después debe leer los n números positivos (flotantes), promediarlos y mostrar el promedio.
    '''
    num = int(input("Números a promediar: "))
    promedio = 0

    for i in range(num):
        n = float(input(f"Promedio {i+1}: "))

        promedio += n

    print(f"Promedio: {promedio/num}")

def desde_a_hasta_b():
    '''
    Escribe un programa que pida los valores a y b y muestre una serie de números que va 
    desde a hasta b. Supón que a < b.
    '''
    a = int(input("a: "))
    b = int(input("b: "))

    for i in range(a, b+1):
        print(i, end = " ")

def regresiva_a_b():
    '''
    Escribe un programa que pida los valores a y b y muestre una cuenta regresiva de números que va 
    desde b hasta a. Supón que a < b.
    '''
    a = int(input("\na: "))
    b = int(input("b: "))

    for i in range(b, a - 1, -1):
        print(i, end = " ")

def rango_pares(a, b):
    '''
    Escribe un programa que lea los valores enteros a y b y muestre todos los números pares que se 
    encuentran desde a hasta b. Supón que a < b. Si a y/o b son pares, deben de ser incluidos. 
    El 0 es considerado par.
    '''
    for i in range(a, b+1):
        if i % 2 == 0:
            print(i)

def serie_5():
    '''
    Escribe un programa que lea los valores a y b y muestre una serie de números que empiezan en a y 
    se incrementan de 5 en 5 hasta llegar a b. Nota que a y b no necesariamente son múltiplos de 5, y 
    que debe mostrar todos los números que sean <= b. Supón que siempre se te dará un valor de a < b.
    '''
    num1 = int(input("Número 1: "))
    num2 = int(input("Número 2: "))

    for i in range(num1, num2 + 1, 5):
        print(i)

def alterna(num):
    '''
    Escribe un programa que lea un valor n y que muestre en la pantalla n caracteres que 
    alternan entre # y %.
    Los caracteres se deben mostrar uno en cada renglón.
    Observa que el primer caracter que se debe mostrar siempre es #
    '''
    for i in range(1, num + 1):
        if i % 2 == 0:
            print("%")
        else:
            print("#")

def cuadrados_consecutivos(num):
    '''
    Escribe un programa que reciba un número entero y calcule la suma: 1^2 + 2^2 + 3^2 +...+"numero^2". 
    Donde "numero" es el valor que el usuario proporcionó. 
    Finalmente se imprime el resultado de la suma en pantalla.
    '''
    suma = 0
    for i in range(num + 1):
        suma += i * i
    print(suma)   

def serie_escalera(num):
    '''
    Escribe un programa que lea un número N y muestre la siguiente lista de números:

    1, 2, ... N, N-1, N-2 ... 1
    '''
    for i in range(1, num):
        print(i, end = ", ")

    for i in range(num, 0, -1):
        print(i, end = ", " if i != 1 else "")

cuenta_numeros()
suma_n_numeros(6)
promedio()
desde_a_hasta_b()
regresiva_a_b()
rango_pares(3, 12)
serie_5()
alterna(7)
cuadrados_consecutivos(5)
serie_escalera(4)