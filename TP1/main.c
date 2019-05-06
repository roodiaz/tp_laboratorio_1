#include <stdio.h>
#include <stdlib.h>
#include "funcionesDiaz.h"

int main()
{
    char salir = 'n';
    int i = 0;
    int flag1 = 0;
    int flag2 = 0;
    int flag3 = 0;
    int num1;
    int num2;
    int opcion;

    do
    {

     if(flag1 == 0 && flag2 == 0)
   {
    printf("\n *** Menu de opciones *** \n\n");
    printf("1- Ingresar 1er operando (A = x).\n");
    printf("2- Ingresar 2do operando (B = y).\n");
    printf("3- Calcular todas las operaciones.\n");
    printf("4- Informar resultados.\n");
    printf("5- Salir.\n");
    printf("\nIngrese opcion: ");
    scanf("%d",&opcion);
   }
    else if(flag1 == 1 && flag2 == 0)
   {
    printf("\n\n *** Menu de opciones *** \n\n");
    printf("1- Ingresar 1er operando (A = %d).\n",num1);
    printf("2- Ingresar 2do operando (B = y).\n");
    printf("3- Calcular todas las operaciones.\n");
    printf("4- Informar resultados.\n");
    printf("5- Salir.\n");
    printf("\nIngrese opcion: ");
    scanf("%d",&opcion);
   }
   else if(flag1 == 0 && flag2 == 1)
   {
    printf("\n\n *** Menu de opciones *** \n\n");
    printf("1- Ingresar 1er operando (A = x).\n");
    printf("2- Ingresar 2do operando (B = %d).\n", num2);
    printf("3- Calcular todas las operaciones.\n");
    printf("4- Informar resultados.\n");
    printf("5- Salir.\n");
    printf("\nIngrese opcion: ");
    scanf("%d",&opcion);
   }
   else
   {
    printf("\n\n *** Menu de opciones *** \n\n");
    printf("1- Ingresar 1er operando (A = %d).\n",num1);
    printf("2- Ingresar 2do operando (B = %d).\n",num2);
    printf("3- Calcular todas las operaciones.\n");
    printf("4- Informar resultados.\n");
    printf("5- Salir.\n");
    printf("\nIngrese opcion: ");
    scanf("%d",&opcion);
   }

        switch(opcion)
        {
            case 1:
                printf("\n>>>>Ingresar primer numero: ");
                scanf("%d",&num1);
                flag1 = 1;
                system("pause");
            break;
            case 2:
                printf("\n>>>>>Ingresar segundo numero: ");
                scanf("%d",&num2);
                flag2 = 1;
                system("pause");
            break;
            case 3:
                if(flag1 == 0 || flag2 == 0)
                {
                    printf("\nNo es posible calcular. No se ha ingresado uno o ambos numeros.\n");
                }
                else
                {
                    printf("\na- Calcular la suma de (%d + %d)\n",num1,num2);
                    printf("b- Calcular la resta de (%d - %d)\n",num1,num2);
                    printf("c- Calcular la division de (%d / %d)\n",num1,num2);
                    printf("d- Calcular la  multiplicacion de (%d * %d)\n",num1,num2);
                    printf("e- Calcular el factorial de (!%d) y (!%d)\n",num1,num2);
                    flag3 = 1;
                    system("pause");
                }
            break;
            case 4:
                    if(flag1 == 0 || flag2 == 0)
                {
                    printf("\nNo es posible mostrar los resultados. Falta ingresar uno o ambos numeros.\n");
                }
                    else if(flag3 == 0)
                {
                        printf("\nNo es posible mostrar los resultados. Falta realizar las operaciones (opcion 3).");
                }

                else
                {
                    printf("\na- El resultado de %d + %d es: %d\n",num1, num2, sumarDosNumeros(num1, num2));
                    printf("b- El resultado de %d - %d es: %d\n",num1, num2, restarDosNumeros(num1, num2));
                    printf("c- El resultado de %d / %d es: %f\n",num1, num2, dividirDosNumeros(num1, num2));
                    printf("d- El resultado de %d * %d es: %d\n",num1, num2, multiplicarDosNumeros(num1, num2));
                    printf("e- El factorial de !%d es: %d y el factorial de !%d es: %d\n",num1, factorial(num1), num2, factorial(num2));
                    system("pause");
                }

            break;
            case 5:
                    printf("\n>>>>Desea salir? s / n: ");
                    scanf(" %c",&salir);
            break;

        }

        i++;

    } while ( salir == 'n');



    return 0;
}
