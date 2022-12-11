#ifndef USER_H
#define USER_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream> 
#include <cstring>
#include <algorithm>
using namespace std;

class User{
    protected:
        int userID;
        string nombre, correo, contrasena, clave;
    public:
        User(int, string, string, string);
        User();
        ~User();
        bool buscar(User);
        User login(User, bool&, bool&);
        void logout();  //ver como se hace el logout
        int getUserID();
        string getUserName();
        string getUserEmail();
        string getUserClave();
        void setUserID(int);
        void setUserEmail(string);
        void setUserPassword(string);
        void setUserName(string);
        void setUserClave(string);
        string getUserPassword(); // Checar
};

// Constructores
User::User(int _userID, string _nombre,  string _correo, string _contrasena){
    userID = _userID;
    nombre = _nombre;
    correo = _correo;
    contrasena = _contrasena;
}
User::User(){}
// Destructor
User::~User(){}

//Ingresar a la sesion
User User::login(User _usuario, bool &clave, bool &cuentaExiste){
    /*
    Primero se busca en el archivo .txt por columna, después se agrega en cada variable,
    se verifica si el correo y la contraseña existen, si es así se crea actualiza y regresa un objeto 
    con todos los atributos guardados en el .txt y se actualiza clave a true, si no se encuentran 
    el correo y la contraseña en la misma fila se regresa el objeto sin modificaciones.

    Después se verifica su clave para saber si el usuario es admin o cliente y se regresa como referencia
    el valor clave indicando true si es admin o false si es cliente
    */
    ifstream file("users.txt");
    string texto;
    int count = 0;
    int _usuarioID;
    string _usuarioEmail, _usuarioPassword, _usuarioNombre, _usuarioClave;
    while (getline(file, texto)) { // Se repite según la cantidad de líneas en el documento
        istringstream ss(texto); // Agarra la linea actual y la hace string
        while(ss){ // Itera en toda el documento hasta que se acabe
            switch(count) {
                case 0: // Obtener el ID
                    ss >> _usuarioID;
                case 1: // Obtener el Email
                    ss >> _usuarioEmail;
                case 2: // Obtener la Contraseña
                    ss >> _usuarioPassword;
                case 3: // Obtener el Nombre
                    ss >> _usuarioNombre;
                case 4: // Obtener la Clave
                    ss >> _usuarioClave;
            }
            count++;
            if (_usuarioEmail == _usuario.getUserEmail() && _usuarioPassword == _usuario.getUserPassword()) {
                _usuario.setUserID(_usuarioID); // Se actualizan valores según lo guardado en el .txt
                _usuario.setUserName(_usuarioNombre); 
                _usuario.setUserClave(_usuarioClave);
                cuentaExiste = true; // Indica que si tiene una sesión iniciada
                if (_usuarioClave == "admin"){
                    clave = true; 
                }
                file.close();
                return _usuario;
            }
        } 
        count = 0;
    }
    file.close();
    return _usuario;
}

// Salirse de la sesión
void User::logout(){
    
}

// Busca si ya hay datos registrados
bool User::buscar(User usuario){
    ifstream file("users.txt");
    string texto, _usuarioNombre, _usuarioClave;
    int _usuarioID;
    int count = 0;
    string correo, contrasena;
    while (getline(file, texto)) { // Se repite según la cantidad de líneas en el documento
        istringstream ss(texto); // Agarra la linea actual y la hace string
        while(ss){ // Itera en toda el documento hasta que se acabe
            switch(count) {
                case 0: // Obtener el ID
                    ss >> _usuarioID;
                case 1: // Obtener el Email
                    ss >> correo;
                case 2: // Obtener la Contraseña
                    ss >> contrasena;
                case 3: // Obtener el Nombre
                    ss >> _usuarioNombre;
                case 4: // Obtener la Clave
                    ss >> _usuarioClave;
            }
            count++;
            if (correo == usuario.getUserEmail() || contrasena == usuario.getUserPassword()) {
                file.close();
                return false;
            }
        } 
        count = 0;
    }
    file.close();
    return true;
}
// Getters
int User::getUserID(){
    return userID;
}
string User::getUserName(){
    return nombre;
}
string User::getUserEmail(){
    return correo;
}
string User::getUserPassword(){
    return contrasena;
}
string User::getUserClave(){
    return clave;
}

// Setters
void User::setUserID(int _ID){
    userID = _ID;
}
void User::setUserEmail(string _correo){
    correo = _correo;
}
void User::setUserPassword(string _contrasena){
    contrasena = _contrasena;
}   
void User::setUserName(string _name){
    nombre = _name;
}
void User::setUserClave(string _clave){
    clave = _clave;
}
#endif