#include "funciones.h"

int funciones_menu(float operatorOne, float operatorTwo, int flag1, int flag2)
{
        int option;

        /**< Muestro segun el flag que cambia en case 1 y case 2. */
        if(flag1==0)
        {
            printf("##########CALCULADORA##########\n");
            printf("1. Ingresar 1er operando (A=x): \n");
        }else{
            printf("\n##########CALCULADORA##########\n");
            printf("1. 1er operando (A=%.1f): \n", operatorOne);
        }
        if(flag2==0)
        {
            printf("2. Ingresar 2do operando (B=y): \n");
        }else{
            printf("2. 2do operando (B=%.1f): \n", operatorTwo);
        }
        if(flag1==0)
        {
            printf("3. Calcular todas las operaciones: \n a) Calcular la suma (A + B)\n b) Calcular la resta (A - B)\n c) Calcular la division (A / B)\n d) Calcular la multiplicacion (A * B)\n e) Calcular el factorial (A!)\n");
            printf("4. Informar resultados:\n a) Calcular la suma (A + B)= \n b) Calcular la resta (A - B)= \n c) Calcular la division (A / B)= \n d) Calcular la multiplicacion (A * B)= \n e) Calcular el factorial (A!)= \n");
        }else{
            printf("3. Calcular todas las operaciones: \n a) Calcular la suma (%.1f + %.1f)\n b) Calcular la resta (%.1f - %.1f)\n c) Calcular la division (%.1f / %.1f)\n d) Calcular la multiplicacion (%.1f * %.1f)\n e) Calcular el factorial (%.1f!)\n", operatorOne, operatorTwo, operatorOne, operatorTwo, operatorOne, operatorTwo, operatorOne, operatorTwo, operatorOne);
            printf("4. Informar resultados:\n a) Calcular la suma (%.1f + %.1f)= \n b) Calcular la resta (%.1f - %.1f)= \n c) Calcular la division (%.1f / %.1f)= \n d) Calcular la multiplicacion (%.1f * %.1f)= \n e) Calcular el factorial (%.1f!)= \n", operatorOne, operatorTwo, operatorOne, operatorTwo, operatorOne, operatorTwo, operatorOne, operatorTwo, operatorOne);
        }
            printf("5. Salir.\n");
            printf("Elija una opcion: ");
            scanf("%d", &option);
            system("cls");

        return option;
}

float funciones_getOperatorOne(void)
{
    float operando1;

    printf("1. Ingrese el 1er operando (A=x): "); /**< Pide y devuelve un flotante. */
    scanf("%f", &operando1);

    return operando1;
}

float funciones_getOperatorTwo(void)
{
    float operatorTwo;

    printf("2. Ingrese el 2do operando (B=y): "); /**< Pide y devuelve un flotante */
    scanf("%f", &operatorTwo);

    return operatorTwo;
}

void funciones_calculateOperations(float operatorOne, float operatorTwo)
{
    printf("3. Calculando operaciones...\n a) Calcular la suma (%.1f + %.1f)\n b) Calcular la resta (%.1f - %.1f)\n c) Calcular la division (%.1f / %.1f)\n d) Calcular la multiplicacion (%.1f * %.1f)\n e) Calcular el factorial (%.1f!)\n", operatorOne, operatorTwo, operatorOne, operatorTwo, operatorOne, operatorTwo, operatorOne, operatorTwo, operatorOne);
}

void funciones_showOperations(float operatorOne, float operatorTwo, int flag3, float showSum, float showSubtraction, float showDivision, float showMultiplication, float showFactorial)
{
    /**< Muestro segun el flag 3 que cambia si el usuario entro en el case 3 (comprueba que haya ingresado los numeros). */
    if(flag3==1)
        {
            printf("4. Los resultados son:\n a) Calcular la suma (%.1f + %.1f)= %.1f\n b) Calcular la resta (%.1f - %.1f)= %.1f\n ", operatorOne, operatorTwo, showSum, operatorOne, operatorTwo, showSubtraction);
    if(showDivision != -1.00 )/**< Valor asignado en caso que el divisor sea 0. */
        {
            showDivision = printf("c) Calcular la division (%.1f / %.1f)= %.1f\n",operatorOne, operatorTwo, showDivision);
        }else{
            showDivision = printf("c) Calcular la division (%.1f / %.1f)= Error, no es posible dividir por 0.\n", operatorOne, operatorTwo);
        }
           printf(" d) Calcular la multiplicacion (%.1f * %.1f)= %.1f\n",operatorOne, operatorTwo, showMultiplication);
    if(showFactorial != -1.00) /**< Valor asignado en caso de que el numero sea menor a cero o decimal. */
        {
           showFactorial = printf(" e) Calcular el factorial (%.1f!)= %.1f\n", operatorOne, showFactorial);
        }else{
           showFactorial = printf(" e) Calcular el factorial (%.1f!)= Error, no es posible realizar el factorial de un negativo o decimal.\n", operatorOne);
        }
        }else{
           printf("Porfavor, calcule las operaciones antes de mostrarlas:\n\n"); /**< Mensaje si el usuario muestra antes de calcular. */
           flag3=0;
        }
}

float funciones_sum(float operatorOne, float operatorTwo)
{
    float outcomeSum;

    outcomeSum = operatorOne + operatorTwo;

    return outcomeSum;
}

float funciones_subtraction(float operatorOne, float operatorTwo)
{
    float outcomeSubtraction;

    outcomeSubtraction = operatorOne - operatorTwo;

    return outcomeSubtraction;
}

float funciones_division(float operatorOne, float operatorTwo)
{
    float outcomeDivision;

    if(operatorTwo!= 0)
    {
    outcomeDivision= operatorOne / operatorTwo;
    }else{
    outcomeDivision = -1.00; /**< Si el divisor es 0, asigno -1.00 para informar el caso de error. */
    }

    return outcomeDivision;
}

float funciones_multiplication(float operatorOne, float operatorTwo)
{
    float outcomeMultiplication;

    outcomeMultiplication = operatorOne * operatorTwo;

    return outcomeMultiplication;
}

float funciones_factorial(float operatorOne)
{
    /**< Asigno el primer numero ingresado a una variable float e int. */
    int operatorInt = operatorOne;
    float operatorFloat = operatorOne;
    double outcomeFactorial = 1; /**< Doy un valor inicial para que el resultado vaya cambiando en cada iteracion */

    if(operatorInt-operatorFloat==0) /**< Si el resultado de el entero - el flotante es 0, el numero ingresado es entero. */
    {
    if( operatorOne > 0) /**< Si ese entero es mayor a cero, entra. */
    {
       for(operatorOne; operatorOne>0; operatorOne--)
    {
       outcomeFactorial = operatorOne * outcomeFactorial; /**< Realiza el factorial decrementando en uno en cada iteracion y multiplicandolo con el resultado. */
    }
    }else{
        outcomeFactorial = -1; /**< Si la resta del entero menos el flotante es != 0, asigno -1.00 para informar el caso de error. */
    }
    return outcomeFactorial;
    }else
    {
        outcomeFactorial = -1; /**< Si el numero es menor o igual a cero, asigno -1.00 para informal el caso de error. */
        return outcomeFactorial;
    }
}
