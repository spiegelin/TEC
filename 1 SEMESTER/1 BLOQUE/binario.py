'''
Programa que incluya la función binario_decimal que convierta números binarios (base 2) 
en números decimales (base 10). La función deberá recibir un string que contenga el número binario a 
convertir y regresar un número entero equivalente en base 10. Si el string recibido es de tamaño 0 o no 
está formada por sólo 1s y 0s se devuelve un -1.

Escribe después la función main que lea el string, lo envíe a la función y luego muestre el valor de 
retorno de la función en la pantalla.

Diego Espejo 26/08/2022
'''
def main():
    binario = input("Binario: ")
    numero = binario_decimal(binario)
    print(numero)

def binario_decimal(binario):
    numero = 0
    if len(binario) < 1:
        return -1
    else: 
        for i in binario:
            if i != "1" and i != "0":
                return -1

    digito = list(map(int, binario)) # Pasar de string a int, y cada elemento anexarlo a una lista 
    digito = digito[::-1] # Invertir la lista

    contador = 0
    for i in digito:
        numero += int(digito[contador])*(2**contador)
        contador += 1
    return numero

main()