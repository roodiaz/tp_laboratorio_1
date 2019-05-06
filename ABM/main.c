#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include "ArrayEmployees.h"

#define TAM 1000


int main()
{
    eEmpleado lista[TAM];
    float flag=0;
    char salir = 'n';

    do
    {
        switch(menuABM())
        {
            case 1:
                altaEmpleado(lista, TAM);
                flag =1;
            break;

            case 2:
                if(flag == 0)
                {
                    printf("\nPrimero debe dar de alta algun empleado!!!!\n\n");
                    system("pause");
                }
                else
                {
                    modificacionEmpleado(lista, TAM);
                }
            break;

            case 3:
                if(flag == 0)
                {
                    printf("\nPrimero debe dar de alta algun empleado!!!!\n\n");
                    system("pause");
                }
                else
                {
                    bajaEmpleado(lista, TAM);
                }
            break;

            case 4:
                if(flag == 0)
                {
                    printf("\nPrimero debe dar de alta algun empleado!!!!\n\n");
                    system("pause");
                }
                else
                {
                    informacionEmpleados(lista,TAM);
                }
            break;

            case 5:
                printf("\nDesea salir?s/n: ");
                fflush(stdin);
                salir = tolower(getche());

                if(salir != 's' || salir != 'n')
                {
                    printf("No es una opcion valida. Ingrese s/n: ");
                    fflush(stdin);
                    salir = tolower(getche());
                }
            break;

            default:
                printf("\n\nNo se ha ingresado una opcion valida!!!!.\n\n");
                system("pause");
        }

    }while(salir == 'n');


    return 0;
}
