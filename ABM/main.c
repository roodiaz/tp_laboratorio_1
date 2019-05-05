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

    char salir = 'n';
    int flag = 0;

    eEmpleado lista[TAM];
    inicializarEmpleados(lista,TAM);


    do
    {
        switch(menuABM())
        {
            case 1:
                altaEmpleado(lista, TAM);
                flag=1;
            break;

            case 2:
                if(flag == 0)
                {
                    printf("Primero debe dar de alta algun empleado.\n");
                }
                else
                {
                    modificacionEmpleado(lista, TAM);
                }
            break;

            case 3:
                if(flag == 0)
                {
                    printf("Primero debe dar de alta algun empleado.\n");
                }
                else
                {
                    bajaEmpleado(lista, TAM);
                }
            break;

            case 4:

            break;

            case 5:
                printf("\nDesea salir? s/n");
                fflush(stdin);
                salir = tolower(getche());

                if(salir != 's' || salir != 'n')
                {
                    printf("No es una opcion valida. Ingrese s/n: ");
                    fflush(stdin);
                    salir = tolower(getche());
                }
            break;

        }

    }while(salir == 'n');

    return 0;
}


