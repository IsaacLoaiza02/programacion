#include <iostream>
using namespace std;

int main() {
    const int MAX = 100;
    int matriz[MAX][MAX];
    int n;

    cout << "Ingrese el tamaño de la matriz cuadrada (máximo " << MAX << "): ";
    cin >> n;

    if (n <= 0 || n > MAX) {
        cout << "Tamaño inválido. Intente nuevamente." << endl;
        return 1;
    }

    cout << "\nMatriz generada:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matriz[i][j] = 10 + rand() % 11; 
            cout << matriz[i][j] << "\t";   
        }
        cout << endl;
    }

    int sumaDiagonalPrincipal = 0, sumaDiagonalSecundaria = 0;
    for (int i = 0; i < n; ++i) {
        sumaDiagonalPrincipal += matriz[i][i];
        sumaDiagonalSecundaria += matriz[i][n - i - 1];
    }

    string resultado;
    if (sumaDiagonalPrincipal > sumaDiagonalSecundaria) {
        resultado = "La diagonal principal es mayor.";
    } else if (sumaDiagonalPrincipal < sumaDiagonalSecundaria) {
        resultado = "La diagonal secundaria es mayor.";
    } else {
        resultado = "Ambas diagonales son iguales.";
    }

    cout << "\nDiagonales resaltadas:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j || i + j == n - 1) {
                cout << matriz[i][j] << "\t"; 
            } else {
                cout << "-\t"; 
            }
        }
        cout << endl;
    }

    cout << "\nSuma de la diagonal principal: " << sumaDiagonalPrincipal << endl;
    cout << "Suma de la diagonal secundaria: " << sumaDiagonalSecundaria << endl;
    cout << resultado << endl;

    return 0;
}