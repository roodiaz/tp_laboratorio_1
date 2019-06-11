#include "Employee.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Employee* employee_new()
{
    Employee* this = (Employee*) malloc(sizeof(Employee));

    if(this != NULL)
    {
        this->id = 0;
        strcpy(this->nombre, "");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }
    return this;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    int auxId;
    int auxSueldo;
    int auxHoras;

    Employee* this = employee_new();

    auxId = atoi(idStr);
    auxHoras = atoi(horasTrabajadasStr);
    auxSueldo = atoi(sueldoStr);

    employee_setId(this, auxId);
    employee_setNombre(this, nombreStr);
    employee_setSueldo(this, auxSueldo);
    employee_setHorasTrabajadas(this, auxHoras);

    return this;
}

void employee_delete(Employee* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}

int employee_setId(Employee* this,int id)
{
    int estado=0;

    if(this != NULL && id > 0)
    {
        this->id=id;
        estado=1;
    }
    return estado;
}

int employee_getId(Employee* this,int* id)
{
    int estado=0;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        estado=1;
    }

    return estado;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int estado=0;

    if(this != NULL && nombre!= NULL && strlen(nombre)>3)
    {
        strcpy(this->nombre, nombre);
        estado=1;
    }

    return estado;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int estado=0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        estado=1;
    }
    return estado;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int estado=0;

    if(this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas=horasTrabajadas;
        estado=1;
    }
    return estado;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int estado=0;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        estado=1;
    }

    return estado;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int estado=0;

    if(this != NULL && sueldo > 0)
    {
        this->sueldo=sueldo;
        estado=1;
    }
    return estado;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int estado=0;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        estado=1;
    }

    return estado;
}

void mostrarEmployee(Employee* emp)
{
    printf("%d  %s  %d  %d\n",emp->id,emp->nombre,emp->horasTrabajadas,emp->sueldo);
}
