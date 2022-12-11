'''
EJERCICIOS : Problemas que toman decisiones

Diego Espejo 21/08/2022
'''
from math import sqrt

def licencia():
    '''
    Una persona puede obtener su licencia de manejo si es mayor de edad y tiene identificación oficial. 
    Escribe un programa en Python que lea la edad de una persona y si tiene (s/n) identificación oficial.
    De salida debe mostrar Si si puede obtener su licencia o No si no la puede obtener
    '''
    edad = int(input("Ingrese su edad: "))
    id = input("¿Tiene identificación oficial? (s/n): ").lower()

    if edad >= 18 and id == "s":
        print("Si")
    else:
        print("No")

def tipoTriangulo():
    '''
    Realiza un programa que sea útil para determinar si los números enteros X, Y y Z, 
    proporcionados por el usuario, son medidas correctas para los lados de un triángulo y si lo son, 
    debe decir si se trata de un triángulo Equilátero, Isósceles o Escaleno.
    NOTA: X, Y y Z son los lados de un triángulo si cumplen con las siguientes condiciones:
    
    Todos los números son mayores que cero
    X + Y > Z
    X + Z > Y
    Y + Z > X
    es decir, la suma de dos de las medidas debe ser estrictamente mayor que la tercera.

    El triángulo equilátero tiene 3 lados iguales, el isósceles tiene 2 lados iguales y 
    el escaleno tiene los 3 lados diferentes.
    '''
    x = int(input("Ingrese el valor del lado X: "))
    y = int(input("Ingrese el valor del lado Y: "))
    z = int(input("Ingrese el valor del lado Z: "))

    if (x + y > z) and (x + z > y) and (y + z > x):
        if (x == y) and (x == z):
            print("EQUILATERO")
        elif (x == y) or (x == z) or (z == y):
            print("ISOSCELES")
        else:
            print("ESCALENO")
    else:
        print("NO ES TRIANGULO")

def mayorDeTres():
    '''
    Realiza un programa que muestre el mayor de 3 números enteros x, y, z proporcionados por el usuario.
    No utilices la función incorporada de Python max ().
    '''
    x = int(input("Ingrese X: "))
    y = int(input("Ingrese Y: "))
    z = int(input("Ingrese Z: "))
    
    if x > y and x > z:
        print(x)
    elif y > x and y > z:
        print(y)
    elif z > x and z > y:
        print(z)
    else:
        print("IGUALES")

def ordenaTresNum():
    '''
    Realiza un programa que ordena en forma ascendente tres números enteros x, y, z.
    IMPORTANTE: NO puedes utilizar la función incorporada de Python: sort(), utiliza estatutos de comparación.
    '''
    x = int(input("Ingrese X: "))
    y = int(input("Ingrese Y: "))
    z = int(input("Ingrese Z: "))

    if (x < y) and (x < z): 
        print(x)
        if (y < z):
            print(y)
            print(z)
        else:
            print(z)
            print(y)
    
    elif (y < x) and (y < z):
        print(y)
        if (x < z):
            print(x)
            print(z)
        else:
            print(z)
            print(x)
    
    elif (z < x) and (z < y):
        print(z)
        if (x < y):
            print(x)
            print(y)
        else:
            print(y)
            print(x)
    else:
        print("EQUAL")

def IMC():
    '''
    Escribe un programa que calcule el IMC (Índice de Masa Corporal) de una persona, el cual se utiliza para 
    determinar si la proporción de peso y altura es adecuada. 
    El IMC se puede calcular utilizando la siguiente fórmula:
    indice = peso / altura**2
    
    Donde el peso debe darse en kilogramos y la altura en metros. 
    La siguiente tabla muestra cómo se clasifican los diferentes rangos de índice:

    Rango de índice          Descripción
    índice < 20               'PESO BAJO'
    20 <= índice < 25         'NORMAL'
    25 <= índice < 30         'SOBREPESO'
    30 <= índice < 40         'OBESIDAD'
    40 >= índice              'OBESIDAD MORBIDA'
    '''
    peso = float(input("Peso (kg): "))
    altura = float(input("Altura: "))
    imc = peso / altura**2

    if imc < 20:
        print("PESO BAJO")
    elif imc <= 20 and imc < 25:
        print("NORMAL")
    elif imc <= 25 and imc < 30:
        print("SOBREPESO")
    elif imc <= 30 and imc < 40:
        print("OBESIDAD")
    else:
        print("OBESIDAD MORBIDA")

