#include <iostream>
#include "Tiempo.hpp"
using namespace std;

/* Este el main que prueba todos los operadores sobrecargados*/

int main() {
    Tiempo t1, t2, t4, t5;
    Tiempo t3, t6, t7(15, 59), t8(0,0), t9;
    char opcion = ' ';
    // recibir los valores para t1, t2, t4 y t5
    cout << "Ingrese los valores crear 4 Tiempos, dos valores por renglón separados por 1 espacio." << endl;
    cin >> t1;
    cin >> t2;
    cin >> t4;
    cin >> t5;
    while (opcion != 'h'){
        cout<<"a - Suma tiempo con tiempo función miembro"<<endl;
        cout<<"b - Suma tiempo con minutos función miembro"<<endl;
        cout<<"c - Suma minutos con tiempo función friend"<<endl;
        cout<<"d - Incrementa 1 minuto función miembro"<<endl;
        cout<<"e - Decrementa 1 minuto función friend"<<endl;
        cout<<"f - Agrega tiempo a tiempo función friend"<<endl;
        cout<<"g - Operador > tiempo con tiempo, función miembro"<<endl;
        cout<<"h - Salir"<<endl;
        cout << "------------------------------------------" << endl;
        cout<<"\tIngrese una opción: ";
        cin >> opcion;
        cout << "------------------------------------------" << endl;
        switch (opcion) {
            case 'a':
                // + SUMA tiempo con tiempo miembro
                t3 = t1 + t2;
                cout << t1 << " + " << t2 << " = " << t3 << endl;
                t6 = t4 + t5;
                cout << t4 << " + " << t5 << " = " << t6 << endl;
                cout << "------------------------------------------" << endl;
                break;
                
            case 'b':
                // + SUMA tiempo con minutos miembro
                t3 = t2 + 10;
                cout << t2 << " + " << 10 << " = " << t3 << endl;
                t3 = t2 + 190;
                cout << t2 << " + " << 190 << " = " << t3 << endl;
                cout << "------------------------------------------" << endl;
                break;       
            case 'c':
                // + SUMA minutos con tiempo friend
                t3 = 45 + t2;
                cout << 45 << " + " << t2 << " = " << t3 << endl;            
                t3 = 90 + t2;
                cout << 90 << " + " << t2 << " = " << t3 << endl;
                cout << "------------------------------------------" << endl;
                break;
            case 'd':
                // ++ Incrementa 1 minuto función miembro
                cout << "Antes de incrementar: " << t2 << endl;
                ++t2;
                cout << "Después de incrementar: " << t2 << endl; 
                cout << "Antes de incrementar: " << t7 << endl;
                ++t7;
                cout << "Después de incrementar: " << t7 << endl;
                cout << "------------------------------------------" << endl;
                break;

            case 'e':
                // -- Decrementa 1 minuto   friend
                cout << "Antes de decrementar: " << t2 << endl; 
                --t2;
                cout << "Después de decrementar: " << t2 << endl; 
                cout << "Antes de decrementar: " << t8 << endl; 
                --t8;
                cout << "Después de decrementar: " << t8 << endl;
                cout << "------------------------------------------" << endl;
                break;
            case 'f':
                // += Agrega tiempo a tiempo función friend
                cout << "t2 antes de agregarle t4: " << t2 << endl;
                cout << "Valor de t4: " << t4 << endl;
                t2 += t4;
                cout << "Después de agregarle t2 a t4: " << t2 << endl;
                cout << "t7 antes de agregarle t5: " << t7 << endl;
                cout << "Valor de t5: " << t5 << endl;
                t7 += t5;
                cout << "Después de agregarle t5 a t7: " << t7 << endl;
                cout << "------------------------------------------" << endl;
                break;        
            case 'g':
                // > Regresa true si el primer tiempo es mayor que el segundo  miembro
                cout << "t1 -> " << t1 << endl;
                cout << "t2 -> " << t2 << endl;
                if (t1 > t2)
                    cout << "t1 mayor a t2" << endl;
                else
                    cout << "t1 no es mayor a t2" << endl;
                cout << "t4 -> " << t4 << endl;
                cout << "t5 -> " << t5 << endl;
                if (t4 > t5){
                    cout << "t4 mayor a t5" << endl;
                }else{
                    cout << "t4 no es mayor a t5" << endl;
                }
                cout << "------------------------------------------" << endl;
                break;
            case 'h':
                cout << "Saliendo..." << endl;
                cout << "------------------------------------------" << endl;
                break;
            default:
                cout << "Opción no válida" << endl; 
                cout << "------------------------------------------" << endl;    
            }
    }
    return 0;
}