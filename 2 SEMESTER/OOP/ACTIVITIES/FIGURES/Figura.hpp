#pragma once    
#include <iostream>

class Figura{
    public:
        Figura();
        Figura(int,int);
        int getX() const;
        int getY() const;
        void setX(int);
        void setY(int);
        virtual std::string dibuja(); // Polimorfismo en tiempo de ejecución, manejadores en clase base
        virtual double area() = 0; // Hacerla clase abstracta (no la puedes instanciar - sirve de esqueleto)
        friend std::ostream& operator<<(std::ostream&, Figura&); // Es friend porque el primer operando no pertenece a la clase, no es miembro, el segundo si lo es, pero tiene que ser el primero
    private:
        int x, y;
};