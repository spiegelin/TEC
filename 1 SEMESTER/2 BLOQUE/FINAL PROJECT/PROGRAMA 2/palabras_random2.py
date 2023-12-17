'''
Programa que mediante una API, muestra una palabra aleatoria y su definición

07/10/2022
Diego Espejo
Gael 
'''
import requests

url = "https://palabras-aleatorias-public-api.herokuapp.com/random"
response = requests.get(url)
text = str(response.content, encoding="UTF-8")

lista_texto = text.split("{") # Por el formato en el que está, lo dividimos cuando aparezca una llave
texto = "".join(lista_texto) # Lo juntamos para hacerlo string de nuevo

# Para obtener la palabra
palabra = texto[texto.find('"Word":')] # Buscamos la palabra "Word": 
palabra_random = []

count = 1
while palabra != ",": # Por el formato de la api, mientras no aparezca una "," que siga agregando cada letra a la lista
    palabra_random.append(palabra)
    palabra = texto[texto.find('"Word":')+count]
    count += 1

# Une la lista "palabra_random" -> crea string, la separa por comillas -> crea lista, y escoge el tercer elemento de esa lista, 
# que es la palabra en forma de string 
palabra_random = "".join(palabra_random).split('"')[3].upper() 

# Itera sobre la palabra random y entrega una string de los mismos caracteres pero con _
palabra_escondida = []
for i in palabra_random:
    palabra_escondida.append("_ ")

print(palabra_random)

# Para obtener la definición
definicion = texto[texto.find('"DefinitionMD":')] # Buscamos la palabra "Word": 
lista_definicion = []

count = 15
while definicion not in [":", "/", "*", "\\", "<", ">", "[", "]", ";"]: # Mientras no aparezca una , que siga agregando cada letra a la lista
    lista_definicion.append(definicion)
    definicion = texto[texto.find('"DefinitionMD":')+count] # Te da el índice de donde se encuentra esa palabra
    count += 1

definicion = "".join(lista_definicion).split('"')[2]

definicion = definicion.split(" ")

# En caso de que la definición sea muy larga. se hace esto para que se le agregue un salto de renglón
if len(definicion) > 13:
    definicion = definicion[:11] + ["\n"] + definicion[11::]
    definicion = " ".join(definicion)
else:
    definicion = " ".join(definicion)

# En caso de no haber definición
if definicion == "":
    definicion = "No se encontró la definición"

print(definicion)