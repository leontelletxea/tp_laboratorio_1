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

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int ret = 0;
    if(this!=NULL && horasTrabajadas < (int*)48)
    {
        this->horasTrabajadas = (int)horasTrabajadas;
        ret = 1;
    }

    return ret;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajdas)
{

}


int employee_CompareByName(Employee* e1, Employee* e2)
{
    //verificar nulidad

    return strcmp(e1->nombre, e2->nombre);
}

int employee_CompareById(Employee* e1, Employee* e2)
{
    //verificar nulidad

    if(e1->id > e2->id)
    {
        return 1;
    }
    else
    {
        if(e1->id < e2->id)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }



    return strcmp(e1->nombre, e2->nombre);
}


int createEmployeeId(void)
{
    static int id=1000;
    id++;
    return id;
}
