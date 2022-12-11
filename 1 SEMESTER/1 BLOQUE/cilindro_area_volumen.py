from math import pi

def main():
    radio = float(input("Radio: "))
    altura = float(input("Altura: "))

    print(f"\nArea: {(area_cilindro(radio, altura)):.2f}")
    print(f"Volumen: {(volumen_cilindro(radio, altura)):.2f}")

def area_cilindro(radio, altura):
    '''
    Recibe el radio y altura del cilindro y regrese el área calculada.
    '''
    area = ((2*pi)*radio*altura) + ((2*pi)*radio**2)
    return area

def volumen_cilindro(radio, altura):
    '''
    Recibe el radio y altura del cilindro y regrese el volumen calculado.
    '''
    volumen = (pi * radio**2)*(altura)
    return volumen

main()