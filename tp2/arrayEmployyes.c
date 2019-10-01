#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputDiaz.h"
#include "arrayEmployyes.h"


int menuABM()
{
    int opcion;

    system("cls");
    printf("***** Menu ABM *****\n\n");
    printf("1. Altas.\n");
    printf("2. Modificar.\n");
    printf("3. Bajas.\n");
    printf("4. Informar.\n\n");
    printf("5. Salir.\n\n");
    printf("Ingresar opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

int menuModificacion()
{
    int opcion;

    system("cls");
    printf("***** Menu modificacion *****\n\n");
    printf("1. Nombre.\n");
    printf("2. Apellido.\n");
    printf("3. Salario.\n");
    printf("4. Sector.\n\n");
    printf("5. Volver al menu principal.\n\n");
    printf("Ingresar opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

int menuSectores()
{
    int opcion;

    system("cls");
    printf("***** Menu sectores *****\n\n");
    printf("1. RRHH\n");
    printf("2. Sistemas\n");
    printf("3. Legales\n");
    printf("4. Ventas\n");
    printf("5. Compras\n\n");
    printf("Ingrese numero sector: ");
    scanf("%d",&opcion);

    while(opcion < 0 || opcion > 5)
    {
        printf("Ingrese numero sector valido: ");
        scanf("%d",&opcion);
    }

    return opcion;
}

int menuInformes()
{
    int opcion;

    system("cls");
    printf("***** Menu informes *****\n\n");
    printf("1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector.\n");
    printf("2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n\n");
    printf("3. Volver al menu principal\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

void inicializarEmpleados(eEmployee vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

int buscarLibre(eEmployee vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarId(int id, eEmployee vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].id == id && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarNombreSector(int id, eSector vec[], int tam, char dondeAsignar[])
{
    int todoOk = 0;

    for(int i=0; i < tam; i++)
    {
        if( id == vec[i].idSector)
        {
            strcpy(dondeAsignar, vec[i].nombreSector);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}

void mostrarDato(eEmployee vec, eSector vecS[], int tamS)
{
    char nombreCarrera[20];

    buscarNombreSector(vec.sector,vecS,tamS,nombreCarrera);

    printf("%d  %10s  %10s     %.2f    %10s\n",vec.id,vec.name,vec.lastName,vec.salary,nombreCarrera);
}

void mostrarDatos(eEmployee vec[], int tam, eSector vecS[], int tamS)
{
    int cont=0;

    printf("ID        NOMBRE     APELLIDO     SALARIO       SECTOR\n");
    printf("--        ------     --------     -------       ------\n\n");

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            mostrarDato(vec[i],vecS,tamS);
            cont++;
        }
    }

    if(cont == 0)
    {
        printf("No hay datos en el sistema\n\n");
    }


    printf("\n\n");
}

int hardCodeo(eEmployee vec[], int tam,int cantidad)
{
    int cont=0;

    eEmployee datos[]=
    {
        {1000,"Jose","Martinez",25000,3,0},
        {1001,"Ana","Saa",28000,4,0},
        {1002,"Matias","Rodriguez",22000,2,0},
        {1003,"Rocio","Diaz",30000,3,0},
        {1004,"Camila","Colman",32000,3,0},

    };

    if(cantidad <= 5 && tam >= cantidad)
    {
        for(int i=0; i<cantidad; i++)
        {
            vec[i]=datos[i];
            cont++;
        }
    }

    return cont;
}

int altaEmpleado(eEmployee vec[], int tam, int id, eSector vecS[], int tamS)
{
    int todoOk = 0;
    int indice;

    system("cls");

    printf("**** Alta empleado ****\n\n");

    indice = buscarLibre(vec, tam);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        vec[indice].id =id;

        getStringAlpha(51,2,"Ingrese nombre: ",vec[indice].name);
        getStringAlpha(51,2,"Ingrese apelllido: ",vec[indice].lastName);
        getFloatRange(0,100000,&vec[indice].salary,"Ingrese sueldo: ");
        vec[indice].sector=menuSectores();
        vec[indice].isEmpty=0;

        todoOk = 1;
        printf("\nAlta exitosa!!\n\n");
    }

    return todoOk;
}

int modificarEmpleado(eEmployee vec[], int tam, eSector vecS[], int tamS)
{
    int todoOk = 0;
    int id;
    int indice;
    int confirma;
    int salir;


    printf("***** Modificar empleado *****\n\n");

    mostrarDatos(vec,tam,vecS,tamS);

    printf("Ingrese id: ");
    scanf("%d", &id);

    indice = buscarId(id, vec, tam);

    if( indice == -1)
    {
        printf("No existe un empleado con ese id\n\n");
    }
    else
    {
        system("cls");
        mostrarDato(vec[indice],vecS,tamS);

        confirma=confimarSalir("\n\nDesea modificar este empleado? s/n: ");

        if(confirma == 1)
        {
            do
            {
                switch(menuModificacion())
                {
                case 1:
                    getStringAlpha(51,2,"Ingrese nombre: ",vec[indice].name);
                    printf("\nOperacion realizada con exito\n");
                    break;

                case 2:
                    getStringAlpha(51,2,"Ingrese apelllido: ",vec[indice].lastName);
                    printf("\nOperacion realizada con exito\n");
                    break;

                case 3:
                    getFloatRange(0,100000,&vec[indice].salary,"Ingrese sueldo: ");
                    printf("\nOperacion realizada con exito\n");
                    break;

                case 4:
                    vec[indice].sector=menuSectores();
                    printf("\nOperacion realizada con exito\n");
                    break;

                case 5:
                    salir=confimarSalir("Volver al menu principal? s/n: ");
                    break;

                default:
                    printf("Ingrese opcion valida\n\n");
                }
            }
            while(salir != 1);
        }
        else
        {
            printf("Modificacion cancelada.\n\n");
        }

        todoOk=1;

    }

    return todoOk;
}

void bajaEmpleado(eEmployee vec[], int tam, eSector vecS[], int tamS)
{
    int id;
    int esta;
    int confirma;

    printf("***** Baja empleado *****\n\n");

    mostrarDatos(vec,tam,vecS,tamS);

    printf("\nIngrese numero de id a dar de baja: ");
    scanf("%d",&id);

    esta=buscarId(id,vec,tam);

    if(esta==-1)
    {
        printf("No existe ese numero de id en el sistema\n");
    }
    else
    {
        confirma=confimarSalir("\nDesea dar de baja este empleado? s/n: ");

        if(confirma==1)
        {
            vec[esta].isEmpty=1;
            printf("\nOperacion realizada con exito\n");
        }
        else
        {
            printf("\nOperacion cancelada.\n\n");
        }
    }
}

void ordenarEmpleados(eEmployee vec[], int tam)
{
    eEmployee aux;

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(strcmp(vec[i].lastName,vec[j].lastName)>0)
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
            else
            {
                if(strcmp(vec[i].lastName,vec[j].lastName) == 0 && vec[i].sector > vec[j].sector)
                {
                    aux=vec[i];
                    vec[i]=vec[j];
                    vec[j]=aux;
                }
            }

        }
    }

}

void promedioTotal(eEmployee vec[], int tam)
{
    int contSueldos=0;
    int contEmpleados =0;
    float totalSueldos=0;
    float promedioSueldos=0;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            totalSueldos+=vec[i].salary;
            contSueldos++;
        }
    }

    promedioSueldos=(float)totalSueldos/contSueldos;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0 && vec[i].salary>promedioSueldos)
        {
            contEmpleados++;
        }
    }


    system("cls");

    printf("\nEl total de los salarios es de %.2f",totalSueldos);
    printf("\nEl promedio de los sueldos es de: %.2f",promedioSueldos);
    printf("\nEl total de empleados que superan el sueldo promedio es de: %d\n\n",contEmpleados);
    system("pause");


}

void informes(eEmployee vec[], int tam, eSector vecS[], int tamS)
{
    int salir;

    do
    {
        system("cls");

        switch(menuInformes())
        {
        case 1:
            ordenarEmpleados(vec,tam);
            system("cls");
            mostrarDatos(vec,tam,vecS,tamS);
            system("pause");
            break;

        case 2:
            promedioTotal(vec,tam);
            break;

        case 3:
            salir=confimarSalir("\nVolver al menu principa? s/n: ");
            break;


        default:
            printf("ingrese opcion valida.");

        }

    }
    while(salir != 1);


}