def añoBisiesto():
    '''
    El siguiente algoritmo se puede usar para determinar si un año determinado es bisiesto:
    
    - Los años bisiestos son cualquier año que es divisible por 4 (como 2012, 2016, etc).
    - Excepto si puede dividirse por 100, entonces no lo es (como 2100, 2200, etc).
    - A menos que pueda ser divisible por 400, como 2000, 2400.

    Escribe el programa que determine si un año es bisiesto o no.
    '''
    año = int(input("Ingrese el año: "))

    if año % 4 == 0:
        if año % 100 == 0:
            if año % 400 == 0:
                print(True)
            else:
                print(False)
        else:
            print(True)
    else:
        print(False)

def sigDía():
    '''
    Escribe un programa que dada una fecha (año, mes y día), devuelva la fecha del día siguiente. 
    Te recomiendo que antes de ponerte de codificar, verifiques todas las posibilidades que se pueden 
    presentar.
    '''
    año = int(input("Año: "))
    mes = int(input("Mes: "))
    día = int(input("Día: "))

    if día <= 31 or mes <= 12:
        if día < 31:
            if mes == 2 and día == 29: # Febrero es la excepción
                print(año)
                print(mes + 1)
                print(1)
            elif (día == 30) and (mes == 4 or mes == 6 or mes == 9 or mes == 11): # Tienen 30 días: Abril, junio, septiembre y noviembre.
                print(año)
                print(mes + 1)
                print(1)
            else:
                print(año)
                print(mes)
                print(día + 1)
        else:
            if mes == 12:
                print(año + 1)
                print(1)
                print(1)
            else:
                print(año)
                print(mes + 1)
                print(1)
    else:
        print("Fecha Incorrecta")

def puntoEnCircunferencia():
    '''
    Escriba un programa que pida el radio y las coordenadas del centro de una circunferencia, 
    así como las coordenadas de un punto. 
    El programa deberá indicar si el punto está sobre la circunferencia, dentro o fuera de ella. 
    Investiga o recuerda la fórmula del calculo de distancia entre dos puntos porque la vas a necesitar:

    d(A/B) = sqrt((X2 - X1)**2 + (Y2 - Y1)**2)
    '''
    radio = float(input("Radio: "))
    x1 = float(input("X1 (Centro circunferencia): "))
    y1 = float(input("Y1 (Centro circunferencia): "))
    x2 = float(input("X2: "))
    y2 = float(input("Y2: "))
    distancia = sqrt((x2 - x1)**2 + (y2 - y1)**2)

    if distancia < radio:
        print("DENTRO")
    elif distancia > radio:
        print("FUERA")
    else:
        print("SOBRE")

def conversion():
    '''
    Escribe un programa que pida una distancia en centímetros y que escriba esa distancia en su equivalente 
    en kilómetros, metros y centímetros (escribiendo solamente las unidades necesarias).
    '''
    distancia = int(input("Distancia: "))
    
    if distancia >= 100000:
        km = distancia // 100000
        m = (distancia - (km * 100000)) // 100
        cm = (distancia - (km * 100000) - (m * 100))

        if m == 0:
            print(f"{km} km")
            print(f"{cm} cm")
        elif cm == 0:
            print(f"{km} km")
            print(f"{m} m")
        elif m == 0 and cm == 0:
            print(f"{km} km")
        else:
            print(f"{km} km")
            print(f"{m} m")
            print(f"{cm} cm")
    
    elif distancia < 100000 and distancia >= 100:
        m = distancia // 100
        cm = distancia - (m * 100)

        if cm == 0:
            print(f"{m} m")
        else:
            print(f"{m} m")
            print(f"{cm} cm") 
    else:
        print(f"{distancia} cm")

