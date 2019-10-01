#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputDiaz.h"
#include "arrayEmployyes.h"

#define TAM 4
#define TAMS 5


int main()
{
    int salir;
    int id = 1000;
    eEmployee empleados[TAM];
    eSector sectores[TAMS]=
    {
        {1,"RRHH"},
        {2,"SISTEMAS"},
        {3,"LEGALES"},
        {4,"VENTAS"},
        {5,"COMPRAS"}
    };

    inicializarEmpleados(empleados,TAM);
     id = id+hardCodeo(empleados,TAM,3);


    do
    {
        switch(menuABM())
        {
        case 1:
            if(altaEmpleado(empleados,TAM,id,sectores,TAMS))
            {
                id++;
            }
            break;

        case 2:
            system("cls");
            modificarEmpleado(empleados,TAM,sectores,TAMS);
            break;

        case 3:
            system("cls");
            bajaEmpleado(empleados,TAM,sectores,TAMS);
            break;

        case 4:
            informes(empleados,TAM,sectores,TAMS);
            break;

        case 5:
            salir=confimarSalir("Desea salir? s/n: ");
            break;

        default:
            system("cls");
            printf("Ingrese opcion valida!\n\n");
        }
        system("pause");

    }
    while(salir != 1);


    return 0;
}
