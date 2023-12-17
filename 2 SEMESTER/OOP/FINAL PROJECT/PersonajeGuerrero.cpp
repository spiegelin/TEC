#include "PersonajeGuerrero.hpp"
#include <cstdlib> // Para los números aleatorios
#include <random>
#include <chrono>
#include <thread>

// Constructores
PersonajeGuerrero::PersonajeGuerrero(){}

PersonajeGuerrero::PersonajeGuerrero(std::string _nombre, std::string _desc, Mundo* _ubi,int _tipo, int _saludTotal, int _saludActual, int _maxAtaque):Personaje(_nombre, _desc, _ubi, _tipo) {
    setSaludTotal(_saludTotal);
    saludActual = _saludActual;
    maxAtaque = _maxAtaque;
}

// Destructor
PersonajeGuerrero::~PersonajeGuerrero(){}

// Getters
int PersonajeGuerrero::getSaludTotal() {
    return saludTotal;
}

int PersonajeGuerrero::getSaludActual() {
    return saludActual;
}

int PersonajeGuerrero::getMaxAtaque() {
    return maxAtaque;
}

// Setters
void PersonajeGuerrero::setSaludTotal(int _saludTotal) {
    try {
        if (_saludTotal == 0) {
            throw "Error 222: Se otorgó 0 puntos de vida.";
        }
        saludTotal = _saludTotal;
    } catch(const char* msg) {
        std::cout << msg << " Tendré que reiniciar el programa" << std::endl;
        std::cout << "Nombre de personaje: " << getNombre() << std::endl;

        exit(-1);
    }
}

void PersonajeGuerrero::setSaludActual(int _saludActual) {
    // Evitar valores negativos
    if (_saludActual < 0) {
        saludActual = 0;
    } else if (_saludActual > getSaludTotal()) {
        saludActual = getSaludTotal(); // Para que no teng vida extra, y si es mayor a su vida máxima, se resetee
    } else {
        saludActual = _saludActual;
    } 
}

void PersonajeGuerrero::setMaxAtaque(int _maxAtaque) {
    maxAtaque = _maxAtaque;
}

// Métodos
bool PersonajeGuerrero::isAlive() {
    if (getSaludActual() > 0) {
        return true;
    } else {
        return false;
    }
}

int PersonajeGuerrero::porcentajeSalud()  {
    return ((getSaludTotal() - getSaludActual()) * 100) / getSaludTotal();
}

void PersonajeGuerrero::barraVida() {
    int max = 20;
    int cantP = (porcentajeSalud() * max) / 100;
    int cantI = max - cantP;

    for (int i = 0; i < cantI; i++) {
        std::cout << "%";
    }

    for (int i = 0; i < cantP; i++) {
        std::cout << "=";
    } 
    std::cout << std::endl;
}

void PersonajeGuerrero::imprime() {
    Personaje::imprime();
    std::cout << "SALUD: "; barraVida();
    std::cout << "-------------------------------------" << std::endl;
}
/*
int PersonajeGuerrero::juega() {
    int num = std::rand() % getMaxAtaque()+1; // de 0 al ataque Máximo
    return num;
}
*/
int PersonajeGuerrero::juega(int opcion) {
    if (opcion == 1) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, getMaxAtaque());
        return dis(gen);
    } else if (opcion == 2) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, getMaxAtaque() * 1.2);
        return dis(gen);
    } else if (opcion == 15) {
        return 1000;
    } else {
        return 0;
    } 
}

void PersonajeGuerrero::recibeInteraccion(int num) {
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "OHHHH NO " << Personaje::getNombre() << " RECIBIÓ " << num << " PUNTOS DE DAÑO " << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    setSaludActual(getSaludActual() - num);

    if (getSaludActual() <= 0) {
        std::cout << Personaje::getNombre() << " MURIÓ..." << std::endl;
        std::cout << "-------------------------------------" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    } else {
        imprime();
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    }
}