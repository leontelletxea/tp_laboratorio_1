#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int flag1=0;
    int flag2=0;
    int flag3=0;
    int opcion;
    float operando1=0;
    float operando2=0;
    float mostrarSuma, mostrarResta, mostrarDivision, mostrarMultiplicacion, mostrarFactorial;

    do
    {
        opcion = funciones_Menu(operando1, operando2, flag1, flag2);

        switch(opcion)
        {
            case 1:
                operando1 = funciones_GetOperando1();
                flag1=1;
                break;
            case 2:
                operando2 = funciones_GetOperando2();
                flag2=1;
                break;
            case 3:
                funciones_CalcularOperaciones(operando1, operando2);
                mostrarSuma = funciones_Suma(operando1, operando2);
                mostrarResta = funciones_Resta(operando1, operando2);
                mostrarDivision = funciones_Dividir(operando1, operando2);
                mostrarMultiplicacion = funciones_Multiplicar(operando1, operando2);
                mostrarFactorial = funciones_Factorial(operando1);
                flag3=1;
                break;
            case 4:
                funciones_MostrarOperaciones(operando1, operando2, flag3, mostrarSuma, mostrarResta, mostrarDivision, mostrarMultiplicacion, mostrarFactorial);
                break;
            case 5:
                break;
                default:
                printf("Error, reingrese una de las opciones especificadas: \n\n");
        }
    }while(opcion!=5);
    system("cls");
    printf("Exit console...");
    return 0;
}


