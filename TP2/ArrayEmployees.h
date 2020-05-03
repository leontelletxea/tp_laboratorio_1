#include <stdio.h>
#define EMPTY 0
#define FULL 1
#define SIZE 1000

struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;

void hardCodeEmployee(Employee list[], int len);

Employee addEmployees(void);

void printEmployees(Employee list[], int len);

void showEmployee(Employee auxEmployee);

void chargeAllEmployee(Employee list[], int len);

int initEmployees(Employee list[] , int len);

int searchEmpty(Employee list[], int len);

void chargueOneEmployeer(Employee list[], int len);

int optionMenu(void);

void actionMenu(Employee list[], int option, int len);

int findEmployeeById(Employee list[] , int len);

void removeEmployee(Employee list[]);

void editEmployee(Employee list[]);

static int createEmployeeId(void);

int sortEmployees(Employee list[], int len);

void totalSalaryAndAverage(Employee list[], int len);
