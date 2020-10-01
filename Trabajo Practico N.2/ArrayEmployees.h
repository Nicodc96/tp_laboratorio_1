// SECTOR BIBLIOTECA
#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}Employee;
#endif // ARRAYEMPLOYEES_H_INCLUDED

int hardcodearEmpleados(Employee x[], int tam, int cant); // FUNCION DE TESTING
/** \brief Función unica y exclusivamente para fines de TESTING | Ingresa manualmente al array principal
*          datos de empleados
 *
* \param Employee x[] | Recibe el array principal de empleados
* \param int tam      | Tamaño del array principal
* \param int cant     | Cantida de Empleados a Hardcodear de Maximo 10
*
* \return int counter | La funcion devolverá un numero entero que servira para indicar al array principal
*         cuantos IDs se ingresaron y sumarlos. Así el próximo ingreso tomará la ID que corresponda.
*/

int menu();
/** \brief Menú de Opciones Principal | El programa iniciará mostrando esta función donde
*          el usuario ingresará un caracter de la cual devolverá la función correspondiente. Si
*          el caracter no corresponde a ninguno del menú indicará el mensaje de error y se volverá
*          a ejecutar.
* \param void
*
* \return char option | Devolverá un char que servirá para ejecutar una orden en el switch de main();
*/

int initEmployees(Employee employeesList[], int len);
/** \brief Función inicializadora del Array Principal | Antes de inicializar el menú principal
*          la función cargará en memoria el valor de isEmpty = 1 en todos los valores del array de tipo
*          Employee indicando que pueden ingresarse empleados y que no están ocupados.
*
* \param Employee employeesList[] | Array principal
* \param int len                  | Indicador del tamaño del array principal
*
* \return int isOk                | (0) si no pudo inicializarse el array, (1) si se ha cargado correctamente el array
*/

Employee addEmployee(int id, char name[],char lastName[],float salary,int sector);
/** \brief Función encargada de agregear elementos al array principal |
*
* \param int id             | ID del empleado
* \param char name[]        | Nombre del Empleado
* \param char lastName[]    | Apellido del Empleado
* \param float salary       | Salario del Empleado
* \param int sector         | Sector correspondiente al Empleado
*
* \return newEmployee       | La funcion devolvera el elemento cargado con los datos recibido por parámetro
*/

int searchEmpty(Employee employeesList[], int len);
/** \brief Función buscadora del primer elemento del array principal con valor
*          isEmpty = 1
*
* \param Employee employeesList[]   | Array principal
* \param int len                    | Tamaño del array principal
*
* \return int indice                | (-1) si no se encontrado ningún elemento del array
*         con valor isEmpty = 1 o el índice del elemento encontrado
*/

int newEmployee(Employee employeesList[], int len, int id);
/** \brief Función encargada de agregar un nuevo elemento al array principal
*
* \param Employee employeesList[]   | Array principal
* \param int len                    | Tamaño del array principal
* \param int id                     | ID pre-establecido desde main()
*
* \return int isOk                  | (0) Si el array está completo o no se pudo agregar el empleado al array
*         y (1) indicando que se agrego el empleado al array
*/

int findEmployeeById(Employee employeesList[], int len, int id);
/** \brief Función que busca un empleado con un ID recibido por parámetro
*
* \param int id                     | ID del empleado a buscar
* \param Employee employeesList[]   | Array principal
* \param int len                    | Tamaño del array principal
*
* \return int indice                | La funcion devolvera el indice del empleado si se ha encontrado
*         o devolverá (-1) si no se ha encontrado el empleado o el array es igual a NULL
*/

void printEmployee(Employee employeeX);
/** \brief Función que imprime un empleado
 *
 * \param Employee employeeX    | Un elemento de tipo Employee
 *
 * \return void                 |
 */

