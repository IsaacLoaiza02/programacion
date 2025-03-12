#include <iostream>
#include <string>
#include "ahorcadoisaacloaiza.h"

using namespace std;

void dibujarAhorcado(int fallos) {
    switch (fallos) {
        case 1: cout << "Cabeza" << endl; break;
        case 2: cout << "Cuerpo" << endl; break;
        case 3: cout << "Pierna 1" << endl; break;
        case 4: cout << "Pierna 2" << endl; break;
        case 5: cout << "Base de la horca" << endl; break;
        case 6: cout << "Palo vertical" << endl; break;
        case 7: cout << "Soga unida" << endl; break;
        default: break;
    }
}

void jugar() {
    int opcion;
    cout << "Selecciona un tema:\n1. Paises\n2. Deportes\n3. Animales\n4. Frutas\n";
    cin >> opcion;

    string* palabras;
    int num_palabras;

    switch (opcion) {
        case 1: palabras = paises; num_palabras = NUM_PAISES; break;
        case 2: palabras = deportes; num_palabras = NUM_DEPORTES; break;
        case 3: palabras = animales; num_palabras = NUM_ANIMALES; break;
        case 4: palabras = frutas; num_palabras = NUM_FRUTAS; break;
        default: cout << "Opcion invalida!" << endl; return;
    }

    string palabra = palabras[rand() % num_palabras];
    string palabra_oculta(palabra.size(), '_');
    int intentos_fallidos = 0;
    string letras_incorrectas = "";

    while (intentos_fallidos < 7) {
        cout << "Palabra: " << palabra_oculta << endl;
        cout << "Letras incorrectas: " << letras_incorrectas << endl;
        cout << "Introduce una letra: ";
        
        char letra;
        cin >> letra;
        
        bool letra_correcta = false;
        for (int i = 0; i < palabra.size(); i++) {
            if (palabra[i] == letra) {
                palabra_oculta[i] = letra;
                letra_correcta = true;
            }
        }

        if (!letra_correcta) {
            letras_incorrectas += letra;
            intentos_fallidos++;
            dibujarAhorcado(intentos_fallidos);
        }

        if (palabra_oculta == palabra) {
            cout << "¡Ganaste! La palabra es: " << palabra << endl;
            break;
        }
    }

    if (intentos_fallidos == 7) {
        cout << "¡Perdiste! La palabra era: " << palabra << endl;
    }
}

int main() {
    jugar();
    return 0;
}