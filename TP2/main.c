#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"

int main()
{
    int option;
    Employee listEmployee[SIZE];

    initEmployees(listEmployee, SIZE);

    hardCodeEmployee(listEmployee, SIZE);

    do
    {
        option = optionMenu();
        actionMenu(listEmployee, option, SIZE);
    }while(option!=5);
    printf("Exiting program...\n");

    return 0;
}
