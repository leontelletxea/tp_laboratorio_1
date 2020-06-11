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
    int hoursWorked;
    int ret;
    char name[51];
    float salary;

    if(pArrayListEmployee!=NULL)
    {
        auxEmployee = employee_new();
        if(auxEmployee!=NULL)
        {
            id = createEmployeeId();
            printf("Id asignado: %d\n", id);
            employee_setId(auxEmployee, id);

            do
            {
                ret = getWord(name, "\nIngrese el nombre del empleado: ");
            }while(ret!=0);

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
    Employee* auxEmployee;
    int searchId;
    int index;
    int i;
    int size;
    int option;
    int id;
    int hoursWorked;
    float salary;
    char name[51];
    char answer;

    searchId = getInt("\nIngrese el id de usuario que desea modificar: ", "\nError, ingrese un id valido", 1, 5000);
    size = ll_len(pArrayListEmployee);

    for(i=0; i<size; i++)
    {
        auxEmployee =(Employee*) ll_get(pArrayListEmployee, i);
        id=auxEmployee->id;
        strcpy(name, auxEmployee->nombre);
        hoursWorked=auxEmployee->horasTrabajadas;
        salary=auxEmployee->sueldo;
        if(id==searchId)
        {
            index = i;
            break;
        }
    }

    if(auxEmployee!=NULL && auxEmployee->id==searchId)
    {

    do
    {
        printf("\n\n%4d %10s %10d              $%.1f\n", id, name, hoursWorked, salary);
        printf("\n\nMenu de edicion\n");
        printf("1.Nombre\n");
        printf("2.Horas Trabajadas\n");
        printf("3.Sueldo\n");
        printf("4.Guardar cambios\n");
        printf("5.Salir del menu\n");
        option = getInt("Seleccione una opcion: ", "\nError, ingrese una opcion valida: ", 1, 5);
        system("cls");

        switch(option)
        {
        case 1:
            getWord(name, "\nIngrese el nuevo nombre: ");
            break;
        case 2:
            hoursWorked = getInt("\nIngrese la nueva cantidad de horas trabajadas: ", "\nError, ingrese una cantidad valida: ", 1, 48);
            break;
        case 3:
            salary = getFloat("\nIngrese el nuevo sueldo: ", "\nError, ingrese un sueldo valido: ", 10000, 100000);
            break;
        case 4:
            answer = getChar("\nEsta seguro que desea actualizar este empleado? (Enter=Si / n=No): ", "\nError, ingrese (Enter=Si / n=No): ", '\n', 'n');
            if(answer=='\n')
            {
                auxEmployee->id=id;
                strcpy(auxEmployee->nombre, name);
                auxEmployee->horasTrabajadas=hoursWorked;
                auxEmployee->sueldo=salary;
                ll_set(pArrayListEmployee, index, auxEmployee);
                printf("\nEl empleado fue actualizado satisfactoriamente\n\n");
            }else{
                id=auxEmployee->id;
                strcpy(name, auxEmployee->nombre);
                hoursWorked=auxEmployee->horasTrabajadas;
                salary=auxEmployee->sueldo;
                printf("\nSe cancelo la modificacion de el empleado\n\n");
            }
            break;
        }
    }while(option!=5);
    system("cls");
    printf("\nSaliendo del menu de edicion...\n\n");
    }else{
        printf("\nError, empleado no encontrado...\n\n");
    }

    return 1;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int searchId;
    int index;
    int i;
    int size;
    int* id=0;
    char answer;

    searchId = getInt("\nIngrese el id de usuario que desea eliminar: ", "\nError, ingrese un id valido: ", 1, 5000);
    size = ll_len(pArrayListEmployee);

    for(i=0; i<size; i++)
    {
        auxEmployee =(Employee*) ll_get(pArrayListEmployee, i);
        if(auxEmployee->id==searchId)
        {
            index = i;
            break;
        }
    }

    if(size!=NULL && auxEmployee!=NULL && auxEmployee->id==searchId)
    {
        answer = getChar("\nEsta seguro que desea eliminar a este empleado? (Enter=Si / n=No): ", "\nError, ingrese (Enter=Si / n=No): ", '\n', 'n');
        if(answer=='\n')
        {
            ll_remove(pArrayListEmployee, index);
            printf("\nEl empleado fue removido satisfactoriamente\n\n");
        }else{
            printf("\nSe cancelo la eliminacion de el empleado\n\n");
        }
    }else{
        printf("\nError, empleado no encontrado...\n\n");
    }

    return 1;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int i;
    int size;
    int* id=0;
    int* horasTrabajadas=0;
    char nombre[51];

    size = ll_len(pArrayListEmployee);
    printf("  Id     Nombre  Horas Trabajadas        Sueldo\n");
    for(i=0; i<size; i++)
    {
        auxEmployee =(Employee*) ll_get(pArrayListEmployee, i);
        employee_getId(auxEmployee, &id);
        employee_getNombre(auxEmployee, nombre);
        employee_getHorasTrabajadas(auxEmployee, &horasTrabajadas);
        printf("%4d %10s %10d              $%.1f\n", id, nombre, horasTrabajadas, auxEmployee->sueldo);
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
    FILE* pData;
    int i;
    int size;
    int* id=0;
    int* horasTrabajadas=0;
    char nombre[51];

    size = ll_len(pArrayListEmployee);

    pData = fopen(path, "w");

    if(pData!=NULL)
    {
        for(i=0; i<size; i++)
        {
            if(i==0)
            {
                fprintf(pData, "id,nombre,horasTrabajadas,sueldo\n");
            }
            auxEmployee =(Employee*) ll_get(pArrayListEmployee, i);
            employee_getId(auxEmployee, &id);
            employee_getNombre(auxEmployee, nombre);
            employee_getHorasTrabajadas(auxEmployee, &horasTrabajadas);
            fprintf(pData, "%d,%s,%d,%f\n", (int)id, nombre, (int)horasTrabajadas, auxEmployee->sueldo);
        }
        printf("Se guardo la lista correctamente en el archivo data.csv (Texto)\n\n");
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
            controller_ListEmployee(listEmployee);
            controller_editEmployee(listEmployee);
            break;
        case 5:
            controller_ListEmployee(listEmployee);
            controller_removeEmployee(listEmployee);
            break;
        case 6:
            controller_ListEmployee(listEmployee);
            break;
        case 7:
            //ll_sort(listEmployee, employee_CompareByName, 1);
            ll_sort(listEmployee, employee_CompareById, 0);
            controller_ListEmployee(listEmployee);
            break;
        case 8:
            controller_saveAsText("data.csv", listEmployee);
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
