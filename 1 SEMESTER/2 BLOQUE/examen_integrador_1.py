'''
Examen Integrador Práctica Programa 1

Cree una función llamada encontrar_tres que reciba como parámetro una lista de números y devuelve 
la suma de todos los números de esa lista que son divisibles por 3. 
Así, si la lista fuera [0,4,2,6,9,8,3,12], la función devolvería 30 (0+6+9+3+12)

Diego Espejo 18/10/2022
'''
def encontrar_tres(lista_numeros):
    suma = 0
    for i in lista_numeros:
        if i % 3 == 0:
            suma += i
    return suma

print(encontrar_tres([0,4,2,6,9,8,3,12]))