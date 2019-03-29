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
                printf("Ingresar primer numero: ");
                scanf("%d",&num1);
                flag1 = 1;
            break;
            case 2:
                printf("Ingresar segundo numero: ");
                scanf("%d",&num2);
                flag2 = 1;
            break;
            case 3:
                if(flag1 == 0 || flag2 == 2)
                {
                    printf("Error. No se ha ingresado uno o ambos operandos.\n");
                }
                else
                {
                    printf("a- Calcular la suma de (%d + %d)\n",num1,num2);
                    printf("b- Calcular la resta de (%d - %d)\n",num1,num2);
                    printf("c- Calcular la")
                }

        }




        i++;
    } while ( seguir == 's');



    return 0;
}
