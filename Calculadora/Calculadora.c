#include <stdio.h>
#include <stdlib.h>
#include "funcionesDiaz.h"

int main()
{
    char seguir = 's';
    int i = 0;
    int flag1 = 0;
    int flag2 = 0;
    int num1;
    int num2;

    do
    {

        switch(menuOpciones())
        {
            case 1:
                printf("\nIngresar primer numero: ");
                scanf("%d",&num1);
                flag1 = 1;
            break;
            case 2:
                printf("\nIngresar segundo numero: ");
                scanf("%d",&num2);
                flag2 = 1;
            break;
            case 3:
                if(flag1 == 0 || flag2 == 2)
                {
                    printf("\nNo es posible calcular. No se ha ingresado uno o ambos numeros.\n");
                }
                else
                {
                    printf("/n ***Menu opcion 3*** \n");
                    printf("a- Calcular la suma de (%d + %d)\n",num1,num2);
                    printf("b- Calcular la resta de (%d - %d)\n",num1,num2);
                    printf("c- Calcular la division de (%d / %d)\n",num1,num2);
                    printf("d- Calcular la  multiplicacion de (%d * %d)\n",num1,num2);
                    printf("e- Calcular el factorial de (!%d) y (!%d)\n",num1,num2);
                }
            break;
            case 4:
                    if(flag1 == 0 || flag2 == 0)
                {
                    printf("\nNo es posible mostrar los resultados. Falta ingresar uno o ambos numeros.\n");
                }
                else
                {
                    printf("a- El resultado de %d + %d es: %d",num1, num2, sumarDosNumeros(num1, num2));
                    printf("b- El resultado de %d - %d es: %d",num1, num2, restarDosNumeros(num1, num2));
                    printf("c- El resultado de %d / %d es: %f",num1, num2, dividirDosNumeros(num1, num2));
                    printf("d- El resultado de %d * %d es: %d",num1, num2, multiplicarDosNumeros(num1, num2));
                    printf("e- El factorial de !%d es: %d y el factorial de !%d es: %d",num1, factorial(num1), num2, factorial(num2));
                }

            break;
            case 5:
                    printf("\nDesea seguir? s / n: ");
                    scanf(" %c",&seguir);
            break;

        }




        i++;
    } while ( seguir == 's');



    return 0;
}
