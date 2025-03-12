#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Conductor {
    string nombre;
    int total_kms;
};

// Utilizamos el método burbuja mejorado para ordenar los conductores
void ordenarConductores(vector<Conductor> &conductores) {
    int n = conductores.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (conductores[j].total_kms < conductores[j + 1].total_kms) {
                // Intercambiar
                Conductor temp = conductores[j];
                conductores[j] = conductores[j + 1];
                conductores[j + 1] = temp;
            }
        }
    }
}

int main() {
    srand(time(0)); // Inicializar la semilla para la generación de números aleatorios

    int n; 
    cout << "Ingrese el numero de conductores: ";
    cin >> n;
    cin.ignore(); 

    vector<string> nombres(n);
    vector<vector<int>> kms(n, vector<int>(5));
    vector<int> total_kms(n, 0); 
    vector<string> dias = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes"}; 

    // Pedir los datos de los conductores y generar los kilometros aleatoriamente
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el nombre del conductor " << i + 1 << ": ";
        getline(cin, nombres[i]);

        cout << "Kilometros recorridos por " << nombres[i] << " en cada dia de la semana:\n";
        for (int j = 0; j < 5; j++) {
            kms[i][j] = rand() % 101; // Generar un número aleatorio entre 0 y 100
            total_kms[i] += kms[i][j]; 
            cout << dias[j] << ": " << kms[i][j] << " km\n";
        }
    }

    // Buscamos el conductor que mas kilometros recorrio 
    int max_km = total_kms[0];
    string mejor_conductor = nombres[0];

    for (int i = 1; i < n; i++) {
        if (total_kms[i] > max_km) {
            max_km = total_kms[i];
            mejor_conductor = nombres[i];
        }
    }

    vector<Conductor> conductores(n);
    for (int i = 0; i < n; i++) {
        conductores[i] = {nombres[i], total_kms[i]};
    }
    ordenarConductores(conductores);

    // Mostrar la lista de conductores con kilometros recorridos en forma de tabla
    cout << "\nLista de conductores con kilometros recorridos:\n";
    cout << left << setw(20) << "Conductor" << setw(10) << "Total Kms" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << left << setw(20) << conductores[i].nombre << setw(10) << conductores[i].total_kms << endl;
    }

    cout << "\nConductor con mayor kilometraje: " << mejor_conductor << " con " << max_km << " km\n";

    // Mostrar la tabla de posiciones de los conductores en forma descendente
    cout << "\nTabla de posiciones de los conductores en forma descendente:\n";
    for (int i = 0; i < n; i++) {
        cout << left << setw(20) << conductores[i].nombre << ": ";
        for (int j = 0; j < conductores[i].total_kms / 10; j++) { 
            cout << "*";
        }
        cout << " (" << conductores[i].total_kms << " km)\n";
    }

    return 0;
}