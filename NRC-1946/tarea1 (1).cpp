#include <iostream>
using namespace std;

int main() {
    int limiteInferior, limiteSuperior;
    int numero;
    int sumaIntervalo = 0;
    int fueraIntervalo = 0;
    bool igualLimite = false;

    do {
        cout << "Introduce el limite inferior: ";
        cin >> limiteInferior;
        cout << "Introduce el limite superior: ";
        cin >> limiteSuperior;

        if (limiteInferior >= limiteSuperior) {
            cout << "El limite inferior no puede ser mayor o igual al superior. Intenta de nuevo." << endl;
        }
    } while (limiteInferior >= limiteSuperior);

    while (true) {
        cout << "Introduce un número (0 para terminar): ";
        cin >> numero;

        if (numero == 0) {
            break; 
        }

        if (numero > limiteInferior && numero < limiteSuperior) {
            sumaIntervalo += numero; 
        } else {
            fueraIntervalo++; 
        }

        if (numero == limiteInferior || numero == limiteSuperior) {
            igualLimite = true;
        }
    }

    cout << "La suma de los números dentro del intervalo abierto es: " << sumaIntervalo << endl;
    cout << "La cantidad de números fuera del intervalo es: " << fueraIntervalo << endl;

    if (igualLimite) {
        cout << "Se ha introducido al menos un número igual a los límites del intervalo." << endl;
    } else {
        cout << "No se ha introducido ningún número igual a los límites del intervalo." << endl;
    }

    return 0;
}