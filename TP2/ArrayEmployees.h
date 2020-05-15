#include <stdio.h>
#define EMPTY 0
#define FULL 1

struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;

/** \brief - Harcodeo corriente de los empleados
 *
 * \param list[] Employee - recibe la lista de empleados
 * \param len int - Recibe el tamaño del array
 * \return void
 *
 */
void hardCodeEmployees(Employee list[], int len);

/** \brief - Pide y retorna un entero
 *
 * \param message[] char - Recibe un mensaje
 * \param messageError[] char - Recibe un mensaje ante caso de error
 * \param min int - Recibe un parametro como maximo
 * \param max int - Recibe un parametro como minimo
 * \return int - Devuelve el entero ingresado
 *
 */
int getInt(char message[], char messageError[], int min, int max);

/** \brief - Pide y retorna un flotante
 *
 * \param message[] char - Recibe un mensaje
 * \param messageError[] char - Recibe un mensaje ante caso de error
 * \param min float Recibe un parametro como maximo
 * \param max float Recibe un parametro como minimo
 * \return float - Devuelve el flotante ingresado
 *
 */
float getFloat(char message[], char messageError[], float min, float max);

/** \brief - Pide y devuelve un char
 *
 * \param message[] char - Recibe un mensaje
 * \param messageError[] char - Recibe un mensaje ante caso de error
 * \param answer1 char - Recibe un primer parametro
 * \param answer2 char - Recibe un segundo parametro
 * \return char - Retorna el char
 *
 */
char getChar(char message[], char messageError[], char answer1, char answer2);

/** \brief - Pide y retorna una cadena de caracteres
 *
 * \param wordValue[] char - Recibe una variable como referencia a la cual sera asignada la cadena
 * \param message[] char - Recibe un mensaje
 * \return void
 *
 */
void getWord(char wordValue[], char message[]);

/** \brief - Pide los datos para agregar un empleado
 *
 * \param void
 * \return Employee - Retorna los datos ingresados guardados en una variable auxiliar
 *
 */
Employee addEmployees(void);

/** \brief - Imprime los empleados recorriendo el array y llamando a la funcion showEmployee() pasandole la posicion de i;
 *
 * \param list[] Employee - Recibe la lista de empleados
 * \param len int - Recibe el tamaño del array
 * \return void
 *
 */
void printEmployees(Employee list[], int len);

/** \brief - Muestra un empleado, esta funcion es llamada desde otras funciones
 *
 * \param auxEmployee Employee
 * \return void
 *
 */
void showEmployee(Employee auxEmployee);

/** \brief - Inicializa el estado de todo el array en vacio
 *
 * \param list[] Employee - Recibe la lista de empleados
 * \param len int - Recibe el tamaño del array
 * \return int retorna 0
 *
 */
int initEmployees(Employee list[] , int len);

/** \brief - Busca un id ingresado por el usuario en el array, si lo encuentra retorna su posicion, sino retorna una -1
 *
 * \param list[] Employee - Recibe la lista de empleados
 * \param len int - Recibe el tamaño del array
 * \return int - Retorna la posicion si encontro el id, o -1 si no lo encontro
 *
 */
int searchEmpty(Employee list[], int len);

/** \brief - Carga un empleado, esta funcion llama a addEmployee(); y es usada desde el menu de accion
 *
 * \param list[] Employee - Recibe la lista de empleados
 * \param len int - Recibe el tamaño del array
 * \return void
 *
 */
void chargueOneEmployee(Employee list[], int len);

/** \brief - Menu de opciones corriente
 *
 * \param void
 * \return int - Retorna la opcion elegida por el usuario
 *
 */
int optionMenu(void);

/** \brief - Menu de accion, opera segun la opcion elegida en optionMenu();
 *
 * \param list[] Employee - Recibe la lista de empleados
 * \param len int - Recibe el tamaño del array
 * \param option int - Recibe la opcion elegida por el usuario en optionMenu();
 * \param flag int - Recibe un flag para saber si se ingreso un empleado como minimo y si se puede entrar en los case 2, 3 y 4
 * \return void
 *
 */
void actionMenu(Employee list[], int len, int option, int flag);

/** \brief - Pide un id al usuario, y recorre el array, si coincide con un id valido retorna la posicion de ese Empleado
 *
 * \param list[] Employee - Recibe la lista de empleados
 * \param len int - Recibe el tamaño del array
 * \return int - Retorna la posicion del empleado si se encontro el id, o -1 si no lo encontro
 *
 */
int findEmployeeById(Employee list[] , int len);

/** \brief - llama a la funcion findEmployeeById(); y elimina el Empleado que ingreso el usuario si este existe
 *
 * \param list[] Employee - Recibe la lista de empleados
 * \param len int - Recibe el tamaño del array
 * \return void
 *
 */
void removeEmployee(Employee list[], int len);

/** \brief - llama a la funcion findEmployeeById(); y edita el Empleado que ingreso el usuario si este existe
 *
 * \param list[] Employee - Recibe la lista de empleados
 * \param len int - Recibe el tamaño del array
 * \return void
 *
 */
void editEmployee(Employee list[], int len);

/** \brief - Crea el un id de empleado, el cual es unico, esta funcion es llamada desde addEmployees
 *
 * \param void
 * \return int - Retorna el id
 *
 */
int createEmployeeId(void);

/** \brief - Ordena a los empleados por doble criterio ante igualdad, por apellido y sector
 *
 * \param list[] Employee - Recibe la lista de empleados
 * \param len int - Recibe el tamaño del array
 * \return int - Retorna 0
 *
 */
int sortEmployees(Employee list[], int len);

/** \brief - Calcula el salario total de todos los empleados y su promedio
 *
 * \param list[] Employee - Recibe la lista de empleados
 * \param len int - Recibe el tamaño del array
 * \return void
 *
 */
void showTotalSalaryAndAverage(Employee list[], int len);

/** \brief - Muestra los empleados que excedan el salario promedio (50.000)
 * \param list[] Employee - Recibe la lista de empleados
 * \param len int - Recibe el tamaño del array
 * \return void
 *
 */
void showEmployeesWhoExceedTheAverageSalary(Employee list[], int len);
