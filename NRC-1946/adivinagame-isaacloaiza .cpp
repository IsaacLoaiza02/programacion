#include <iostream>
#include "arrays.h"

using namespace std;

int main() {
    srand(time(NULL));  

    int rangoInicio, rangoFin;
    cout << "Introduce el número menor del rango: ";
    cin >> rangoInicio;
    cout << "Introduce el número mayor del rango: ";
    cin >> rangoFin;

    int secreto;
    vector::llenar(&secreto, 1, rangoInicio, rangoFin); 

    int intento, intentos = 0;
    cout << "¡Adivina el número secreto entre " << rangoInicio << " y " << rangoFin << "!\n";

    do {
        cout << "Ingresa tu intento: ";
        cin >> intento;
        intentos++;

        if (intento < secreto) {
            cout << "El número es mayor. ¡Sigue intentando!\n";
        } else if (intento > secreto) {
            cout << "El número es menor. ¡Sigue intentando!\n";
        } else {
            cout << "¡Felicidades! Adivinaste el número en " << intentos << " intentos.\n";
        }

    } while (intento != secreto);

    return 0;
}

// isaac loaiza 