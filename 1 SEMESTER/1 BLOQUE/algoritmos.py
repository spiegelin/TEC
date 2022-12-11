def ejercicio1():
    '''
    Ejercicio 1
    Escribe un algoritmo para verificar si un precio dado por el usuario es válido o no lo es, 
    para ser válido debe ser un valor positivo.
    '''
    try:
        precio = float(input("Ingresa un precio: "))
        if precio < 0:
            print("No es válido, el precio debe ser positivo")
        else:
            print("Su precio es válido")
    except:
        print("Inserte un número")

def ejercicio2():
    '''
    Ejercicio 2
    Escribe un algoritmo que muestre la velocidad promedio de un automóvil dadas la distancia recorrida en kilómetros y 
    el tiempo que se tardó en recorrer esa distancia dado en horas.
    '''
    distancia = float(input("Inserte la distancia en km: "))
    tiempo = float(input("Inserte el tiempo en horas: "))

    print(f"La velocidad promedio del automóvil es de {distancia/tiempo} km/h")

def ejercicio3():
    '''
    Ejercicio 3
    Escribe un algoritmo que dada una longitud en metros, calcule y muestre su equivalente en pies.
    Recuerda que 1 pie = 12 pulgadas, 1 pulgada = 2.54 cm, 1 m = 100 cm
    '''
    metros = float(input("Ingrese la longitud: "))
    print(f"Su equivalente en pies es: {metros * 3.28084} ft") # 3.28084 es equivalente a 1 metro en pies

def ejercicio4():
    '''
    Ejercicio 4
    Escribe un algoritmo que verifique si una persona puede obtener su licencia de conducir. 
    Para hacerlo debe ser mayor de edad (18 años o más) y traer una identificación oficial. 
    '''
    edad = int(input("Dime tu edad: "))
    identifica = input("¿Tiene su identificación? si/no ")
    if edad >= 18 and identifica == "si":
        print("Puede obtener su licencia")
    else:
        print("No puede obtener su identificación :(")

#ejercicio1()
#ejercicio2()
#ejercicio3()
ejercicio4()