#ifndef TARJETA_H
#define TARJETA_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <math.h>
using namespace std;




// VALIDAR SI LA TARJETA INGRESADA ES VÁLIDA
/*
American Express: 15 digits, starts 34 or 37
MasterCard: 16 digits, starts 51, 52, 53, 54 or 55
Visa: 13 or 16 digits, starts with 4 (not always)
Multiply every digit by 2, starting with second-to-last digit, add those products, add that number to
the sum of number that weren't multiplied by 2. If the last digit is 0, number is valid
*/
// Define functions
/**/
bool validarTarjeta(long);
int countDigits(long);
bool checkNumber(long);
int firstDigits(long);

bool validarTarjeta(long num) {
    int digits = countDigits(num);
    int starts = firstDigits(num);
    bool check = checkNumber(num); // Checks if number is valid, true (1), false (0))

    if (starts >= 40 && starts <= 49) { // Checks if VISA starts with a 4, but since "starts" has two digits it has to make a range
        if (check == 1) {
            if (digits == 13 || digits == 16) {
                cout << "Tu tarjeta es VISA" << endl;
                return false; // VISA
            } else {
            printf("INVALID\n");
            return true;
            }
        } else {
            printf("INVALID\n");
            return true;
        }
    } else if (starts == 34 || starts == 37) {
        if (digits == 15 && check == 1) {
            cout << "Tu tarjeta es AMEX" << endl;
            return false; // AMEX
        } else {
            printf("INVALID\n");
            return true;
        }
    } else if (starts == 51 || starts == 52 || starts == 53 || starts == 54 || starts == 55) {
        if (digits == 16 && check == 1) {
            cout << "Tu tarjeta es MASTERCARD" << endl;
            return false; // MASTERCARD
        } else {
            printf("INVALID\n");
            return true;
        }
    } else if (starts == 1) {
        cout <<"ENCONTRASTE EL SECRETO, AHORA PUEDES PAGAR SIN TARJETA" << endl;
        return false;
    } else {
        printf("INVALID\n");
        return true;
    }
}

int countDigits(long num){
    int counter = 0;
    while (num != 0) {
        num = num / 10;
        counter++;
    }
    return counter;
}

int firstDigits(long num){
    while (num >= 100) { // Stops at the first 2 digits
        num = num / 10;
    }
    return num;
}

bool checkNumber(long num){
    int counter = 1;
    long x = num; // Store the value of the given number
    int sum1 = 0;
    int sum2 = 0;
    while (num != 0) {
        num = num / 10;

        if (counter % 2 == 0) { // since we start the counter at 1 (odd), and we need to multiply the second-to-last number, the counter at that position will be 2 (even)
            int num1 = (x % 10) * 2; // We use modulo to get the last digit
            if (num1 >= 0 && num1 < 10) { // In case the multiplied number has two digits
                sum1 += num1;
            } else {
                int y = num1;
                while(num1 != 0) {
                    num1 = num1 / 10;
                    int n = y % 10;
                    sum1 += n;
                    y = floor(y/10); // Rounds result (6.7 -> 6)
                }
            }
        } else { // if the counter is not even
            int num2 = (x % 10);
            sum2 += num2;
        }
        counter++;
        x = floor(x/10);
    }
    int finalSum = sum1 + sum2;
    int last = finalSum % 10;

    if (last == 0) {
        return true;
    }
    else {
        return false;
    }
}
#endif