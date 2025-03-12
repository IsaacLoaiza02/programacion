#include <iostream>
#include <string>

using namespace std;

void reemplazarTodas(string &cadena, const string &objetivo, const string &porcion) {
    size_t pos = 0;
    while ((pos = cadena.find(objetivo, pos)) != string::npos) {
        // Verificar si la coincidencia es una palabra completa
        bool esInicio = (pos == 0 || isspace(cadena[pos - 1]));
        bool esFin = (pos + objetivo.length() == cadena.length() || isspace(cadena[pos + objetivo.length()]));

        if (esInicio && esFin) {  // Solo reemplaza si está aislada
            cadena.replace(pos, objetivo.length(), porcion);
            pos += porcion.length();  // Avanza para evitar reemplazos infinitos
        } else {
            pos += objetivo.length();  // Seguir buscando sin reemplazar
        }
    }
}

int main() {
    string cadena, objetivo, porcion;

    cout << "Ingrese la frase inicial: ";
    getline(cin, cadena);

    cout << "Ingrese la palabra o frase que desea cambiar: ";
    getline(cin, objetivo);

    cout << "Ingrese la nueva palabra o frase: ";
    getline(cin, porcion);

    reemplazarTodas(cadena, objetivo, porcion);

    cout << "Cadena modificada: " << cadena << endl;

    return 0;
}