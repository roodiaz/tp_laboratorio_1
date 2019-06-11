#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/

int menu();

int main()
{
    LinkedList* listEmp = ll_newLinkedList();
    int opcion=0;

    do
    {
        switch(menu())
        {
        case 1:
            if(controller_loadFromText("data.csv",listEmp) == 1)
            {
                printf("Archivo cargado correctamente.\n\n");
            }
            else
            {
                printf("Error al cargar archivos.\n\n");
            }
            system("pause");
            break;
        case 2:
            if(controller_loadFromBinary("data.bin",listEmp) == 1)
            {
                printf("Archivo cargado correctamente.\n\n");
            }
            else
            {
                printf("Error al cargar archivos.\n\n");
            }
            system("pause");
            break;
        case 3:
            if(controller_addEmployee(listEmp)==1)
                {
                    printf("\nEmpleado dado de alta con exito!!!\n\n");
                }
                else
                {
                    printf("\nError al ingresar el empleado.\n\n");
                }
                system("pause");
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;

        }
    }
    while(opcion != 10);
    return 0;
}


int menu()
{
    int opcion;

    system("cls");
    printf("                    ###   Menu   ###\n");
    printf("--------------------------------------------------------\n\n");
    printf("1_ Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2_ Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3_ Alta de empleado\n");
    printf("4_ Modificar datos de empleado\n");
    printf("5_ Baja de empleado\n");
    printf("6_ Listar empleados\n");
    printf("7_ Ordenar empleados\n");
    printf("8_ Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9_ Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10_ Salir\n\n");

    printf("INGRESE OPCION: ");
    scanf("%d",&opcion);

    return opcion;

}


