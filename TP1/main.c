#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void)
{
    int option;  /**< La opcion que devuelve funciones_Menu() determina en que case entrar. */
    int flag1=0; /**< Declaro los flag que cambian en el case 1 y 2. */
    int flag2=0; /**< para mostrar los datos cargados con un if en funciones_Menu() */
    int flag3=0; /**< Cambia en el case 3 para verificar que el usuario no muestre sin calcular. */
    float operatorOne=0;
    float operatorTwo=0;
    float showSum, showsubtraction, showDivision, showMultiplication, showFactorial;

    do
    {
        option = funciones_menu(operatorOne, operatorTwo, flag1, flag2); /**< Asigno la opcion que pide y devuelve el menu. */

        switch(option) /**< Opera segun la variable asignada arriba. */
        {
            case 1:
                operatorOne = funciones_getOperatorOne(); /**< Asigno el dato que pide y devuelve la funcion. */
                flag1=1;
                break;
            case 2:
                operatorTwo = funciones_getOperatorTwo(); /**< Asigno el dato que pide y devuelve la funcion. */
                flag2=1;
                break;
            case 3: /**< Asigno los resultados que retornan las funciones. */
                funciones_calculateOperations(operatorOne, operatorTwo);
                showSum = funciones_sum(operatorOne, operatorTwo);
                showsubtraction = funciones_subtraction(operatorOne, operatorTwo);
                showDivision = funciones_division(operatorOne, operatorTwo);
                showMultiplication = funciones_multiplication(operatorOne, operatorTwo);
                showFactorial = funciones_factorial(operatorOne);
                flag3=1;
                break;
            case 4: /**< Muestro las operaciones que imprime en la funcion. */
                funciones_showOperations(operatorOne, operatorTwo, flag3, showSum, showsubtraction, showDivision, showMultiplication, showFactorial);
                break;
            case 5:
                break;
                default:
                printf("Error, reingrese una de las opciones especificadas. \n\n"); /**< Mensaje de error si no entra en ningun case. */
        }
    }while(option!=5);
    system("cls");
    printf("Exit console...");
    return 0;
}
