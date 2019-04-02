#include <stdio.h>
#include <stdlib.h>
#include "funcionesDiaz.h"


int sumarDosNumeros (int x, int y)
{
    int sumar;

    sumar = x + y;

    return sumar;
}

int restarDosNumeros (int x, int y)
{
    int resta;

    resta = x - y;

    return resta;
}

int multiplicarDosNumeros (int x, int y)
{
    int producto;

    producto = x * y;

    return producto;
}

float dividirDosNumeros (int x, int y)
{
    float resto;

    if( y == 0 )
    {
        printf("Error. No se puede dividir por 0.");
    }
    else
    {
        resto =(float) x / y;
    }

    return resto;
}

int factorial (int x)
{
    if ( x == 0 )
    {
        x = 1;
    }
    else
    {
        x = x * factorial(x-1);
    }

    return x;
}

int menuOpciones ()
{
    int opcion;

    printf("\n\n *** Menu de opciones *** \n\n");
    printf("1- Ingresar 1er operando (A = x).\n");
    printf("2- Ingresar 2do operando (B = y).\n");
    printf("3- Calcular todas las operaciones.\n");
    printf("4- Informar resultados.\n");
    printf("5- Salir.\n");
    printf("\nIngrese opcion: ");

    scanf("%d",&opcion);

    return opcion;
}
