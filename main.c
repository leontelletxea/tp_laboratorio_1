#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcion;
    int flag1=0;
    int flag2=0;
    int flag3=0;
    float operando1=0;
    float operando2=0;
    float mostrarsuma;
    float mostrarresta;
    float mostrardivision;
    float mostrarmultiplicacion;
    float mostrarfactorial;

    do
    {
        if(flag1==0)
        {
        printf("1. Ingresar 1er operando (A=x): \n");
        }else
        {
        printf("\n1. 1er operando (A=%.1f): \n", operando1);
        }

        if(flag2==0)
        {
        printf("2. Ingresar 2do operando (B=y): \n");
        }else
        {
        printf("2. 2do operando (B=%.1f): \n", operando2);
        }

        if(flag1==0)
        {
        printf("3. Calcular todas las operaciones: \n a) Calcular la suma (A + B)\n b) Calcular la resta (A - B)\n c) Calcular la division (A / B)\n d) Calcular la multiplicacion (A * B)\n e) Calcular el factorial (A!)\n");
        printf("4. Informar resultados:\n a) Calcular la suma (A + B)= \n b) Calcular la resta (A - B)= \n c) Calcular la division (A / B)= \n d) Calcular la multiplicacion (A * B)= \n e) Calcular el factorial (A!)= \n");
        }else
        {
        printf("3. Calcular todas las operaciones: \n a) Calcular la suma (%.1f + %.1f)\n b) Calcular la resta (%.1f - %.1f)\n c) Calcular la division (%.1f / %.1f)\n d) Calcular la multiplicacion (%.1f * %.1f)\n e) Calcular el factorial (%.1f!)\n", operando1, operando2, operando1, operando2, operando1, operando2, operando1, operando2, operando1);
        printf("4. Informar resultados:\n a) Calcular la suma (%.1f + %.1f)= \n b) Calcular la resta (%.1f - %.1f)= \n c) Calcular la division (%.1f / %.1f)= \n d) Calcular la multiplicacion (%.1f * %.1f)= \n e) Calcular el factorial (%.1f!)= \n", operando1, operando2, operando1, operando2, operando1, operando2, operando1, operando2, operando1);
        }
        printf("5. Salir.\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);
        system("cls");
        switch(opcion)
        {
            case 1:
                printf("1. Ingrese el 1er operando (A=x): ");
                scanf("%f", &operando1);
                flag1=1;
                break;
            case 2:
                printf("2. Ingrese el 2do operando (B=y): ");
                scanf("%f", &operando2);
                flag2=1;
                break;
            case 3:
                printf("3. Calculando operaciones...\n a) Calcular la suma (%.1f + %.1f)\n b) Calcular la resta (%.1f - %.1f)\n c) Calcular la division (%.1f / %.1f)\n d) Calcular la multiplicacion (%.1f * %.1f)\n e) Calcular el factorial (%.1f!)\n", operando1, operando2, operando1, operando2, operando1, operando2, operando1, operando2, operando1);
                mostrarsuma = FuncionSuma(operando1, operando2);
                mostrarresta = FuncionResta(operando1, operando2);
                mostrardivision = FuncionDividir(operando1, operando2);
                mostrarmultiplicacion = FuncionMultiplicar(operando1, operando2);
                mostrarfactorial = FuncionFactorial(operando1);
                flag3=1;
                break;
            case 4:
                if(flag3==1)
                {
                 printf("4. Los resultados son:\n a) Calcular la suma (%.1f + %.1f)= %.1f\n b) Calcular la resta (%.1f - %.1f)= %.1f\n ", operando1, operando2, mostrarsuma, operando1, operando2, mostrarresta);
                if(mostrardivision != -1.00 )
                {
                    mostrardivision = printf("c) Calcular la division (%.1f / %.1f)= %.1f\n",operando1, operando2, mostrardivision);
                }else
                {
                    mostrardivision = printf("c) Calcular la division (%.1f / %.1f)= Error, no es posible dividir por 0.\n", operando1, operando2);
                }
                printf(" d) Calcular la multiplicacion (%.1f * %.1f)= %.1f\n",operando1, operando2, mostrarmultiplicacion);
                if(mostrarfactorial != -1.00)
                {
                    mostrarfactorial = printf(" e) Calcular el factorial (%.1f!)= %.1f\n", operando1, mostrarfactorial);
                }else{
                    mostrarfactorial = printf(" e) Calcular el factorial (%.1f!)= Error, no es posible realizar el factorial de un negativo o decimal.\n", operando1);
                }
                }else
                {
                    printf("Porfavor, calcule las operaciones antes de mostrarlas:\n");
                    flag3=0;
                }

                break;
            case 5:
                break;
                default:
                printf("Error, reingrese una de las opciones especificadas: \n\n");
        }
    }while(opcion!=5);
    system("cls");
    printf("EXIT CONSOLE");
    return 0;
}


