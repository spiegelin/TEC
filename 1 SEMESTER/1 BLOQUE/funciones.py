from math import pi
def main():
    print('''\dMENÚ DE FUNCIONES \n
1. Segundos a días, horas, minutos
2. Pies a cm
3. Volumen de esfera
4. Múltiplo de un número
5. Compara dos números''')

    elección = int(input())

    if elección == 1:
        segundos = int(input("Ingrese los segundos: "))
        print(segundos(segundos))
    elif elección == 2:
        pies = int(input("Ingrese los pies: "))
        print(convierte_pies_cm(pies))
    elif elección == 3:
        radio = int(input("Ingrese el radio: "))
        print(volumen_esfera(radio))
    elif elección == 4:
        x = int(input("Ingrese número: "))
        y = int(input("Ingrese múltiplo: "))
        print(multiplo_de(x,y))
    elif elección == 5:
        x = int(input("Ingrese número a comparar: "))
        y = int(input("Ingrese número a comparar: "))
        print(compara(x,y))
    else:
        print("No está en el menú")


def segundos(segundos):
    días = segundos // 86400
    sobra_días = segundos % 86400

    horas = sobra_días // 24
    sobra_horas = sobra_días % 24

    minutos = sobra_horas // 60
    sobra_minutos = sobra_horas % 60

    segundos_finales = sobra_minutos // 60

    print(f"{días} días, {horas} horas, {minutos} minutos, {segundos_finales} segundos")


def convierte_pies_cm(pies):
    '''
    Ejercicio 3
    Escribe un algoritmo que dada una longitud en metros, calcule y muestre su equivalente en pies.
    Recuerda que 1 pie = 12 pulgadas, 1 pulgada = 2.54 cm, 1 m = 100 cm
    '''
    return pies * 30.48 # 328.084 es equivalente a 1 metro en pies

def volumen_esfera(radio):
    """
    V = 4/3 pi r**3
    """
    volumen = (4/3 * pi * (radio**3))
    return volumen


def multiplo_de(x, y):
    if x % y == 0:
        return True
    else:
        return False

def compara(x, y):
    if x < y:
        return -1
    elif x > y:
        return 1
    else:
        return 0

main()