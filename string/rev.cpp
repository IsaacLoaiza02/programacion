#include <iostream>     
#include "../librerias/string.h"
using namespace std;    
main()
{
    string palabras;
    cout << "Introduce una palabra: ";
    getline(cin, palabras);
    reemplazar(palabras);
    cout << "La cadena modificada es: " << palabras << endl;
    return 0;
}