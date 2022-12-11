'''
Construir un programa que calcule y muestre por pantalla las raíces de la ecuación 
de segundo grado de coeficientes reales. Los valores de los coeficientes se indican 
en el propio código del programa mediante sentencias de asignación a variables reales. 
Siendo la ecuación de segundo grado de la forma: f(x)=a·x^2+b·x +c.

Diego Espejo 19/08/2022
'''
from math import sqrt # Importa raíz de la librería math
a = 1 # Valores de el coeficiente a
b = 7 # Valores de el coeficiente b
c = 10 # Valores de el coeficiente c

print(f'''La ecuación de segundo grado es: {a}x2 + {b}x + {c}

El coeficiente a es: {a}
El coeficiente b es: {b}
El coeficiente c es: {c}\n''')

x1 = (-b + (sqrt(b**2 - (4*a*c)))) / (2*a) # Solución de raíces
x2 = (-b - (sqrt(b**2 - (4*a*c)))) / (2*a)

print(f"La raíz x1 es igual a: {x1:.2f}") # Redondear a 2 decimales
print(f"La raíz x2 es igual a: {x2:.2f}")