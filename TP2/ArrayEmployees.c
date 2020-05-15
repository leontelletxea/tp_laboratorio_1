#include "ArrayEmployees.h"
#include <stdio.h>
#include <string.h>

void hardCodeEmployees(Employee list[], int len)
{
  int i;
  int id[5]={1,2,3,4,5};
  char name[5][51]={"Travis","Roddy","Mark","Steve","Stephen"};
  char lastName[5][51]={"Scott","Richhy","Suckemberg","Jobs","Hawkings"};
  float salary[5]= {10000,50000,12000,13000,14000};
  int sector[5]= {1,2,3,4,1};;

  for(i=0; i<len; i++)
  {
      list[i].id = id[i];
      strcpy(list[i].name, name[i]);
      strcpy(list[i].lastName, lastName[i]);
      list[i].salary = salary[i];
      list[i].sector = sector[i];
      list[i].isEmpty = FULL;
  }

}

int getInt(char message[],char messageError[], int min, int max)
{

    int integerValue;

    printf("%s", message);
    scanf("%d", &integerValue);

    while(integerValue <  min || integerValue > max)
    {
        printf("%s", messageError);
        scanf("%d", &integerValue);
    }

    return integerValue;
}

float getFloat(char message[],char messageError[], float min, float max)
{

    float decimalValue;

    printf("%s", message);
    scanf("%f", &decimalValue);

    while(decimalValue <  min || decimalValue > max)
    {
        printf("%s", messageError);
        scanf("%f", &decimalValue);
    }

    return decimalValue;
}

char getChar(char message[],char messageError[], char answer1, char answer2)
{
    char letterValue;

    printf("%s", message);
    fflush(stdin);
    scanf("%c", &letterValue);
    fflush(stdin);

    while(letterValue!=answer1 && letterValue!=answer2)
    {
        printf("%s", messageError);
        fflush(stdin);
        scanf("%c", &letterValue);
    }

    return letterValue;
}

void getWord(char wordValue[], char message[])
{
    int len;

    printf("%s", message);
    fflush(stdin);
    fgets(wordValue, 51, stdin);

    len=strlen(wordValue);
    wordValue[len-1]='\0';
}

Employee addEmployees()
{
    Employee auxEmployee; /** Genero una variable auxiliar en la que guardare los datos ingresados por el usuario */

    auxEmployee.id = createEmployeeId(); /** Llamo a la funcion que genera un id automatico y lo asigno al id de ese empleado */
    getWord(auxEmployee.name, "\nEnter the employee name: ");
    getWord(auxEmployee.lastName, "\nEnter the employee's last name: ");
    auxEmployee.salary = getFloat("\nEnter the employee's salary: ", "\nError, please enter an existing salary (10000 <> 100000): ", 10000, 100000);
    auxEmployee.sector = getInt("\nEnter the employee's sector: ", "\nError, please enter an existing sector (1/2/3/4): ", 1, 4);
    auxEmployee.isEmpty = FULL; /** Despues de pedir todos los datos al usuario, marco esa posicion como ocupada, para despues operar con mayor facilidad */

    return auxEmployee; /** Retorno la variable auxiliar que despues es asignada en las funciones para cargar empleados */
}

int createEmployeeId(void)
{
    static int id=0; /** Defino un entero estatico para que cada vez que es llamada el numero tenga el valor en el cual quedo despues del incremento */    id++;
    return id; /** Retorno ese numero que es asignado en la funcion addEmployee(); */
}

void printEmployees(Employee list[], int len)
{
    int i;
    int flag=0; /** Genero un flag para mostrar los titulos una sola vez */

    for(i=0;i<len;i++) /** Recorre el array de Empleados */
    {
       if(list[i].isEmpty == FULL) /** Si la posicion i esta ocupada entra */
       {
           if(flag==0) /** Si es la primera vez entro */
           {
                printf("\n\n##### ID ## NAME #LAST NAME ##### SALARY ##### SECTOR ###\n");
           }
            showEmployee(list[i]); /** Muestro el empleado en la posicion ocupada */
            flag=1; /** Cambio el flag para no mostrar de nuevo el titulo */
       }
    }
}

void showEmployee(Employee auxEmployee)
{
    printf("\n%8d %8s %8s\t $%8.1f %8.d\n", auxEmployee.id, auxEmployee.name, auxEmployee.lastName, auxEmployee.salary, auxEmployee.sector);
    /** Muestro un empleado, la funcion es llamada desde otras funciones indicando la posicion */
}

