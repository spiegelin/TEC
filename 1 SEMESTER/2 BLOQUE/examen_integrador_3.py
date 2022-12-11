'''
Examen Integrador Práctica Programa 3

En matemáticas, el producto punto, o producto escalar (o a veces producto interior en el contexto del 
espacio euclidiano), es una operación algebraica que toma dos secuencias de números de igual de longitud 
(normalmente vectores de coordenadas) y devuelve un único número. Algebraicamente, es la suma de los 
productos de las entradas correspondientes de las dos secuencias de números.

Crea una función llamada punto_producto que reciba dos listas de números (digamos lista1 y lista2). 
La función devuelve el producto punto de las dos listas.
Para obtener la máxima puntuación, si las listas no tienen el mismo tamaño, la función debe devolver 
el valor especial valor especial de NaN (que representa que no es un número). Puedes crear este valor con 
la expresión: float('NaN')


Ejemplo. Si la entrada es [2,4,5,6] y [1,2,3,4] el resultado será
(2*1)+(4*2)+(5*3)+(6*4) que es 49

Diego Espejo 18/10/2022
'''
def punto_producto(lista1, lista2):
    if len(lista1) != len(lista2):
        producto = float('NaN')
    else:
        producto = 0
        for i in range(len(lista1)):
            producto += lista1[i] * lista2[i]
    return producto


print(punto_producto([2,4,5,6], [1,2,3,4]))