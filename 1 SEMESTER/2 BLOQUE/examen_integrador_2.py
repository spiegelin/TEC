'''
Examen Integrador Práctica Programa 2

Escribe un programa que reciba un string y un número entero positivo, el programa crea una nueva 
cadena con la cadena original pero dividida con guiones en cada intervalo del número recibido y la 
muestra en pantalla. Si recibe un número negativo o 0, deberá imprimir el mensaje: "Error".

Ejemplo:
Paracaidas
3

>>>Par-aca-ida-s

Diego Espejo 18/10/2022
'''
texto = input("Ingresa la string: ") # Recibe como string
texto = list(texto) # Convierte a lista dividida entre letras
num = int(input("Ingresa el número entero positivo: "))
cant = len(texto) // num # Cantidad de guiones

if num < 1:
    print("Error")
else:
    contador = 0
    for i in range(len(texto)+cant): # Se le suma la cantidad de guiones para que no se acabe antes el ciclo
        if contador == num:
            texto.insert(i, "-") # Se agrega el guion en la posición actual
            contador = 0
        else:
            contador += 1

if texto[-1] == "-": # En caso de que se agregue un guion al final
    texto.pop()

print("".join(texto)) # Convertir a string