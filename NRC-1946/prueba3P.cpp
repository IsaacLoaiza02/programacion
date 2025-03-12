#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int CONDUCTORES = 5;
const int DIAS = 7;
vector<string> nombresEjemplo = {"Carlos", "Ana", "Luis", "Maria", "Pedro", "Elena", "Juan", "Sofia", "Miguel", "Laura"};
vector<string> diasSemana = {"Lun", "Mar", "Mie", "Jue", "Vie", "Sab", "Dom"};

void mostrarGraficoBarras(string nombre, int kilometros) {
    cout << "\nGrafico de barras para " << nombre << ":\n";
    cout << nombre << " | ";
    for (int i = 0; i < kilometros / 5; i++) { 
        cout << "/";
    }
    cout << " (" << kilometros << " km)" << endl;
}

int main() {
    vector<string> nombres(CONDUCTORES);
    vector<vector<int>> kms(CONDUCTORES, vector<int>(DIAS));
    vector<int> total_kms(CONDUCTORES, 0);
    
    for (int i = 0; i < CONDUCTORES; i++) {
        nombres[i] = nombresEjemplo[rand() % nombresEjemplo.size()];
    }
    
    for (int i = 0; i < CONDUCTORES; i++) {
        for (int j = 0; j < DIAS; j++) {
            kms[i][j] = rand() % 101;
            total_kms[i] += kms[i][j];
        }
    }
    
    for (int i = 0; i < CONDUCTORES - 1; i++) {
        for (int j = 0; j < CONDUCTORES - i - 1; j++) {
            if (total_kms[j] < total_kms[j + 1]) {
                swap(total_kms[j], total_kms[j + 1]);
                swap(nombres[j], nombres[j + 1]);
                swap(kms[j], kms[j + 1]);
            }
        }
    }
    
    cout << "\nkilometros recorridos por cada conductor en la semana:" << endl;
    cout << "Nombre\t";
    for (const string &dia : diasSemana) {
        cout << dia << "\t";
    }
    cout << "Total" << endl;
    
    for (int i = 0; i < CONDUCTORES; i++) {
        cout << nombres[i] << "\t";
        for (int j = 0; j < DIAS; j++) {
            cout << kms[i][j] << "\t";
        }
        cout << total_kms[i] << endl;
    }
    
    cout << "\nConductor con mayor recorrido: " << nombres[0] << " con " << total_kms[0] << " km." << endl;
    mostrarGraficoBarras(nombres[0], total_kms[0]);
    
    cout << "\nConductor con segundo mayor recorrido: " << nombres[1] << " con " << total_kms[1] << " km." << endl;
    mostrarGraficoBarras(nombres[1], total_kms[1]);

    cout << "\nConductor con tercer mayor recorrido: " << nombres[2] << " con " << total_kms[2] << " km." << endl;
    mostrarGraficoBarras(nombres[2], total_kms[2]);

    cout << "\nConductor con cuarto mayor recorrido: " << nombres[3] << " con " << total_kms[3] << " km." << endl;
    mostrarGraficoBarras(nombres[3], total_kms[3]);

    cout << "\nConductor con quinto mayor recorrido: " << nombres[4] << " con " << total_kms[4] << " km." << endl;
    mostrarGraficoBarras(nombres[4], total_kms[4]);
    
    return 0;
}