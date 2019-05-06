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
            break;

            case 3:
                if(flag == 0)
                {
                    printf("Primero debe dar de alta algun empleado.\n");
                    system("pause");
                }
                else
                {
                    bajaEmpleado(lista, TAM);
                }
            break;
        }

    }while(salir == 'n');


    return 0;
}
