from random import randint

palabras = ["diccionario", "compuesto", "ahorcado", "celular", "navojoa", "silvestre", "reglamento"]
palabra_random = palabras[randint(0,6)].upper()


palabra_escondida = []
for i in palabra_random:
    palabra_escondida.append("_ ")

print(palabra_random)
