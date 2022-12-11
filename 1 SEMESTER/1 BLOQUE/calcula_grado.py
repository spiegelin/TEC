def calcula_grado():
    '''
    Esta función debe recibir un número flotante entre 0 y 1, y debe regresar una nota alfabética de 
    acuerdo con la siguiente tabla:

    Score	Nota
    >0.9	A
    >0.8	B
    >0.7	C
    >0.6	D
    <=0.6	F
    '''
    try:
        score = float(input("Score: "))
        
        if score > 0.9 and score <= 1:
            print("A")
        elif score > 0.8 and score <= 0.9:
            print("B")
        elif score > 0.7 and score <= 0.8:
            print("C")
        elif score > 0.6 and score <= 0.7:
            print("D")
        elif score <= 0.6:
            print("F")
        else:
            print("score incorrecto")
    except:
        print("Escriba un número entre 0 y 1")

calcula_grado()