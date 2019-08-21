#ifndef LINEAS_H_INCLUDED
#define LINEAS_H_INCLUDED
#include "Linea.h"
#include "Constantes.h"

typedef struct NodoAbb
{
    Linea linea;
    NodoAbb * hizq;
    NodoAbb * hder;
}abbnodo;

typedef abbnodo * Lineas;


// Crear un �rbol vac�o
void LineasCrear (Lineas &lineas);

//Liber memoria del �rbol
void LineasLiberar (Lineas &lineas);

// Saber si el �rbol est� vac�o
bool LineasEsVacio (Lineas lineas);

// Devolver la ra�z del �rbol
// Precondici�n: Arbol NO vac�o
Linea LineasDevolverRaiz (Lineas lineas);

// Obtener el sub�rbol izquierdo
// Precondici�n: Arbol NO vac�o
 Lineas LineasDevolverHijoIzq (Lineas lineas);

// Obtener el sub�rbol derecho
// Precondici�n: Arbol NO vac�o
Lineas LineasDevolverHijoDer (Lineas linea);

// Insertar un nuevo valor en el ABB
// precondici�n: el valor no exist�a previamente en el ABB
void LineasInsert (Lineas &lineas, Linea linea);

// Muestra el arbol
void LineasMostrar (Lineas lineas);

// Indica si una Linea existe en el abb
bool LineasExisteLineaEnABB (Lineas lineas, String codigo);

// Devuelve una Linea indicada del abb
Linea LineasDevolverLineaPorCodigo (Lineas lineas, String codigo);

void LineasMostrarParadasDeLinea (Lineas lineas, String codigo);

void LineasInsertarParadaEnLinea (Lineas &lineas, String codigo, String nombre);

#endif // LINEAS_H_INCLUDED

