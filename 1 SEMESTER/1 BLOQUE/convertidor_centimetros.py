def convertidor_centimetros():
    '''
    Programa que convierte pies, pulgadas y yardas a centímetros, para lo cual debes definir 
    3 funciones:

    - Función que reciba una cantidad de pies (entero positivo) y devuelva el equivalente a centímetros.
    - Función que reciba una cantidad de pulgadas (entero positivo) y devuelva el equivalente a centímetros.
    - Función que reciba una cantidad de yardas (entero positivo) y devuelva el equivalente en centímetros.
    '''
    try:
        print("""Convertidor de pies a centímetros:
- (1) Pies a cm
- (2) Pulgadas a cm
- (3) Yardas a cm""")
        menu = int(input("¿A qué desea convertir?: \n"))

        if menu == 1:
            pies = float(input("Pies: "))
            print(f"Centimetros: {(pies * 30.48):.2f} cm")
        elif menu == 2:
            pulgadas = float(input("Pulgadas: "))
            print(f"Centimetros: {(pulgadas * 2.54):.2f} cm")
        elif menu == 3:
            yardas = float(input("Yardas: "))
            print(f"Centimetros: {(yardas * 91.44):.2f} cm")
        else:
            print("Error")
    except:
        print("Error")

convertidor_centimetros()