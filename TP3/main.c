#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
     Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
     10. Salir
*****************************************************/

/** Nota: todas las variables y funciones en español, fueron brindadas por el profesor
    a la hora de pasar el comprimido con el proyecto, sus declaraciones permanecieron
    intactas durante el desarrollo del TP */

int main()
{
    LinkedList* listEmployee = ll_newLinkedList(); /** Creo una LinkedList */

    optionMenu(listEmployee); /** Y se la paso al menu que operara con ella */

    return 0;
}


