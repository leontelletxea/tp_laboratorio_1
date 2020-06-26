
/** \brief Lee el archivo de texto que recibe como parametro, y guarda sus datos en una variable auxiliar de tipo empleado con el contructor parametrizado
 *         employee_newParametros(); luego lo agrega a la LinkedList con la funcion ll_add();
 * \param pFile FILE* El retorno cuando se abre el archivo en la funcion controller_loadFromText(); para verificar nulidad
 * \param pArrayListEmployee LinkedList* La LinkedList sobre la cual se esta trabajando
 * \return int Retorna 1
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief Lee el archivo binario que recibe como parametro, y guarda sus datos en una variable auxiliar de tipo empleado con el contructor parametrizado
 *         employee_newParametros(); luego lo agrega a la LinkedList con la funcion ll_add();
 * \param pFile FILE* El retorno cuando se abre el archivo en la funcion controller_loadFromText(); para verificar nulidad
 * \param pArrayListEmployee LinkedList* LinkedList* La LinkedList sobre la cual se esta trabajando
 * \return int Retorna 1
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief Recorre la LinkedList y toma el id mas alto y lo incrementa en 1
 *
 * \param pArrayListEmployee LinkedList* La LinkedList sobre la cual se esta trabajando
 * \return int Retorna el id incrementado en 1
 *
 */
int createEmployeeId(LinkedList* pArrayListEmployee);
