#ifndef PEDIDO_H
#define PEDIDO_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <math.h>
#include "validarTarjeta.h"
#include "Cliente.h"
#include "Carrito.h"
using namespace std;

class Pedido{
    protected:
        int pedidoID;
        string detallesEnvio;
        double totalCompra;
    public:
        Pedido(int, string, double);
        Pedido();
        ~Pedido();
        int iniciarPedido(vector<Producto>, Cliente);
        int getPedidoID();
};

// Constructor
Pedido::Pedido(){}
Pedido::Pedido(int _pedidoID, string _detallesEnvio, double _totalCompra){
    pedidoID = _pedidoID;
    detallesEnvio = _detallesEnvio;
    totalCompra = _totalCompra;
}

// Destructor
Pedido::~Pedido(){
}

// Finalizar Pedido
//void Pedido::iniciarPedido(vector<Producto> _ProductosCarrito){
// Finalizar Pedido
int Pedido::iniciarPedido(vector<Producto> ProductosCarro, Cliente cliente){
    printf("---------------------------------------------------------\n");
    int opc; 
    string nombreTitular, cvv, direccionEntrega;
    long numeroTarjeta;
    bool validada = true;
    vector<Producto> _ProductosCarrito;
    _ProductosCarrito = ProductosCarro;
    cout << _ProductosCarrito[0].getNombreProducto() << endl;

    // Imprimir cada producto
    printf("Estos son los productos a comprar: \n");
    for (int i=0; i < _ProductosCarrito.size(); i++){
        string nombreProductos = _ProductosCarrito[i].getNombreProducto();
        printf("- %s (%i) ($%.2f)\n", nombreProductos.c_str(), _ProductosCarrito[i].getCantidadProducto(), _ProductosCarrito[i].getPrecioTotal());
    }

    // Método de pago
    cout << "---------------------------------------------------------" << endl;
    cout << "Ingrese la dirección de entrega: "; cin >> direccionEntrega; //cliente.setClientEntrega(direccionEntrega);
    cout << "---------------------------------------------------------" << endl;
    cout << "Elije tu método de pago: \n1. Tarjeta de Crédito\n2. Tarjeta de Débito\nElije una opción: "; cin >> opc;
    cout << "---------------------------------------------------------" << endl;
    cout << "Ingrese los datos de la tarjeta: " << endl;
    cout << "Ingrese el nombre del titular de la tarjeta: "; cin >> nombreTitular;
    
    do {
        cout << "Ingrese el número de la tarjeta: "; cin >> numeroTarjeta; // Validar tarjeta
        validada = validarTarjeta(numeroTarjeta);
    } while(validada == true);
    
    do {
        printf("Ingrese el CVV: "); cin >> cvv; // Validar cvv
        if (cvv.length() != 3) {
            printf("El CVV contiene únicamente 3 dígitos\n");
        }
    } while (cvv.length() != 3);

    // Resumen del Pedido
    cout << "---------------------------------------------------------" << endl;
    cout << "                    RESUMEN DE PEDIDO " << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "                          NOMBRE " << endl << cliente.getUserName().c_str() << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "                          CORREO " << endl << cliente.getUserEmail().c_str() << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "                      MÉTODO DE PAGO" << endl;
    cout << "Tarjeta: " << numeroTarjeta << endl;
    cout << "Titular: " << nombreTitular << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "                     DIRECCIÓN ENTREGA " << endl << direccionEntrega.c_str() << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "                         PRODUCTOS" << endl; // Imprimir cada producto
    double total = 0;
    for (int i=0; i< _ProductosCarrito.size(); i++){
        string nombreProductos = _ProductosCarrito[i].getNombreProducto();
        printf("- %s (%i) ($%.2f)\n", nombreProductos.c_str(), _ProductosCarrito[i].getCantidadProducto(), _ProductosCarrito[i].getPrecioTotal());
        total = total + _ProductosCarrito[i].getPrecioTotal();
    }
    cout << "---------------------------------------------------------" << endl;
    cout << "                           TOTAL" << endl;
    cout << "$" << total << endl;
    cout << "---------------------------------------------------------" << endl;
    
    // Finalizar 
    opc = 0;
    printf("\n¿Confirmar? (1)\nRegresar (2)\nElección: "); cin >> opc;
    if (opc == 1){
        printf("¡¡¡Se ha completado el pago, el pedido llegará pronto a %s!!!\n", direccionEntrega.c_str());
        printf("Gracias por usar nuestro servicio :)\n");
        cliente.~Cliente(); // Logout
        return 1;
        //EXIT_SUCCESS;
    } else {
        cout << "---------------------------------------------------------" << endl;
        //main();
        //menuCliente(cliente);
        return 0;
        //EXIT_FAILURE;
    }
}

int Pedido::getPedidoID(){
    return pedidoID;
}

// vector<Producto> productosCarr;
// Ingresa dirrrecion de entrega -> setClientEntrega("Calle sabe cual");
#endif