#include "ArrayEmployees.h"
#include <stdio.h>
#include <string.h>

void hardCodeEmployee(Employee list[], int len)
{
  int i;
  int id[5]={1,2,3,4,5};
  char name[5][51]={"Travis","Roddy","Mark","Steve","Stephen"};
  char lastName[5][51]={"Scott","Richhy","Suckemberg","Jobs","Hawkings"};
  float salary[5]= {10000,11000,12000,13000,14000};
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

Employee addEmployees()
{
    Employee auxEmployee;
    int len;

    auxEmployee.id=createEmployeeId();

    printf("\nEnter the employee name: ");
    fflush(stdin);
    fgets(auxEmployee.name, 51, stdin);
    printf("\nEnter the employee's last name: ");
    fflush(stdin);
    fgets(auxEmployee.lastName, 51, stdin);

    printf("\nEnter the employee's salary: ");
    scanf("%f", &auxEmployee.salary);
    while(auxEmployee.salary<10000)
    {
        printf("\nError, please enter an existing salary: ");
        scanf("%f", &auxEmployee.salary);
    }

    printf("\nEnter the employee's sector: ");
    scanf("%d", &auxEmployee.sector);
    while(auxEmployee.sector!=1 && auxEmployee.sector!=2 && auxEmployee.sector!=3 && auxEmployee.sector!=4)
    {
        printf("\nError, please enter an existing sector: ");
        scanf("%d", &auxEmployee.sector);
    }

    len=strlen(auxEmployee.name);
    auxEmployee.name[len-1]='\0';
    len=strlen(auxEmployee.lastName);
    auxEmployee.lastName[len-1]='\0';

    auxEmployee.isEmpty = FULL;

    return auxEmployee;


}

static int createEmployeeId(void)
{
    static int id=0;
    id++;
    return id;
}

void printEmployees(Employee list[], int len)
{
    int i;
    int flag=0;

    printf("\n\n##### ID ## NAME #LAST NAME ##### SALARY ##### SECTOR ###\n");

    for(i=0;i<len;i++)
    {
       if(list[i].isEmpty==FULL)
       {
        showEmployee(list[i]);
        flag=1;
       }
    }
    if(flag==0)
    {
       printf("\nNothing to show, please add an employeer...\n\n");
    }

}

void showEmployee(Employee auxEmployee)
{

    printf("\n%8d %8s %8s\t $%8.1f %8.d\n", auxEmployee.id, auxEmployee.name, auxEmployee.lastName, auxEmployee.salary, auxEmployee.sector);

}

void chargeAllEmployee(Employee list[], int len)
{
  int i;

  for(i=0; i<len; i++)
  {
      list[i] = addEmployees();
  }
}

int initEmployees(Employee list[] , int len)
{
  int i;

  for(i=0; i<len; i++)
  {
      list[i].isEmpty = EMPTY;
  }
 return 0;
}

int searchEmpty(Employee list[], int len)
{
  int i;
  int index = -1;

  for(i=0; i<len; i++)
  {
      if(list[i].isEmpty==EMPTY)
      {
          index =  i;
          break;
      }
  }

  return index;

}

void chargueOneEmployeer(Employee list[], int len)
{
  int index;

  index = searchEmpty(list, len);

  if(index!=-1)
  {
      list[index] = addEmployees();
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
        printf("CHOOSE AN OPTION: ");
        scanf("%d", &option);
        system("cls");

        return option;
}

void actionMenu(Employee list[], int option, int len)
{
            switch(option)
            {
            case 1:
                 printf("### ADD EMPLOYEE ###");
                 chargueOneEmployeer(list, SIZE);
            break;
            case 2:
                 printf("### EDIT EMPLOYEES MENU ###");
                 editEmployee(list);
            break;
            case 3:
                 printf("### DELETE EMPLOYEE ###");
                 removeEmployee(list);
            break;
            case 4:
                 printf("### LIST EMPLOYEES ###");
                 sortEmployees(list, SIZE);
                 printEmployees(list, SIZE);
                 totalSalaryAndAverage(list, SIZE);
            break;
            case 5:
            break;
            }

}

int findEmployeeById(Employee list[] , int len)
{
    int i, searchId;
    int flag=0;

    printf("\nEnter the employeer id: ");
    scanf("%d", &searchId);

    for(i=0; i<len;i++)
    {
        if(searchId == list[i].id)
        {
            return i;
            flag=1;
        }
    }

    if(flag==0)
    {
        return -1;
    }

}

void removeEmployee(Employee list[])
{
    int findReturn;
    char answer;

    findReturn=findEmployeeById(list, SIZE);

    if(findReturn != -1)
    {
    printf("\nIf you are shure you want to delete this employeer press ENTER\n");
    fflush(stdin);
    scanf("%c", &answer);
    if(answer=='\n')
    {
    list[findReturn].isEmpty=EMPTY;
    printf("\nEmployeer deleted\n");
    }else{
    printf("\nAction canceled\n");
    }
    }else{
    printf("\nError employeer id not found\n");
    }
}

void editEmployee(Employee list[])
{
    int findReturn;
    int answer;
    int len;
    char enter;
    Employee auxEmployee;

    findReturn=findEmployeeById(list, SIZE);
    auxEmployee=list[findReturn];


    if(findReturn!=-1)
    {

    do
    {
    printf("\n1.NAME\n");
    printf("2.LAST NAME\n");
    printf("3.SALARY\n");
    printf("4.SECTOR\n");
    printf("5.SAVE CHANGES\n");
    printf("6.EXIT EDIT\n");
    printf("CHOOSE AN OPTION: ");
    scanf("%d", &answer);
    system("cls");

    switch(answer)
    {
        case 1:
           printf("\nReenter name: ");
           fflush(stdin);
           fgets(auxEmployee.name, 51, stdin);

           len=strlen(auxEmployee.name);
           auxEmployee.name[len-1]='\0';
           printf("\nEmployeer precharged succesfully\n");
           break;
        case 2:
           printf("\nReenter last name: ");
           fflush(stdin);
           fgets(auxEmployee.lastName, 51, stdin);

           len=strlen(auxEmployee.lastName);
           auxEmployee.lastName[len-1]='\0';
           printf("\nEmployeer precharged succesfully\n");
           break;
        case 3:
           printf("\nReenter salary: ");
           scanf("%f", &auxEmployee.salary);
           while(auxEmployee.salary<10000)
           {
                printf("\nError, please enter an existing salary: ");
                scanf("%f", &auxEmployee.salary);
           }
           printf("\nEmployeer precharged succesfully\n");
           break;
        case 4:
           printf("\nReenter sector: ");
           scanf("%d", &auxEmployee.sector);
           while(auxEmployee.sector!=1 && auxEmployee.sector!=2 && auxEmployee.sector!=3 && auxEmployee.sector!=4)
           {
                printf("\nError, please enter an existing sector: ");
                scanf("%d", &auxEmployee.sector);
           }
           printf("\nEmployeer precharged succesfully\n");
           break;
        case 5:
        printf("\nAre you shure you want to save changes? (ENTER=Yes)\n");
        fflush(stdin);
        scanf("%c", &enter);
        if(enter=='\n')
        {
            list[findReturn].id=auxEmployee.id;
            list[findReturn]=auxEmployee;
            list[findReturn].salary=auxEmployee.salary;
            list[findReturn].isEmpty=FULL;

            printf("\nChanges saved succefully\n");

        }else{
            printf("\nChanges saves canceled\n");
        }
            break;
        case 6:
            break;
        default:
            printf("\nError, select an existing option: ");
            fflush(stdin);
            scanf("%d", &answer);
            break;

    }
    }while(answer!=6);
    printf("\nExit edit menu\n");
    }else{
    printf("\nError, employeer id not found\n");
    }

}

int sortEmployees(Employee list[], int len)
{
    Employee auxEmployee;
    int i;
    int j;

    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(strcmp(list[i].lastName,list[j].lastName)>0)
            {
                auxEmployee = list[i];
                list[i] = list[j];
                list[j] = auxEmployee;
            }
            else
            {
               if(list[i].lastName==list[j].lastName)
               {
                   if(list[i].sector>list[j].sector)
                   {
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                   }
               }
            }
        }

    }
    return 0;
}

void totalSalaryAndAverage(Employee list[], int len)
{
    int i;
    int counter=0;
    float total=0;
    float promedy;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==FULL)
        {
            total+= list[i].salary;
            counter++;
        }

    }

    promedy = total/counter;
    if(total==0)
    {
        promedy=0;
    }
    printf("\n################################ TOTAL SALARY ###########\n");
    printf("\n                                  $%.1f\n", total);
    printf("\n############################### SALARY PROMEDY ##########\n");
    printf("\n                                  $%.1f\n", promedy);

}


