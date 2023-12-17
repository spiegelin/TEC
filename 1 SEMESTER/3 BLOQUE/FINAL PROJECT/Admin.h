#ifndef ADMIN_H
#define ADMIN_H
#include "User.h"
//#include "Producto.h"
#include <stdlib.h>
#include <fstream>
using namespace std;

class Admin: public User{
    public:
        Admin(int _userID, string _nombre, string _correo, string _contrasena);
        ~Admin();
        void addProd(string, int);
        void addClient(int, string, string, string);
        void deleteProd();
        void deleteClient();  
};

Admin::Admin(int _userID, string _nombre, string _correo, string _contrasena):User(_userID, _nombre, _correo, _contrasena){

}

Admin::~Admin(){
}

void Admin::addProd(string name, int price){
    ofstream file("productos.txt", ios::app);
    file << endl << name << " " << price << " " << 1;
    file.close();
}

void Admin::addClient(int id, string name, string email, string password){
    ofstream file("users.txt", ios::app);
    file << endl << id << " " << email << " " << password << " " << name << " " << "cliente" << " ";
    file.close();
}
#endif
