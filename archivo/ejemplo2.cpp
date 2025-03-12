#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream archivoEntrada;
    archivoEntrada.open("ejemplo1.txt");
    if (archivoEntrada.is_open())
    {
        string linea;
        while (getline(archivoEntrada, linea))
        {
            cout << "Leido: " << linea << endl;
        }
        archivoEntrada.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo" << endl;
    }   
    return 0;
}