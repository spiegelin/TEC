'''
Problemas que utilizan listas

Diego Espejo 23/09/2022
'''

def lista_muestra():
    '''
    Pregunta cuántos elementos se agregarán a una lista. 
    Después debe leer esa cantidad de datos e ingresarlos a la lista.
    Finalmente mostrar la lista leída en el formato que se muestra en el ejemplo. 
    '''
    while True:
        num = int(input("¿Cuántos elementos se agregarán a la lista?: "))
        if num > 0:
            break
    
    lista = []
    for i in range(num): lista.append(int(input()))
    for i in range(num): print(f"lista[{i}] = {lista[i]}")

#lista_muestra()

def lista_invertida():
    '''
    Programa que pregunte cuántos elementos se agregarán a una lista.
    Después debe leer esa cantidad de datos e ingresarlos a la lista.
    El programa debe desplegar los elementos ingresados en forma inversa, 
    el indice mayor al menor.
    '''
    while True:
        num = int(input("¿Cuántos elementos se agregarán a la lista?: "))
        if num > 0:
            break
    
    lista = []
    for i in range(num): lista.append(int(input()))
    for i in range(0, -num, -1): print(f"lista[{i-1}] = {lista[i-1]}")

#lista_invertida()

def promedio_lista():
    '''
    Programa que lea un valor entero n, y después n valores enteros y los agregue a una lista.
    El programa debe calcular el promedio de los valores de la lista
    Finalmente debe mostrar la lista y en el siguiente renglón el promedio de los valores que contiene.
    '''
    while True:
        num = int(input("¿Cuántos elementos se agregarán a la lista?: "))
        if num > 0:
            break
    
    lista = []
    for i in range(num): lista.append(int(input()))
    print(lista)
    print(sum(lista)/num)

#promedio_lista()

def pares_impares():
    '''
    Programa que lea números enteros y los vaya agregando a una lista, dejará de leer 
    cuando se introduzca un valor negativo. Luego el programa debe contar la cantidad de valores 
    pares e impares de la lista.  Considera al 0 como par.
    '''
    pares = 0
    impares = 0
    while True:
        num = int(input(""))
        if num < 0:
            break
        if num % 2 == 0:
            pares += 1
        else:
            impares += 1

        

    print(f"PARES = {pares}")
    print(f"IMPARES = {impares}")

#pares_impares()

def lista_cuadrado():
    '''
    Programa que pregunte cuántos elementos se agregarán a una lista. 
    Después debe leer esa cantidad de datos e ingresarlos a la lista.
    Posteriormente deberá construir una segunda lista, con el cuadrado de cada uno de los elementos 
    de la lista original.
    '''
    while True:
        num = int(input("¿Cuántos elementos se agregarán a la lista?: "))
        if num > 0:
            break
    
    lista = []
    for i in range(num): lista.append(int(input()))
    lista_nueva = [i**2 for i in lista]
    print(lista)
    print(lista_nueva)

#lista_cuadrado()

def al_reves():
    '''
    Programa que lea valores enteros y los agregue a una lista, dejará de leer al leer el valor -1.
    El programa debe crear otra lista que contenga los valores de la primera lista, pero en orden invertido.
    Luego debe mostrar ambas.
    '''
    lista = []
    while True:
        num = int(input())
        if num < 0:
            break
        else:
            lista.append(num)

    print(lista)
    print(lista[::-1])

#al_reves()

def combina_listas():
    lista = [1,2,3,4,5]
    lista2 = [9,8,7,6]
    lista3 = lista + lista2

    lista3[::2] = lista
    lista3[1::2] = lista2
    print(lista3)

combina_listas()