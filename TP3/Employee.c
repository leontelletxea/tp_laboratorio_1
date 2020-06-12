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
        employee_setHorasTrabajadas(listEmployee, auxInt);
        auxFloat = atof(sueldoStr);
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


int employee_CompareByName(void* e1, void* e2)
{
    Employee* employee1 = (Employee*) e1;
    Employee* employee2 = (Employee*) e2;
    int ret;
    char nameEmployee1[51];
    char nameEmployee2[51];

    employee_getNombre(employee1, nameEmployee1);
    employee_getNombre(employee2, nameEmployee2);

    if(employee1!=NULL && employee2!=NULL)
    {
        ret = strcmp(nameEmployee1, nameEmployee2);
    }else{
        ret = -1;
    }
    return ret;
}
int employee_CompareById(void* e1, void* e2)
{
    Employee* employee1 = (Employee*) e1;
    Employee* employee2 = (Employee*) e2;
    int ret;
    int idEmployee1;
    int idEmployee2;

    employee_getId(employee1, &idEmployee1);
    employee_getId(employee2, &idEmployee2);

    if(employee1!=NULL && employee2!=NULL)
    {
        if(idEmployee1 > idEmployee2)
        {
            ret = 1;
        }else{
            if(idEmployee1 < idEmployee2)
            {
                ret = -1;
            }else{
                ret = 0;
            }
        }
    }
    return ret;
}
