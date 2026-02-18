#ifndef JUEGO_H
#define JUEGO_H    

#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <fstream>


using namespace std;

struct Nodo {
    string nombre;
    int puntaje;
    Nodo* siguiente;
};

class Juego {
private:
    Nodo* cabeza;

    int contarJugadores() {
        if (cabeza == NULL) return 0;

        int i = 0;
        Nodo* aux = cabeza;

        do {
            i++;
            aux = aux->siguiente;
        } while (aux != cabeza);

        return i;
    }

    string convertirJugada(int j) {
        if (j == 1) return "Piedra";
        if (j == 2) return "Papel";
        return "Tijera";
    }

    void mostrarRec(Nodo* actual, Nodo* inicio) {
        cout << "Nombre: " << actual->nombre
             << " | Puntaje: " << actual->puntaje << endl;

        if (actual->siguiente != inicio)
            mostrarRec(actual->siguiente, inicio);
    }

    Nodo* ganadorRec(Nodo* actual, Nodo* inicio, Nodo* mayor) {
        if (actual->puntaje > mayor->puntaje)
            mayor = actual;

        if (actual->siguiente == inicio)
            return mayor;

        return ganadorRec(actual->siguiente, inicio, mayor);
    }

public:
    Juego() {
        cabeza = NULL;
        srand(time(0));
    }

   // Inserta un nuevo jugador en la lista circular.
  // Valida que no se exceda el máximo de 5 jugadores.
    void inscribirJugador() {
        if (contarJugadores() >= 5) {
            cout << "Maximo 5 jugadores permitidos." << endl;
            return;
        }

        string nombre;
        cout << "Nombre del jugador: ";
        cin >> nombre;

        Nodo* nuevo = new Nodo();
        nuevo->nombre = nombre;
        nuevo->puntaje = 0;

        if (cabeza == NULL) {
            cabeza = nuevo;
            nuevo->siguiente = cabeza;
        } else {
            Nodo* aux = cabeza;
            while (aux->siguiente != cabeza) {
                aux = aux->siguiente;
            }
            aux->siguiente = nuevo;
            nuevo->siguiente = cabeza;
        }

        cout << "Jugador agregado correctamente." << endl;
    
    }
     void mostrarJugadores() {
        if (cabeza == NULL) {
        cout << "No hay jugadores inscritos." << endl;
            return;
        }

        cout << "\n****** LISTA DE JUGADORES ******" << endl;
        mostrarRec(cabeza, cabeza);
    }

    void jugar() {
        if (contarJugadores() < 2) {
            cout << "Se necesitan minimo 2 jugadores." << endl;
            return;
        }

        Nodo* jugador1 = cabeza;

        do {
            Nodo* jugador2 = jugador1->siguiente;

            while (jugador2 != cabeza) {

                int j1 = rand() % 3 + 1;
                int j2 = rand() % 3 + 1;

                cout << "\n" << jugador1->nombre
                     << " vs " << jugador2->nombre << endl;

                cout << jugador1->nombre << " saco: "
                     << convertirJugada(j1) << endl;

                cout << jugador2->nombre << " saco: "
                     << convertirJugada(j2) << endl;

                if (j1 == j2) {
                    cout << "Empate!" << endl;
                }
                else if ((j1 == 1 && j2 == 3) ||
                         (j1 == 2 && j2 == 1) ||
                         (j1 == 3 && j2 == 2)) {
                    cout << jugador1->nombre << " gana esta ronda!" << endl;
                    jugador1->puntaje += 3;
                }
                else {
                    cout << jugador2->nombre << " gana esta ronda!" << endl;
                    jugador2->puntaje += 3;
                }

                jugador2 = jugador2->siguiente;
            }

            jugador1 = jugador1->siguiente;

        } while (jugador1 != cabeza);

        cout << "\nPartidas finalizadas.\n";
        guardarResultados();
    }

    
    // Muestra en pantalla el jugador con mayor puntaje.
   // Utiliza la función recursiva ganadorRec().
void reportarGanador() {
        if (cabeza == NULL) {
            cout << "No hay jugadores." << endl;
            return;
        }

        Nodo* ganador = ganadorRec(cabeza, cabeza, cabeza);

        cout << "\n****** GANADOR ******" << endl;
        cout << "Nombre: " << ganador->nombre << endl;
        cout << "Puntaje: " << ganador->puntaje << endl;
    }

    // Guarda en el archivo resultados.txt la lista de jugadores.
   // Fecha de ejecución y el ganador del juego. 
void guardarResultados() {
    if (cabeza == NULL) {
        cout << "No hay jugadores para guardar."<< endl;
        return;
    }

    ofstream archivo("resultados.txt", ios::app);

    if (!archivo) {
        cout << "Error al abrir el archivo."<< endl;
        return;
    }

    time_t ahora = time(0);
    char* fecha = ctime(&ahora);

    archivo << "*****************************************"<< endl;
    archivo << "Fecha: " << fecha;
    archivo << "RESULTADOS DE LA COMPETENCIA"<< endl<< endl;

    Nodo* actual = cabeza;
    Nodo* ganador = cabeza;

    do {
        archivo << "Nombre: " << actual->nombre
                << " | Puntaje: " << actual->puntaje << endl;

        if (actual->puntaje > ganador->puntaje)
            ganador = actual;

        actual = actual->siguiente;

    } while (actual != cabeza);

    archivo << "\nGANADOR: " << ganador->nombre
            << " con " << ganador->puntaje << " puntos."<< endl;

    archivo << "****************************************"<< endl<< endl;

    archivo.close();

    cout << "Resultados guardados en 'resultados.txt'" << endl;
}

 void ayuda() {
        cout << "\n********** AYUDA DEL SISTEMA **********\n\n";
        cout << "Este programa utiliza una lista circular dinamica." << endl;
        cout << "Permite inscribir hasta 5 jugadores." << endl;
        cout << "Todos compiten contra todos automaticamente." << endl;
        cout << "Cada victoria suma 3 puntos." << endl;
        cout << "El ganador se obtiene mediante una funcion recursiva." << endl << endl;
    }
    
void integrantes() {
        cout << "\n****** INTEGRANTES ******\n";
        cout << "Gerardo Moran - 00382425" << endl;
        cout << "Tania Quintanilla  - 00385125" << endl;
        cout << "Pamela Rodriguez - 00383825" << endl;
    }
};

#endif
