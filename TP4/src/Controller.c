#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Validations.h"



int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pData=NULL;

    pData = fopen(path,"r");

    if(pArrayListEmployee!=NULL && pData!=NULL)
    {
        parser_EmployeeFromText(pData, pArrayListEmployee);
    }
    return 1;
}

int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pData=NULL;

    pData = fopen(path,"rb");

    if(pArrayListEmployee!=NULL && pData!=NULL)
    {
        parser_EmployeeFromBinary(pData, pArrayListEmployee);
    }
    return 1;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int id;
    int hoursWorked;
    int ret;
    int retAdd;
    char name[51];
    float salary;

    if(pArrayListEmployee!=NULL)
    {
        if(ll_len(pArrayListEmployee) > 0)
        {
            auxEmployee = employee_new();
            if(auxEmployee!=NULL)
            {
                id = createEmployeeId(pArrayListEmployee);
                employee_setId(auxEmployee, id);
                printf("*Id de empleado: %d\n", id);

                do
                {
                    ret = getWord(name, "\nIngrese el nombre del empleado: ");
                }while(ret!=0);
                employee_setNombre(auxEmployee, name);

                hoursWorked = getInt("\nIngrese la cantidad de horas trabajadas: ","\nError, ingrese la cantidad de horas trabajadas: ", 1, 350);
                employee_setHorasTrabajadas(auxEmployee, hoursWorked);

                salary = getFloat("\nIngrese el sueldo: ","\nError, ingrese el sueldo: ", 10000, 100000);
                employee_setSueldo(auxEmployee, salary);

                retAdd = ll_add(pArrayListEmployee, auxEmployee);
                if(retAdd!=-1)
                {
                    printf("\n*Se cargo el empleado correctamente\n\n");
                }else{
                    printf("\n*La carga de empleado fallo\n\n");
                }
            }else{
                printf("\n*Imposible cargar el empleado\n\n");
            }
        }else if(ll_len(pArrayListEmployee) == 0)
        {
            printf("*Imposible cargar el empleado, primero cargue la lista con la opcion 1 o 2 del menu\n\n");
        }

    }
    return 1;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int searchId;
    int i;
    int size = 0;
    int option;
    int id;
    int hoursWorked;
    float salary;
    char name[51];
    char answer;

    if(pArrayListEmployee != NULL)
    {
        if(!ll_isEmpty(pArrayListEmployee))
        {
            size = ll_len(pArrayListEmployee);
            searchId = getInt("\nIngrese el id de usuario que desea modificar: ", "\nError, ingrese un id valido", 1, 5000);
            for(i=0; i<size; i++)
            {
                auxEmployee =(Employee*) ll_get(pArrayListEmployee, i);
                if(auxEmployee!=NULL)
                {
                    employee_getId(auxEmployee, &id);
                    employee_getNombre(auxEmployee, name);
                    employee_getHorasTrabajadas(auxEmployee, &hoursWorked);
                    employee_getSueldo(auxEmployee, &salary);
                    if(id==searchId)
                    {
                        system("cls");
                        break;
                    }
                }
            }

        if(auxEmployee!=NULL && auxEmployee->id==searchId)
        {
        do
        {
            printf("  Id     Nombre  Horas Trabajadas        Sueldo\n\n");
            printf("%4d %10s %10d              $%.1f", id, name, hoursWorked, salary);
            printf("\n\n*** Menu Editar ***\n");
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
                getWord(name, "Ingrese el nuevo nombre: ");
                system("cls");
                break;
            case 2:
                hoursWorked = getInt("Ingrese la nueva cantidad de horas trabajadas: ", "\nError, ingrese una cantidad valida: ", 1, 48);
                system("cls");
                break;
            case 3:
                salary = getFloat("Ingrese el nuevo sueldo: ", "\nError, ingrese un sueldo valido: ", 10000, 100000);
                system("cls");
                break;
            case 4:
                answer = getChar("Esta seguro que desea actualizar este empleado? (Enter=Si / n=No): ", "\nError, ingrese (Enter=Si / n=No): ", '\n', 'n');
                if(answer=='\n')
                {
                    system("cls");
                    employee_setNombre(auxEmployee, name);
                    employee_setHorasTrabajadas(auxEmployee, hoursWorked);
                    employee_setSueldo(auxEmployee, salary);
                    printf("*El empleado fue modificado satisfactoriamente\n\n");
                }else{
                    system("cls");
                    employee_getId(auxEmployee, &id);
                    employee_getNombre(auxEmployee, name);
                    employee_getHorasTrabajadas(auxEmployee, &hoursWorked);
                    employee_getSueldo(auxEmployee, &salary);
                    printf("*Se cancelo la modificacion de el empleado\n\n");
                }
                break;
            }
        }while(option!=5);
        system("cls");
        printf("*Saliendo del menu de edicion...\n\n");
        }else{
            system("cls");
            printf("*Error, empleado no encontrado...\n\n");
        }
        }
    }

    return 1;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int searchId;
    int index;
    int i;
    int size = 0;
    int id;
    int hoursWorked;
    float salary;
    char name[51];
    char answer;

    if(pArrayListEmployee != NULL)
    {
        if(!ll_isEmpty(pArrayListEmployee))
        {
            size = ll_len(pArrayListEmployee);
            searchId = getInt("Ingrese el id de usuario que desea eliminar: ", "\nError, ingrese un id valido: ", 1, 5000);

            for(i=0; i<size; i++)
            {
                auxEmployee =(Employee*) ll_get(pArrayListEmployee, i);

                if(auxEmployee!=NULL)
                {
                    employee_getId(auxEmployee, &id);
                    employee_getNombre(auxEmployee, name);
                    employee_getHorasTrabajadas(auxEmployee, &hoursWorked);
                    employee_getSueldo(auxEmployee, &salary);
                    if(id==searchId)
                    {
                        index = i;
                        break;
                    }
                }
            }

            if(auxEmployee!=NULL && auxEmployee->id==searchId)
            {
                system("cls");
                printf("  Id     Nombre  Horas Trabajadas        Sueldo\n\n");
                printf("%4d %10s %10d              $%.1f", id, name, hoursWorked, salary);
                answer = getChar("\n\nEsta seguro que desea eliminar a este empleado? (Enter=Si / n=No): ", "\nError, ingrese (Enter=Si / n=No): ", '\n', 'n');
                if(answer=='\n')
                {
                    auxEmployee = ll_pop(pArrayListEmployee, index);
                    if(auxEmployee != NULL)
                    {
                        system("cls");
                        printf("                           Id      Nombre Horas Trabajadas        Sueldo\n\n");
                        printf("*Se elimino al empleado: %4d %10s %10d              $%.1f\n\n", auxEmployee->id,
                                                                                                auxEmployee->nombre,
                                                                                                auxEmployee->horasTrabajadas,
                                                                                                auxEmployee->sueldo);
                    }else{
                        system("cls");
                        printf("*La eliminacion de empleado fallo\n\n");
                    }
                }else{
                    system("cls");
                    printf("*Se cancelo la eliminacion de el empleado\n\n");
                }
            }else{
                system("cls");
                printf("*Error, empleado no encontrado...\n\n");
            }
        }else if(ll_isEmpty(pArrayListEmployee)){
                system("cls");
                printf("*No hay empleados cargados, ingrese 1 o 2 para cargarlos o 3 para dar de alta uno\n\n");
            }
    }

    return 1;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int i;
    int size = 0;
    int id;
    int hoursWorked;
    float salary;
    char name[51];

    if(pArrayListEmployee!=NULL)
    {
        size = ll_len(pArrayListEmployee);
        if(!ll_isEmpty(pArrayListEmployee))
        {
            printf("  Id     Nombre  Horas Trabajadas        Sueldo\n\n");
            for(i=0; i<size; i++)
            {
                auxEmployee =(Employee*) ll_get(pArrayListEmployee, i);
                if(auxEmployee!=NULL)
                {
                    employee_getId(auxEmployee, &id);
                    employee_getNombre(auxEmployee, name);
                    employee_getHorasTrabajadas(auxEmployee, &hoursWorked);
                    employee_getSueldo(auxEmployee, &salary);
                    printf("%4d %10s %10d              $%.1f\n", id, name, hoursWorked, salary);
                }
            }
            printf("\n");
        }else if(ll_isEmpty(pArrayListEmployee)){
            printf("*No hay empleados cargados, ingrese 1 o 2 para cargarlos o 3 para dar de alta uno\n\n");
        }
    }
    return 1;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int option;
    int retSort;

    if(pArrayListEmployee != NULL)
    {
        if(!ll_isEmpty(pArrayListEmployee))
        {
            do
            {
                system("cls");
                printf("*** Menu ordenar ***\n");
                printf("1.Ordenar por Nombre de la A-Z\n");
                printf("2.Ordenar por Nombre de la Z-A\n");
                printf("3.Ordenar por Id de menor a mayor\n");
                printf("4.Ordenar por Id mayor a menor\n");
                printf("5.Salir del menu ordenar\n");
                option = getInt("Elija una opcion: ", "\nError, elija una opcion valida: ", 1, 5);
                system("cls");

                switch(option)
                {
                case 1:
                    printf("*Ordenando la lista, un momento por favor...\n\n");
                    retSort = ll_sort(pArrayListEmployee, employee_CompareByName, 1);
                    if(retSort!=-1)
                    {
                        controller_ListEmployee(pArrayListEmployee);
                    }else{
                        printf("*El ordenamiento fallo\n\n");
                    }
                    system("pause");
                    break;
                case 2:
                    printf("*Ordenando la lista, un momento por favor...\n\n");
                    retSort = ll_sort(pArrayListEmployee, employee_CompareByName, 0);
                    if(retSort!=-1)
                    {
                        controller_ListEmployee(pArrayListEmployee);
                    }else{
                        printf("*El ordenamiento fallo\n\n");
                    }
                    system("pause");
                    break;
                case 3:
                    printf("*Ordenando la lista, un momento por favor...\n\n");
                    retSort = ll_sort(pArrayListEmployee, employee_CompareById, 1);
                    if(retSort!=-1)
                    {
                        controller_ListEmployee(pArrayListEmployee);
                    }else{
                        printf("*El ordenamiento fallo\n\n");
                    }
                    system("pause");
                    break;
                case 4:
                    printf("*Ordenando la lista, un momento por favor...\n\n");
                    retSort = ll_sort(pArrayListEmployee, employee_CompareById, 0);
                    if(retSort!=-1)
                    {
                        controller_ListEmployee(pArrayListEmployee);
                    }else{
                        printf("*El ordenamiento fallo\n\n");
                    }
                    system("pause");
                    break;
                }
            }while(option!=5);
            printf("*Saliendo del menu ordenar...\n\n");
        }else if(ll_isEmpty(pArrayListEmployee)){
                printf("*No hay empleados cargados, ingrese 1 o 2 para cargarlos o 3 para dar de alta uno\n\n");
            }
    }

    return 1;
}

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    FILE* pData;
    int i;
    int size = 0;
    int id;
    int hoursWorked;
    float salary;
    char name[51];

    if(pArrayListEmployee != NULL)
    {
        if(!ll_isEmpty(pArrayListEmployee))
        {
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
                    if(auxEmployee!=NULL)
                    {
                        employee_getId(auxEmployee, &id);
                        employee_getNombre(auxEmployee, name);
                        employee_getHorasTrabajadas(auxEmployee, &hoursWorked);
                        employee_getSueldo(auxEmployee, &salary);
                        fprintf(pData, "%d,%s,%d,%f\n", id, name, hoursWorked, salary);
                    }
                }
                printf("*Se guardo la lista correctamente en el archivo data.csv (Modo Texto)\n\n");
            }else{
            printf("*Imposible cargar el archivo");
            }
            fclose(pData);
        }else if(ll_isEmpty(pArrayListEmployee)){
                printf("*No hay empleados cargados, ingrese 1 o 2 para cargarlos o 3 para dar de alta uno\n\n");
            }
    }

    return 1;
}

