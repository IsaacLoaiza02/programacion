#include <iostream>
using namespace std;

// Función para calcular la suma de los divisores propios de un número
int SumaDivisoresPropios(int n) {
    int suma = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            suma += i;
        }
    }
    return suma;
}

// Función para verificar si un número es abundante
bool EsAbundante(int n) {
    return SumaDivisoresPropios(n) > n;
}

// Función para verificar si un número es deficiente
bool EsDeficiente(int n) {
    return SumaDivisoresPropios(n) < n;
}

// Función para verificar si dos números son amigos
bool SonAmigos(int a, int b) {
    return SumaDivisoresPropios(a) == b && SumaDivisoresPropios(b) == a;
}

// Función principal
int main() {
    int opcion;

    cout << "Seleccione una opción:" << endl;
    cout << "1. Verificar si un número es abundante" << endl;
    cout << "2. Verificar si un número es deficiente" << endl;
    cout << "3. Verificar si dos números son amigos" << endl;
    cin >> opcion;

    switch (opcion) {
        case 1: {
            int numero;
            cout << "Ingrese un número: ";
            cin >> numero;
            if (EsAbundante(numero)) {
                cout << numero << " es un número abundante." << endl;
            } else {
                cout << numero << " no es un número abundante." << endl;
            }
            break;
        }
        case 2: {
            int numero;
            cout << "Ingrese un número: ";
            cin >> numero;
            if (EsDeficiente(numero)) {
                cout << numero << " es un número deficiente." << endl;
            } else {
                cout << numero << " no es un número deficiente." << endl;
            }
            break;
        }
        case 3: {
            int num1, num2;
            cout << "Ingrese el primer número: ";
            cin >> num1;
            cout << "Ingrese el segundo número: ";
            cin >> num2;
            if (SonAmigos(num1, num2)) {
                cout << num1 << " y " << num2 << " son números amigos." << endl;
            } else {
                cout << num1 << " y " << num2 << " no son números amigos." << endl;
            }
            break;
        }
        default:
            cout << "Opción no válida." << endl;
            break;
    }

    return 0;
}
