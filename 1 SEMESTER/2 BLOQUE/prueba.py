texto = input("Ingresa la string: ")
texto = list(texto)
num = int(input("Ingresa el número entero positivo: "))

cantidad_guiones = len(texto) // num

contador = 0
prueba = 0
while True:
    if prueba == cantidad_guiones:
        break
    elif contador == num:
        texto.insert(contador, "-")
        prueba += 1
        contador += 1
    else:
        contador += 1

print("".join(texto))