int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    FILE* pData;
    int i;
    int size = 0;

    if(pArrayListEmployee != NULL)
    {
        if(!ll_isEmpty(pArrayListEmployee))
        {
            size = ll_len(pArrayListEmployee);
            pData = fopen(path, "wb");
            if(pData!=NULL)
            {
                for(i=0; i<size; i++)
                {
                    auxEmployee =(Employee*) ll_get(pArrayListEmployee, i);
                    if(auxEmployee!=NULL)
                    {
                        fwrite(auxEmployee, sizeof(Employee),1,pData);
                    }
                }
                printf("*Se se guardo la lista correctamente en el archivo data.bin (Modo Binario)\n\n");
            }else{
            printf("*Imposible cargar el archivo");
            }
            fclose(pData);
        }else if(ll_isEmpty(pArrayListEmployee)){
                printf("*No hay empleados cargados, ingrese 1 o 2 para cargarlos o 3 para dar de alta uno\n\n");
            }
    }
    return 1;
}

void controller_clear(LinkedList* listEmployee)
{
    int returnAux;

    if(listEmployee != NULL)
    {
        if(!ll_isEmpty(listEmployee))
        {
        returnAux = ll_clear(listEmployee);
        if(returnAux == 0)
        {
            printf("*Se eliminaron todos los elementos de la lista\n\n");
        }else{
            printf("*Error, fallo el borrado de los elementos de la lista\n\n");
        }
        }else if(ll_isEmpty(listEmployee)){
                printf("*No hay empleados cargados, ingrese 1 o 2 para cargarlos o 3 para dar de alta uno\n\n");
            }
    }
}

