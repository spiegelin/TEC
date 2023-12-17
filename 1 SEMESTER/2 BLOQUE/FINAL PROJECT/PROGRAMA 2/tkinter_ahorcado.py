'''
Programa que mediante el uso de tkinter, muestra el juego del ahorcado, incrementando el vocabulario, 
para de esta forma poder entender la mayoría de las preguntas que se presentan
en el examen PISA.

07/10/2022
Diego Espejo
Gael 
'''
from palabras_random2 import palabra_random, palabra_escondida, definicion
from tkinter import *

# Crear Ventana Principal
root = Tk() 
root.title("Juego del Ahorcado")
root.geometry('1600x1000')

# Pantalla de Bienvenida
class pantallaInicio:
    window = Frame(root, 
        height=1000,
        width=1600,
        bg="black",
        )
    window.pack()

    Button(window,
        text="Jugar",
        font="Arial 30",
        command=window.destroy
        ).place(x=640,y=500) 

    Label(window,
        text="""Muy buenas, prepárate para el mejor juego de ahorcado 
    que verás el día de hoy
        
    Disfruta!""",
        font="Arial 30",
        bg="black",
        fg="yellow"
        ).place(x=300,y=200) 

# Pantalla del Juego
class pantallaJuego:
    # Ventana Secundaria
    frm = Frame(root, 
        height=1000,
        width=1600,
        bg="black"
        )
    frm.pack()

    # Imagen Ahorcado
    imagen = PhotoImage(file="/Users/spiegel/Documents/TEC/1 SEMESTRE/PENSAMIENTO COMPUTACIONAL/CODE/Proyecto Bloque/PROGRAMA 2/Fotos/0.png")
    imagen = imagen.subsample(3)
    photo = Label(frm, 
        image=imagen
        )
    photo.place(x=550, y=70)

    palabra = Label(frm,
        text="         ".join(palabra_escondida),
        font="Arial 30",
        bg="black",
        fg="white"
        )
    palabra.place(x=300,y=500)

# Pantalla de la definición de la palabra
class pantallaDefinicion:
    # Ventana secundaria
    frm2 = Frame(root, 
        height=1000,
        width=1600,
        bg="black",
        )
    frm2.pack()

    # Botón cambiar pestaña
    cambiar = Button(frm2,
        text="Siguiente",
        font="Arial 25",
        command=frm2.destroy
        ).place(x=600,y=500) 

    # Definición de la palabra
    Label(frm2,
        text=f"""Palabra: {palabra_random.title()}

Significado de la palabra:""",
        font="Arial 30",
        bg="black",
        fg="yellow"
        ).place(x=530,y=200)
    Label(frm2,
        text=f"{definicion}",
        font="Arial 30", # 30
        bg="black",
        fg="yellow"
        ).place(x=80,y=330)

# Pantalla de la despedida
class pantallaFinal:
    # Ventana secundaria
    ventana = Frame(root, 
        height=1000,
        width=1600,
        bg="black",
        )
    ventana.pack()

    # Botón salir
    salir = Button(ventana,
        text="Abandonar Juego",
        font="Arial 30",
        command=root.destroy
        ).place(x=560,y=500) 

    # Texto de salida
    Label(ventana,
        text="""Muchas gracias por haber jugado el juego, 
    espero te hayas divertido.
        
Buen Día!""",
        font="Arial 30",
        bg="black",
        fg="yellow"
        ).place(x=400,y=200) 

