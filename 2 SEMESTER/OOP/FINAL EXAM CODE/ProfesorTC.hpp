// No olvides la instrucción que hace que no de duplique en memoria la defición de la clase

//Escribe la declaración de la clase ProfesorTC, recuerda que deriva de Profesor
#pragma once
#include "Profesor.hpp"
//Definición de la clase ProfesorTC

class ProfesorTC: public Profesor {
    public:
        // Constructores
        ProfesorTC();
        ProfesorTC(int, double, int);
        
        
        // Getters
        int getIncentivo();

        // Setters
        void setIncentivo(int);

        // Métodos
        double calculaSueldoFinal() override;       
    private:
        int incentivo;
};