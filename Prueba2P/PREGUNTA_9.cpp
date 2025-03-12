#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int obtenerEleccionUsuario() {
    int eleccion;
    cout << "Elige una opción:\n1. Piedra\n2. Papel\n3. Tijera\n";
    cin >> eleccion;
    while (eleccion < 1 || eleccion > 3) {
        cout << "Elección no válida. Por favor, elige entre 1, 2 o 3: ";
        cin >> eleccion;
    }
    return eleccion;
}


int obtenerEleccionMaquina() {
    return rand() % 3 + 1; 
}


int determinarGanadorRonda(int usuario, int maquina) {
    if (usuario == maquina) {
        return 0; 
    } else if ((usuario == 1 && maquina == 3) || (usuario == 2 && maquina == 1) || (usuario == 3 && maquina == 2)) {
        return 1; 
    } else {
        return -1; 
    }
}


void determinarGanadorJuego(int puntosUsuario, int puntosMaquina) {
    cout << "\nResultados finales:\n";
    cout << "Usuario: " << puntosUsuario << " puntos\n";
    cout << "Máquina: " << puntosMaquina << " puntos\n";

    if (puntosUsuario > puntosMaquina) {
        cout << "¡Felicidades! Ganaste el juego.\n";
    } else if (puntosUsuario < puntosMaquina) {
        cout << " GAME OVER. La máquina (JARVIS) ganó el juego. ¡Inténtalo de nuevo!\n";
    } else {
        cout << "Es un empate.\n";
    }
}

int main() {
    srand(time(0)); 

    int nivel;
    cout << "Elige el nivel de dificultad:\n";
    cout << "1. Principiante\n2. Intermedio\n3. Avanzado\n";
    cin >> nivel;

    int puntosUsuario = 0, puntosMaquina = 0;

    
    if (nivel == 2) {
        puntosMaquina = 1; 
    } else if (nivel == 3) {
        puntosMaquina = 2; 
    }


    for (int ronda = 1; ronda <= 5; ronda++) {
        cout << "\n--- Ronda " << ronda << " ---\n";
        int eleccionUsuario = obtenerEleccionUsuario();
        int eleccionMaquina = obtenerEleccionMaquina();

        cout << "Elegiste: " << (eleccionUsuario == 1 ? "Piedra" : eleccionUsuario == 2 ? "Papel" : "Tijera") << endl;
        cout << "La máquina (JARVIS) eligió: " << (eleccionMaquina == 1 ? "Piedra" : eleccionMaquina == 2 ? "Papel" : "Tijera") << endl;

        
        int resultado = determinarGanadorRonda(eleccionUsuario, eleccionMaquina);
        if (resultado == 1) {
            cout << "¡Ganaste esta ronda!\n";
            puntosUsuario++;
        } else if (resultado == -1) {
            cout << "La máquina (JARVIS) ganó esta ronda.\n";
            puntosMaquina++;
        } else {
            cout << "Esta ronda es un empate.\n";
        }

    
        cout << "Puntos Usuario: " << puntosUsuario << " | Puntos Máquina (JARVIS): " << puntosMaquina << endl;
    }


    determinarGanadorJuego(puntosUsuario, puntosMaquina);

    return 0;
}
