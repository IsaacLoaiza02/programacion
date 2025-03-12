#include <iostream>
#include <stdlib.h>   // libreria Para rand() y srand()
#include <time.h>     // libreria para el uso de time()
using namespace std;

// Función para llenar un vector con números flotantes aleatorios
void llenaDatos(float v[], int ne) {
    srand(time(NULL)); // Inicializa la semilla para generar números aleatorios
    for (int i = 0; i < ne; i++) {
        v[i] = (float(rand()) / RAND_MAX) * 19.0 + 1.0; 
    }
}

// Función para mostrar los datos del vector
void verDatos(float v[], int ne) {
    cout << "Los elementos del vector son: " << endl;
    for (int i = 0; i < ne; i++) {
        cout << v[i] << "   "; // Muestra los números flotantes
    }
    cout << endl;
}

// Función para calcular el promedio de los números en el vector
float sumaPromedioCifras(float v[], int ne) {
    float suma = 0.0;
    for (int i = 0; i < ne; i++) {
        suma += v[i];
    }
    return suma / ne; 
}

// Función para contar cuántos elementos están debajo del promedio
int contarDebajoPromedio(float v[], int ne, float promedio) {
    int contar = 0;
    for (int i = 0; i < ne; i++) {
        if (v[i] < promedio) {
            contar++;
        }
    }
    return contar; // Retorna la cantidad de elementos
}

void guardaElementosMenores(float v[], int ne, float promedio, float lista[]) {
    int j = 0;
    for (int i = 0; i < ne; i++) {
        if (v[i] < promedio) {
            lista[j] = v[i];
            j++;
        }
    }
}

int main() {
    int ne, menores;
    float promedioNumeros;

    // Solicitar al usuario la cantidad de elementos del vector
    cout << "¿Cuántos elementos tiene el vector?: ";
    cin >> ne;

    // Declarar los vectores
    float vector[ne]; // Vector principal
    llenaDatos(vector, ne); // completar el vector con números aleatorios
    verDatos(vector, ne);   

    // Calcular el promedio y mostrarlo
    promedioNumeros = sumaPromedioCifras(vector, ne);
    cout << "El promedio de los datos generados es = " << promedioNumeros << endl;
    menores = contarDebajoPromedio(vector, ne, promedioNumeros);
    cout << "La cantidad de elementos bajo del promedio son: " << menores << endl;
    float listaMenores[menores];
    guardaElementosMenores(vector, ne, promedioNumeros, listaMenores);
    verDatos(listaMenores, menores);

}
