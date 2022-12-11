import random

numero = random.randint(1,100)

while True:
    adivina = int(input("Adivina el número: "))
    
    if adivina < numero:
        print("Muy bajo")
    elif adivina > numero:
        print("Muy alto")
    else:
        print("Muy bien")
        break