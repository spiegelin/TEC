archivo = open("file.txt", "r", encoding="UTF-8")

print(archivo.read(30))

archivo = open("file.txt", "w")
archivo.write("Texto\n")
archivo.close()


reader = csv.reader(file)

for row in reader:
    print(row)
file.close()


# CALIFICACIONES, eliminar celdas extra

f=open("answers. CSV", "r")

respuestas=[]
for row in f:
     respuestas. append(row) 
f.close() 
lista=[]
for recorre in respuestas:
     lista. append(recorre.strip().split(","))
print (lista)
               
# Lista de elementos en el documento
f = open("ListaMini.csv", 'r', encoding= "UTF-8")
reader = csv.reader(f)

# Creo la lista de listas
lista=[]
for row in reader:
   print (row)
   lista=lista+[row]
print(lista)

#reviso el número de elementos en la lista
tam=len(lista)

