#pragma once // prevents multiple definitions
//Definición de la clase Profesor

class Profesor {
    public:
        // Constructores
        Profesor();
        Profesor(int, double);
        
        
        // Getters
        double getSueldoBase();
        int getNumNomina();

        // Setters
        void setSueldoBase(double);
        void setNumNomina(int);

        // Métodos
        virtual double calculaSueldoFinal() = 0;
        bool operator==(Profesor&);        
    private:
        int numNomina;
        double sueldoBase;
};