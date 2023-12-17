#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include "User.h"
using namespace std;

class Cliente:public User{
    private:
        string direccionEntrega;
        double balance;
    public:
        Cliente();
        Cliente(int _userID, string _nombre, string _correo, string _contrasena, string direccionEntrega);
        ~Cliente();
        void setClientEntrega(string);
        int getClientID();
        string getClientEntrega();
};

// Constructor
Cliente ::Cliente(){};
Cliente::Cliente(int _userID, string _nombre, string _correo, string _contrasena, string _direccionEntrega):User(_userID, _nombre, _correo, _contrasena){
    direccionEntrega = _direccionEntrega;
}

// Destructor
Cliente::~Cliente(){
}

// Conseguir ID
int Cliente::getClientID(){
    return getUserID();
}
void Cliente::setClientEntrega(string _direccionEntrega){
    direccionEntrega = _direccionEntrega;
}
string Cliente::getClientEntrega(){
    return direccionEntrega;
}
#endif