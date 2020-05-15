#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define SIZE 5 /** 1000 */ /** Cambio a 5 el define para el harcodeo */

int main()
{
    int option;
    int flag=1; /** 0 */ /** Cambio a 1 el flag para el harcodeo y que entre en los case 2, 3 y 4 */

    Employee listEmployees[SIZE];
    //initEmployees(listEmployees, SIZE);
    hardCodeEmployees(listEmployees, SIZE); /** Comento el inicializador arriba para habilitar el harcodeo */

    do
    {
        option = optionMenu(); /** La opcion elegida en el menu se guarda en option */
        if(option==1)
        {
            flag=1; /** Si es igual a 1 cambio el flag para permitir entrar en el case 2, 3 y 4 */
        }
        actionMenu(listEmployees, SIZE, option,  flag); /** Menu con los case y llamadas a las funciones, le paso el tamaño la opcion elegida */
        }while(option!=5);                             /** y el flag para saber si se cargo un Empleado */
         printf("Exit console...\n");

    return 0;
}
