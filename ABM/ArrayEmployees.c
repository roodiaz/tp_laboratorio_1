#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include "ArrayEmployees.h"

int menuABM()
{
    int opcion;

    system("cls");
    printf("##### Menu ABM #####\n\n");
    printf("   1. Altas.\n");
    printf("   2. Modificar.\n");
    printf("   3. Bajas.\n");
    printf("   4. Informar.\n\n");
    printf("      a. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n");
    printf("      b. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n\n");
    printf("   5. Salir.\n\n");
    printf(">> Ingresar opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

void mostrarEmpleado(eEmpleado empleado)
{
    printf("\n%d  %10s  %10s   %.2f    %d\n", empleado.id, empleado.nombre, empleado.apellido, empleado.sueldo, empleado.sector);
}

void mostrarEmpleados(eEmpleado vec[], int tam)
{
    int contador = 0;

    system("cls");

    printf("   ID        Nombre     Apellido    Sueldo    Sector\n\n");

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1)
        {
            mostrarEmpleado(vec[i]);
            contador++;
        }
    }
    printf("\n\n");

    if( contador == 0)
    {
        printf("\nNo hay empleados que mostrar\n");
    }
}

int buscarLibre(eEmpleado vec[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarEmpleado(eEmpleado vec[], int tam, int id)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1 && vec[i].id == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void altaEmpleado(eEmpleado vec[], int tam)
{

    int indice;
    int id;
    int ocupado;
    char auxChar[100];

    indice = buscarLibre(vec, tam);

    if( indice == -1)
    {
        printf("\nNo hay lugar en el sistema\n");
        system("pause");
    }
    else
    {
        srand(time(NULL));
        id = 1000 + rand() % (10000 - 1000);

        ocupado = buscarEmpleado(vec, tam, id);

        if( ocupado != -1)
        {
            srand(time(NULL));
            id = 1000 + rand() % (10000 - 1000);
        }
        else
        {
            vec[indice].id = id;

            printf("\nId: %d\n",id);

            printf("Ingresar nombre: ");
            fflush(stdin);
            gets(auxChar);


            while(strlen(auxChar)>50)
            {
                printf("Error. Ingresar nombre del empleado: ");
                gets(auxChar);
            }

            strlwr(auxChar);
            auxChar[0] = toupper(auxChar[0]);
            strcpy(vec[indice].nombre, auxChar);

            printf("Ingresar apellido: ");
            fflush(stdin);
            gets(auxChar);

            while(strlen(auxChar)>50)
            {
                printf("Error. Ingresar apellido del empleado: ");
                gets(auxChar);
            }

            strlwr(auxChar);
            auxChar[0] = toupper(auxChar[0]);

            strcpy(vec[indice].apellido, auxChar);


            printf("Ingrese sueldo: ");
            scanf("%f", &vec[indice].sueldo );

            while(vec[indice].sueldo<0)
            {
                printf("Error. Ingrese sueldo: ");
                scanf("%f", &vec[indice].sueldo );
            }

            printf("\n** Sectores **\n");
            printf("1. RRHH\n");
            printf("2. Sistemas\n");
            printf("3. Legales\n");
            printf("4. Ventas\n");
            printf("5. Compras\n\n");
            printf("Ingrese numero de sector: ");
            scanf("%d",&vec[indice].sector);

            while(vec[indice].sector < 1 || vec[indice].sector > 5)
            {
                printf("Error. Ingrese un sector valido: ");
                scanf("%d",&vec[indice].sector);
            }

            vec[indice].ocupado = 1;

            printf("\nAlta empleado realizada con exito.\n\n");
            system("pause");

        }
    }
}

void bajaEmpleado(eEmpleado vec[], int tam)
{
    int id;
    int indice;
    char confirma;

    printf("\nIngrese el Id: ");
    scanf("%d" ,&id);

    indice = buscarEmpleado (vec, tam, id);

    if (indice == -1)
    {
        printf ("El id %d no esta registrado en el sistema \n", id);
        system("pause");
    }
    else
    {
        mostrarEmpleado (vec[indice]);

        printf ("\nDesea dar de baja al empleado? s/n: ");
        fflush(stdin);
        confirma=tolower(getche());

        if(confirma != 's' && confirma != 'n')
        {
            printf("No es una opcion valida. Ingrese s/n: ");
            fflush(stdin);
            confirma=tolower(getche());
        }

        if(confirma == 's')
        {
            vec[indice].ocupado = 0 ;
        }
        else
        {
            printf ("\nSe ha cancelado la operacion.\n\n" );
            system("pause");
        }
    }
}
