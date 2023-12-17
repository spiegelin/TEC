#pragma once
// Agrega los include que te hagan falta

//Genera la definición de la clase ProfesorHoras, recuerda que deriva de Profesor
#include "Profesor.hpp"
//Definición de la clase ProfesorHoras

class ProfesorHoras: public Profesor {
    public:
        // Constructores
        ProfesorHoras();
        ProfesorHoras(int, double, int);
        
        
        // Getters
        int getHoras();

        // Setters
        //void setHoras(int);

        // Métodos
        double calculaSueldoFinal() override;       
    private:
        int horas;
};