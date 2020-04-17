/** \brief Muestra el menu de opciones
 * \param operatorOne float - primer numero ingresado en el menu.
 * \param operatorTwo float - segundo numero ingresado en el menu.
 * \param flag1 int - cambia en el case cuando se ingresa el primer numero para mostrar los numeros cargados.
 * \param flag2 int - cambia en el case cuando se ingresa el primer numero para mostrar los numeros cargados.
 * \return option int - Devuelve un entero que determina en que case entrar.
 */
int funciones_menu(float operatorOne, float operatorTwo, int flag1, int flag2);

/** \brief Muestra un dialogo y permite cargar el primer numero.
 * \return operatorOne float - Devuelve el primer numero ingresado.
 */
float funciones_getOperatorOne(void);

/** \brief Muestra un dialogo y permite cargar el segundo numero.
 * \return operatorTwo float - Devuelve el segundo numero ingresado.
 */
float funciones_getOperatorTwo(void);

/** \brief Muestra un mensaje informando que se han realizado las operaciones.
 * \param operatorOne float - primer numero ingresado en el menu.
 * \param operatorTwo float - segundo numero ingresado en el menu.
 */
void funciones_calculateOperations(float operatorOne, float operatorTwo);

/** \brief Muestra las operaciones realizadas.
 * \param operatorOne float - primer numero ingresado en el menu.
 * \param operatorTwo float - segundo numero ingresado en el menu.
 * \param flag3 int - Cambia si se ejecuta el case 3, para verificar que las operaciones han sido calculadas.
 * \param showSum float - Recibe la asigacion que se efectua en el case 3.
 * \param showSubtraction float - Recibe la asigacion que se efectua en el case 3.
 * \param showDivision float - Recibe la asigacion que se efectua en el case 3.
 * \param showMultiplication float - Recibe la asigacion que se efectua en el case 3.
 * \param showFactorial float Recibe la asigacion que se efectua en el case 3.
 */
void funciones_showOperations(float operatorOne, float operatorTwo, int flag3, float showSum, float showSubtraction, float showDivision, float showMultiplication, float showFactorial);

/** \brief Toma las variables operando1 y operando2.
 * \param outcomeSum float - se guarga la suma entre operando1 y operando2.
 * \param operatorOne float - primer numero ingresado en el menu.
 * \param operatorOne float - segundo numero ingresado en el menu.
 * \return outcomeSum float - devuelve el resultado de la suma.
 */
float funciones_sum(float operatorOne, float operatorTwo);

/** \brief Toma las variables operando1 y operando2.
 * \param outcomeSubtraction float - se guarga la resta entre operando1 y operando2.
 * \param operatorOne float - primer numero ingresado en el menu.
 * \param operatorTwo float - segundo numero ingresado en el menu.
 * \return outcomeSubtraction float - devuelve el resultado de la resta.
 */
float funciones_subtraction(float operatorOne, float operatorTwo);

/** \brief Toma las variables operando1 y operando2.
 * \param outcomeDivision float - se guarga la division entre operando1 y operando2.
 * \param operatorOne float - primer numero ingresado en el menu.
 * \param operatorTwo float - segundo numero ingresado en el menu.
 * \return outcomeDivision float - devuelve el resultado de la division.
 */
float funciones_division(float operatorOne, float operatorTwo);

/** \brief Toma las variables operando1 y operando2.
 * \param outcomeMultiplication float - se guarga el producto entre operando1 y operando2.
 * \param operatorOne float - primer numero ingresado en el menu.
 * \param operatorTwo float - segundo numero ingresado en el menu.
 * \return outcomeMultiplication float - devuelve el resultado del producto.
 */
float funciones_multiplication(float operatorOne, float operatorTwo);

/** \brief Toma la variable operando1.
 * \param outcomeFactorial float - toma el valor 1.
 * \param operatorOne float - primer numero ingresado en el menu.
 * \return outcomeFactorial int - devuelve el factorial de operando1 relizado con el for.
 */
float funciones_factorial(float operatorOne);
