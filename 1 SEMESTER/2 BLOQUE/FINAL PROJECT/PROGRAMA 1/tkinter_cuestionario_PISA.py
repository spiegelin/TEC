'''
Programa que mediante el uso de tkinter, muestra preguntas del examen PISA
07/10/2022
Diego Espejo
Gael 
'''
from tkinter import *
from tkinter import ttk
from preguntas_PISA import obtener_pregunta, posicion, keys

# Crear Ventana Principal
root = Tk() 
root.title("Examen PISA")
root.geometry('3000x1000')

# Primera Parte - Pantalla de Bienvenida
class pantallaInicio:
    # Pantalla de Inicio
    window = Frame(root, 
        height=1000,
        width=3000,
        bg="white",
        )
    window.pack()

    Button(window,
        text="Empezar Test",
        font="Arial 17",
        command=window.destroy
        ).place(x=1200,y=700) 

    Label(window,
        text="""Bienvenido a nuestra página para estudiar el examen PISA,
    
    Éxito!""",
        font="Arial 30",
        bg="white",
        fg="black"
        ).place(x=300,y=200) 

# Segunda Parte - Preguntas PISA
class pantallaPreguntas:
    '''
    Se crea una clase en donde están definidos el texto,
    la imagen de las preguntas, y todo lo que se observa en la pantalla
    '''
    pantallaRespuestas = False
    respuestaCorrecta = False
    # Ventana Secundaria
    frm = Frame(root, 
        height=1000,
        width=3000,
        bg="white"
        )
    frm.pack()

    # Botón Enviar
    enviar = Button(frm, 
        text="Enviar",
        font="Arial 17",
        fg="black",
        command=lambda:display_text()
        )
    enviar.place(x=990,y=700)


    # Botón Sig. Pregunta
    siguiente = Button(frm, 
        text="Siguiente Pregunta",
        font="Arial 17",
        fg="black",
        command=lambda:repetir(), # Te lleva a la función repetir, la cual reinicia el valor de las variables, y así se generan las nuevas preguntas
        )
    siguiente.place(x=1100,y=700)

    # Botón Salir
    salir = Button(frm, 
        text="Salir",
        font="Arial 17", 
        fg="black",
        bg="white",
        command=root.destroy
        )
    salir.place(x=1300,y=700) 

    imagen_pregunta, texto_pregunta, respuesta_pregunta = obtener_pregunta() # Te da dos paths, uno a la imagen y otro al archivo txt
    imagen = PhotoImage(file=imagen_pregunta)

    # Posición de cada elemento de las preguntas
    xy_imagen, xy_texto, xy_respuesta = posicion() # Coordenadas preseleccionadas en otro archivo
    
    # Texto - Pregunta
    texto = Label(frm, 
        text=open(texto_pregunta).read(),
        font="Arial 20",
        fg="Black",
        bg="white"
        )
    texto.place(x=xy_texto[0],y=xy_texto[1]) # El valor recibido por la función "posicion()" es una lista con la coordenada x (índice = 0) y y (índice = 1)

    # Imagen - Pregunta
    photo = Label(frm, 
        image=imagen
        )
    photo.place(x=xy_imagen[0],y=xy_imagen[1])

    # Label - Respuesta
    respuesta = Label(frm, 
        text="Respuesta:",
        font="Arial 20",
        fg="black",
        bg="white"
        )
    respuesta.place(x=xy_respuesta[0],y=xy_respuesta[1]) 

    # Escribir Respuesta
    entrada_texto = Entry(frm, 
        textvariable=StringVar(),
        font="Arial 19"
        )
    entrada_texto.place(x=xy_respuesta[0]+130,y=xy_respuesta[1]) 

# Tercera Parte
class pantallaFinal:
    contadorCorrectas = 0
    texto_salida = "/Users/spiegel/Documents/TEC/1 SEMESTRE/PENSAMIENTO COMPUTACIONAL/CODE/Proyecto Bloque/PROGRAMA 1/Preguntas/Final/salida.txt"
    foto_salida = "/Users/spiegel/Documents/TEC/1 SEMESTRE/PENSAMIENTO COMPUTACIONAL/CODE/Proyecto Bloque/PROGRAMA 1/Preguntas/Final/Screen Shot 2022-10-13 at 12.47.45.png"
    imagen = PhotoImage(file=foto_salida)
    imagen = imagen.subsample(2) # Significa que reduces la foto 1/2 de su tamaño

    # Pantalla de Inicio
    final = Frame(root, 
        height=1000,
        width=3000,
        bg="white",
        )
    final.pack()

    # Texto Final
    texto = Label(final, 
        text=open(texto_salida).read(),
        font="Arial 35",
        fg="Black",
        bg="white"
        )
    texto.place(x=550,y=50)

    # Puntuacion
    puntuacion = Label(final, 
        text="Ninguna respuesta correcta. \nPractica más!",
        font="Arial 35",
        fg="Black",
        bg="white"
        )
    puntuacion.place(x=475,y=550)
    
    # Imagen final
    photo = Label(final, 
        image=imagen
    )
    photo.place(x=470,y=150)
    
    # Finalizar
    Button(final,
        text="Finalizar",
        font="Arial 17",
        command=root.destroy
        ).place(x=1200,y=700)

