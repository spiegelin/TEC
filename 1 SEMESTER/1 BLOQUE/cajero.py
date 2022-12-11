"""
Eres el cajero de un banco y tienes que entregar 
la cantidad solicitada por el usuario en billetes de $200, $50, $20 y monedas de $1
"""
try:
    cantidad = int(input("Escriba la cantidad a entregar: "))

    while(cantidad < 0):
        print("Estás mal, ponte pilas")
        cantidad = int(input("Escriba la cantidad a entregar: "))
    
    billetes = [200, 50, 20, 1]

    for i in range(4):
        billetes.append(cantidad // billetes[i])
        cantidad %= billetes[i]
        billetes.pop(i)
        
    print(f"200: {billetes[0]}, 50: {billetes[1]}, 20: {billetes[2]}, 1: {billetes[3]}")

except ValueError:
    print("El dato no es número")