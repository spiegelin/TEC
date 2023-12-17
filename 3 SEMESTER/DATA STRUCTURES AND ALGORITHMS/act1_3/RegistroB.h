#ifndef REGISTROB_H
#define REGISTROB_H

#include <string>

using namespace std;


class RegistroB{
    private:

        string mes;
        int dia;
        string hora;
        string ip;
        string error;
        int numes;

    public:
        RegistroB();
        RegistroB(string mes, int numes, int dia, string hora, string ip, string error);
        bool operator > (RegistroB otro);
        bool operator < (RegistroB otro);
        bool operator == (RegistroB otro);
        bool operator <= (RegistroB otro);

        string getMes(){return mes;}
        int getDia(){return dia;}
        string getHora(){return hora;}
        string getIP(){return ip;}
        string getError(){return error;}
        int getNumes(){return numes;}


};

#endif