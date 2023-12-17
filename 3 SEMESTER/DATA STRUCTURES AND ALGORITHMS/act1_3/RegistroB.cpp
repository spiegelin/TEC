
#include <string>
using namespace std;

#include "RegistroB.h"

RegistroB::RegistroB(){
    this->mes = "";
    this->dia = 0;
    this->hora = "";
    this->ip = "";
    this->error = "";
    this->numes = 0;
}

RegistroB::RegistroB(string mes, int numes,int dia, string hora, string ip, string error){
    this->mes = mes;
    this->dia = dia;
    this->hora = hora;
    this->ip = ip;
    this->error = error;
    this->numes = numes;
}

bool RegistroB::operator> (RegistroB otro){
    if (this->numes > otro.numes){
        return true;
    }else if (this->numes == otro.numes){
        if (this->dia > otro.dia){
            return true;
        }else if (this->dia == otro.dia){
            if (this->hora > otro.hora){
                return true;
            
            }else{
                return false;
            }
        }else{
            return false;
        }
    }else{
        return false;
    }
}

bool RegistroB::operator< (RegistroB otro){
    if (this->numes < otro.numes){
        return true;
    }else if (this->numes == otro.numes){
        if (this->dia < otro.dia){
            return true;
        }else if (this->dia == otro.dia){
            if (this->hora < otro.hora){
                return true;
            
            }else{
                return false;
            }
        }else{
            return false;
        }
    }else{
        return false;
    }
}

bool RegistroB::operator == (RegistroB otro){

    if (this->numes == otro.numes && this->dia == otro.dia && this->hora == otro.hora){
        return true;
    }else{
        return false;
    }
}


bool RegistroB::operator <= (RegistroB otro){
    return (*this<otro) || (*this == otro);
}