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
