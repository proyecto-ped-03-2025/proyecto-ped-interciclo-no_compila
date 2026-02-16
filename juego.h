#include <iostream>


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

}
