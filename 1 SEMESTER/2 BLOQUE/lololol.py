from random import randint

nombres = ["Fredi", "Espejo", "Sebas", "Diego", "Pablo", "Max", "Pololo"]

def equipos_2(nombres):
    while(True):
        opc = input("")

        if nombres == []:
            break    
        elif len(nombres) == 1:
            print(nombres[0])
            break

        num1 = randint(0,len(nombres)-1)
        integrante_1 = nombres[num1]
        nombres.pop(num1)

        num2 = randint(0,len(nombres)-1)
        integrante_2 = nombres[num2]
        nombres.pop(num2)

        print(integrante_1, integrante_2)

equipos_2(nombres)
'''
for i in range(len(nombres)):
    if nombres == []:
        break
    elif len(nombres) == 1:
        print(nombres[0])
        break

    num1 = randint(0,len(nombres)-1)
    num2 = randint(0,len(nombres)-1)

    integrante_1 = nombres[num1]
    nombres.pop(num1)

    integrante_2 = nombres[num2]
    nombres.pop(num2)

    print(integrante_1, integrante_2)
    '''