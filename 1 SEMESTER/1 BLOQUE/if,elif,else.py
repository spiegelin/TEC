'''
Programa que analiza funciones pa saber si es if, elif o else

Diego Espejo 19/08/2022
'''

try:
    x = float(input("Indica el valor de la x: "))

    if x <= -1:
        print("f(x) = 2x")
    elif x > -1 and x < 1:
        print("f(x) = 2x + 1")
    elif x >= 1 and x < 4:
        print("f(x) = -x + 4")
    else:
        print("f(x) = x - 1")
except:
    print("Ingrese un número")