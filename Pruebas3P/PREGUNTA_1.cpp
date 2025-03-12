#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

string ordenarPalabrasPorLongitud(const string &cadena) {
    stringstream ss(cadena);  
    string palabra;  
    vector<string> palabras;  

    
    while (ss >> palabra) {
        palabras.push_back(palabra);
    }
    
    sort(palabras.begin(), palabras.end(), [](const string &a, const string &b) {
        return a.size() > b.size(); 
    });
    

    string resultado;
    for (size_t i = 0; i < palabras.size(); i++) {
        resultado += palabras[i]; 
        if (i != palabras.size() - 1) { 
            resultado += " ";
        }
    }
    
    return resultado;  
}

int main() {
    string cadena; 
    
    
    cout << "Introduce una cadena de palabras: ";
    getline(cin, cadena);  
    
    
    string resultado = ordenarPalabrasPorLongitud(cadena);
    

    cout << "Cadena ordenada por longitud de palabras: " << resultado << endl;
    
    return 0; 
}
