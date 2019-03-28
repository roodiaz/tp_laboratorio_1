#include <stdio.h>
#include <stdlib.h>

float sumarDosNumeros (float x, float y)
{
    float sumar;

    sumar = x + y;

    return sumar;
}

float restarDosNumeros (float x, float y)
{
    float resta;

    resta = x - y;

    return resta;
}

float multiplicarDosNumeros (float x, float y)
{
    float producto;

    producto = x * y;

    return producto;
}

float dividirDosNumeros (float x, float y)
{
    float resto;

    if( y == 0 )
    {
        printf("Error, no se puede dividir por 0. Ingrese otro numero.");
    }
    else
    {
        resto = x / y;
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
