import math

def pita():
    """
    Programa que reciba los dos catetos de un triángulo rectángulo 
    y encuentre su hipotenusa
    """
    try:
        x = float(input("Dame un cateto: "))
        y = float(input("Dame un cateto: "))

        while(x <= 0 or y <= 0):
            print("Estás mal, ponte pilas")
            x = float(input("Dame un cateto: "))
            y = float(input("Dame un cateto: "))

        c = math.sqrt(x**2 + y**2)

        print(f"El valor de la hipotenusa es de {c:.2f}")
    except:
        print("El dato no es número")

def a_circulo():
    """
    Obtener área según radio
    """
    try:
        radio = float(input("Dame el radio del círculo: "))
        while(radio <= 0):
            print("Estás mal, ponte pilas")
            radio = float(input("Dame el radio del círculo: "))
        
        print(f"El área es de {(math.pi * (radio**2)):.2f}")
    except:
        print("El dato no es número")


def hipo():
    """
    Cateto opuesto y ángulo, saca hipotenusa
    """
    try:
        x = float(input("Dame el cateto opuesto: "))
        angulo = float(input("Dame un ángulo en radianes: "))

        while(x <= 0 or angulo <= 0):
            print("Estás mal, ponte pilas")
            x = float(input("Dame el cateto opuesto: "))
            angulo = float(input("Dame un ángulo en radianes: "))

        hipotenusa = x / math.sin(angulo)

        print(f"La hipotenusa es de {hipotenusa:.2f}")

    except:
        print("El dato no es número")

def volumen_esfera():
    """
    V = 4/3 pi r**3
    """
    try:
        radio = float(input("Dame el radio: "))
        while(radio <= 0):
            print("Estás mal, ponte pilas")
            radio = float(input("Dame el radio: "))
        
        print(f"El volumen es de {(4/3 * math.pi * (radio**3)):.2f}")
    except:
        print("El dato no es número")

def operacion():
    """
    b/2a (x-y)
    """
    try:
        x = float(input("Dame x: "))
        y = float(input("Dame y: "))
        a = float(input("Dame a: "))
        b = float(input("Dame b: "))

        while(x <= 0 or y <= 0 or a <= 0 or b <= 0):
            print("Estás mal, ponte pilas")
            x = float(input("Dame x: "))
            y = float(input("Dame y: "))
            a = float(input("Dame a: "))
            b = float(input("Dame b: "))

        c = (b/2*a) (x - y)

        print(f"El resulta es de: {c:.2f}")
    except:
        print("El dato no es número")

pita()
a_circulo()
hipo()
volumen_esfera()
operacion()