#include <iostream>
#include <vector>

using namespace std;

// Declaración de funciones
void imprimeVector(vector<int>);

void ordenaInsercion(vector<int>&);
void ordenaBurbuja(vector<int>&);
void ordenaMerge(vector<int>&, int, int);
void merge(vector<int>&, int, int, int);

int busqSecuencial(vector<int>, int);
int busqBinariaIterativa(vector<int>, int);
int busqBinariaRecursiva(vector<int>, int, int, int);

// Programa principal
int main() {
    // Vectores desordenados
    vector<int> n1;
    n1.push_back(14);
    n1.push_back(3);
    n1.push_back(1);
    n1.push_back(34);
    n1.push_back(2);
    n1.push_back(29);

    vector<int> n2;
    n2.push_back(8);
    n2.push_back(125);
    n2.push_back(432);
    n2.push_back(1);
    n2.push_back(19);
    n2.push_back(4);

    vector<int> n3;
    n3.push_back(5);
    n3.push_back(0);
    n3.push_back(4);
    n3.push_back(3);
    n3.push_back(1);
    n3.push_back(2);
    
    // Vector ordenado
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    A.push_back(5);
    A.push_back(6);
    A.push_back(8);
    A.push_back(10);
    A.push_back(12);
    A.push_back(14);
    A.push_back(16);    

    // Ordenamiento de Inserción
    cout << "Vector original: ";
    imprimeVector(n1);
    cout << "Inserción: ";
    ordenaInsercion(n1);
    imprimeVector(n1);
    cout << endl;

    // Ordenamiento Burbuja
    cout << "Vector original: ";
    imprimeVector(n2);
    cout << "Burbuja: ";
    ordenaBurbuja(n2);
    imprimeVector(n2);
    cout << endl;

    // Ordenamiento Merge
    cout << "Vector original: ";
    imprimeVector(n3);
    cout << "Merge: ";
    ordenaMerge(n3, 0, n3.size()-1);    
    imprimeVector(n3);
    cout << endl;

    // Vector ordenado
    cout << "Vector: " << endl;
    imprimeVector(A);
    cout << endl;

    // Casos prueba
    int v1, v2, v3, v4;
    v1 = 4;
    v2 = 12;
    v3 = 7;
    v4 = 16;

    // Búsqueda Secuencial
    cout << "Búsqueda Secuencial" << endl;
    cout << "Índice del número " << v1 << " es: " << busqSecuencial(A, v1) << endl;
    cout << "Índice del número " << v2 << " es: " << busqSecuencial(A, v2) << endl;
    cout << "Índice del número " << v3 << " es: " << busqSecuencial(A, v3) << endl;
    cout << "Índice del número " << v4 << " es: " << busqSecuencial(A, v4) << endl;
    cout << endl;

    // Búsqueda Binaria Iterativa
    cout << "Búsqueda Binaria Iterativa" << endl;
    cout << "Índice del número " << v1 << " es: " << busqBinariaIterativa(A, v1) << endl;
    cout << "Índice del número " << v2 << " es: " << busqBinariaIterativa(A, v2) << endl;
    cout << "Índice del número " << v3 << " es: " << busqBinariaIterativa(A, v3) << endl;
    cout << "Índice del número " << v4 << " es: " << busqBinariaIterativa(A, v4) << endl;
    cout << endl;

    // Búsqueda Binaria Recursiva
    int L = 0;
    int R = A.size() - 1;
    cout << "Búsqueda Binaria Recursiva" << endl;
    cout << "Índice del número " << v1 << " es: " << busqBinariaRecursiva(A, v1, L, R) << endl;
    cout << "Índice del número " << v2 << " es: " << busqBinariaRecursiva(A, v2, L, R) << endl;
    cout << "Índice del número " << v3 << " es: " << busqBinariaRecursiva(A, v3, L, R) << endl;
    cout << "Índice del número " << v4 << " es: " << busqBinariaRecursiva(A, v4, L, R) << endl;
    cout << endl;
}

// Función para imprimir vectores
void imprimeVector(vector<int> A) {
    // Pasa por cada elemento del vector para despues imprimirlo
    for (int i = 0; i < A.size(); ++i) {
        cout << " " << A[i];
    }
    cout << endl;
}

// Ordenamiento de Inserción
void ordenaInsercion(vector<int> &A) {
    // Iniciamos el loop desde el 2 elemento
    for (int i = 1; i < A.size(); i++) {
        int key = A[i];  // Guardamos el valor actual en key

        // Insertamos n[i] en la secuencia sorteada
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j+1] = A[j];  // Se mueven los números mayores a la derecha
            j = j - 1;  // Se mueve el índice a la izquierda
        }
        A[j+1] = key;
    }
}

// Ordenamiento Burbuja
void ordenaBurbuja(vector<int> &A) {
    // Recorre todo el vector
    for (int i = 0; i < A.size(); ++i) {
        // Recorre la parte no ordenada
        for (int j = 0; j < A.size() - i - 1; ++j) {
            if (A[j] > A[j+1]) {
                // Swap de valores
                int temp = A[j]; 
                A[j] = A[j+1]; 
                A[j+1] = temp; 
            }
        }
    }
}

// Ordenamiento Merge
void merge(vector<int> &A, int l, int m, int r) {
    // Dividimos el array en 2
    int n1 = m - l + 1;
    int n2 = r - m;

    // Se generan dos nuevos subarrays
    vector<int> L(n1);
    vector<int> R(n2);

    // Los rellenamos con los datos del vector original
    for (int i = 0; i < n1; i++)
        L[i] = A[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[m + 1 + j];

    // Se combinan los vectores pero a la vez se van comparando
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    // En caso de que haya elementos restantes en alguno de los subarrays
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

void ordenaMerge(vector<int>& A, int l, int r) {
    if (l < r) {
        int m = ((l + r) / 2);

        // Recursividad
        ordenaMerge(A, l, m);
        ordenaMerge(A, m+1, r);

        // Combina los subarrays
        merge(A, l, m, r);
    }
}

// Búsqueda Secuencial
int busqSecuencial(vector<int> A, int n) {
    // Se recorre el vector completo y se compara cada dato con el esperado, sino existe se regresa -1
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == n) {
            return i;
        }
    }
    return -1;
}

// Búsqueda Binaria Iterativa
int busqBinariaIterativa(vector<int> A, int n) {
    // Se definen los límites low y high
    int L = 0;
    int R = A.size() - 1;

    while (L <= R) {
        int M = (L + R) / 2;

        // Diferentes casos, si se encuentra en el medio regresarlo, sino mover algún límite según el caso
        if (n == A[M]) { 
            return M;
        } else if (n > A[M]) {
            L = M + 1;
        } else {
            R = M - 1;
        }
    }
    return -1;
}


// Búsqueda Binaria Recursiva
int busqBinariaRecursiva(vector<int> A, int n, int L, int R) {
    // Caso Recursivo
    if (L <= R) {
        int M = (L + R) / 2;

        // Prácticamente mismo caso que con el iterativo, si el de en medio es lo regresa, sino cambia los límites
        if (A[M] == n) {
            return M;
        }
        else if (A[M] < n) {
            return busqBinariaRecursiva(A, n, M + 1, R);
        }
        else {
            return busqBinariaRecursiva(A, n, L, M - 1);
        }
    }
    return -1;
}