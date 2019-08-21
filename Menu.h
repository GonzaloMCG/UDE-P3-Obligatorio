#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdlib.h>
#include "Ciudades.h"
#include "Lineas.h"
#include "Rutas.h"

///Cabezales sintácticos de subprogramas

    //Menu Principal
void MenuPrincipalDesplegar();

    //Menu Altas de Ciudades
void MenuAltasCiudades();

    //Agregar tramo entre ciudades
void MenuAltasTramos();

    //Existe secuencia entre ciudades
void MenuConsultaSecuencia();

    //Ingresar nueva Linea
void MenuAltaLinea();

    //Listar Lineas  (código, origen, destino y cantidad de paradas)
void MenuListarLineas();

    //Agrega una parada a una Linea
void MenuAgregarParada();

    //Listar Paradas de una Linea (número de parada y nombre de ciudad)
void MenuListarParadas();

    //Mensaje de Salida del Programa
void MenuPrincipalSalir();

    //Procedimiento para mostrar el principio del menu (grafico)
void TextoInicioMenu();

    //Procedimiento para mostrar el final del menu (grafico)
void TextoFinalDeMenu();

#endif // MENU_H_INCLUDED
