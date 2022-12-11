def areaTriangulo():
    '''
    Escribe un programa que lea los datos: base (b) y altura (h) y muestre el área del triángulo.
    '''
    base = float(input("Valor de la base: "))
    altura = float(input("Valor de la altura: "))

    print(f"El área del triángulo es {(base*altura)/2}\n")

def promedio():
    '''
    En una universidad cada estudiante cursa 4 materias en el semestre. 
    Desarrolla un programa que reciba la calificación de cada materia, 
    calcula el promedio de las 4 materias y lo despliega.
    '''
    promedio = 0
    for i in range(4):
        cali = float(input(f"Escribe tu calificación de la materia {i+1}: "))
        promedio += cali

    print(f"El promedio es: {promedio/4}\n")

def cienAños():
    '''
    Crea un programa que pregunte al usuario su edad y el año actual, como resultado le indicará el año en que cumplirá 100 años.
    NOTA: Haz la versión simple de este ejercicio, es decir, no consideres el mes de nacimiento, solo el año.
    Después haremos una en la que sí consideraremos el mes de nacimiento.
    '''
    edad = int(input("Dime tu edad: "))
    año = int(input("Dime el año actual: "))
    añosFaltantes = 100 - edad

    print(f"El año en el que cumplirás 100 años será en el {año + añosFaltantes}\n")

def lustros():
    '''
    Realiza un programa que indique el número de lustros que ha vivido una persona 
    por medio de su año de nacimiento y el año actual.
    '''
    nacimiento = int(input("Dime tu año de nacimiento: "))
    año = int(input("Dime el año actual: "))

    print((año - nacimiento) / 5)
    print("")

def peso():
    '''
    A inicio de año, las personas están preocupadas por su peso por lo que acuden a nutriólogos, 
    gimnasios y cualquier otra cosa que les ayude en el proceso. 
    Realiza un programa que ayude a las personas a indicar cuántos kilos debe bajar por mes una persona dados el peso inicial, 
    el peso final y el número de meses que una persona estará en un programa integral para bajar de peso.
    '''
    pesoInicial = float(input("Indica tu peso inicial: "))
    pesoFinal = float(input("Indica tu peso final: "))
    meses = int(input("Indique el número de meses del programa: "))
    kilos = (pesoInicial - pesoFinal) / meses

    print(f"Debe bajar {kilos} kilos por cada mes\n")

def pendiente():
    '''
    Realiza un programa que reciba las coordenadas de dos puntos y que calcule la pendiente de la recta 
    que une esos dos puntos.

    La fórmula para calcular la pendiente es:
    m = (y2 - y1) / (x2 - x1)
    '''
    x1 = float(input("Dime la coordenada x1: "))
    y1 = float(input("Dime la coordenada y1: "))
    x2 = float(input("Dime la coordenada x2: "))
    y2 = float(input("Dime la coordenada y2: "))

    print(f"La pendiente es igual a {((y2 - y1) / (x2 - x1)):.2f}\n")

def distancia():
    '''
    Un caracol de un terrario de una primaria pública corre a 5.7 mm/s. (34.2 cm/min)
    Realiza un programa para indicar cuántos centímetros recorrerá el caracol en una cantidad de minutos 
    dada por el usuario.
    '''
    minutos = float(input("Ingrese los minutos: "))

    print(f"Los centímetros recorridos serán {minutos*34.2}\n")

def costoCel():
    '''
    Una compañía de telefonía celular cobra $0.80 por mensaje, por mega o por minuto. 
    Realiza un programa que calcule el costo total mensual de un usuario según estos datos.
    '''
    mensajes = int(input("Número de mensajes: "))
    megas = float(input("Número de megas: "))
    minutos = int(input("Número de minutos: "))

    print(f"El costo mensual será de {(mensajes * 0.80) + (megas * 0.80) + (minutos * 0.80)}\n")

def cemento():
    '''
    Haz un programa sirva para calcular el precio que va a pagar un cliente por comprar cemento.
    El programa debe leer la cantidad de bultos de cemento que va a comprar el cliente, 
    y el precio del bulto de cemento.
    El programa debe mostrar como salida 3 datos uno en cada renglón: 
    el precio antes de impuestos, los impuestos (que son el 16% del precio) y el total a pagar por el cliente.
    '''
    bultos = int(input("Ingrese la cantidad de bultos de cemento: "))
    precio = float(input("Precio del bulto de cemento: "))
    precioFinal = bultos * precio

    print(f"El precio antes de impuestos es de {precioFinal}")
    print(f"Los impuestos son de {precioFinal * 0.16}")
    print(f"El total a pagar es de {(precioFinal * 0.16) + precioFinal}\n")

def videojuegos():
    '''
    GameStore tiene venta de videojuegos los nuevos tienen un costo de 1,000 y los usados 350.
    Escribe un programa que sirva para calcular el total de la compra.
    '''
    juegosNuevos = (int(input("Ingrese la cantidad de juegos nuevos: "))) * 1000 # precio de juegos nuevos
    juegosUsados = (int(input("Ingrese la cantidad de juegos usados: "))) * 350 # precio de juegos usados

    print(f"El total de la compra es de {juegosNuevos + juegosUsados}\n")

areaTriangulo()
promedio()
cienAños()
lustros()
peso()
pendiente()
distancia()
costoCel()
cemento()
videojuegos()