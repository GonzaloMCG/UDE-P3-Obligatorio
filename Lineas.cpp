#include "Lineas.h"

// Crear un �rbol vac�o
void LineasCrear (Lineas &lineas)
{
    lineas = NULL;
}

//Liber memoria del �rbol
void LineasLiberar (Lineas &lineas)
{
	if (lineas != NULL)
	{
    	LineasLiberar(lineas->hizq);
    	LineasLiberar(lineas->hder);
    	LineaLiberar (lineas->linea);
	delete lineas;
    	lineas = NULL;
	}
}


// Saber si el �rbol est� vac�o
bool LineasEsVacio (Lineas lineas)
{
    return (bool) (lineas == NULL);
}

// Devolver la ra�z del �rbol
// Precondici�n: Arbol NO vac�o
Linea LineasDevolverRaiz (Lineas lineas)
{
    return lineas->linea;
}

// Obtener el sub�rbol izquierdo
// Precondici�n: Arbol NO vac�o
 Lineas LineasDevolverHijoIzq (Lineas lineas)
 {
    return lineas->hizq;
 }

// Obtener el sub�rbol derecho
// Precondici�n: Arbol NO vac�o
Lineas LineasDevolverHijoDer (Lineas lineas)
{
    return lineas->hder;
}

// Insertar un nuevo valor en el ABB
// precondici�n: el valor no exist�a previamente en el ABB
void LineasInsert (Lineas &lineas, Linea linea)
{
    String actual, nuevo;
    if (lineas == NULL)
    {
        lineas = new abbnodo;
        lineas->linea = linea;
        lineas->hizq = NULL;
        lineas->hder = NULL;
    }
    else
    {
        LineaDevolverCodigo(linea, nuevo);
        LineaDevolverCodigo(lineas->linea, actual);
        if (!StringMenor(actual, nuevo))
            LineasInsert (lineas->hizq, linea);
        else
            LineasInsert (lineas->hder, linea);
    }
}

// Muestra el arbol
void LineasMostrar (Lineas lineas)
{
    if (lineas != NULL)
    {
        LineasMostrar(lineas->hizq);
        LineaMostrar(lineas->linea);
        LineasMostrar(lineas->hder);
    }
}

// Indica si una linea existe en el abb
bool LineasExisteLineaEnABB (Lineas lineas, String codigo)
{
    String straux;
    StringCrear(straux);
    if (lineas == NULL)
        return false;
    else
    {
        LineaDevolverCodigo(lineas->linea, straux);
        if (StringIguales(straux, codigo))
            return true;
        else
        {
            if (StringMenor(codigo, straux))
                return LineasExisteLineaEnABB (lineas->hizq, codigo);
            else
                return LineasExisteLineaEnABB (lineas->hder, codigo);
        }
    }
}

// Devuelve una linea indicada del abb
//La linea debe existir
Linea LineasDevolverLineaPorCodigo (Lineas lineas, String codigo)
{
    String straux;
    StringCrear(straux);
    LineaDevolverCodigo(lineas->linea, straux);
    if(StringIguales(straux, codigo))
        return lineas->linea;
    else
        {
            if(StringMenor(codigo, straux))
                return LineasDevolverLineaPorCodigo(lineas->hizq, codigo);
            else
                return LineasDevolverLineaPorCodigo(lineas->hder, codigo);
        }
}

void LineasMostrarParadasDeLinea(Lineas lineas, String codigo)
{
    LineaMostrarParadas(LineasDevolverLineaPorCodigo(lineas, codigo));
}

void LineasInsertarParadaEnLinea (Lineas &lineas, String codigo, String nombre)
{
    String straux;
    StringCrear(straux);
    LineaDevolverCodigo(lineas->linea, straux);
    if(StringIguales(straux, codigo))
        LineaInsertarParada(lineas->linea, nombre);
    else
    {
        if(StringMenor(codigo, straux))
            LineasInsertarParadaEnLinea(lineas->hizq, codigo, nombre);
        else
            LineasInsertarParadaEnLinea(lineas->hder, codigo, nombre);
    }
    StringDestruir(straux);
}
