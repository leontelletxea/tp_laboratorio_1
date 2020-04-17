/** \brief Muestra el menu de opciones
 * \param operando1 float - primer numero ingresado en el menu.
 * \param operando2 float - segundo numero ingresado en el menu.
 * \param flag1 int - cambia en el case cuando se ingresa el primer numero para mostrar los numeros cargados.
 * \param flag2 int - cambia en el case cuando se ingresa el primer numero para mostrar los numeros cargados.
 * \return opcion int - Devuelve un entero que determina en que case entrar.
 */
int funciones_Menu(float operando1, float operando2, int flag1, int flag2);

/** \brief Muestra un dialogo y permite cargar el primer numero.
 * \return operando1 float - Devuelve el primer numero ingresado.
 */
float funciones_GetOperando1();

/** \brief Muestra un dialogo y permite cargar el segundo numero.
 * \return operando2 float - Devuelve el segundo numero ingresado.
 */
float funciones_GetOperando2();

/** \brief Muestra un mensaje informando que se han realizado las operaciones.
 * \param operando1 float - primer numero ingresado en el menu.
 * \param operando2 float - segundo numero ingresado en el menu.
 */
void funciones_CalcularOperaciones(float operando1, float operando2);

/** \brief Muestra las operaciones realizadas.
 * \param operando1 float - primer numero ingresado en el menu.
 * \param operando2 float - segundo numero ingresado en el menu.
 * \param flag3 int - Cambia si se ejecuta el case 3, para verificar que las operaciones han sido calculadas.
 * \param mostrarSuma float - Recibe la asigacion que se efectua en el case 3.
 * \param mostrarResta float - Recibe la asigacion que se efectua en el case 3.
 * \param mostrarDivision float - Recibe la asigacion que se efectua en el case 3.
 * \param mostrarMultiplicacion float - Recibe la asigacion que se efectua en el case 3.
 * \param mostrarFactorial float Recibe la asigacion que se efectua en el case 3.
 */
void funciones_MostrarOperaciones(float operando1, float operando2, int flag3, float mostrarSuma, float mostrarResta, float mostrarDivision, float mostrarMultiplicacion, float mostrarFactorial);

/** \brief Toma las variables operando1 y operando2.
 * \param resultadosuma float - se guarga la suma entre operando1 y operando2.
 * \param operando1 float - primer numero ingresado en el menu.
 * \param operando2 float - segundo numero ingresado en el menu.
 * \return resultadosuma float - devuelve el resultado de la suma.
 */
float funciones_Suma(float operando1, float operando2);

/** \brief Toma las variables operando1 y operando2.
 * \param resultadoresta float - se guarga la resta entre operando1 y operando2.
 * \param operando1 float - primer numero ingresado en el menu.
 * \param operando2 float - segundo numero ingresado en el menu.
 * \return resultadoresta float - devuelve el resultado de la resta.
 */
float funciones_Resta(float operando1, float operando2);

/** \brief Toma las variables operando1 y operando2.
 * \param resultadodivision float - se guarga la division entre operando1 y operando2.
 * \param operando1 float - primer numero ingresado en el menu.
 * \param operando2 float - segundo numero ingresado en el menu.
 * \return resultadodivision float - devuelve el resultado de la division.
 */
float funciones_Dividir(float operando1, float operando2);

/** \brief Toma las variables operando1 y operando2.
 * \param resultadomultiplicacion float - se guarga el producto entre operando1 y operando2.
 * \param operando1 float - primer numero ingresado en el menu.
 * \param operando2 float - segundo numero ingresado en el menu.
 * \return resultadomultiplicacion float - devuelve el resultado del producto.
 */
float funciones_Multiplicar(float operando1, float operando2);

/** \brief Toma la variable operando1.
 * \param resultadofactorial float - toma el valor 1.
 * \param operando1 float - primer numero ingresado en el menu.
 * \return resultadofactorial float - devuelve el factorial de operando1 relizado con el for.
 */
float funciones_Factorial(float operando1);