void controller_delete(LinkedList* listEmployee)
{
    int returnAux;

    if(listEmployee != NULL)
    {
        if(!ll_isEmpty(listEmployee))
        {
        returnAux = ll_deleteLinkedList(listEmployee);
        if(returnAux == 0)
        {
            printf("*Se eliminaron todos los elementos de la lista y la lista\n\n");
        }else{
            printf("*Error, fallo el borrado de la lista\n\n");
        }
        }else if(ll_isEmpty(listEmployee)){
                printf("*No hay empleados cargados, ingrese 1 o 2 para cargarlos o 3 para dar de alta uno\n\n");
            }
    }
}

LinkedList* controller_clone(LinkedList* listEmployee)
{
    LinkedList* clonedList = NULL;

    if(listEmployee != NULL)
    {
        if(!ll_isEmpty(listEmployee))
        {
        clonedList = ll_clone(listEmployee);
        if(clonedList != NULL)
        {
            printf("*La lista de Empleados original fue copiada correctamente en la lista de Empleados 2\n\n");
        }else{
            printf("*Error, imposible copiar la lista de Empleados 1\n\n");
        }
        }else if(ll_isEmpty(listEmployee)){
                printf("*No hay empleados cargados, ingrese 1 o 2 para cargarlos o 3 para dar de alta uno\n\n");
            }
    }

    return clonedList;
}

