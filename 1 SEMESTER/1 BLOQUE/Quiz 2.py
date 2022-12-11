'''
Quiz 2 Programación

Diego Espejo 26/08/2022
'''
def main():
    print("\033[34mPrograma que calcula el volumen y área de un prisma rectangular \n")
    try:
        largo = float(input("\033[33mLargo (m): "))
        ancho = float(input("\033[31mAncho (m): "))
        altura = float(input("\033[32mAltura (m): "))
        area = area_prisma(largo, ancho, altura)
        volumen = volumen_prisma(largo, ancho, altura)

        print(f"\n\033[35mÁrea: {area:.2f} m2")
        print(f"\033[39mVolumen: {volumen:.2f} m3")
    except:
        print("\n\033[39mIngrese números porfavor")

def area_prisma(largo, ancho, altura):
    '''
    Función que recibe el largo, ancho y alto del prisma y regrese el área de todas sus caras.
    '''
    area_bases = (largo * ancho) * 2
    area_caras1 = (largo * altura) * 2
    area_caras2 = (ancho * altura) * 2
    area = area_bases + area_caras1 + area_caras2
    return area

def volumen_prisma(largo, ancho, altura):
    '''
    Función que recibe el largo, ancho y alto del prisma y regrese el volumen calculado.
    '''
    area_base = largo * ancho
    volumen = area_base * altura
    return volumen

main()