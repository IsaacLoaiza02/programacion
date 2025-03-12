#include <iostream>
using namespace std;
//MODIFICAR PARA QUE NO CAMBIE LOS NOMBRES DE LA VARIABLE ORIGINAL
string replace(string cadena, string objetivo, string porcion) {
    int size = porcion.size();
    int pos = cadena.find(objetivo);

    if (pos != std::string::npos) {
        cadena.replace(pos, objetivo.size(), porcion);
        return cadena;
    } else {
        return "-1";
    }
}

int main() {
    std::string cadena, objetivo, porcion;

    
    cout << "Ingrese una cadena: ";
    getline(cin, cadena);

    cout << "Ingrese la palabra a buscar: ";
    getline(cin, objetivo);

    cout << "Ingrese la palabra por la que desea reemplazar: ";
    getline(cin , porcion);

    int size = porcion.size();
    int pos = cadena.find(objetivo);

    if (pos != std::string::npos) {
        cadena.replace(pos, objetivo.size(), porcion);
        std::cout << cadena << std::endl;
    } else {
        std::cout << "-1" << std::endl; 
    }

}
