#include <iostream>
#include <string>

using namespace std;

string reemplazarSubcadena(string texto, const string& buscar, const string& reemplazo) {
    size_t pos = 0;
    while ((pos = texto.find(buscar, pos)) != string::npos) {
        texto.replace(pos, buscar.length(), reemplazo);
        pos += reemplazo.length();
    }
    return texto;
}

int main() {
    string textoOriginal, buscar, reemplazo;
    
    cout << "Ingresa la cadena original: ";
    getline(cin, textoOriginal);
    
    cout << "Ingresa la subcadena a reemplazar: ";
    getline(cin, buscar);
    
    cout << "Ingresa la nueva subcadena: ";
    getline(cin, reemplazo);
    
    string textoModificado = reemplazarSubcadena(textoOriginal, buscar, reemplazo);
    cout << "Cadena modificada: " << textoModificado << endl;
    
    return 0;
}