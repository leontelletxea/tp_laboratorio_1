#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#endif // FUNCIONES_H_INCLUDED

/** \brief Toma las variables operando1 y operando2.
 * \param resultadosuma float - se guarga la suma entre operando1 y operando2.
 * \param operando1 float - primer numero ingresado en el menu.
 * \param operando2 float - segundo numero ingresado en el menu.
 * \return resultadosuma float - devuelve el resultado de la suma.
 */
float FuncionSuma(float operando1, float operando2);

/** \brief Toma las variables operando1 y operando2.
 * \param resultadoresta float - se guarga la resta entre operando1 y operando2.
 * \param operando1 float - primer numero ingresado en el menu.
 * \param operando2 float - segundo numero ingresado en el menu.
 * \return resultadoresta float - devuelve el resultado de la resta.
 */
float FuncionResta(float operando1, float operando2);

/** \brief Toma las variables operando1 y operando2.
 * \param resultadodivision float - se guarga la division entre operando1 y operando2.
 * \param operando1 float - primer numero ingresado en el menu.
 * \param operando2 float - segundo numero ingresado en el menu.
 * \return resultadodivision float - devuelve el resultado de la division.
 */
float FuncionDividir(float operando1, float operando2);

/** \brief Toma las variables operando1 y operando2.
 * \param resultadomultiplicacion float - se guarga el producto entre operando1 y operando2.
 * \param operando1 float - primer numero ingresado en el menu.
 * \param operando2 float - segundo numero ingresado en el menu.
 * \return resultadomultiplicacion float - devuelve el resultado del producto.
 */
float FuncionMultiplicar(float operando1, float operando2);

/** \brief Toma la variable operando1.
 * \param resultadofactorial float - toma el valor 1.
 * \param operando1 float - primer numero ingresado en el menu.
 * \return resultadofactorial float - devuelve el factorial de operando1 relizado con el for.
 */
float FuncionFactorial(float operando1);
