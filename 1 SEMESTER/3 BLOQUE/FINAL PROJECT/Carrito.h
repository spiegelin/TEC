#ifndef CARRITO_H
#define CARRITO_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Producto.h"
using namespace std;

class Carrito{
protected:
    vector<Producto> productosCarr;
    double totalCompra;
public:
    Carrito();
    ~Carrito();
    void addProdCar(vector<Producto>);
    void borrarProdCar();
    void displayCarrito();
    bool isProdin(string);
    vector<Producto> getVectorProducto(){
        return productosCarr;
    }
};

// Constructor
Carrito::Carrito(){
}

// Destructor
Carrito::~Carrito(){
}

// Agregar productos al carrito
void Carrito::addProdCar(vector<Producto> Productos){
    int numProd;
    cout << "---------------------------------------------------------" << endl;
    cout << "                      CATÁLOGO" <<endl;
    cout << "---------------------------------------------------------" << endl;
    int size = Productos.size();

    for(int i=0;i<size;i++){ //FOR que imprime todo el catalogo de productos
        cout << Productos[i].getNombreProducto()<< endl;
    }
    cout << "---------------------------------------------------------" << endl;
    cout << "¿Cuántos productos desea anadir?: "; cin >> numProd;
    
    for(int i=0;i<numProd;i++){ //FOR que se repite segun cuantos productos se añadiran
        string nomProd;
        cout << "Ingrese el nombre del " << i+1 << " producto que desea anadir: "; cin >> nomProd;
        bool isProdx=false;
        for(int i=0;i<size;i++){ //FOR que recorre el vector para buscar el nombre del producto a agregar
            if(nomProd==Productos[i].getNombreProducto()){
                Producto prod_anadir = Productos[i];
                cout << "Ingrese la cantidad de este producto que desea anadir: ";
                int cant =1;
                double preciouni;
                cin >> cant;

                int size2 = productosCarr.size();
                for(int i=0;i<size2;i++){ 
                    if(productosCarr[i].getNombreProducto()==nomProd){
                        int cantx = productosCarr[i].getCantidadProducto();
                        int prec = productosCarr[i].getPrecioTotal();
                        int uni = productosCarr[i].getPrecioUnitario();
                        productosCarr[i].setCantidad(cantx+cant);
                        productosCarr[i].setPrecioTotal(prec+uni*cant);
                    }
                }
                
                prod_anadir.setCantidad(cant);
                preciouni = prod_anadir.getPrecioUnitario();
                prod_anadir.setPrecioTotal((double)cant*preciouni);
                productosCarr.push_back(prod_anadir);
                
                int size3 = productosCarr.size();
                int cont = 0;
                for(int i=0;i<size3;i++){ 
                    if(productosCarr[i].getNombreProducto()==nomProd){
                        cont = cont+1;
                    }
                    if(cont>1){
                        productosCarr.pop_back();
                    }

                }
                
                isProdx=true;
            }
        }
                
        if(isProdx){
            cout << "Se anadio " << nomProd << " correctamente"<<endl;
            cout <<  "---------------------------------------------------------" << endl;
        }else{
            cout << "Lo sentimos, no contamos con ese producto. Su producto no se anadio\n"<<endl;
            i = i-1;
        }


    }
}



// Borrar productos del Carrito
void Carrito::borrarProdCar(){
    Producto producto_borrar;
    int size = productosCarr.size();
    displayCarrito();

    string nomProd;
    cout << "Ingrese el nombre del producto que desea borrar: ";
    cin >> nomProd;

    bool isDel=false;
    for(int i=0;i<size;i++){ //FOR que recorre el vector para buscar el nombre del producto a eliminar
        if(nomProd==productosCarr[i].getNombreProducto()){
            if(productosCarr[i].getCantidadProducto()==1){
                productosCarr.erase(begin(productosCarr) + i);
                }else{
                    int cant = productosCarr[i].getCantidadProducto();
                    int prec = productosCarr[i].getPrecioTotal();
                    int uni = productosCarr[i].getPrecioUnitario();
                    productosCarr[i].setCantidad(cant-1);
                    productosCarr[i].setPrecioTotal(prec-uni);
                }
            isDel=true;
        }
    }

    if(isDel){
        cout << "Se elimino el producto: " << nomProd;
    }else{
        cout << "Lo sentimos, no se pudo eliminar el producto ya que no esta en el carrito"<<endl;
    }
}


// Mostrar Carrito
void Carrito::displayCarrito(){
    cout << "---------------------------------------------------------" << endl;
    //cout << "\nEste es su carrito al momento" <<endl;
    int size = productosCarr.size();
    cout << "                      CARRITO"<<endl;
    cout << "---------------------------------------------------------"<<endl;
    cout << "     PRODUCTO         CANTIDAD         PRECIO"<<endl;
    for(int i=0;i<size;i++){ //FOR que imprimetodo el catalogo de productos
        string name = productosCarr[i].getNombreProducto();
        cout<< "     " << name;
        int maxspace = 15;
        int spaces = maxspace - name.length();
        for(int i=0;i<spaces;i++){
            cout << " ";
        }
        cout<< "      " << productosCarr[i].getCantidadProducto();
        cout<< "            " << productosCarr[i].getPrecioTotal()<< endl;
        cout<<"---------------------------------------------------------" << endl;
    }
}
#endif