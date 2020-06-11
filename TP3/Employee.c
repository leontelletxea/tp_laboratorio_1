#include <stdlib.h>
#include "Employee.h"
#include <string.h>

Employee* employee_new()
{
    Employee* listEmployee = (Employee*) malloc(sizeof(Employee));

    return listEmployee;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* listEmployee;
    int auxInt;
    float auxFloat;

    listEmployee = employee_new();
    if(listEmployee!=NULL)
    {
        auxInt = atoi(idStr);
        employee_setId(listEmployee, auxInt);
        employee_setNombre(listEmployee, nombreStr);
        auxInt = atoi(horasTrabajadasStr);
        listEmployee->horasTrabajadas = auxInt;
        employee_setHorasTrabajadas(listEmployee, auxInt);
        auxFloat = atof(sueldoStr);
        listEmployee->sueldo = auxFloat;
        employee_setSueldo(listEmployee, auxFloat);
    }

    return listEmployee;
}


int employee_setNombre(Employee* this,char* nombre)
{
    int ret = 0;
    if(this!=NULL)
    {
        strcpy(this->nombre, nombre);
        ret = 1;
    }

    return ret;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int ret = 0;
    if(this!=NULL)
    {
        strcpy(nombre, this->nombre);
        ret = 1;
    }

    return ret;
}



int employee_setSueldo(Employee* this,float sueldo)
{
    int ret = 0;
    if(this!=NULL && sueldo >= 10000)
    {
        this->sueldo = sueldo;
        ret = 1;
    }

    return ret;
}
int employee_getSueldo(Employee* this,float* sueldo)
{
    int ret = 0;
    if(this!=NULL)
    {
        *sueldo = this->sueldo;
        ret = 1;
    }

    return ret;
}

int employee_setId(Employee* this,int id)
{
    int ret = 0;
    if(this!=NULL && id > 0)
    {
        this->id = id;
        ret = 1;
    }

    return ret;
}
int employee_getId(Employee* this,int* id)
{
    int ret = 0;
    if(this!=NULL)
    {
        *id = this->id;
        ret = 1;
    }

    return ret;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int ret = 0;
    if(this!=NULL && horasTrabajadas <= 350)
    {
        this->horasTrabajadas = (int)horasTrabajadas;
        ret = 1;
    }

    return ret;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int ret = 0;
    if(this!=NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        ret = 1;
    }

    return ret;
}


int employee_CompareByName(Employee* e1, Employee* e2)
{
    int ret;

    if(e1!=NULL && e2!=NULL)
    {
        ret = strcmp(e1->nombre, e2->nombre);
    }else{
        ret = -1;
    }

    return ret;
}

int employee_CompareById(Employee* e1, Employee* e2)
{
    int ret;

    if(e1!=NULL && e2!=NULL)
    {
        if(e1->id > e2->id)
        {
            ret = 1;
        }
        else
        {
            if(e1->id < e2->id)
            {
                ret = -1;
            }
            else
            {
                ret = 0;
            }
        }
    }
    return ret;
}
