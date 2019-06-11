#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
    char salir;

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
                printf("\nEmpleado dado de alta con exito.\n\n");
            }
            else
            {
                printf("\nError al ingresar el empleado.\n\n");
            }
            system("pause");
            break;
        case 4:
            if(controller_editEmployee(listEmp)==1)
            {
                printf("\nEmpleado modificado con exito.\n\n");
            }
            else
            {
                printf("Error al modificar empleado.\n\n");
            }
            system("pause");
            break;
        case 5:
            if(ll_isEmpty(listEmp)!=1)
            {
                if(controller_removeEmployee(listEmp)==1)
                {
                    printf("Empleado dado de baja con exito.\n\n");
                }
                else
                {
                    printf("Error al dar de baja.\n\n");
                }
            }
            else
            {
                printf("No hay empleados cargados en el sistema.\n\n");
            }
            system("pause");
            break;
        case 6:
            if(ll_isEmpty(listEmp)!=1)
            {
                controller_ListEmployee(listEmp);
            }
            else
            {
                printf("No hay empleados cargados en el sistema.\n\n");
            }
            system("pause");
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            printf("\nDesea salir? s/n: ");
            fflush(stdin);
            scanf("%c",&salir);
            salir=tolower(salir);
            break;
        default:
            printf("Opcion invalida\n");
            break;

        }
    }
    while(salir != 's');
    return 0;
}




