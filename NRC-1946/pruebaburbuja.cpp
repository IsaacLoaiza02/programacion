//https://github.com/Isaac020905/isaacloaiza1946.git
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void llenarvector(int v[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 20 + 1;
    }
}

int ordenarburbuja1(int v[], int n) {
    int aux, contador = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            contador++;
            if (v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
    return contador;
}

int ordenarburbuja2(int v[], int n) {
    int mejora = 1, aux, contador = 0;
    for (int i = 0; i < n - mejora; i++) {
        for (int j = 0; j < n - mejora; j++) {
            contador++;
            if (v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
        mejora++;
    }
    return contador;
}

int ordenarburbuja3(int v[], int n) {
    int mejora = 1, aux, contador = 0;
    bool cambio = true;
    while (mejora < n && cambio) {
        cambio = false;
        for (int j = 0; j < n - mejora; j++) {
            contador++;
            if (v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                cambio = true;
            }
        }
        mejora++;
    }
    return contador;
}

void muestravector(int v[], int n) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void compararVersiones(int v[], int n) {
    int vec1[n], vec2[n], vec3[n];
    copy(v, v + n, vec1);
    copy(v, v + n, vec2);
    copy(v, v + n, vec3);

    int comparaciones1 = ordenarburbuja1(vec1, n);
    int comparaciones2 = ordenarburbuja2(vec2, n);
    int comparaciones3 = ordenarburbuja3(vec3, n);

    cout << "Comparaciones versión 1: " << comparaciones1 << endl;
    cout << "Comparaciones versión 2: " << comparaciones2 << endl;
    cout << "Comparaciones versión 3: " << comparaciones3 << endl;

    if (comparaciones1 <= comparaciones2 && comparaciones1 <= comparaciones3) {
        cout << "La mejor versión es la versión 1." << endl;
    } else if (comparaciones2 <= comparaciones1 && comparaciones2 <= comparaciones3) {
        cout << "La mejor versión es la versión 2." << endl;
    } else {
        cout << "La mejor versión es la versión 3." << endl;
    }
}

void ejecutarPrograma() {
    int no;
    cout << "Número de elementos: ";
    cin >> no;
    int vec[no];

    llenarvector(vec, no);

    cout << "Vector original: ";
    muestravector(vec, no);

    compararVersiones(vec, no);
}

int main() {
    ejecutarPrograma();
    return 0;
}