#include "funciones.h"

int funciones_Menu(float operando1, float operando2, int flag1, int flag2)
{
        int opcion;

        if(flag1==0)
        {
            printf("1. Ingresar 1er operando (A=x): \n");
        }else{

            printf("\n1. 1er operando (A=%.1f): \n", operando1);
        }
        if(flag2==0)
        {
            printf("2. Ingresar 2do operando (B=y): \n");
        }else{
            printf("2. 2do operando (B=%.1f): \n", operando2);
        }
        if(flag1==0)
        {
            printf("3. Calcular todas las operaciones: \n a) Calcular la suma (A + B)\n b) Calcular la resta (A - B)\n c) Calcular la division (A / B)\n d) Calcular la multiplicacion (A * B)\n e) Calcular el factorial (A!)\n");
            printf("4. Informar resultados:\n a) Calcular la suma (A + B)= \n b) Calcular la resta (A - B)= \n c) Calcular la division (A / B)= \n d) Calcular la multiplicacion (A * B)= \n e) Calcular el factorial (A!)= \n");
        }else{
            printf("3. Calcular todas las operaciones: \n a) Calcular la suma (%.1f + %.1f)\n b) Calcular la resta (%.1f - %.1f)\n c) Calcular la division (%.1f / %.1f)\n d) Calcular la multiplicacion (%.1f * %.1f)\n e) Calcular el factorial (%.1f!)\n", operando1, operando2, operando1, operando2, operando1, operando2, operando1, operando2, operando1);
            printf("4. Informar resultados:\n a) Calcular la suma (%.1f + %.1f)= \n b) Calcular la resta (%.1f - %.1f)= \n c) Calcular la division (%.1f / %.1f)= \n d) Calcular la multiplicacion (%.1f * %.1f)= \n e) Calcular el factorial (%.1f!)= \n", operando1, operando2, operando1, operando2, operando1, operando2, operando1, operando2, operando1);
        }
            printf("5. Salir.\n");
            printf("Elija una opcion: ");
            scanf("%d", &opcion);
            system("cls");

        return opcion;
}

float funciones_GetOperando1()
{
    float operando1;

    printf("1. Ingrese el 1er operando (A=x): ");
    scanf("%f", &operando1);

    return operando1;
}

float funciones_GetOperando2()
{
    float operando2;

    printf("2. Ingrese el 2do operando (B=y): ");
    scanf("%f", &operando2);

    return operando2;
}

void funciones_CalcularOperaciones(float operando1, float operando2)
{
    printf("3. Calculando operaciones...\n a) Calcular la suma (%.1f + %.1f)\n b) Calcular la resta (%.1f - %.1f)\n c) Calcular la division (%.1f / %.1f)\n d) Calcular la multiplicacion (%.1f * %.1f)\n e) Calcular el factorial (%.1f!)\n", operando1, operando2, operando1, operando2, operando1, operando2, operando1, operando2, operando1);
}

void funciones_MostrarOperaciones(float operando1, float operando2, int flag3, float mostrarSuma, float mostrarResta, float mostrarDivision, float mostrarMultiplicacion, float mostrarFactorial)
{
    if(flag3==1)
        {
            printf("4. Los resultados son:\n a) Calcular la suma (%.1f + %.1f)= %.1f\n b) Calcular la resta (%.1f - %.1f)= %.1f\n ", operando1, operando2, mostrarSuma, operando1, operando2, mostrarResta);
    if(mostrarDivision != -1.00 )
        {
            mostrarDivision = printf("c) Calcular la division (%.1f / %.1f)= %.1f\n",operando1, operando2, mostrarDivision);
        }else{
            mostrarDivision = printf("c) Calcular la division (%.1f / %.1f)= Error, no es posible dividir por 0.\n", operando1, operando2);
        }
           printf(" d) Calcular la multiplicacion (%.1f * %.1f)= %.1f\n",operando1, operando2, mostrarMultiplicacion);
    if(mostrarFactorial != -1.00)
        {
           mostrarFactorial = printf(" e) Calcular el factorial (%.1f!)= %.1f\n", operando1, mostrarFactorial);
        }else{
           mostrarFactorial = printf(" e) Calcular el factorial (%.1f!)= Error, no es posible realizar el factorial de un negativo o decimal.\n", operando1);
        }
        }else{
           printf("Porfavor, calcule las operaciones antes de mostrarlas:\n\n");
           flag3=0;
        }
}

float funciones_Suma(float operando1, float operando2)
{
    float resultadoSuma;

    resultadoSuma = operando1 + operando2;

    return resultadoSuma;
}

float funciones_Resta(float operando1, float operando2)
{
    float resultadoResta;

    resultadoResta = operando1 - operando2;

    return resultadoResta;
}

float funciones_Dividir(float operando1, float operando2)
{
    float resultadoDivision;

    if(operando2 != 0)
    {
    resultadoDivision= operando1 / operando2;
    }else{
    resultadoDivision = -1.00;
    }

    return resultadoDivision;
}

float funciones_Multiplicar(float operando1, float operando2)
{
    float resultadoMultiplicion;

    resultadoMultiplicion = operando1 * operando2;

    return resultadoMultiplicion;
}

float funciones_Factorial(float operando1)
{
    int operandoInt = operando1;
    float operandoFloat = operando1;
    double resultadoFactorial = 1;

    if(operandoInt-operandoFloat==0)
    {
    if( operando1 > 0)
    {

    for(operando1; operando1>0; operando1--)
    {
    resultadoFactorial = operando1 * resultadoFactorial;
    }

    }else{
    resultadoFactorial = -1;
    }
    return resultadoFactorial;
    }else
    {
        resultadoFactorial = -1;
        return resultadoFactorial;
    }
}