def comparaFechas():
    '''
    Haz un programa que pida al usuario 2 fechas del mismo año 
    (es decir, debe pedir día y mes para cada una de las fechas) y que muestre en la pantalla un 
    mensaje que indique cual de las dos fechas ocurre primero, o bien, si son iguales.
    '''
    día1 = int(input("Día 1?: "))
    mes1 = int(input("Mes 1?: "))
    día2 = int(input("Día 2?: "))
    mes2 = int(input("Mes 2?: "))

    if mes1 < mes2:
        print("La fecha 1 ocurre primero")
    elif mes1 > mes2:
        print("La fecha 2 ocurre primero")
    else:
        if día1 < día2:
            print("La fecha 1 ocurre primero")
        elif día1 > día2:
            print("La fecha 2 ocurre primero")
        else:
            print("Las fechas son iguales.")

def cuadrante():
    '''
    Escribe un programa que lea un número entero que se encuentre entre 0 y 360 que representa los 
    grados del plano cartesiano y que muestre como resultado el número de cuadrante en donde se encuentra.

    En caso de que el grado caiga en un eje, tu programa debe mostrar la palabra "eje".
    En caso de que el grado sea menor a cero o mayor a 360, tu programa debe mostrar la palabra "excede".
    '''
    grados = int(input("Ingrese los grados: "))

    if grados >= 0 and grados <= 360:
        if grados < 90:
            print("cuadrante 1")
        elif grados > 90 and grados < 180:
            print("cuadrante 2")
        elif grados > 180 and grados < 270:
            print("cuadrante 3")
        elif grados > 270:
            print("cuadrante 4")
        else:
            print("eje")
    else:
        print("excede")

def cuadrática():
    '''
    Realiza un programa para calcular los valores de la ecuación cuadrática ax^2+bx+c usando la 
    fórmula cuadrática.

    El programa debe leer tres valores enteros a, b y c, y encontrar los valores de x, considerando las 
    siguientes restricciones:

    Si a = 0 y b = 0 se debe desplegar el mensaje "No tiene solucion”
    Si a = 0 y b != 0 se debe despejar el valor de x = –c/b y mostrar este valor.
    Si a != 0 y b != 0 se debe calcular el discriminante.
        - Si el valor del discriminante es negativo debe mostrar el mensaje "Raices complejas"
        - Si el valor del discriminante es positivo debe calcular y mostrar los dos valores de x, 
          una en cada renglón
        - En caso de que el discriminante sea cero se debe mostrar sólo un valor de x = -b/(2a)
    '''
    a = float(input("a: "))
    b = float(input("b: "))
    c = float(input("c: "))

    if a == 0 and b == 0:
        print("No tiene solución")
    elif a == 0 and b != 0:
        print(-c/b)
    else:
        discriminante = b**2 - (4*a*c)
        if discriminante < 0:
            print("Raíces complejas")
        elif discriminante > 0:
            x1 = (-b + (sqrt(b**2 - (4*a*c)))) / (2*a) # Solución de raíces
            x2 = (-b - (sqrt(b**2 - (4*a*c)))) / (2*a)
            print(f"{x1:.2f}") # Redondear a 2 decimales
            print(f"{x2:.2f}")
        else:
            print(-b/(2*a))

def juego():
    '''
    Piedra (a), Papel (p) o Tijera (t)
    '''
    ana = input("a, p, t: ").lower()
    juan = input("a, p, t: ").lower()

    if len(ana) == 1 and len(juan) == 1:
        if juan == ana:
            print("Empate")
        elif ana == 'a' and juan == 'p':
            print("Gana Juan")
        elif ana =='a' and juan == 't':
            print("Gana Ana")
        elif ana == 'p' and juan == 'a':
            print("Gana Ana")
        elif ana == 'p' and juan == 't':
            print("Gana Juan")
        elif ana == 't' and juan == 'p':
            print("Gana Ana")
        elif ana == 't' and juan == 'a':
            print("Gana Juan")
        else:
            print("Tirada incorrecta")
    else:
        print("Las tiradas deben ser un caracter")

licencia()
tipoTriangulo()
mayorDeTres()
ordenaTresNum()
IMC()
añoBisiesto()
sigDía()
puntoEnCircunferencia()
conversion()
comparaFechas()
cuadrante()
cuadrática()
juego()