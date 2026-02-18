#include <iostream>
#include "juego.h"
using namespace std;

int main() {

Juego juego;
    int opcion;

    do {
        cout << "\n** MENU PRINCIPAL ***\n";
        cout << "1. Inscribir jugador" << endl;
        cout << "2. Ver jugadores" << endl;
        cout << "3. Realizar juego" << endl;
        cout << "4. Reportar ganador" << endl;
        cout << "5. Guardar resultados" << endl;
        cout << "6. Ayuda" << endl;
        cout << "7. Integrantes" << endl;
        cout << "8. Salir" << endl;           
        cout << "Opcion: ";
        cin >> opcion;

     switch (opcion) {

        case 1: {
            char respuesta;
            do {
                juego.inscribirJugador();
                cout << "Desea agregar otro jugador? (s/n): ";
                cin >> respuesta;
            } while (respuesta == 's' || respuesta == 'S');
            break;
        }

        case 2:
            juego.mostrarJugadores();
            break;

        case 3:
            juego.jugar();
            break;

        case 4:
            juego.reportarGanador();
            break;


    return 0;
} 