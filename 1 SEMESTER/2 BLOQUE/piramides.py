# Pirámide Números
n = int(input("De cuántos renglones?: "))
for i in range(1, n+1):
    for j in range(1, i+1):
        print(j, end=" ")
    print()

# Pirámide asterísticos
n = int(input("De cuántos renglones?: "))
for i in range(1, n+1):
    print("*"*i)

# Pirámide Invertida
n = int(input("De cuántos renglones?: "))
for i in range(1, n+1):
    print(" "*i, end=" ")
    for j in range(i, n+1):
        print("*", end="")
    print()

# Pirámide invertida números
n = int(input("De cuántos renglones?: "))
pos = n
for i in range(1, n+1):
    for j in range(pos, 0, -1):
        print(j, end=" ")
    print()
    pos -= 1

# Triángulo equilátero
n = int(input("De cuántos renglones?: "))
pos = n
for i in range(1, n+1):
    print(" "*pos, end=" ")
    for j in range(1, i+1):
        print(j, end=" ")
    print()
    pos -= 1