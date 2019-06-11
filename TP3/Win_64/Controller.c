#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "inputDiaz.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int estado=0;
    FILE* f;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        f = fopen(path, "r");

        if(f==NULL)
        {
            estado=0;
            exit(1);
        }
        else
        {
            parser_EmployeeFromText(f, pArrayListEmployee);
            fclose(f);
            estado=1;
        }

    }

    return estado;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* f;
    int estado=0;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        f = fopen(path,"rb");

        if(f != NULL)
        {
            parser_EmployeeFromBinary(f,pArrayListEmployee);
            fclose(f);
            estado=1;
        }
        else
        {
            fclose(f);
            estado=0;
            exit(1);
        }

    }

    return estado;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int estado=0;
    int auxSueldo;
    int auxId;
    int auxHoras;
    char auxChar[50];
    Employee* this;

    if(pArrayListEmployee != NULL)
    {

        obtenerNumeroEntre(&auxId, 99999, 0,"Ingresar id del empleado: ");

        obtenerCadenaChar(auxChar, 128, "Ingrese nombre: ");

        obtenerNumeroEntre(&auxHoras,1000,0,"Ingresar horas trabajadas: ");

        obtenerNumeroEntre(&auxSueldo,500000,0,"Ingresar sueldo del empleado: ");

        this = employee_new();

        if(this != NULL)
        {
            if( employee_setId(this,auxId) == 1 &&
                employee_setNombre(this,auxChar) == 1 &&
                employee_setHorasTrabajadas(this,auxHoras) == 1 &&
                employee_setSueldo(this,auxSueldo) == 1 )
                {
                    ll_add(pArrayListEmployee,this);
                    estado=1;
                }
                else
                {
                    estado=0;
                    exit(1);
                }
        }

    }

    return estado;
}




/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

