'''
Desarrolla un programa que contenga una función que reciba un número entero positivo diferente a cero que 
representa la cantidad de términos a calcular de la serie, muestre la secuencia de términos que se van 
generando y regrese el resultado de la serie.
'''

def leibniz():
    num = int(input("¿Qué tan largo bro?: "))
    x = 0

    for n in range(num):
        x += ((-1)**n / (2*n + 1))
        print(f"{x:.4f}")

def primo():
    num = int(input("¿Hasta qué número bro?: "))
    for i in range(num+1):
        primo = True
        for j in range(2, i):
            if i % j == 0:
                primo = False
                break
        
        if i == 0 or i == 1:
            print(f"{i} no es primo")
        elif primo:
            print(f"{i} es primo")
        else:
            print(f"{i} no es primo")
primo()



