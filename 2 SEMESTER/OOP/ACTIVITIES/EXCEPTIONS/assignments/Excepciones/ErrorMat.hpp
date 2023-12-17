#pragma once

static const int ERROR_DOMINIO = 100; 
static const int ERROR_RANGO = 101;
class ErrorMat{ // clase para manejo de excepciones
    
    public:
        ErrorMat() : motivo(0) {}; // declaracion de constructor en formato inline
        ErrorMat(int m) : motivo(m) {};
        const char* porque() const throw();

    private:
        int motivo;
};

const char* ErrorMat::porque() const throw(){
    switch (motivo){ // segun el valor de motivo se desplegara el mensaje adecuado
    case ERROR_DOMINIO:
        return "Error de DOMINIO ";
        break;
    case ERROR_RANGO:
        return "Error de RANGO ";
        break;
    default:
        return "Error DESCONOCIDO";
    }
}