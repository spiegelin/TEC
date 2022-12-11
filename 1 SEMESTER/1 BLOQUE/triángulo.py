def checar_tri():  
    a = float(input("Indica un lado del trángulo: "))
    b = float(input("Indica un lado del trángulo: "))
    c = float(input("Indica un lado del trángulo: "))

    if (a + b > c) and (a + c > b) and (b + c > a):
        if (a == b and a != c) or (b == c and b != a) or (a == c and a != b):
            print("El trángulo es isóceles")
        elif (a == b) and (a == c):
            print("El triángulo es equilátero")
        else:
            print("El triángulo es escaleno")
    else:
        print("La suma de dos lados tiene que ser mayor al tercero")

checar_tri()