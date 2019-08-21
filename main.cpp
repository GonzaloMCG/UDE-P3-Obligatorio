#include "Menu.h"

int main()
{
    ///Declaración de Variables
    int Opcion, intaux1, intaux2, i;
    String codigo, straux, straux2, straux3, straux4;
    Ciudad ciudadaux, ciudadaux2;
    Rutas rutas;
    Linea linea;
    Lineas lineas;
    Ciudades ciudades;

    ///Inicializar
    LineasCrear(lineas);
    CiudadesCrear(ciudades);
    RutasCrear(rutas);
    i = 0;
    for (i = 0; i < cant; i++)
    {
        fflush(stdin);
        MenuAltasCiudades();
        StringCrear(straux);
        printf("Ingrese el nombre de la ciudad: ");
        StringCargar(straux);
        CiudadCrear(ciudadaux, straux, i);
        CiudadesInsertar(ciudades, ciudadaux);
        StringDestruir(straux);
    }

    ///Despliegue de Menu Principal
    do
    {
        StringCrear(codigo);
        StringCrear(straux);
        StringCrear(straux2);
        StringCrear(straux3);
        StringCrear(straux4);
        MenuPrincipalDesplegar();
        fflush(stdin);
        scanf("%d",&Opcion);
        switch(Opcion)
        {
        case 1 :///1. Agregar tramo entre ciudades
            {
                MenuAltasTramos();
                fflush(stdin);
                printf("Ingrese Ciudad de origen: ");
                StringCargar(straux);
                if (CiudadesPertenece(ciudades, straux))
                {
                    fflush(stdin);
                    printf("Ingrese Ciudad de destino: ");
                    StringCargar(straux2);
                    if (CiudadesPertenece(ciudades, straux2))
                    {
                        intaux1 = CiudadDevolverID(CiudadesObtener(ciudades, straux));
                        intaux2 = CiudadDevolverID(CiudadesObtener(ciudades, straux2));
                        RutasAgregarTramo(rutas, intaux1, intaux2);
                    }
                    else
                        printf("\nCiudad ingresada no existe\n");
                }
                else
                    printf("\nCiudad ingresada no existe\n");

                system("pause");
                break;
            }

        case 2 :///2. Existe secuencia entre ciudades
            {
                MenuConsultaSecuencia();
                fflush(stdin);
                printf("Ingrese una Ciudad: ");
                StringCargar(straux);
                if (CiudadesPertenece(ciudades, straux))
                {
                    fflush(stdin);
                    printf("Ingrese otra Ciudad: ");
                    StringCargar(straux2);
                   if (CiudadesPertenece(ciudades, straux2))
                    {
                        intaux1 = CiudadDevolverID(CiudadesObtener(ciudades, straux));
                        intaux2 = CiudadDevolverID(CiudadesObtener(ciudades, straux2));
                        if(RutasDFSecuencia(rutas, intaux1, intaux2))
                        {
                            printf("Existe");
                        }
                        else
                        {
                            printf("No existe");
                        }
                        printf(" una secuencia de tramos que une ");
                        StringMostrar(straux);
                        printf(" con ");
                        StringMostrar(straux2);
                        printf(".\n");
                    }
                    else
                        printf("\nCiudad ingresada no existe\n");
                }
                else
                    printf("\nCiudad ingresada no existe\n");

                system("pause");
                break;
            }

        case 3:///3. Ingresar nueva Linea
            {
                MenuAltaLinea();
                fflush(stdin);
                printf("Ingrese el codigo de la linea: ");
                StringCargar(codigo);
                if (StringEsAlfaNumerico(codigo))
                {
                    if (LineasExisteLineaEnABB(lineas, codigo))
                    {
                        printf("La linea con el codigo ");
                        StringMostrar(codigo);
                        printf(" ya existe.\n\n");
                    }
                    else
                    {
                        fflush(stdin);
                        printf("Ingrese la ciudad de origen: ");
                        StringCargar(straux);
                        if (CiudadesPertenece(ciudades, straux))
                        {
                            fflush(stdin);
                            printf("Ingrese la ciudad de destino: ");
                            StringCargar(straux2);
                            if (CiudadesPertenece(ciudades, straux2))
                            {
                                if (!StringIguales(straux, straux2))
                                {
                                    ciudadaux = CiudadesObtener(ciudades, straux);
                                    ciudadaux2 = CiudadesObtener(ciudades, straux2);
                                    if (RutasDFSecuencia(rutas, CiudadDevolverID(ciudadaux), CiudadDevolverID(ciudadaux2)))
                                    {
                                        LineaCrear(linea, codigo, ciudadaux, ciudadaux2);
                                        LineasInsert(lineas, linea);
                                    }
                                    else
                                    {
                                        printf("No existe una secuencia de tramos entre la ciudad de origen y la de destino.\n");
                                    }
                                }
                                else
                                {
                                    printf("La ciudad de origen no puede ser igual a la de destino\n");
                                }
                            }
                            else
                                printf("\nLa ciudad de destino no existe.\n");
                        }
                        else
                        {
                            printf("\nLa ciudad de origen no existe.\n");
                        }
                    }
                }
                else
                {
                    printf("\nEl codigo ingresado no es alfanumerico.\n");
                }

                system("pause");
                break;
            }
        case 4 :///4. Listar Lineas  (código, origen, destino y cantidad de paradas)
            {
                MenuListarLineas();
                if (lineas == NULL)
                {
                    printf("\nNo hay lineas ingresadas en la empresa.\n");
                }
                else
                {
                    LineasMostrar(lineas);
                }
                system("pause");
                break;
            }
        case 5 :///5. Agrega una parada a una Linea
            {
                MenuAgregarParada();
                fflush(stdin);
                printf("Ingrese el codigo de una linea: ");
                StringCargar(straux);
                if (LineasExisteLineaEnABB(lineas, straux))
                {
                    printf("Ingrese la nueva parada: ");
                    StringCargar(straux2);
                    if (CiudadesPertenece(ciudades, straux2))
                    {
                        linea = LineasDevolverLineaPorCodigo(lineas, straux);
                        if (ParadasVacia(LineaDevolverParadas(linea)))
                        {
                            CiudadDevolverNombre(LineaDevolverOrigen(linea), straux4);
                            if (StringIguales(straux2, straux4))
                            {
                                LineasInsertarParadaEnLinea(lineas, straux, straux2);
                            }
                            else
                            {
                                printf("\nLa primer parada debe coincidir con el origen de la linea.\n");
                            }
                        }
                        else
                        {
                            ParadaDevolverNombre(ParadasUltimo(LineaDevolverParadas(linea)), straux3);
                            CiudadDevolverNombre(LineaDevolverDestino(linea), straux4);
                            if (StringIguales(straux4, straux3))
                            {
                                printf("\nLa linea ya tiene su recorrido terminado.\n");
                            }
                            else
                            {
                                if (RutasExisteTramo(rutas, CiudadDevolverID(CiudadesObtener(ciudades, straux2)), CiudadDevolverID(CiudadesObtener(ciudades, straux3))))
                                {
                                    LineasInsertarParadaEnLinea(lineas, straux, straux2);
                                }
                                else
                                {
                                    printf("\nNo existe una tramo entre la ultima parada antes del destino y la nueva.\n");
                                }
                            }
                        }
                    }
                    else
                    {
                        printf("La parada que desea agregar no existe.\n");
                    }
                }
                else
                {
                    printf("La linea ingresada no existe.\n");
                }

                ///BLOQUE DE CODIGO
                ///BLOQUE DE CODIGO

                system("pause");
                break;
            }
        case 6 :///6. Listar Paradas de una Linea (número de parada y nombre de ciudad)
            {
                MenuListarParadas();
                fflush(stdin);
                printf("Ingresar una Linea: ");
                StringCargar(codigo);
                if (LineasExisteLineaEnABB(lineas, codigo))
                {
                    LineasMostrarParadasDeLinea(lineas, codigo);
                }
                else
                {
                    printf("\nLa linea ingresada no existe.\n");
                }

                system("pause");
                break;
            }
        default:
            {
                break;
            }
        }
        StringDestruir(codigo);
        StringDestruir(straux);
        StringDestruir(straux2);
        StringDestruir(straux3);
        StringDestruir(straux4);
    }while(Opcion != 0); ///Volver al menu principal
    ///Salida del programa
    MenuPrincipalSalir();
    LineasLiberar(lineas);
    CiudadLiberar(ciudadaux);
    CiudadLiberar(ciudadaux2);
    CiudadesLiberar(ciudades);
}
