#include "funciones.h"

float FuncionSuma(float operando1, float operando2)
{
    float resultadosuma;

    resultadosuma= operando1 + operando2;

    return resultadosuma;
}

float FuncionResta(float operando1, float operando2)
{
    float resultadoresta;

    resultadoresta= operando1 - operando2;

    return resultadoresta;
}

float FuncionDividir(float operando1, float operando2)
{
    float resultadodivision;

    if(operando2 != 0)
    {
    resultadodivision= operando1 / operando2;
    }else{
    resultadodivision= -1.00;
    }

    return resultadodivision;
}

float FuncionMultiplicar(float operando1, float operando2)
{
    float resultadomultiplicion;

    resultadomultiplicion= operando1 * operando2;

    return resultadomultiplicion;
}

float FuncionFactorial(float operando1)
{
    int operandoint=operando1;
    float operandofloat=operando1;
    double resultadofactorial= 1;

    if(operandoint-operandofloat==0)
    {
    if( operando1 > 0)
    {

    for(operando1; operando1>0; operando1--)
    {
    resultadofactorial= operando1 * resultadofactorial;
    }

    }else{
    resultadofactorial= -1;
    }
    return resultadofactorial;
    }else
    {
        resultadofactorial=-1;
        return resultadofactorial;
    }


}