int printEmployees(Employee employeesList[], int len);
/** \brief Función que imprime el Array de empleados si NO estan vacios
*
* \param Employee employeesList[]     | Array principal
* \param int len                      | Tamaño del array principal
*
* \return int isOk                    | (1) si hay al menos 1 empleado cargado y lo muestra o
*         (0) si no hay empleados cargados mostrando el mensaje de error.
*/

int removeEmployee(Employee employeesList[], int len, int id);
/** \brief Función removedora de empleados con un ID recibido por parámetro
*
* \param Employee employeesList[]   | Array principal
* \param int len                    | Tamaño del array principal
* \param int id                     | ID recibido por parámetro
*
* \return int follow                | (0) si la funcion se ha cancelado o se realizaron demasiados
*         intentos fallidos o (1) si se ha dado de baja correctamente
*/

void removingEmployee(Employee employeesList[], int len);
/** \brief Función encargada de pedir un ID y ejecutar la función removeEmployee
 *
 * \param Employee employeesList[]  | Array principal
 * \param int len                   | Tamaño del array principal
 *
 * \return void                     | La funcion no retorna valor ya que termina en la funcion
 *         removeEmployee.
 */

int sortEmployees(Employee employeesList[], int len, int order);
/** \brief Función ordenadora de Array Principal
*
* \param Employee employeesList[]   | Array principal
* \param int len                    | Tamaño del array principal
* \param int order                  | Orden (1) de manera ascendente o (0) de manera descendente
*
* \return int isOk                  | (1) si se ha realizado correctamente el ordenamiento o (0) en caso contrario
*/

void modifyMenuCases(Employee employeesList[], int len, int id);
/** \brief Función ejecutora de la modificación de empleados | La función ejecuta la función
*          modifyMenu con un switch y realiza la acción que esta devuelva
* \param Employee employeesList[]  | Array principal
* \param int len                   | Tamaño del array principal
* \param int id                    | ID recibido de la funcion modifyingEmployee
*
* \return void                     |
*/

void modifyingEmployee(Employee employeesList[], int len);
/** \brief Función encargada de solicitar el ID del Empleado a modificar y
*          ejecutar la funcion modifyMenuCases
*
* \param Employee employeesList[]   | Array Principal
* \param int len                    | Tamaño del array principal
*
* \return void                      | La funcion termina enviando el ID verificado del empleado y
*         ejecutando a la funcion modifyMenuCases
*/

int modifyMenu(Employee employeesList[], int len, int id);
/** \brief Sub-Menú de opciones de modificación de los elementos en el array principal
*
* \param Employee employeesList[]   | Array Principal
* \param int len                    | Tamaño del array principal
* \param int id                     | ID verificado recibido de la funcion modifyingEmployee
*
* \return int option                | La función devolverá un entero (entre 1 y 5) verificado
*         que utilizará la función modifyMenuCases
*/

int checkEmployee(Employee employeesList[], int len);
/** \brief Función que comprueba si existen empleados en el array principal
*
* \param Employee employeesList[]   | Array principal
* \param int len                    | Tamaño del array principal
*
* \return int isOk                  | (0) si no existen empleados en el array o (1)
*         si hay al menos un empleado en el array.
*/

void sortEmployeesSalary(Employee employeesList[], int len);
/** \brief Función ejecutada por reportEmployees encargada de calcular e informar los salarios
*          totales de todos los empleados, el promedio de todos ellos y cuantos empleados superan
*          el promedio del salario general.
*
* \param Employee employeesList[]   | Array principal
* \param int len                    | Tamaño del array principal
*
* \return void                      | La funcion empieza y termina dentro de la función reportEmployees
*/

void reportEmployees(Employee employeesList[], int len);
/** \brief Funcion ejecutora de la opción "INFORMAR" | Muestra el menú de informes, ejecuta la opción
*          verificada y, llama las funciones sortEmployee y sortEmployeesSalary.
*
*
* \param Employee employeesList[]   | Array principal
* \param int len                    | Tamaño del array principal
*
* \return void                      | La función no retorna ningún valor, termina en main() una vez finalizado
*         el búcle while.
*/
