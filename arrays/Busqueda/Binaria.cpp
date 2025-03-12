#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../../librerias/arrays.h"
using namespace std;
using namespace vectorn;
bool isBusquedaBinaria(int v[], int n, int elemento) {
    int arriba,abajo,centro;
    abajo=0;
    arriba=n-1;
    while(abajo<=arriba) {
        centro=(abajo+arriba)/2;
        if(v[centro]==elemento) {
            return true;
        }
        else if(v[centro]>elemento) {
            arriba=centro+1;
        }
        else {
            abajo=centro-1;
        }
    }
}

main()
{
    int ne, dato;
    cout << "Nro de Elementos del Array: ";
    cin >> ne;
    int vector[ne];
    llenarVector(vector, ne);
    cout << "Vector original: ";
    verVector(vector,ne);
    ordenarBurbujav3(vector, ne);
    cout<< "Vector ordenado: ";
    verVector(vector, ne);
    cout << "Ingrese el dato a buscar: ";
    cin >> dato;

    (isBusquedaBinaria(vector, ne, dato)) ? cout << "\nDato Encontrado ": cout << "\nDato no encontrado";
}