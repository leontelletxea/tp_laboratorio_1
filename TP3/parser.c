#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    char id[51];
    char nombre[51];
    char horasTrabajadas[51];
    char sueldo[51];
    char cabecera[51];
    int i=-1;

    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            i++;
            if(i==0)
            {
                fscanf(pFile, "%[^\n]\n", cabecera);
                continue;
                i++;
            }
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
            auxEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
            ll_add(pArrayListEmployee, auxEmployee);
        }
        printf("Se cargaron los datos desde el archivo data.csv (Texto)\n\n");
        fclose(pFile);
    }
    else
    {
        printf("\nImposible cargar los datos\n\n");
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
        printf("Se cargaron los datos desde el archivo data.bin (Binario)\n\n");
        fclose(pFile);
    }
    else
    {
        printf("\nImposible cargar los datos\n\n");
    }

    return 1;
}
