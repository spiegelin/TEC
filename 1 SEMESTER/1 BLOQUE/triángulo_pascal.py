'''
Triángulo de Pascal

Diego Espejo 30/08/2022
'''
num = int(input("Número de filas: "))
num_espacios = num - 1

for i in range(num):
    renglon = 11**i
    espacios = " "*num_espacios
    lista_digitos = [str(a) for a in str(renglon)]
    print(espacios, " ".join(lista_digitos))
    num_espacios -= 1
