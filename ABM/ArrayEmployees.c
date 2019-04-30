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

void inicializarEmpleados(eEmpleado vec[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        vec[i].ocupado = 0;
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
        if(vec[i].id == 1 && vec[i].id == id)
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
   int aleatorio;
   int usado;
   char auxChar[100];

   indice = buscarLibre(vec,tam);

   if(indice == -1)
   {
       printf("No hay lugar para dar de alta.\n");
   }

   else
   {
        srand(time(NULL));
        aleatorio = 1000 + rand() % (10000 - 1000);

        usado = buscarEmpleado(vec, tam, aleatorio);

        while(usado != -1)
        {
            srand(time(NULL));
            aleatorio = 1000 + rand() % (10000 - 1000);
        }

        if(usado == -1)
        {
            vec[indice].id = aleatorio;
            printf("\nId: %d\n",aleatorio);

            printf("Ingresar nombre: ");
            fflush(stdin);
            gets(auxChar);


            while(strlen(auxChar)>50)
            {
                printf("Error. Ingresar nombre del empleado: ");
                gets(auxChar);
            }

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

            while(vec[indice].sector < 0 || vec[indice].sector > 5)
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

void mostrarEmpleado(eEmpleado empleado)
{
    printf("Id  Nombre  Apellido Sueldo Sector \n");
    printf("%d    %s       %s      %2.f   %d",empleado.id,empleado.nombre,empleado.apellido,empleado.sueldo,empleado.sector);
}

