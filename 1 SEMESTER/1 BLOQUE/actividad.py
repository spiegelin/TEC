def promedio():
    num = int(input("Cuántas materias tienes?: "))
    suma = 0
    for i in range(num):
        x = float(input(f"Calificación de la materia {i+1}: "))
        suma += x
    
    print(f"Tu promedio es de {suma/num}\n")

def cantidad():
    # 1 dólar = 20 pesos
    convertir = input("Dólar (1) / Peso (0): ")

    if convertir == "1":
        dolar = float(input("Cuántos dólares tienes?: "))
        print(f"En pesos sería {dolar * 20}\n")
    elif convertir == "0":
        peso = float(input("Cuántos pesos tienes?: "))
        print(f"En pesos sería {peso / 20}\n")
    else:
        print("Bro, pon algo bueno\n")

def propina():
    monto = float(input("Cuánto pagaste?: "))
    propina = (float(input("cuánta propina quieres dejar?: ")) / 100)

    print(f"El monto final es de {monto * propina}\n")

promedio()
cantidad()
propina()



