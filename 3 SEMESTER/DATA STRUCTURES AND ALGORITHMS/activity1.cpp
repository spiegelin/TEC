#include <iostream>

using namespace std;
int sumaRecursiva(int);

int main() {
    cout << sumaRecursiva(5) << endl;

}

int sumaRecursiva(int n) {
    // Write a function that will sum all numbers from 1 to n, where n is the argument of the function
    if (n > 1) {
        return sumaRecursiva(n-1) + n;
    } else {
        return 1;
    }
}