int initEmployees(Employee list[] , int len)
{
  int i;

  for(i=0; i<len; i++) /** Recorre el array */
  {
      list[i].isEmpty = EMPTY; /** e incializa todas las posiciones como vacias */
  }

  return 0;
}

int searchEmpty(Employee list[], int len)
{
  int i;
  int index = -1;

  for(i=0; i<len; i++) /** Recorre el array */
  {
      if(list[i].isEmpty == EMPTY) /** Busca una posicion vacia, si la encuentra, la guarda en la variable index */
      {
          index =  i;
          break;
      }
  }

  return index; /** Retorna la posicion que encontro libre */
}

void chargueOneEmployee(Employee list[], int len) /** Esta funcion es llamada desde el menu de acciones */
{
  int index;

  index = searchEmpty(list, len); /** Guardo la posicion vacia que encuentra la funcion en la variable index */

  if(index!=-1)
  {
      list[index] = addEmployees(); /** Si la posicion es valida (Distinta de -1) llamo a addEmployees(); */
  }
}

int optionMenu(void)
{
        int option;
        printf("\n### MAIN MENU ###");
        printf("\n1.ADD EMPLOYEE\n");
        printf("2.EDIT EMPLOYEES MENU\n");
        printf("3.DELETE EMPLOYEE\n");
        printf("4.LIST EMPLOYEES\n");
        printf("5.EXIT MENU\n");
        option = getInt("CHOOSE AN OPTION: ", "ERROR CHOOSE AN EXISTING OPTION: ", 1, 5); /** Guardo la opcion elegida */
        system("cls");

        return option; /** Devuelvo la opcion */
}

void actionMenu(Employee list[], int len, int option, int flag) /** Segun la opcion retornada por el menu, entro en el respectivo case */
{
            switch(option)
            {
                case 1:
                     printf("### ADD EMPLOYEE ###");
                     chargueOneEmployee(list, len);
                break;
                case 2:
                     if(flag==1) /** El flag lo recibe desde el main y determina si se ingreso un Empleado o no para mostrar*/
                     {
                         printf("### EDIT EMPLOYEES MENU ###");
                         editEmployee(list, len);
                     }else{
                         printf("Error, please enter at least one employee before edit someone\n"); /** Si no es igual a 1 muestro el error */
                     }
                break;
                case 3:
                     if(flag==1) /** El flag lo recibe desde el main y determina si se ingreso un Empleado o no para mostrar*/
                     {
                         printf("### DELETE EMPLOYEE ###");
                         removeEmployee(list, len);
                     }else{
                         printf("Error, please enter at least one employee before delete someone\n"); /** Si no es igual a 1 muestro el error */
                     }
                break;
                case 4:
                     if(flag==1) /** El flag lo recibe desde el main y determina si se ingreso un Empleado o no para mostrar*/
                     {
                         printf("### LIST EMPLOYEES ###");
                         sortEmployees(list, len);
                         printEmployees(list, len);
                         showTotalSalaryAndAverage(list, len);
                         showEmployeesWhoExceedTheAverageSalary(list, len);
                     }else{
                         printf("Error, please enter at least one employee before list\n"); /** Si no es igual a 1 muestro el error */
                     }
                break;
                case 5:
                break;
            }

}

int findEmployeeById(Employee list[] , int len)
{
    int i, searchId;
    int flag=0; /** Flag que determinara si se encontro o no el id */
    /** Pido el id validando que exista entre 1 y el tamaño del array y lo guardo en la variable*/
    searchId = getInt("\nEnter the employeer id: ", "\nError enter a valid id: ", 1, len); /** Guardo el id ingresado por el usuario en la variable */

    for(i=0; i<len;i++) /** Recorre el array */
    {
        if(searchId == list[i].id) /** Si en la lista el id ingresado por el usuario es igual a un id existente retorno la posicion de ese Empleado */
        {
            return i;
            flag=1; /** Cambio el flag para saber que se encontro un Empleado con ese id */
        }
    }

    if(flag==0) /** Si no encontro ningun id igual al ingresado por el usuario retorno -1 para poder operar en funcion editar y eliminar*/
    {
        return -1;
    }
}

