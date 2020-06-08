#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Validations.h"



int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pData=NULL;

    pData = fopen(path,"r");

    parser_EmployeeFromText(pData, pArrayListEmployee);

    return 1;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pData=NULL;

    pData = fopen(path,"rb");

    parser_EmployeeFromBinary(pData, pArrayListEmployee);

    return 1;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int id;
    char name[51];
    int hoursWorked;
    float salary;

    if(pArrayListEmployee!=NULL)
    {
        auxEmployee = employee_new();
        if(auxEmployee!=NULL)
        {
            id = createEmployeeId();
            printf("Id asignado: %d\n", id);
            employee_setId(auxEmployee, id);

            getWord(name, "\nIngrese el nombre del empleado: ");
            employee_setNombre(auxEmployee, name);

            hoursWorked = getInt("\nIngrese la cantidad de horas trabajadas: ","\nError, ingrese la cantidad de horas trabajadas: ", 1, 48);
            employee_setHorasTrabajadas(auxEmployee, hoursWorked);

            salary = getFloat("\nIngrese el sueldo: ","\nError, ingrese el sueldo: ", 10000, 100000);
            employee_setSueldo(auxEmployee, salary);

            ll_add(pArrayListEmployee, auxEmployee);
            printf("\nSe cargo el empleado correctamente\n\n");
        }else{
            printf("\nImposible cargar el empleado\n\n");
        }
    }

    return 1;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
return 1;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
return 1;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int i;
    int size;

    size = ll_len(pArrayListEmployee);
    printf("        Id      Nombre Horas Trabajadas       Sueldo\n");
    for(i=0; i<size; i++)
    {
        auxEmployee =(Employee*) ll_get(pArrayListEmployee, i);
        printf("%10d %10s %10d              $%.1f\n", auxEmployee->id, auxEmployee->nombre, auxEmployee->horasTrabajadas, auxEmployee->sueldo);
    }
    printf("\nList size: %d\n\n", size);

    return 1;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
return 1;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int i;
    int size;
    FILE* pData;

    size = ll_len(pArrayListEmployee);

    pData = fopen(path, "w");

    if(pData!=NULL)
    {
        for(i=0; i<size; i++)
        {
            auxEmployee =(Employee*) ll_get(pArrayListEmployee, i);
            fwrite(auxEmployee, sizeof(Employee),1,pData);
        }
        printf("Se guardo la lista correctamente en el archivo data.bin (Binario)\n\n");
    }else{
    printf("Imposible cargar el archivo");
    }
    fclose(pData);
    return 1;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int i;
    int size;
    FILE* pData;

    size = ll_len(pArrayListEmployee);

    pData = fopen(path, "wb");

    if(pData!=NULL)
    {
        for(i=0; i<size; i++)
        {
            auxEmployee =(Employee*) ll_get(pArrayListEmployee, i);
            fwrite(auxEmployee, sizeof(Employee),1,pData);
        }
        printf("Se se guardo la lista correctamente en el archivo data.bin (Binario)\n\n");
    }else{
    printf("Imposible cargar el archivo");
    }
    fclose(pData);
    return 1;
}

void optionMenu(LinkedList* listEmployee)
{
    int option;

    do
    {
        printf("||| MENU |||\n");
        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
        printf("3. Alta de empleado\n");
        printf("4. Modificar datos de empleado\n");
        printf("5. Baja de empleado\n");
        printf("6. Listar empleados\n");
        printf("7. Ordenar empleados\n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
        printf("10.Salir\n");
        fflush(stdin);
        option = getInt("Ingrese una opcion: ","Error, elija una opcion valida: ",1,10);
        system("cls");
        switch(option)
        {
        case 1:
            controller_loadFromText("data.csv", listEmployee);
            break;
        case 2:
            controller_loadFromBinary("data.bin", listEmployee);
            break;
        case 3:
            controller_addEmployee(listEmployee);
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            controller_ListEmployee(listEmployee);
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            controller_saveAsBinary("data.bin", listEmployee);
            break;
        case 10:
            break;
        }
        }while(option!=10);
        printf("Exit Menu...\n");
}
