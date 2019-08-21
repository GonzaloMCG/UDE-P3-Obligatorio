#include "Menu.h"

///Implementación de los subprogramas definidos en el .h


    ///Menu Principal
void MenuPrincipalDesplegar()
{
    int i,h;
    system("cls");
    for(i=0;i<56;i++)
    {
        printf("*");
    }
    printf("\n******               MENU PRINCIPAL               ******\n");
    for(i=0;i<56;i++)
    {
        printf("*");
    }
    for(i=0;i<3;i++)
    {
        printf("\n**");
        for(h=0;h<52;h++)
            printf(" ");
        printf("**");
    }
    printf("\n**      1. Agregar una conexion entre Ciudades        **\n");
    printf("**      2. Consultar conexion entre dos Ciudades      **\n");
    printf("**      3. Ingresar nueva Linea                       **\n");
    printf("**      4. Listar todas las Lineas                    **\n");
    printf("**      5. Agregar Paradas a una Linea                **\n");
    printf("**      6. Listar las Paradas de una Linea            **\n");
    printf("**      0. Salir                                      **");
    for(i=0;i<3 ;i++)
    {
        printf("\n**");
        for(h=0;h<52;h++)
            printf(" ");
        printf("**");
    }
    printf("\n");
    for(i=0;i<56;i++)
    {
        printf("*");
    }
    printf("\n                 Ingrese una Opcion: ");
}

    ///Mensaje de Salida del Programa
void MenuPrincipalSalir()
{
    int i,h;
    system("cls");
    for(i=0;i<56;i++)printf("*");
    printf("\n******           SALIENDO DEL PROGRAMA            ******\n");
    for(i=0;i<56;i++)printf("*");
    for(i=0;i<3;i++)
    {
        printf("\n**");
        for(h=0;h<52;h++)
            printf(" ");
        printf("**");
    }
    printf("\n**           Integrantes:                             **\n");
    printf("**           Federico Perez - 4.469.564-1             **\n");
    printf("**           Fernando Vila - 3.513.169-0              **\n");
    printf("**           Gonzalo Caceres - 4.490.558-7            **");
    for(i=0;i<3 ;i++)
    {
        printf("\n**");
        for(h=0;h<52;h++)
            printf(" ");
        printf("**");
    }
    printf("\n");
    for(i=0;i<56;i++)printf("*");
}


    ///Menu Altas de Ciudades
void MenuAltasCiudades()
{
    int i;
    system("cls");
    for(i=0;i<56;i++){printf("*");}
    printf("\n******             AGREGAR CIUDADES               ******\n");
    for(i=0;i<56;i++){printf("*");}
    printf("\n\n");
}

    ///Agregar tramo entre ciudades
void MenuAltasTramos()
{
    int i;
    system("cls");
    for(i=0;i<56;i++){printf("*");}
    printf("\n******              AGREGAR CONEXIONES            ******\n");
    for(i=0;i<56;i++){printf("*");}
    printf("\n\n");
}

    ///Existe secuencia entre ciudades
void MenuConsultaSecuencia()
{
    int i;
    system("cls");
    for(i=0;i<56;i++){printf("*");}
    printf("\n******             CONSULTAR CONEXIONES           ******\n");
    for(i=0;i<56;i++){printf("*");}
    printf("\n\n");
}

    ///Ingresar nueva Linea
void MenuAltaLinea()
{
    int i;
    system("cls");
    for(i=0;i<56;i++){printf("*");}
    printf("\n******           INGRESAR NUEVA LINEA             ******\n");
    for(i=0;i<56;i++){printf("*");}
    printf("\n\n");

}

    ///Listar Lineas  (código, origen, destino y cantidad de paradas)
void MenuListarLineas()
{
    int i;
    system("cls");
    for(i=0;i<56;i++){printf("*");}
    printf("\n******                LISTADO LINEAS              ******\n");
    for(i=0;i<56;i++){printf("*");}
    printf("\n\n");
}


    ///Agrega una parada a una Linea
void MenuAgregarParada()
{
    int i;

    system("cls");
    for(i=0;i<56;i++){printf("*");}
    printf("\n******               AGREGAR PARADAS              ******\n");
    for(i=0;i<56;i++){printf("*");}
    printf("\n\n");
}

    ///Listar Paradas de una Linea (número de parada y nombre de ciudad)
void MenuListarParadas()
{
    int i;
    system("cls");
    for(i=0;i<56;i++){printf("*");}
    printf("\n******             LISTADO DE PARADAS             ******\n");
    for(i=0;i<56;i++){printf("*");}
    printf("\n\n");
}

    ///Procedimiento para mostrar el principio del menu (grafico)
void TextoInicioMenu()
{
    int i,h;
    for(i=0;i<3;i++)
    {
        printf("\n**");
        for(h=0;h<52;h++)
            printf(" ");
        printf("**");
    }
}

    ///Procedimiento para mostrar el final del menu (grafico)
void TextoFinalDeMenu()
{
    int i,h;
    for(i=0;i<3;i++)
    {
        printf("\n**");
        for(h=0;h<52;h++)
            printf(" ");
        printf("**");
    }
    printf("\n");
    for(i=0;i<56;i++){printf("*");}
    printf("\n\n");
}
