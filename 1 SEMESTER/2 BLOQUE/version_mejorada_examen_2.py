'''
Ejemplo:
Paracaidas
3

>>>Par-aca-ida-s

Diego Espejo 20/10/2022
'''
palabra = input("Ingrese la palabra: ")
num = int(input("Ingrese un número: "))

count = 0
for i in palabra:
    if count == num:
        print(f"-{i}", end="")
        count = 1
    else:
        print(i, end="")
        count += 1