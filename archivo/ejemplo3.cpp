#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream archivoSalida;
    archivoSalida.open("ejemplo1.txt", ios::app);
    if (archivoSalida.is_open())
    {
        archivoSalida << "linea agregada al final." << endl;
        archivoSalida << "Otra linea mas" << endl;
        archivoSalida.close();
        cout << "Texto agregado con exito" << endl;
    }
    else
    {
        cout << "No se pudo abrir el archivo" << endl;
    }
}