void controller_containsAll(LinkedList* listEmployee)
{
    LinkedList* clonedList = NULL;
    int returnAux;


    if(listEmployee != NULL)
    {
        if(!ll_isEmpty(listEmployee))
        {
        clonedList = controller_clone(listEmployee);
        system("pause");
        returnAux = ll_containsAll(listEmployee, clonedList);
        if(returnAux == 1)
        {
            printf("\n*Todos los elementos de la lista de empleados 2 estan contenidos en la lista de empleados 1\n\n");
        }else if(returnAux == 0)
        {
            printf("\n*Todos los elementos de la lista de empleados 2 NO estan contenidos en la lista de empleados 1\n\n");
        }else if(returnAux = -1)
        {
            printf("\n*Imposible comprobar que los elementos de la lista de empleados 2 estan contenidos en la lista de empleados 1\n\n");
        }
        }else if(ll_isEmpty(listEmployee)){
                printf("*No hay empleados cargados, ingrese 1 o 2 para cargarlos o 3 para dar de alta uno\n\n");
            }
    }
}

void controller_push(LinkedList* listEmployee)
{
    Employee* auxEmployee;
    Employee* temporaryEmployee;
    int returnAux;
    int searchId;
    int size;
    int index;
    int i;
    if(listEmployee != NULL)
    {
        if(!ll_isEmpty(listEmployee))
        {
            temporaryEmployee->id = createEmployeeId(listEmployee);
            strcpy(temporaryEmployee->nombre, "Temporal");
            temporaryEmployee->horasTrabajadas = 8;
            temporaryEmployee->sueldo = 10000;
            size = ll_len(listEmployee);
            searchId = getInt("Ingrese el id de Empleado donde desea insertar el Empleado temporal: ", "\nError, ingrese un id valido: ", 1, 5000);

            for(i=0; i<size; i++)
            {
                auxEmployee =(Employee*) ll_get(listEmployee, i);

                if(auxEmployee!=NULL)
                {
                    if(auxEmployee->id == searchId)
                    {
                        index = i;
                        break;
                    }
                }
            }

           returnAux = ll_push(listEmployee, index, temporaryEmployee);
           if(returnAux == 0)
           {
               printf("                             Id      Nombre Horas Trabajadas        Sueldo\n\n");
               printf("*Se agrego el empleado temporal: %4d %10s %10d              $%.1f\n\n", temporaryEmployee->id,
                                                                                               temporaryEmployee->nombre,
                                                                                               temporaryEmployee->horasTrabajadas,
                                                                                               temporaryEmployee->sueldo);
           }
        }else if(ll_isEmpty(listEmployee)){
                printf("*No hay empleados cargados, ingrese 1 o 2 para cargarlos o 3 para dar de alta uno\n\n");
            }
    }
}

