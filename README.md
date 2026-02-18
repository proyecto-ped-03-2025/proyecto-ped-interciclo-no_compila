# Juego Piedra, Papel o Tijera (Lista Circular Dinámica)

## Descripción General

Este programa simula un torneo automático de *Piedra, Papel o Tijera* entre varios jugadores utilizando una *lista circular dinámica* en C++.

El sistema permite registrar jugadores, ejecutar partidas todos contra todos, determinar el ganador mediante recursividad y guardar los resultados en un archivo de texto.

---

# Documentación de Usuario

## ¿Qué puede hacer el usuario?

El sistema permite:

* Inscribir hasta 5 jugadores
* Visualizar jugadores registrados
* Ejecutar el torneo automático
* Ver el ganador
* Guardar resultados en archivo
* Consultar ayuda del sistema
* Ver integrantes del equipo

---

## Cómo ejecutar el programa

1. Compilar el proyecto en C++.
2. Ejecutar el programa.
3. Usar el menú principal ingresando el número de la opción deseada.

---

## Menú Principal

| Opción | Función            |
| ------ | ------------------ |
| 1      | Inscribir jugador  |
| 2      | Ver jugadores      |
| 3      | Realizar juego     |
| 4      | Reportar ganador   |
| 5      | Guardar resultados |
| 6      | Ayuda              |
| 7      | Integrantes        |
| 8      | Salir              |

---

## Flujo típico de uso

1. Registrar jugadores (mínimo 2, máximo 5).
2. Ejecutar el juego.
3. Consultar el ganador.
4. Guardar resultados si se desea.

---

## Archivo generado

El programa crea o actualiza el archivo:

resultados.txt

El archivo contiene:

* Fecha de ejecución
* Lista de jugadores
* Puntajes
* Ganador del torneo

---

## Restricciones

* Máximo 5 jugadores.
* Mínimo 2 jugadores para jugar.
* Los nombres se ingresan sin espacios.

---

---

# Documentación Técnica (Para Programadores)

## Estructuras de Datos

### Nodo

Representa cada jugador en la lista circular.

cpp
struct Nodo {
    string nombre;
    int puntaje;
    Nodo* siguiente;
};


*Campos:*

* nombre: nombre del jugador
* puntaje: puntos acumulados
* siguiente: enlace al siguiente nodo

---

## Tipo de Lista

El sistema implementa una *lista circular simplemente enlazada*.

### Características:

* No existe puntero NULL final.
* El último nodo apunta a la cabeza.
* Permite recorridos continuos.

---

## Principales Funciones

### inscribirJugador()

*Propósito:*
Inserta un nuevo jugador al final de la lista circular.

*Características técnicas:*

* Usa memoria dinámica (new)
* Valida máximo de jugadores
* Mantiene la circularidad

---

### mostrarRec()

*Tipo:* recursiva

*Propósito:*
Mostrar todos los jugadores.

*Condición de parada:*
Cuando el siguiente nodo es la cabeza.

---

### ganadorRec()

*Tipo:* recursiva

*Propósito:*
Encontrar el jugador con mayor puntaje.

*Estrategia:*

* Comparación acumulativa
* Recorrido circular
* Retorno del nodo con mayor puntaje

---

### jugar()

*Propósito:*
Ejecutar torneo todos contra todos.

*Detalles técnicos:*

* Uso de rand()
* Doble recorrido de la lista
* Cada victoria suma 3 puntos

---

### guardarResultados()

*Propósito:*
Persistir resultados en archivo de texto.

*Aspectos técnicos:*

* Uso de ofstream
* Modo ios::app (no sobrescribe el archivo)
* Obtención de fecha con time() y ctime()
* Recorrido circular para guardar datos

---
---

## Validaciones Implementadas

* Lista vacía
* Máximo de jugadores
* Mínimo para jugar
* Error de apertura de archivo

---

# Estado del Proyecto

* Lista circular dinámica
* Recursividad implementada
* Manejo de archivos
* Menú interactivo
* Validaciones básicas
* Código modularizado

---

## Creadores:

* Gerardo Moran -- 0038245
* Tania Quintanilla -- 00385125
* Pamela Rodriguez -- 00383825

---
---








[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/5ESmLAlU)
