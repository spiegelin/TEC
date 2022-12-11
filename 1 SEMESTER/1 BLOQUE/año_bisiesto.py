def es_bisiesto(año):
    '''
    Esta función debe recibir como parámetro un número entero que representa un año, y te debe regresar 
    True si el año es bisiesto, y False en caso contrario.

    Recuerda que un año es bisiesto si es divisible entre 4, excepto cuando es divisible entre 100. 
    Aquellos años que son divisibles entre 100 no son bisiestos, a menos que sean divisibles entre 400.
    '''
    if año % 4 == 0:
        if año % 100 == 0:
            if año % 400 == 0:
                return True
            else:
                return False
        else:
            return True
    else:
        return False

print(es_bisiesto(1996))