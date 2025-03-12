#include <iostream>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()
#define MAX 50
using namespace std;

// Función para llenar la tabla con números aleatorios entre 10 y 20
void llenaTablaAleatoria(int tabla[][MAX], int f, int c) 
{
    srand(time(0)); // Semilla para los números aleatorios
    for (int i = 0; i < f; i++) 
    {
        for (int j = 0; j < c; j++) 
        {
            tabla[i][j] = rand() % 11 + 10; // Genera números entre 10 y 20
        }
    }
}

// Función para imprimir la tabla
void ImprimeTabla(int tabla[][MAX], int f, int c) 
{
    cout << "\nLa tabla es:\n";
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++) 
        {
            cout << tabla[i][j] << "\t";
        }
        cout << endl;
    }
}

// Función para calcular la suma de la diagonal principal (i == j)
int SumaDiagonalPrincipal(int tabla[][MAX], int n) 
{
    int suma = 0;
    for (int i = 0; i < n; i++) 
    {
        suma += tabla[i][i];
    }
    return suma;
}

// Función para calcular la suma de la diagonal secundaria (i + j == n - 1)
int SumaDiagonalSecundaria(int tabla[][MAX], int n) 
{
    int suma = 0;
    for (int i = 0; i < n; i++) 
    {
        suma += tabla[i][n - i - 1];
    }
    return suma;
}

// Función para determinar cuál diagonal tiene mayor suma
void DeterminaDiagonalMayor(int sumaPrincipal, int sumaSecundaria) 
{
    cout << "Suma de la diagonal principal: " << sumaPrincipal << endl;
    cout << "Suma de la diagonal secundaria: " << sumaSecundaria << endl;

    if (sumaPrincipal > sumaSecundaria) 
    {
        cout << "La diagonal principal tiene la mayor suma.\n";
    } 
    
    else if (sumaSecundaria > sumaPrincipal) 
    {
        cout << "La diagonal secundaria tiene la mayor suma.\n";
    } 
    
    else 
    {
        cout << "Ambas diagonales tienen la misma suma.\n";
    }
}

// Función para graficar las diagonales
void GraficaDiagonales(int tabla[][MAX], int n) 
{
    cout << "\nGraficando las diagonales:\n";

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (i == j || i + j == n - 1) 
            {
                cout << tabla[i][j] << "\t"; // Imprime las diagonales
            }

             else 
            {
                cout << "*\t"; // Imprime un asterisko  para los valores no pertenecientes a las diagonales
            }
        }
        cout << endl;
    }
}

int main() {
    int tabla[MAX][MAX], n;

    cout << "Introduzca el tamaño de la matriz cuadrada (max " << MAX << "): ";
    while (!(cin >> n) || n <= 0 || n > MAX) 
    {
        cout << "Error: Introduzca un número válido (1-" << MAX << "): ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    llenaTablaAleatoria(tabla, n, n);

    ImprimeTabla(tabla, n, n);

    int sumaPrincipal = SumaDiagonalPrincipal(tabla, n);
    int sumaSecundaria = SumaDiagonalSecundaria(tabla, n);

    DeterminaDiagonalMayor(sumaPrincipal, sumaSecundaria);

    GraficaDiagonales(tabla, n);

}
