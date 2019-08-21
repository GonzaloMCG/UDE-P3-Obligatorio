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


// Crear un árbol vacío
void LineasCrear (Lineas &lineas);

//Liber memoria del árbol
void LineasLiberar (Lineas &lineas);

// Saber si el árbol está vacío
bool LineasEsVacio (Lineas lineas);

// Devolver la raíz del árbol
// Precondición: Arbol NO vacío
Linea LineasDevolverRaiz (Lineas lineas);

// Obtener el subárbol izquierdo
// Precondición: Arbol NO vacío
 Lineas LineasDevolverHijoIzq (Lineas lineas);

// Obtener el subárbol derecho
// Precondición: Arbol NO vacío
Lineas LineasDevolverHijoDer (Lineas linea);

// Insertar un nuevo valor en el ABB
// precondición: el valor no existía previamente en el ABB
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

