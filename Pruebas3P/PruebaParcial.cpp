#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Conductor {
    string nombre;
    int total_kms;
};

void ordenarConductores(vector<Conductor> &conductores) {
    for (size_t i = 0; i < conductores.size() - 1; i++) {
        for (size_t j = 0; j < conductores.size() - i - 1; j++) {
            if (conductores[j].total_kms < conductores[j + 1].total_kms) {
                swap(conductores[j], conductores[j + 1]);
            }
        }
    }
}

void mostrarTabla(const vector<Conductor> &conductores) {
    cout << "\nTabla de posiciones de los conductores en forma descendente:\n";
    for (const auto &c : conductores) {
        cout << c.nombre << " : ";
        for (int i = 0; i < c.total_kms / 10; i++) {  // Escala para los asteriscos
            cout << "*";
        }
        cout << " (" << c.total_kms << " km)\n";
    }
}

int main() {
    srand(time(0)); 

    int n; 
    cout << "Ingrese el numero de conductores: ";
    cin >> n;
    cin.ignore(); 

    vector<Conductor> conductores(n);
    vector<string> dias = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes"};

    for (int i = 0; i < n; i++) {
        cout << "Ingrese el nombre del conductor " << i + 1 << ": ";
        getline(cin, conductores[i].nombre);
        
        conductores[i].total_kms = 0;
        for (const auto &dia : dias) {
            int kms = rand() % 101;
            conductores[i].total_kms += kms;
            cout << dia << ": " << kms << " km\n";
        }
    }

    ordenarConductores(conductores);
    mostrarTabla(conductores);

    cout << "\nConductor con mayor kilometraje: " << conductores[0].nombre << " con " << conductores[0].total_kms << " km\n";
    return 0;
}