# Funciones
def repetir():
    '''
    Elimina la pregunta pasada y manda a llamar una función para la nueva
    '''
    if pantallaPreguntas.pantallaRespuestas == True:
        pantallaPreguntas.pantallaRespuestas = False
        if len(keys) > 0:
            if pantallaPreguntas.respuestaCorrecta == True:
                imagen = PhotoImage(file="/Users/spiegel/Documents/TEC/1 SEMESTRE/PENSAMIENTO COMPUTACIONAL/CODE/Proyecto Bloque/PROGRAMA 1/Screen Shot 2022-10-19 at 21.54.31.png")
                pantallaFinal.contadorCorrectas += 1
                pantallaFinal.puntuacion.config(text=f"   Respuestas correctas: {pantallaFinal.contadorCorrectas}")

            elif pantallaPreguntas.respuestaCorrecta == False:
                imagen = PhotoImage(file="/Users/spiegel/Documents/TEC/1 SEMESTRE/PENSAMIENTO COMPUTACIONAL/CODE/Proyecto Bloque/PROGRAMA 1/Screen Shot 2022-10-19 at 21.57.25.png")

            imagen = imagen.subsample(2) # Significa que reduces la foto 1/2 de su tamaño
            pantallaPreguntas.photo.image = imagen
            pantallaPreguntas.texto.config(text="") # Se edita y actualiza el valor de text por el nuevo tras usar la función
            pantallaPreguntas.photo.config(image=imagen) # Se edita y actualiza la imagen por la nueva tras usar la función
            pantallaPreguntas.photo.place(x=350,y=165)
            pantallaPreguntas.enviar.place_forget()
            pantallaPreguntas.entrada_texto.place_forget()
            pantallaPreguntas.respuesta.place_forget()
            pantallaPreguntas.entrada_texto.delete(0, END)
            pantallaPreguntas.entrada_texto.insert(0, "")
        else:
            pantallaPreguntas.frm.destroy() # Se cierra la ventana secundaria

    else:
        keys.pop(0) # Se elimina el primer índice de la lista de keys, para que así se cambie a otra pregunta
        if len(keys) > 0:
            texto, imagen, respuesta = cambiar() 
            pantallaPreguntas.texto.config(text=texto) # Se edita y actualiza el valor de text por el nuevo tras usar la función
            pantallaPreguntas.photo.config(image=imagen) # Se edita y actualiza la imagen por la nueva tras usar la función

            # Se reasigna la posición de cada elemento de las preguntas
            xy_imagen, xy_texto, xy_respuesta = posicion()
            pantallaPreguntas.photo.place(x=xy_imagen[0],y=xy_imagen[1]) # Lo mismo que arriba, se actualiza el valor de las coordenadas x-y
            pantallaPreguntas.texto.place(x=xy_texto[0],y=xy_texto[1])
            pantallaPreguntas.respuesta.place(x=xy_respuesta[0],y=xy_respuesta[1])
            pantallaPreguntas.entrada_texto.place(x=xy_respuesta[0]+130,y=xy_respuesta[1])
            pantallaPreguntas.respuesta_pregunta = respuesta
            pantallaPreguntas.enviar.place(x=990,y=700)
        else:
            pantallaPreguntas.frm.destroy() # Se cierra la ventana secundaria

def cambiar():
    '''
    Cambia el texto y la imagen
    '''
    imagen_pregunta, texto_pregunta, respuesta_pregunta = obtener_pregunta()
    texto=open(texto_pregunta).read()
    imagen = PhotoImage(file=imagen_pregunta)
    respuesta = respuesta_pregunta
    pantallaPreguntas.photo.image = imagen # Se hace porque sino la imagen no se actualiza y se ve gris
    return texto, imagen, respuesta

def display_text():
    pantallaPreguntas.pantallaRespuestas = True
    string = pantallaPreguntas.entrada_texto.get()
    respuesta=pantallaPreguntas.respuesta_pregunta
    if (string == respuesta):
        pantallaPreguntas.respuestaCorrecta = True
    else: 
        pantallaPreguntas.respuestaCorrecta = False
    repetir()

root.mainloop()