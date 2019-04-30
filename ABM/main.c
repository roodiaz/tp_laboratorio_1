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

    char seguir = 's';

    eEmpleado lista[TAM];
    inicializarEmpleados(lista,TAM);


    do
    {
        switch(menuABM())
        {
            case 1:
                altaEmpleado(lista, TAM);
            break;

        }

    }while(seguir == 's');

    return 0;
}