void removeEmployee(Employee list[], int len)
{
    int findReturn;
    char answer;

    printEmployees(list, len);
    findReturn = findEmployeeById(list, len); /** Llamo a la funcion que encuentra el id y lo guardo en la variable*/
    printf("\n%8d %8s %8s\t $%8.1f %8.d\n", list[findReturn].id, list[findReturn].name, list[findReturn].lastName, list[findReturn].salary, list[findReturn].sector);
    /** Muestro el Empleado ingresado por el usuario usando el findReturn que fue asignado */

    if(findReturn != -1) /** Si el id ingresado no retorna un id inexistente pregunto si quiere eliminar ese Empleado */
    {
        answer = getChar("\nAre shure you want to delete this employee? (ENTER=Yes/n=No): ", "\nError, ENTER=Yes/n=No): ", '\n', 'n');
    if(answer=='\n')
    {
        list[findReturn].isEmpty=EMPTY; /** Si presiona enter marco esa posicion como vacia */
        printf("\nEmployeer deleted\n");
    }else{
        printf("\nAction canceled\n"); /** Si no, se calcela la accion */
    }
    }else{
        printf("\nError employeer id not found\n"); /** Si la funcion retorna -1, informo que el id ingresado no se encontro */
    }
}

void editEmployee(Employee list[], int len)
{
    int findReturn;
    int answer;
    int flag=0; /** Flag para determinar si se guardaron los datos o no */
    int flag2=0; /** Flag para mostrar los datos del usuario a editar */
    char enter;
    Employee auxEmployee; /** Genero una variable auxiliar para guardar los datos editados */

    printEmployees(list, len);
    findReturn = findEmployeeById(list, len); /** Llamo a la funcion que encuentra el id y lo guardo en la variable*/
    if(findReturn!=-1)
    {
        auxEmployee = list[findReturn]; /** Si el retorno es valido guardo todos los datos del Empleado en esa posicion en la variable auxiliar */
    }

    if(findReturn!=-1)
    {
        do
        {
            if(flag2==0)
            {
                /** Si es la primera vez que entra, muestro los datos del usuario en esa posicion */
                printf("\n%8d %8s %8s\t $%8.1f %8.d\n", list[findReturn].id, list[findReturn].name, list[findReturn].lastName, list[findReturn].salary, list[findReturn].sector);
            }
            if(flag2==1)
            {
                /** Si no, muestro los datos que carga el usuario en tiempo real mediante la variable auxiliar */
                printf("\n%8d %8s %8s\t $%8.1f %8.d\n", auxEmployee.id, auxEmployee.name, auxEmployee.lastName, auxEmployee.salary, auxEmployee.sector);
            }
            printf("\n1.NAME\n");
            printf("2.LAST NAME\n");
            printf("3.SALARY\n");
            printf("4.SECTOR\n");
            printf("5.SAVE CHANGES\n");
            printf("6.EXIT EDIT\n");
            answer = getInt("CHOOSE AN OPTION: ", "ERROR CHOOSE AN EXISTING OPTION: ", 1, 6); /** Guardo la opcion elegida en la variable */
            system("cls");

            switch(answer)
            {
                case 1:
                    getWord(auxEmployee.name, "\nReenter name: ");
                    printf("\nEmployeer precharged succesfully\n");
                    flag2=1; /** Cambio el flag para mostrar los datos en tiempo real */
                    break;
                case 2:
                    getWord(auxEmployee.lastName, "\nReenter last name: ");
                    printf("\nEmployeer precharged succesfully\n");
                    flag2=1; /** Cambio el flag para mostrar los datos en tiempo real */
                   break;
                case 3:
                    auxEmployee.salary = getFloat("\nReenter salary: ", "\nError, please enter an existing salary (10000 <> 100000): ", 10000, 100000);
                    printf("\nEmployeer precharged succesfully\n");
                    flag2=1; /** Cambio el flag para mostrar los datos en tiempo real */
                    break;
                case 4:
                    auxEmployee.sector = getInt("\nReenter sector: ", "\nError, please enter an existing sector (1/2/3/4): ", 1, 4);
                    printf("\nEmployeer precharged succesfully\n");
                    flag2=1; /** Cambio el flag para mostrar los datos en tiempo real */
                    break;
                case 5:
                    enter = getChar("\nYou want to save changes? (ENTER=Yes/n=No): ", "\nError, enter (ENTER=Yes/n=No): ", '\n', 'n');
                    /** Pregunto si el usuario quiere guardar los datos */
                if(enter=='\n')
                {
                     /** Si presiona enter paso todos los datos de la variable auxiliar a la posicion del array que se esta editando */
                     list[findReturn].id=auxEmployee.id;
                     list[findReturn]=auxEmployee;
                     list[findReturn].salary=auxEmployee.salary;
                     list[findReturn].isEmpty=FULL;
                     printf("\nChanges saved succefully\n");
                }else{
                     printf("\nChanges saves canceled\n"); /** Si no, informo que se cancelo la accion */
                     flag2=0;
                }
                     flag=1; /** Cambio el flag para saber que se guardaron los cambios */
                     break;
                case 6:
                if(flag==0)
                {
                     /** Si el usuario no guardo los datos, aviso que esta a punto de salir sin guardar datos y pregunto si quiere guardarlos */
                     enter = getChar("\nYou're about to leave without saving changes, you want to save them? (ENTER=Yes/n=No): ", "\nError, enter ENTER=Yes/n=No): ", '\n', 'n');
                if(enter=='\n')
                {
                     /** Si presiona enter los guardo */
                     list[findReturn].id=auxEmployee.id;
                     list[findReturn]=auxEmployee;
                     list[findReturn].salary=auxEmployee.salary;
                     list[findReturn].isEmpty=FULL;
                     printf("\nChanges saved succefully\n");
                }else{
                     printf("\nChanges saves canceled\n"); /** Si no, informo que se cancelo la operacion */
                }
                }
                    break;
            }
            }while(answer!=6);
            printf("\nExit edit menu\n");
            }else{
                printf("\nError, employeer id not found\n"); /** Si el retorno no es valido (-1) informo que no se encontro el id */
            }
}

