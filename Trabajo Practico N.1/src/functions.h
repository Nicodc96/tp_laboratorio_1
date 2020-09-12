/*
 * functions.h
 *
 *      Author: Lautaro N. Díaz
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

int menu(int* primerNum, int* segundoNum);
/** \brief  Menu de opciones
*
* \param   Modifico los valores de los operandos en el menu segun vaya cambiando.
* \param   Y devuelvo ese valor al switch.
* \return  Finalmente, devuelvo la opcion seleccionada ejecutando la funcion correspondiente.
*
*/

void menuInformes(int, int, float, int, double, double);
/** \brief Sub-menu de informes
 *
 * \param   Recibo 3 enteros, 1 float y 2 double lo cual son los resultados recibidos de las
 *          funciones operadoras.
 * \param   Valido los resultados, y devuelvo el mensaje que corresponde.
 *
 */

int sumar(int, int);
/** \brief  Funcion sumar.
*
* \param   Obtengo los datos de los operandos y los sumo.
* \param
* \return  Devuelvo el resultado.
*
*/

int restar(int, int);
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
* \param      Condiciono la divison si el divisor es igual a '0', que devolverá '-1' y mostrará el mensaje de error.
*             Verifico ademas que cuando el dividendo es igual a '0' la funcion retorne el valor correcto.
* \return     Devuelvo el resultado.
*
*/

int multiplicar(int, int);
/** \brief   Realizo una multiplicacion.
*
* \param     Multiplico los operandos.
* \param     Verifico que si alguno de los operando es igual a '0', la funcion retorne el valor correcto.
* \return    Devuelvo el resultado.
*
*/

double factorial(int);
/** \brief  Factorizar un numero correspondiente.
*
* \param    Condiciono la funcion, preguntando si el entero ingresado es igual a '0', lo que retornará '1',
*           o si es negativo, lo que devolverá '-1' o si es mayor al valor que puede devolver un double, lo que
            devolverá '-2'
* \param    Realizo un loop con for() donde multiplico un valor base hasta que 'i' sea mayor o igual que el numero ingresado.
* \return   Devuelvo el resultado.
*
*/

#endif /* FUNCTIONS_H_ */
