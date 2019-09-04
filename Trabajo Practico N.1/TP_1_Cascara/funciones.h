// [-std=c99] ACTIVADO

int menu(float*, float*);

/** \brief  Menu de opciones
 *
 * \param   Modifico los valores de los operandos en el menu segun vaya cambiando.
 * \param   Y devuelvo ese valor al switch.
 * \return  Finalmente, devuelvo la opcion seleccionada.
 *
 */

float sumar(float, float);

/** \brief  Funcion sumar.
 *
 * \param   Obtengo los datos de los operandos y los sumo.
 * \param
 * \return  Devuelvo el resultado.
 *
 */

float restar(float, float);

/** \brief  Funcion restar.
 *
 * \param   Resto los operandos.
 * \param
 * \return  Devuelvo el resultado.
 *
 */

 float dividir(float, float);

 /** \brief     Realizo una division.
  *
  * \param      Divido los operandos.
  * \param      Condiciono la divison si el divisor es igual a 0, que devolverá '-1' y mostrará el mensaje de error.
  * \return     Devuelvo el resultado.
  *
  */

  float multiplicar(float, float);

  /** \brief   Realizo una multiplicacion.
   *
   * \param     Multiplico los operandos.
   * \param
   * \return    Devuelvo el resultado.
   *
   */

   float factorizacion(long double);

   /** \brief  Factorizar el operando correspondiente.
    *
    * \param    Condiciono la funcion, preguntando si el factorial ingresado es un numero entero natural, sino devuelve -1.
    * \param    Realizo un loop con for() donde multiplico un valor base hasta que 'i' sea mayor que el numero ingresado.
    * \return   Devuelvo el resultado.
    *
    */



