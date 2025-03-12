#include <iostream>
using namespace std;

void verificarCadena(char cadena[]) {
    bool siNumerica = true;
    bool siAlfabetica = true;

    for (int i = 0; cadena[i] != '\0'; i++) {
        char c = cadena[i];
        if (!(c >= '0' && c <= '9')) {
            siNumerica = false; 
        }
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
            siAlfabetica = false; 
        }
    }

    if (siNumerica) {
        cout << "La cadena es NUMERICA." << endl;
    } else if (siAlfabetica) {
        cout << "La cadena es ALFABETICA." << endl;
    } else {
        cout << "La cadena es ALFANUMERICA." << endl;
    }
}

int main() {
    char cadena[100]; 
    cout << "Introduce una cadena sin espacios que todo sea unido: ";
    cin >> cadena;

    verificarCadena(cadena);


}