int sortEmployees(Employee list[], int len)
{
    Employee auxEmployee; /** Genero variable auxiliar para ordenar */
    int i, j;

    for(i=0; i<len-1; i++) /** Recorro el array hasta una posicion antes que el tamaño del mismo */
    {
        for(j=i+1; j<len; j++) /** Recorro el array */
        {
            if(strcmp(list[i].lastName,list[j].lastName)>0) /** Comparacion de cadenas i y j para ordenamiento A-Z */
            {
                auxEmployee = list[i]; /** Guardo en la variable auxiliar el empleado en la posicion i */
                list[i] = list[j]; /** Asigno el empleado en la posicion j a la posicion i */
                list[j] = auxEmployee; /** Asigno a la posicion j el auxiliar */
            }
            else
            {
               if(strcmp(list[i].lastName,list[j].lastName)==0)/** Sino, si la comparacion de cadenas es completamente igual */
               {
                   if(list[i].sector>list[j].sector) /** Comparacion de enteros para ordenamiento por sector ante igualdad de criterio */
                   {
                        auxEmployee = list[i]; /** Guardo en la variable auxiliar el empleado en la posicion i */
                        list[i] = list[j]; /** Asigno el empleado en la posicion j a la posicion i */
                        list[j] = auxEmployee; /** Asigno a la posicion j el auxiliar */
                   }
               }
            }
        }
    }
    return 0;
}

void showTotalSalaryAndAverage(Employee list[], int len)
{
    int i;
    int counter=0;
    float total=0;
    float promedy;

    for(i=0; i<len; i++) /** Recorro el array */
    {
        if(list[i].isEmpty==FULL) /** Si la posicion i esta ocupada entro */
        {
            total+= list[i].salary; /** Acumulo el salario en la variable total */
            counter++; /** Aumento el contador para saber por cuanto promediar */
        }

    }

    promedy = total/counter; /** Calculo el promedio al salir del for */

    if(total==0) /** Si el total dio cero asigno cero a promedio para no mostrar basura */
    {
        promedy=0;
    }
    if(counter>0) /** Si el contador es mayo a cero, muestro el salario total y promedio */
    {
        printf("\n################################ TOTAL SALARY ###########\n");
        printf("\n                                  $%.1f\n", total);
        printf("\n############################### SALARY PROMEDY ##########\n");
        printf("\n                                  $%.1f\n", promedy);
    }
}

void showEmployeesWhoExceedTheAverageSalary(Employee list[], int len)
{
    int i;
    int flag=0; /** Flag para mostrar el titulo una sola vez */

    for(i=0; i<len; i++) /** Recorro el array */
    {
        if(list[i].isEmpty==FULL) /** Si la posicion i esta ocupada entro */
        {
            if(list[i].salary>=50000) /** Si el salario en la posicion i, es mayor al salario promedio entro */
            {
                if(flag==0) /** Si es la primera vez muestro el titulo */
                {
                    printf("\nEMPLOYEES WHO EXCEED THE AVERAGE SALARY (50.000):\n");
                    printf("\n\n##### ID ## NAME #LAST NAME ##### SALARY ##### SECTOR ###\n");
                    flag=1; /** Cambio el flag para no mostrar dos veces el titulo */
                }
                showEmployee(list[i]); /** Muestro el empleado en la posicion i llamando a la funcion y pasandole la posicion*/
            }
        }
    }
}