# Cada botón de las letras
class letras:
    A = Button(pantallaJuego.frm,
        text="A",
        font="Arial 20",
        command=lambda:revisar("A")
        ).place(x=100,y=570) 

    B = Button(pantallaJuego.frm,
        text="B",
        font="Arial 20",
        command=lambda:revisar("B")
        ).place(x=180,y=570) 
    
    C = Button(pantallaJuego.frm,
        text="C",
        font="Arial 20",
        command=lambda:revisar("C")
        ).place(x=260,y=570)

    D = Button(pantallaJuego.frm,
        text="D",
        font="Arial 20",
        command=lambda:revisar("D")
        ).place(x=340,y=570)
    
    E = Button(pantallaJuego.frm,
        text="E",
        font="Arial 20",
        command=lambda:revisar("E")
        ).place(x=420,y=570)

    F = Button(pantallaJuego.frm,
        text="F",
        font="Arial 20",
        command=lambda:revisar("F")
        ).place(x=500,y=570)

    G = Button(pantallaJuego.frm,
        text="G",
        font="Arial 20",
        command=lambda:revisar("G")
        ).place(x=580,y=570)

    H = Button(pantallaJuego.frm,
        text="H",
        font="Arial 20",
        command=lambda:revisar("H")
        ).place(x=660,y=570)

    I = Button(pantallaJuego.frm,
        text="I",
        font="Arial 20",
        command=lambda:revisar("I")
        ).place(x=740,y=570)

    J = Button(pantallaJuego.frm,
        text="J",
        font="Arial 20",
        command=lambda:revisar("J")
        ).place(x=820,y=570)

    K = Button(pantallaJuego.frm,
        text="K",
        font="Arial 20",
        command=lambda:revisar("K")
        ).place(x=900,y=570)

    L = Button(pantallaJuego.frm,
        text="L",
        font="Arial 20",
        command=lambda:revisar("L")
        ).place(x=980,y=570)

    M = Button(pantallaJuego.frm,
        text="M",
        font="Arial 20",
        command=lambda:revisar("M")
        ).place(x=1060,y=570)

    N = Button(pantallaJuego.frm,
        text="N",
        font="Arial 20",
        command=lambda:revisar("N")
        ).place(x=1140,y=570)

    O = Button(pantallaJuego.frm,
        text="O",
        font="Arial 20",
        command=lambda:revisar("O")
        ).place(x=1220,y=570)

    P = Button(pantallaJuego.frm,
        text="P",
        font="Arial 20",
        command=lambda:revisar("P")
        ).place(x=260,y=640)

    Q = Button(pantallaJuego.frm,
        text="Q",
        font="Arial 20",
        command=lambda:revisar("Q")
        ).place(x=340,y=640)

    R = Button(pantallaJuego.frm,
        text="R",
        font="Arial 20",
        command=lambda:revisar("R")
        ).place(x=420,y=640)

    S = Button(pantallaJuego.frm,
        text="S",
        font="Arial 20",
        command=lambda:revisar("S")
        ).place(x=500,y=640)

    T = Button(pantallaJuego.frm,
        text="T",
        font="Arial 20",
        command=lambda:revisar("T")
        ).place(x=580,y=640)

    U = Button(pantallaJuego.frm,
        text="U",
        font="Arial 20",
        command=lambda:revisar("U")
        ).place(x=660,y=640)

    V = Button(pantallaJuego.frm,
        text="V",
        font="Arial 20",
        command=lambda:revisar("V")
        ).place(x=740,y=640)

    W = Button(pantallaJuego.frm,
        text="W",
        font="Arial 20",
        command=lambda:revisar("W")
        ).place(x=820,y=640)

    X = Button(pantallaJuego.frm,
        text="X",
        font="Arial 20",
        command=lambda:revisar("X")
        ).place(x=900,y=640)

    Y = Button(pantallaJuego.frm,
        text="Y",
        font="Arial 20",
        command=lambda:revisar("Y")
        ).place(x=980,y=640)

    Z = Button(pantallaJuego.frm,
        text="Z",
        font="Arial 20",
        command=lambda:revisar("Z")
        ).place(x=1060,y=640)

def revisar(letra):
    '''
    Revisa si la letra está dentro de la palabra
    '''
    if letra in palabra_random:
            for i in range(len(palabra_random)):
                if letra == palabra_random[i]:
                    palabra_escondida[i] = letra

            pantallaJuego.palabra.config(text="         ".join(palabra_escondida))
            if "_ " not in palabra_escondida:
                Label(pantallaJuego.frm,
                    text=f"""Que inteligente, lograste ganar!!!
                        
        Espero que con este juego poco a poco vaya mejorando tu vocabulario y las palabras que conoces""",
                    bg="black",
                    fg="yellow",
                    font="Arial 30").place(x=0,y=300) 

                Button(pantallaJuego.frm,
                    text="Salir",
                    font="Arial 35",
                    command=pantallaJuego.frm.destroy
                    ).place(x=620,y=450) 
    else:
        pantallaJuego.photo.config(image=cambiar_imagen())

errores = 0 # Tener un contador de cuantos errores tiene el usuario
def cambiar_imagen():
    """
    Cambia la imagen en caso de que se haya equivocado
    """
    global errores # Se refiere a que quiero accesar a la variable global "errores", sino se hace esto, python no entendería a que variable me refiero
    errores += 1
    if errores == 1:
        imagen = PhotoImage(file="/Users/spiegel/Documents/TEC/1 SEMESTRE/PENSAMIENTO COMPUTACIONAL/CODE/Proyecto Bloque/PROGRAMA 2/Fotos/1.png")
    elif errores == 2:
        imagen = PhotoImage(file="/Users/spiegel/Documents/TEC/1 SEMESTRE/PENSAMIENTO COMPUTACIONAL/CODE/Proyecto Bloque/PROGRAMA 2/Fotos/2.png")
    elif errores == 3:
        imagen = PhotoImage(file="/Users/spiegel/Documents/TEC/1 SEMESTRE/PENSAMIENTO COMPUTACIONAL/CODE/Proyecto Bloque/PROGRAMA 2/Fotos/3.png")
    elif errores == 4:
        imagen = PhotoImage(file="/Users/spiegel/Documents/TEC/1 SEMESTRE/PENSAMIENTO COMPUTACIONAL/CODE/Proyecto Bloque/PROGRAMA 2/Fotos/4.png")
    elif errores == 5:
        imagen = PhotoImage(file="/Users/spiegel/Documents/TEC/1 SEMESTRE/PENSAMIENTO COMPUTACIONAL/CODE/Proyecto Bloque/PROGRAMA 2/Fotos/5.png")
    else:
        imagen = PhotoImage(file="/Users/spiegel/Documents/TEC/1 SEMESTRE/PENSAMIENTO COMPUTACIONAL/CODE/Proyecto Bloque/PROGRAMA 2/Fotos/6.png")
        
        Label(pantallaJuego.frm,
            text=f"""   Perdiste :(
        Palabra Correcta: {palabra_random.title()}""",
            bg="black",
            fg="yellow",
            font="Arial 40").place(x=380,y=300) 

        Button(pantallaJuego.frm,
            text="Siguiente",
            font="Arial 35",
            command=pantallaJuego.frm.destroy
            ).place(x=600,y=450) 

    imagen = imagen.subsample(3)
    pantallaJuego.photo.image = imagen
    return imagen

root.mainloop()