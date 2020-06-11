#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    char id[51];
    char name[51];
    char hoursWorked[51];
    char salary[51];
    char title[51];
    int i=-1;

    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            i++;
            if(i==0)
            {
                fscanf(pFile, "%[^\n]\n", title);
                i++;
            }
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, name, hoursWorked, salary);
            auxEmployee = employee_newParametros(id, name, hoursWorked, salary);
            ll_add(pArrayListEmployee, auxEmployee);
        }
        printf("*Se cargaron los datos desde el archivo data.csv (Modo Texto)\n\n");
        fclose(pFile);
    }
    else
    {
        printf("*Imposible cargar los datos\n\n");
    }

    return 1;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;

    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            if(feof(pFile))
            {
                break;
            }
            auxEmployee = employee_new();
            if(fread(auxEmployee,sizeof(Employee),1,pFile)==1)
            {
                ll_add(pArrayListEmployee, auxEmployee);
            }
        }
        printf("*Se cargaron los datos desde el archivo data.bin (Modo Binario)\n\n");
        fclose(pFile);
    }
    else
    {
        printf("*Imposible cargar los datos\n\n");
    }

    return 1;
}