void optionMenu(LinkedList* listEmployee)
{
    int option;

    do
    {
        printf("*** Menu Principal ***\n");
        printf("1. Cargar los datos de los Empleados desde el archivo data.csv (modo texto).\n");
        printf("2. Cargar los datos de los Empleados desde el archivo data.csv (modo binario).\n");
        printf("3. Alta de empleado\n");
        printf("4. Modificar datos de empleado\n");
        printf("5. Baja de empleado y listado del mismo\n");
        printf("6. Listar Empleados\n");
        printf("7. Ordenar Empleados\n");
        printf("8. Guardar los datos de los Empleados en el archivo data.csv (modo texto).\n");
        printf("9. Guardar los datos de los Empleados en el archivo data.csv (modo binario).\n");
        printf("10. Borrar todos los elementos de la lista\n");
        printf("11. Borrar todos los elementos de la lista y la lista\n");
        printf("12. Copiar la lista de Empleados 1 en lista de Empleados 2 y comprobar contenido\n");
        printf("13. Agregar un empleado Temporal\n");
        printf("14.Salir\n");
        fflush(stdin);
        option = getInt("Ingrese una opcion: ","Error, elija una opcion valida: ",1,14);
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
            controller_sortEmployee(listEmployee);
            break;
        case 8:
            controller_saveAsText("data.csv", listEmployee);
            break;
        case 9:
            controller_saveAsBinary("data.bin", listEmployee);
            break;
        case 10:
            controller_clear(listEmployee);
            break;
        case 11:
            controller_delete(listEmployee);
            break;
        case 12:
            controller_containsAll(listEmployee);
            break;
        case 13:
            //controller_push(listEmployee);
            break;
        }
        }while(option!=14);
        printf("Saliendo del Menu...\n");
}
