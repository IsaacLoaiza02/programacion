//corregir codigo de juego de ahorcado
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../tutorias/ahorcado.h""
using namespace std;


string palabraAleatoria(string palabras[]) {
    srand(time(NULL));
    int numero = rand() % 5; // Selecciona un número entre 0 y 4
    return palabras[numero];
}


void mostrarAhorcado(int intentos) {
    string ahorcado[] = {
        "  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n========="
    };
    cout << ahorcado[intentos] << endl;
}


void mostrarPalabra(string palabra, string adivinadas) {
    for (char letra : palabra) {
        if (adivinadas.find(letra) != string::npos) {
            cout << letra << " "; 
        } else {
            cout << "_ "; 
        }
    }
    cout << endl;
}


void jugarAhorcado(string palabra) {
    string letrasAdivinadas = "";
    int intentos = 0;
    bool palabraCompleta = false;

    while (intentos < 7 && !palabraCompleta) {
        cout << "\nIntentos restantes: " << (7 - intentos) << endl;
        mostrarAhorcado(intentos);
        mostrarPalabra(palabra, letrasAdivinadas);
        
        char letra;
        cout << "Ingresa una letra: ";
        cin >> letra;

       
        if (!isalpha(letra)) {
            cout << "Por favor, ingresa solo una letra válida." << endl;
            continue;
        }

        letra = tolower(letra); 

        
        if (palabra.find(letra) != string::npos) {
            if (letrasAdivinadas.find(letra) == string::npos) {
                letrasAdivinadas += letra; 
            } else {
                cout << "Ya ingresaste esta letra antes." << endl;
            }
        } else {
            cout << "Letra incorrecta (ERROR)." << endl;
            intentos++;
        }

     
        palabraCompleta = true;
        for (char letraPalabra : palabra) {
            if (letrasAdivinadas.find(letraPalabra) == string::npos) {
                palabraCompleta = false;
                break;
            }
        }
    }

   
    if (palabraCompleta) {
        cout << "\n¡Felicidades! Adivinaste la palabra: " << palabra << endl;
    } else {
        mostrarAhorcado(6);
        cout << "\nJarvis gana (Perdedor). La palabra era: " << palabra << endl;
    }
}


int opciones() {
    int op;
    cout << "1. Deportes" << endl;
    cout << "2. Animales" << endl;
    cout << "3. Frutas" << endl;
    cout << "4. Paises" << endl;
    cout << "5. autos" << endl;
    cout << "6. equipos de futbol" << endl;
    cout << "7. motos" << endl;
    cout << "Elige una categoría: ";
    cin >> op;
    return op;
}

int main() {
    string palabras[5], palabraSeleccionada;
    int op;

    cout << "Juego del Ahorcado" << endl;
    cout << "-------------------" << endl;
    
    op = opciones();
    (op == 1) ? deportes(palabras) : (op == 2) ? animales(palabras) : (op == 3)? frutas(palabras) : (op == 4)? paises(palabras): (op == 5) ?autos(palabras): (op == 6)? equiposFutbol(palabras): motos(palabras);
    
    palabraSeleccionada = palabraAleatoria(palabras);

    jugarAhorcado(palabraSeleccionada); 


}
