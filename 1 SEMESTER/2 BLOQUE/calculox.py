import math as m

vi = 41.57

angulo = m.radians(30)

g = 9.81
h = 0.94

r = ((vi**2)*(m.sin(angulo))*(m.cos(angulo))) + (vi*m.cos(angulo)*(m.sqrt((m.sin(angulo))**2 + (2*g*h))))

print(r)