'''
Programa que indica si un número es par o impar

Diego Espejo 19/08/2022
'''
def par():

    try:
        num = float(input("Ingresa el número: "))

        if num % 2 == 0:
            print("Su número es par")
        else:
            print("Su número es impar")
    except:
        print("Ingrese un dato numérico")

def multiplo_7():
    try:
        num = float(input("Ingresa el número: "))

        if num % 7 == 0:
            print("Su número es múltiplo de 7")
        else:
            print("Su número no es múltiplo de 7")
    except:
        print("Ingrese un dato numérico")


par()
multiplo_7()