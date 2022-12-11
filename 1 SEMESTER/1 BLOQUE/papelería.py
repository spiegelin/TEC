'''
Factorial

Adara y Diego Espejo 02/09/2022
'''
num = int(input("Número: "))
factorial = 1

for i in range(1, num+1):
    factorial *= i
    

print(factorial)