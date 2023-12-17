#pragma once
#include <stdexcept> 
// clase derivada de Exception
// para probar sobreescritura de metodo what
class DivCero : public std::exception
{
public:
    const char* what() const throw() {
        return "Error: division por cero...";
    }
};
