#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0;
    int opcion;
    char a='x';
    char b='y';
    float A;
    float B;
    float suma;

    do
    {

        if(i==0)
        {
        printf("1. Ingresar 1er operando (A=%c): \n", a);
        printf("2. Ingresar 2do operando (B=%c): \n", b);
        }
        if(i>0)
        {
        printf("1. Ingresar 1er operando (A=%.2f): \n", A);
        printf("2. Ingresar 2do operando (B=%.2f): \n", B);
        }
        printf("3. Calcular todas las operaciones: \n a) Calcular la suma (A+B)\n b) Calcular la resta (A-B)\n c) Calcular la division (A/B)\n d) Calcular la multiplicacion (A*B)\n e) Calcular el factorial (A!)\n");
        printf("4. Informar resultados:\n a) Calcular la suma (A+B)\n b) Calcular la resta (A-B)\n c) Calcular la division (A/B)\n d) Calcular la multiplicacion (A*B)\n e) Calcular el factorial (A!)\n");
        printf("5. Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);
        i++;

        switch(opcion)
        {
            case 1:
                printf("1. Ingrese el 1er operando (A=x): \n");
                scanf("%f", &A);
                break;
            case 2:
                printf("2. Ingrese el 2do operando (B=y): \n");
                scanf("%f", &B);
                break;
            case 3:
                printf("3. Todas las operaciones han sido calculadas: \n a) Calcular la suma (A+B)\n b) Calcular la resta (A-B)\n c) Calcular la division (A/B)\n d) Calcular la multiplicacion (A*B)\n e) Calcular el factorial (A!)\n");
                break;
            case 4:
                printf("4. Informar resultados:\n a) Calcular la suma (A+B)\n b) Calcular la resta (A-B)\n c) Calcular la division (A/B)\n d) Calcular la multiplicacion (A*B)\n e) Calcular el factorial (A!)\n");
                break;
                default:
                printf("Error, reingrese una de las opciones especificadas");
            suma=resultadosuma(A, B);
        }
    }while(opcion!=5);
    //system("pause");
    //system("cls");
    return 0;
}



